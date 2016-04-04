<?php
/**
 * @file
 * Defines \FeatureContext.
 */

use Behat\Behat\Context\Step\Given;
use Behat\Behat\Context\Step\Then;
use Behat\Gherkin\Node\TableNode;
use Behat\Mink\Exception\ElementHtmlException;
use Behat\Mink\Exception\ExpectationException;
use Behat\Mink\Exception\UnsupportedDriverActionException;
use Drupal\DrupalExtension\Context\DrupalContext;
use Drupal\DrupalExtension\Event\EntityEvent;
use Behat\Behat\Event\SuiteEvent;

class FeatureContext extends DrupalContext {
  protected $timestamp;
  protected $originalMailSystem;
  protected $customParameters;
  protected $sysCheckResult;
  protected $ssoIsOn = FALSE;

  protected $sso_module_list = array(
    'prc_sso',
    'prc_sso_user',
    'bt_onelogin_saml',
    'ldap_query',
    'ldap_servers',
    'ldap_user'
  );

  /**
   * Initializes context.
   *
   * Every scenario gets its own context instance.
   * You can also pass arbitrary arguments to the
   * context constructor through behat.yml.
   */
  public function __construct($parameters) {
    $this->timestamp = time();
    $this->customParameters = !empty($parameters) ? $parameters : array();
  }

  protected function fixStepArgument($argument) {
    if (strpos($argument, '@timestamp') !== FALSE) {
      $argument = str_replace('@timestamp', $this->timestamp, $argument);
    }
    if (strpos($argument, '@uname') !== FALSE) {
      $start = strpos($argument, '@uname');
      $bracket_open = strpos($argument, '[', $start);
      $bracket_close = strpos($argument, ']', $start);
      $uname = substr($argument, $bracket_open + 1, $bracket_close - $bracket_open - 1);
      $user = $this->users[$uname];
      $uid = $user->uid;
      $whole_token = "@uname[$uname]";
      $argument = str_replace($whole_token, $uid, $argument);
    }
    if (strpos($argument, '@nid') !== FALSE) {
      $start = strpos($argument, '@nid');
      $bracket_open = strpos($argument, '[', $start);
      $bracket_close = strpos($argument, ']', $start);
      $node_name = substr($argument, $bracket_open + 1, $bracket_close - $bracket_open - 1);
      $found_nid = 0;
      foreach ($this->nodes as $node) {
        if ($node->title == $node_name) {
          $found_nid = $node->nid;
          break;
        }
      }
      $whole_token = '@nid[' . $node_name . ']';
      $argument = str_replace($whole_token, $found_nid, $argument);
    }
    if (strpos($argument, '@currentuid') !== FALSE) {
      if ($this->user) {
        $current_uid = $this->user->uid;
        $argument = str_replace('@currentuid', $current_uid, $argument);
      }
      else {
        throw new Exception("Must be logged in as a user");
      }
    }
    return parent::fixStepArgument($argument);
  }

  /**
   * Checks if Driver supports Javascript.
   *
   * @return bool
   *   TRUE if it does, FALSE otherwise.
   */
  protected function isJavascriptSupported() {
    $js = TRUE;
    $script = 'foo = 1;';
    try {
      $this->getSession()->getDriver()->evaluateScript($script);
    } catch (UnsupportedDriverActionException $e) {
      $js = FALSE;
    }
    return $js;
  }

  /**
   * The default assertRegionHeading() doesn't do a fixStepArgument()
   * on the $heading variable. We need to.
   * @param $heading
   * @param $region
   * @throws Exception
   */
  public function assertRegionHeading($heading, $region) {
    $fixed_heading = $this->fixStepArgument($heading);
    return parent::assertRegionHeading($fixed_heading, $region);
  }

  /**
   * @BeforeSuite
   */
  public static function prepare(SuiteEvent $event) {
    // Disable honeypot timer before suite runs
    variable_set('honeypot_time_limit', '0');
    // Set autologout timeout to minimum length
    variable_set('autologout_timeout', '60');
    // Reduce autologout padding
    variable_set('autologout_padding', '5');
  }

  /**
   * @AfterSuite
   */
  public static function teardown(SuiteEvent $event) {
    // Set honeypot timer back to default after suite runs
    variable_set('honeypot_time_limit', '5');
    // Reset autologout timeout
    variable_set('autologout_timeout', '28800');
    // Reset autologout padding
    variable_set('autologout_padding', '20');
  }

  /**
   * @BeforeScenario @sso
   */
  public function beforeScenarioSSO($event) {
    $this->enableSSO();
    $this->ssoIsOn = TRUE;
  }

  private function enableSSO() {
    if (!module_exists('prc_sso')) {
      $this->assertDrushCommandWithArgument('en', '-y ' . implode(' ', $this->sso_module_list));
    }
  }

  private function disableSSO() {
    if (module_exists('prc_sso')) {
      $this->assertDrushCommandWithArgument('dis', '-y ' . implode(' ', $this->sso_module_list));
    }
  }

  /**
   * @BeforeScenario ~@sso
   */
  public function beforeScenarioNotSSO($event) {
    $this->disableSSO();
    $this->ssoIsOn = FALSE;
  }

  /**
   * @Given /^I flag "([^"]*)" with "([^"]*)"$/
   */
  public function flagNode($node_title, $flag_name) {
    $node_title = $this->fixStepArgument($node_title);
    $flag_name = $this->fixStepArgument($flag_name);

    $all_flags = flag_get_flags();
    $found_flag = NULL;
    foreach ($all_flags as $flag) {
      if ($flag->title == $flag_name) {
        $found_flag = flag_load($flag->name);
        break;
      }
    }
    if (!$found_flag) {
      throw new \Exception(sprintf("Flag '%s' not found", $flag_name));
    }

    $found_node = NULL;
    foreach ($this->nodes as $node) {
      if ($node->title == $node_title) {
        $found_node = $node;
        break;
      }
    }
    if (!$found_node) {
      throw new \Exception(sprintf("Node '%s' not found", $node_title));
    }

    $nid = $found_node->nid;
    $account = $this->user ? user_load($this->user->uid) : NULL;
    $found_flag->flag('flag', $nid, $account, TRUE);
  }

  /**
   * @Given /^I follow meta refresh$/
   */
  public function iFollowMetaRefresh() {
    while ($refresh = $this->getMainContext()
      ->getSession()
      ->getPage()
      ->find('css', 'meta[http-equiv="Refresh"]')) {
      $content = $refresh->getAttribute('content');
      $url = str_replace('0; URL=', '', $content);
      $this->getMainContext()->getSession()->visit($url);
    }
  }

  /**
   * @Then /^"([^"]*)" should be visible$/
   * @param $selector
   * @throws Exception
   */
  public function shouldBeVisible($selector) {
    $el = $this->getSession()->getPage()->find('css', $selector);
    if (empty($el)) {
      throw new Exception("Element ({$selector}) not found");
    }
    elseif (!$el->isVisible()) {
      throw new Exception("Element ({$selector}) is not visible");
    }
  }

  /**
   * @Then /^"([^"]*)" should not be visible$/
   */
  public function shouldNotBeVisible($selector) {
    $el = $this->getSession()->getPage()->find('css', $selector);
    if (empty($el)) {
      throw new Exception("Element ({$selector}) not found");
    }
    elseif ($el->isVisible()) {
      throw new Exception("Element ({$selector}) is visible");
    }
  }

  /**
   * @Then /^the "([^"]*)" radio button should be selected$/
   * @When /^the radio button "(?P<label>[^"]*)" with the id "(?P<id>[^"]*)" should be selected$/
   */
  public function assertRadioButtonSelected($label, $id = FALSE) {
    $element = $this->getSession()->getPage();
    $radiobutton = $id ? $element->findById($id) : $element->find('named', array(
      'radio',
      $this->getSession()->getSelectorsHandler()->xpathLiteral($label)
    ));
    if ($radiobutton === NULL) {
      throw new \Exception(sprintf('The radio button with "%s" was not found on the page %s', $id ? $id : $label, $this->getSession()
        ->getCurrentUrl()));
    }
    $value = $radiobutton->getAttribute('value');
    $labelonpage = $radiobutton->getParent()->getText();
    if ($label != $labelonpage) {
      throw new \Exception(sprintf("Button with id '%s' has label '%s' instead of '%s' on the page %s", $id, $labelonpage, $label, $this->getSession()
        ->getCurrentUrl()));
    }
    $checked = $radiobutton->isChecked();
    if (!$checked) {
      $message = sprintf('Radio button "%s" is not selected, but it should be.', $label);
      throw new ExpectationException($message, $this->getSession());
    }
  }

  public function assertLoggedInByName($name) {
    $name = $this->fixStepArgument($name);
    parent::assertLoggedInByName($name);
  }

  public function assertLinkVisible($link) {
    $link = $this->fixStepArgument($link);
    parent::assertLinkVisible($link);
  }

  public function assertNotLinkVisible($link) {
    $link = $this->fixStepArgument($link);
    parent::assertNotLinkVisible($link);
  }

  /**
   * @Given /^the "([^"]*)" link should point to "([^"]*)"$/
   */
  public function theLinkShouldPointTo($link, $href) {
    $link = $this->fixStepArgument($link);
    $element = $this->getSession()->getPage();
    $result = $element->findLink($link);

    if (empty($result)) {
      throw new \Exception(sprintf("No link to '%s' on the page %s", $link, $this->getSession()
        ->getCurrentUrl()));
    }
    $actual_href = $result->getAttribute('href');
    if (strpos($actual_href, $href) === FALSE) {
      throw new \Exception(sprintf("The link '%s' does not point to '%s', it points to '%s'", $link, $href, $actual_href));
    }

  }

  /**
   * @Then /^"([^"]*)" in "([^"]*)" should be selected$/
   */
  public function inShouldBeSelected($optionValue, $select) {
    $selectElement = $this->getSession()
      ->getPage()
      ->find('named', array('select', "\"{$select}\""));

    if($selectElement) {
      $optionElement = $selectElement->find('named', array(
        'option',
        "\"{$optionValue}\""
      ));

      //it should have the attribute selected and it should be set to selected
      if (!$optionElement->hasAttribute("selected")) {
        throw new \Exception(sprintf('The select box with "%s" has nothing selected', $select));
      }
      if (!$optionElement->getAttribute("selected") == "selected") {
        throw new \Exception(sprintf('The select box "%s" should have had %s selected.', $select, $optionValue));
      }
    }else{
      throw new \Exception(sprintf('The select box "%s" was not found.', $select));
    }
  }

  /**
   * Checks for a field with specified id|name|title|alt|value.
   *
   * @Then /^(?:|I )should see an? "(?P<element>[^"]*)" field$/
   */
  public function iShouldSeeAField($field) {
    $field = $this->fixStepArgument($field);
    if (!$this->getSession()->getPage()->hasField($field)) {
      throw new Exception("Element ({$field}) not found");
    }
  }

  /**
   * Checks for that a field with specified id|name|title|alt|value does not exist.
   *
   * @Then /^(?:|I )should not see an? "(?P<element>[^"]*)" field$/
   */
  public function iShouldNotSeeAField($field) {
    $field = $this->fixStepArgument($field);
    if ($this->getSession()->getPage()->hasField($field)) {
      throw new Exception("Element ({$field}) found");
    }
  }

  /**
   * Checks for a link with specified id|name|title|alt|value.
   *
   * @Then /^(?:|I )should see an? "(?P<element>[^"]*)" link$/
   */
  public function iShouldSeeALink($field) {
    $field = $this->fixStepArgument($field);
    if (!$this->getSession()->getPage()->hasLink($field)) {
      throw new Exception("Element ({$field}) not found");
    }
  }

  /**
   * Checks for a button with specified id|name|title|alt|value.
   *
   * @Then /^(?:|I )should see an? "(?P<button>(?:[^"]|\\")*)" button$/
   */
  public function iShouldSeeAButton($button) {
    $button = $this->fixStepArgument($button);
    if (!$this->getSession()->getPage()->hasButton($button)) {
      throw new Exception("Element ({$button}) not found");
    }
  }

  /**
   * Asserts that a given node type is not editable.
   *
   * @Then /^I should not be able to edit (?:a|an) "([^"]*)" node$/
   */
  public function assertNotEditNodeOfType($type) {
    $node = (object) array('type' => $type);
    $saved = $this->getDriver()->createNode($node);
    $this->nodes[] = $saved;

    // Set internal browser on the node edit page.
    $this->getSession()
      ->visit($this->locatePath('/node/' . $saved->nid . '/edit'));

    // Test status.
    return new Then("I should get a \"403\" HTTP response");

  }

  /**
   * Navigates to the View page for the last node in $this->nodes
   * @Then /^I visit the last node created$/
   */
  public function iVisitTheLastNodeCreated() {
    if (!is_array($this->nodes) || count($this->nodes) == 0) {
      throw new Exception('No nodes have been created by this context');
    }
    $last_index = count($this->nodes) - 1;
    $last_node = $this->nodes[$last_index];
    $nid = $last_node->nid;

    return new Given("I am on \"node/$nid\"");
  }

  /**
   * Navigates to the View page for the first node in $this->nodes
   * @Then /^I visit the first node created$/
   */
  public function iVisitTheFirstNodeCreated() {
    if (!is_array($this->nodes) || count($this->nodes) == 0) {
      throw new Exception('No nodes have been created by this context');
    }
    $last_node = $this->nodes[0];
    $nid = $last_node->nid;

    return new Given("I am on \"node/$nid\"");
  }

  /**
   * Asserts a 403 for the View page for the last node in $this->nodes
   * @Then /^I cannot visit the last node created$/
   */
  public function iCannotVisitTheLastNodeCreated() {
    if (!is_array($this->nodes) || count($this->nodes) == 0) {
      throw new Exception('No nodes have been created by this context');
    }
    $last_index = count($this->nodes) - 1;
    $last_node = $this->nodes[$last_index];
    $nid = $last_node->nid;

    // Set internal browser on the node edit page.
    $this->getSession()->visit($this->locatePath('node/' . $nid));

    // Test status.
    return new Then("I should get a \"403\" HTTP response");
  }


  /**
   * Asserts that a given user has the specified role.
   *
   * @Then /^the user "([^"]*)" should have a role of "([^"]*)"$/
   */
  public function assertUserHasRole($username, $role) {
    $username = $this->fixStepArgument($username);
    entity_get_controller('user')->resetCache();
    $account = user_load_by_mail($username);
    if (!$account) {
      throw new \Exception(sprintf("The user '%s' does not exist", $username));
    }
    $roles = $account->roles;
    if (!array_search($role, $roles)) {
      throw new \Exception(sprintf("The user '%s' did not have a role of '%s'", $username, $role));
    }
  }

  /**
   * Asserts that a given user has the specified role.
   *
   * @Then /^the user "([^"]*)" should not have a role of "([^"]*)"$/
   */
  public function assertUserDoesNotHaveRole($username, $role) {
    $username = $this->fixStepArgument($username);
    $account = user_load_by_mail($username);
    if (!$account) {
      throw new \Exception(sprintf("The user '%s' does not exist", $username));
    }
    $roles = $account->roles;
    if (array_search($role, $roles)) {
      throw new \Exception(sprintf("The user '%s' has the '%s' role", $username, $role));
    }
  }

  /**
   * Deletes the user with the specified email address.
   *
   * @Then /^I delete the user with the email address "([^"]*)"$/
   */
  public function deleteUserByEmail($email) {
    $email = $this->fixStepArgument($email);
    $user = user_load_by_mail($email);
    user_delete($user->uid);
  }

  /**
   * Asserts that a given field has the specified length
   *
   * @Then /^the field "([^"]*)" should have a length of "([^"]*)"$/
   */
  public function assertFieldLength($field, $length) {
    $f = field_info_field($field);
    $actual_length = $f['columns']['format']['length'];
    if ($length != $actual_length) {
      throw new \Exception(sprintf("The field '%s' did not have a length of %d.\nInstead, it was:\n\n%d", $field, $length, $actual_length));
    }
  }

  /**
   * @Then /^I should have the "([^"]*)" role$/
   */
  public function iShouldHaveTheRole($role) {
    $drupal_user = user_load($this->user->uid, TRUE);
    $roles = $drupal_user->roles;
    if (!array_search($role, $roles)) {
      throw new \Exception(sprintf("The current user did not have a role of '%s'", $role));
    }
  }

  /**
   * @Given /^I should not have the "([^"]*)" role$/
   */
  public function iShouldNotHaveTheRole($role) {
    $drupal_user = user_load($this->user->uid);
    $roles = $drupal_user->roles;
    if (array_search($role, $roles)) {
      throw new \Exception(sprintf("The current user has the '%s' role", $role));
    }
  }

  /**
   * Creates multiple users.
   * Overrides parent::createUsers().
   */
  public function createUsers(\Behat\Gherkin\Node\TableNode $usersTable) {
    $this->tableNodeFixStepArguments($usersTable);
    foreach ($usersTable->getHash() as $userHash) {

      // If we have roles convert it to array.
      if (isset($userHash['roles'])) {
        $userHash['roles'] = explode(',', $userHash['roles']);
        $userHash['roles'] = array_map('trim', $userHash['roles']);

        $roles = $userHash['roles'];
        unset($userHash['roles']);
      }

      $user = (object) $userHash;

      // Set a password.
      if (!isset($user->pass)) {
        $user->pass = $this->getDrupal()->random->name();
      }

      $this->dispatcher->dispatch('beforeUserCreate', new EntityEvent($this, $user));
      $this->getDriver()->userCreate($user);
      $this->dispatcher->dispatch('afterUserCreate', new EntityEvent($this, $user));

      // Now we will populate all of the field_ entries in the TableNode
      $account = user_load_by_name($user->name);
      $w = entity_metadata_wrapper('user', $account);

      // We are using email_registration, so we have to tweak the user name to match what it expects
      $email_parts = explode('@', $userHash['mail']);
      $new_user_name = $email_parts[0] . '_' . $account->uid;
      $w->name->set($new_user_name);

      foreach ($userHash as $key => $value) {
        if (strpos($key, 'field_') === 0) {
          // This is a field_something so we have to assign it
          $w->{$key}->set($value);
        }
      }
      $w->save();

      if (isset($roles) && is_array($roles)) {
        $system_roles = user_roles();
        $new_role = array();
        $curr_user = user_load($user->uid);
        foreach ($roles as $role_name) {
          // If the user doesn't already have the role, add the role to that user.
          $key = array_search($role_name, $curr_user->roles);
          if (isset($user->role)) {
            $user->role .= ', ' . $role_name;
          }
          else {
            $user->role = $role_name;
          }
          if ($key == FALSE) {
            // Get the rid from the roles table.
            $rid = array_search($role_name, $system_roles);
            if ($rid != FALSE) {
              $new_role[$rid] = $role_name;
            }
          }
        }
        $all_roles = $curr_user->roles + $new_role; // Add new role to existing roles.
        user_save($curr_user, array('roles' => $all_roles));
      }
      $this->users[$user->name] = $user;
      // This is custom for this implementation - email_registration!
      $this->users[$user->name]->name = $user->mail;
    }
  }

  public function assertNumElements($num, $element) {
    $element = $this->fixStepArgument($element);
    if (substr($element, 0, 2) == '//') {
      // This is xpath
      $this->assertSession()->elementsCount('xpath', $element, intval($num));
    }
    else {
      // This is CSS
      parent::assertNumElements($num, $element);
    }
  }


  /**
   * Creates X number of random users with the specified role.
   * Note: This will delete all users other than UID 1, as Devel Generate Users can.
   * This also will not automatically clean up these users.
   *
   * @Given /^I have a total of (\d+) users with the "(?P<role>[^"]*)" role$/
   */
  public function createXUsersOfYRoleAndKillOtherUsers($number, $role) {
    $uids = db_select('users', 'u')
      ->fields('u', array('uid'))
      ->condition('uid', 1, '>')
      ->execute()
      ->fetchAllAssoc('uid');
    user_delete_multiple(array_keys($uids));
    // Users killed
    $this->createXUsersOfYRole($number, $role);
  }

  /**
   * Creates X number of random users with the specified role
   *
   * @Given /^I create (\d+) users with the "(?P<role>[^"]*)" role$/
   */
  public function createXUsersOfYRole($number, $role) {
    // Provides user data to createUsers()
    $table_node = new \Behat\Gherkin\Node\TableNode();
    $table_node->addRow(array('name', 'mail', 'status'));

    for ($i = 0; $i < $number; $i++) {
      $user_name = 'userbehat' . $i;
      $email = $user_name . '@example.com';
      $table_node->addRow(array($user_name, $email, 1));
    }
    parent::createUsers($table_node);
  }

  /**
   * Asserts that a given field has no empty cells
   *
   * @Given /^I should not see any empty "(?P<column>[^"]*)" cells$/
   */
  public function assertNoCellsEmpty($column) {
    $page = $this->getSession()->getPage();

    $matches = $page->find("xpath", "//*[contains(text(), 'Roles')]");
    $css_class = str_replace('views-field ', '', $matches->getAttribute('class'));

    $cells = $page->findAll('css', "td.$css_class");

    foreach ($cells as $cell) {
      if (!strlen($cell->getText())) {
        throw new \Exception(sprintf("The column '%s' had an empty cell!", $column));
      }
    }
  }

  /**
   * @Given /^the test email system is enabled$/
   */
  public function theTestEmailSystemIsEnabled() {
    // Store the original system to restore after the scenario.
    $mail_system = variable_get('mail_system', array('default-system' => 'DefaultMailSystem'));
    $this->originalMailSystem = $mail_system['default-system'];
    // Set the test system.
    variable_set('mail_system', array('default-system' => 'TestingMailSystem'));
    // Flush the email buffer, allowing us to reuse this step definition to clear existing mail.
    variable_set('drupal_test_email_collector', array());
  }

  /**
   * @Given /^the default email system is enabled$/
   */
  public function theDefaultEmailSystemIsEnabled() {
    // Set the original mail system if one was set.
    if (isset($this->originalMailSystem)) {
      $revert_to = $this->originalMailSystem;
      variable_set('mail_system', array('default-system' => $revert_to));
      // Flush the email buffer, allowing us to reuse this step definition to clear existing mail.
      variable_set('drupal_test_email_collector', array());
    }
  }

  /**
   * Asserts that a given node type is not editable.
   *
   * @Then /^I should not be able to edit another user's "([^"]*)" node$/
   */
  public function assertNotEditAnyNodeOfType($type) {
    $this->assertNotEditNodeOfType($type);
  }

  /**
   * Asserts that a given node type is editable by the author.
   *
   * @Then /^I should be able to edit my own "([^"]*)" node$/
   */
  public function assertEditOwnNodeOfType($type) {
    if (!$this->user->uid) {
      throw new \Exception(sprintf('There is no current logged in user to create a node for.'));
    }
    $node = (object) array(
      'title' => $this->getDrupal()->random->string(255),
      'type' => $type,
      'body' => $this->getDrupal()->random->string(255),
      'uid' => $this->user->uid,
    );
    $saved = $this->getDriver()->createNode($node);
    $this->nodes[] = $saved;

    // Set internal browser on the node edit page.
    $this->getSession()
      ->visit($this->locatePath('/node/' . $saved->nid . '/edit'));

    // Test status.
    return new Then("I should get a \"200\" HTTP response");

  }

  /**
   * @Given /^I have no entities of type "([^"]*)" and bundle "([^"]*)"$/
   */
  public function iHaveNoEntitiesOfTypeAndBundle($type, $bundle) {
    $query = new EntityFieldQuery();

    $query->entityCondition('entity_type', $type)
      ->entityCondition('bundle', $bundle);
    $result = $query->execute();
    if (array_key_exists($type, $result)) {
      $ids = array_keys($result[$type]);
      entity_delete_multiple($type, $ids);
    }
  }

  /**
   * @Given /^entities of type "([^"]*)" and bundle "([^"]*)":$/
   */
  public function createEntities($type, $bundle, TableNode $entitiesTable) {
    $this->tableNodeFixStepArguments($entitiesTable);
    foreach ($entitiesTable->getHash() as $entityHash) {
      $entity = entity_create($type, array('type' => $bundle));
      $wrapper = entity_metadata_wrapper($type, $entity);
      foreach ($entityHash as $key => $value) {
        $wrapper->{$key}->set($value);
      }
      $wrapper->save();
    }
  }

  /**
   * Overrides DrupalContext::createNodes
   * Allows fixStepArgument to be called on each cell value
   * @param $type
   * @param TableNode $nodesTable
   */
  public function createNodes($type, TableNode $nodesTable) {
    $this->tableNodeFixStepArguments($nodesTable);
    if ($type == 'multichoice') {
      foreach ($nodesTable->getHash() as $nodeHash) {
        $this->createMultichoice($nodeHash);
      }
    }
    else {
      parent::createNodes($type, $nodesTable);
    }
  }

  public function createNode($type, $title) {
    $node = (object) array(
      'title' => $title,
      'type' => $type,
      'body' => $this->getDrupal()->random->string(255),
      'status' => 1,
    );
    $this->dispatcher->dispatch('beforeNodeCreate', new EntityEvent($this, $node));
    $saved = $this->getDriver()->createNode($node);
    $this->dispatcher->dispatch('afterNodeCreate', new EntityEvent($this, $saved));
    $this->nodes[] = $saved;

    // Set internal page on the new node.
    $this->getSession()->visit($this->locatePath('/node/' . $saved->nid));
  }


  /**
   * Overrides DrupalContext::createMyNode
   * There is a bug in the original in the 'body' => this->getDrupal()->string(255), because it is missing
   * the ->random
   * @param $type
   * @param $title
   * @throws Exception
   */
  public function createMyNode($type, $title) {
    if (!$this->user->uid) {
      throw new \Exception(sprintf('There is no current logged in user to create a node for.'));
    }

    $node = (object) array(
      'title' => $title,
      'type' => $type,
      'body' => $this->getDrupal()->random->string(255),
      'uid' => $this->user->uid,
      'status' => 1,
    );
    $this->dispatcher->dispatch('beforeNodeCreate', new EntityEvent($this, $node));
    $saved = $this->getDriver()->createNode($node);
    $this->dispatcher->dispatch('afterNodeCreate', new EntityEvent($this, $saved));
    $this->nodes[] = $saved;

    // Set internal page on the new node.
    $this->getSession()->visit($this->locatePath('/node/' . $saved->nid));
  }

  /**
   * This looks for a link with text matching the uid for the specified username
   * and clicks that link.
   *
   * @Then /^I click on the edit link for the user "(?P<username>[^"]*)"$/
   */
  public function clickUserViewEditLink($username) {
    $username = $this->fixStepArgument($username);
    $user = $this->users[$username];
    $uid = $user->uid;
    $this->clickLink($uid);
  }

  /**
   * Verifies that the URL is the edit page for the specified username.
   *
   * @Then /^I should be at the edit page for the user "(?P<username>[^"]*)"$/
   */
  public function assertUserEditUrl($username) {
    $username = $this->fixStepArgument($username);
    $user = $this->users[$username];
    $uid = $user->uid;

    $path = "user/$uid/edit";
    return new Given("I am on \"$path\"");
  }

  /**
   * Deletes the specified LDAP user
   *
   * @Then /^I delete the LDAP user "(?P<email>[^"]*)"$/
   */
  public function deleteLdapUser($email) {
    if (module_exists('ldap_servers') || module_exists('ldap_query')) {
      module_load_include('module', 'ldap_servers', 'ldap_severs');
      $email = $this->fixStepArgument($email);
      $sid = 'LDAP_QA';
      $dn = "uid=$email,ou=People,dc=uat,dc=parcconline,dc=org";
      $ldap_server = ldap_servers_get_servers($sid, NULL, TRUE);
      $boolean_result = $ldap_server->delete($dn);
//    Leave the exception out for now because we need to just keep going if the user doesn't exist anymore
//    if (!$boolean_result) {
//      throw new \Exception(sprintf('The user "%s" did not exist on the LDAP server', $email));
//    }
    }
  }

  /**
   * Verifies that the specified LDAP user has the specified attribute value.
   * @Then /^the LDAP user with "(?P<email>[^"]*)" should have a "(?P<attribute>[^"]*)" attribute of "(?P<value>[^"]*)"$/
   */
  public function assertLdapUserAttribute($email, $attribute, $value) {
    $found_user = FALSE;
    $found_permission = FALSE;
    $email = $this->fixStepArgument($email);
    $value = $this->fixStepArgument($value);
    $ldap_query = ldap_query_get_queries('prc_users', 'all', TRUE);
    $results = $ldap_query->query();
    foreach ($results as $result) {
      if ($result['mail'][0] == $email) {
        $found_user = TRUE;
        if (array_search($value, $result[strtolower($attribute)]) !== FALSE) {
          $found_permission = TRUE;
          break;
        }
      }
    }
    if (!$found_user) {
      throw new \Exception(sprintf('The user "%s" did not exist on the LDAP server', $email));
    }
    if (!$found_permission) {
      throw new \Exception(sprintf('The user "%s" did not have the "%s" of "%s"', $email, $attribute, $value));
    }
  }

  /**
   * Verifies that the specified LDAP user has the specified permission.
   *
   * @Then /^the LDAP user with "(?P<email>[^"]*)" should have the role "(?P<role>[^"]*)"$/
   */
  public function assertLdapUserPermission($email, $role) {
    $found_user = FALSE;
    $found_permission = FALSE;
    $email = $this->fixStepArgument($email);
    $ldap_query = ldap_query_get_queries('prc_users', 'all', TRUE);
    $results = $ldap_query->query();
    foreach ($results as $result) {
      if ($result['mail'][0] == $email) {
        $found_user = TRUE;
        if (array_search($role, $result['parccroles'])) {
          $found_permission = TRUE;
          break;
        }
      }
    }
    if (!$found_user) {
      throw new \Exception(sprintf('The user "%s" did not exist on the LDAP server', $email));
    }
    if (!$found_permission) {
      throw new \Exception(sprintf('The user "%s" did not have the role "%s"', $email, $role));
    }
  }

  /**
   * Verifies that the specified LDAP user does not exist.
   *
   * @Then /^there should not be an LDAP user "(?P<email>[^"]*)"$/
   */
  public function assertLdapUserNotExists($email) {
    $found_user = FALSE;
    $email = $this->fixStepArgument($email);
    $ldap_query = ldap_query_get_queries('prc_users', 'all', TRUE);
    $results = $ldap_query->query();
    foreach ($results as $result) {
      if ($result['mail'][0] == $email) {
        $found_user = TRUE;
      }
    }
    if ($found_user) {
      throw new \Exception(sprintf('The user "%s" existed on the LDAP server', $email));
    }
  }

  /**
   * Verifies that the URL is the edit page for the specified username.
   *
   * @Then /^I edit the user "(?P<username>[^"]*)"$/
   */
  public function gotoUserEdit($username) {
    $username = $this->fixStepArgument($username);
    $user = user_load_by_mail($username);
    $uid = $user->uid;

    $expected_path = "user/$uid/edit";

    $this->assertAtPath($expected_path);
  }

  /**
   * @Then /^I should see the checkbox "(?P<label>[^"]*)"$/
   */
  public function assertCheckboxByIdPresent($label, $id = FALSE) {
    $element = $this->getSession()->getPage();
    $checkbox = $id ? $element->findById($id) : $element->find('named', array(
      'checkbox',
      $this->getSession()->getSelectorsHandler()->xpathLiteral($label)
    ));
    if ($checkbox === NULL) {
      throw new \Exception(sprintf('The checkbox with "%s" was not found on the page %s', $id ? $id : $label, $this->getSession()
        ->getCurrentUrl()));
    }
  }

  /**
   * @Given /^I check the box with the css selector "(?P<label>[^"]*)"$/
   */
  public function iCheckTheBoxWithTheCssSelector($cssQuery) {
    // This seems stupid to have here, but the Mink context
    // messages say it looks by value and it doesn't.
    // Instead, we'll add our own handler to seek by css selector.

    $box = $this->getSession()->getPage()->findAll('css', $cssQuery);
  }

  /**
   * @Then /^I should not see the checkbox "(?P<label>[^"]*)"$/
   */
  public function assertCheckboxByIdNotPresent($label, $id = FALSE) {
    $element = $this->getSession()->getPage();
    $checkbox = $id ? $element->findById($id) : $element->find('named', array(
      'checkbox',
      $this->getSession()->getSelectorsHandler()->xpathLiteral($label)
    ));
    if ($checkbox !== NULL) {
      throw new \Exception(sprintf('The checkbox with "%s" was found on the page %s', $id ? $id : $label, $this->getSession()
        ->getCurrentUrl()));
    }
  }

  /**
   * @Then /^I should see the radio button "(?P<label>[^"]*)"$/
   */
  public function assertRadioByIdPresent($label, $id = FALSE) {
    $element = $this->getSession()->getPage();
    $radiobutton = $id ? $element->findById($id) : $element->find('named', array(
      'radio',
      $this->getSession()->getSelectorsHandler()->xpathLiteral($label)
    ));
    if ($radiobutton === NULL) {
      throw new \Exception(sprintf('The radio button with "%s" was not found on the page %s', $id ? $id : $label, $this->getSession()
        ->getCurrentUrl()));
    }
  }

  /**
   * @Then /^I should not see the radio button "(?P<label>[^"]*)"$/
   */
  public function assertRadioByIdNotPresent($label, $id = FALSE) {
    $element = $this->getSession()->getPage();
    $radiobutton = $id ? $element->findById($id) : $element->find('named', array(
      'radio',
      $this->getSession()->getSelectorsHandler()->xpathLiteral($label)
    ));
    if ($radiobutton !== NULL) {
      throw new \Exception(sprintf('The radio button with "%s" was found on the page %s', $id ? $id : $label, $this->getSession()
        ->getCurrentUrl()));
    }
  }

  /**
   * @Then /^I should not see the button "(?P<button>[^"]*)"$/
   */
  public function assertButtonNotDisplayed($button) {
    $element = $this->getSession()->getPage();

    $buttonObj = $element->findButton($button);
    if (!empty($buttonObj)) {
      throw new \Exception(sprintf("The button '%s' was found and it wasn't suppose to be displayed.", $button));
    }
  }

  /**
   * @Then /^the node titled "(?P<label>[^"]*)" should be published$/
   */
  public function assertNodePublished($title) {
    $title = $this->fixStepArgument($title);
    $query = new EntityFieldQuery();

    $query->entityCondition('entity_type', 'node')
      ->propertyCondition('title', $title);
    $result = $query->execute();
    if (isset($result['node'])) {
      $nids = array_keys($result['node']);
      $items = entity_load('node', $nids);
      $item = reset($items);
      if (!$item->status) {
        throw new \Exception(sprintf('The node with the title "%s" was not published', $title));
      }
    }
    else {
      throw new \Exception(sprintf('The node with the title "%s" was not found', $title));
    }
  }

  public function assertMessage($message) {
    $message = $this->fixStepArgument($message);
    parent::assertMessage($message);
  }

  /**
   * @When /^I fill in the hidden field "([^"]*)" with "([^"]*)"$/
   */
  public function iFillHiddenFieldWith($field, $value) {
    $this->getSession()->getPage()->find('css',
      'input[name="' . $field . '"]')->setValue($value);
  }

  /**
   * @Then /^the node titled "(?P<label>[^"]*)" should not be published$/
   */
  public function assertNodeNotPublished($title) {
    $title = $this->fixStepArgument($title);
    $query = new EntityFieldQuery();

    $query->entityCondition('entity_type', 'node')
      ->propertyCondition('title', $title);
    $result = $query->execute();
    if (isset($result['node'])) {
      $nids = array_keys($result['node']);
      $items = entity_load('node', $nids);
      $item = reset($items);
      if ($item->status) {
        throw new \Exception(sprintf('The node with the title "%s" was published', $title));
      }
    }
    else {
      throw new \Exception(sprintf('The node with the title "%s" was not found', $title));
    }
  }

  public function assertHeading($heading) {
    $heading = $this->fixStepArgument($heading);
    return parent::assertHeading($heading);
  }


  /**
   * @Then /^"(?P<before>[^"]*)" should precede "(?P<after>[^"]*)" for the query "(?P<query>[^"]*)"$/
   */
  public function shouldPrecedeForTheQuery($textBefore, $textAfter, $cssQuery) {
    $items = array_map(
      function ($element) {
        if ($element->getTagName() == 'label' && !$element->getText()) {
          // Certain label tags don't give text in getText() - they only return text in getHtml().
          return $element->getHtml();
        }
        else {
          return $element->getText();
        }
      },
      $this->getSession()->getPage()->findAll('css', $cssQuery)
    );
    $before_index = array_search($textBefore, $items);
    $after_index = array_search($textAfter, $items);
    if ($before_index >= $after_index) {
      throw new Exception("$textBefore does not proceed $textAfter");
    }
  }

  /**
   * @Given /^the "([^"]*)" select box should be empty$/
   */
  public function theSelectBoxShouldBeEmpty($field) {
    $select_field = $this->getSession()->getPage()->findField($field);

    $opt = $select_field->find('named', array(
      'option',
      $this->getSession()->getSelectorsHandler()->xpathLiteral('*')
    ));


    $count = count($opt);
    if ($count != 0) {
      throw new Exception("$field was supposed to have no items. Instead, it had $count items.");
    }
  }

  /**
   * @Given /^I have no "([^"]*)" nodes$/
   */
  public function iHaveNoNodes($type) {
    $command = 'genc';
    $type = $this->nodeTypeByName($type);
    $arguments = "0 0 --types=$type --kill";
    $this->assertDrushCommandWithArgument($command, $arguments);
  }

  /**
   * @When /^I index search results$/
   */
  public function iIndexSearchResults() {
    $this->assertDrushCommand('sapi-c');
    $this->assertDrushCommand('sapi-i');
    cache_clear_all('*', 'cache_views_data', TRUE);
    cache_clear_all('*', 'cache_page', TRUE);
  }

  /**
   * @Given /^I give myself the "([^"]*)" role$/
   */
  public function iGiveMyselfTheRole($rolename) {
    $account = user_load($this->user->uid);
    $roles = user_roles();
    $rid = array_search($rolename, $roles);
    $userroles = $account->roles;
    $userroles[$rid] = $rolename;
    user_save($account, array('roles' => $userroles));
  }

  /**
   * @Given /^I give the user "([^"]*)" the "([^"]*)" role$/
   */
  public function iGiveAUserTheRole($email, $rolename) {
    $email = $this->fixStepArgument($email);
    $account = user_load_by_mail($email);
    $roles = user_roles();
    $rid = array_search($rolename, $roles);
    $userroles = $account->roles;
    $userroles[$rid] = $rolename;
    user_save($account, array('roles' => $userroles));
  }

  /**
   * Finds the machine name of the node type. Matches either name or machine name.
   * @param $name Name or machine name of node type to match
   * @return string Machine name of node type
   */
  protected function nodeTypeByName($name) {
    $found_type = '';
    $types = node_type_get_types();
    foreach ($types as $type) {
      if ($type->name == $name || $type->type == $name) {
        $found_type = $type->type;
        break;
      }
    }
    return $found_type;
  }

  /**
   * @Then /^"([^"]*)" should not have an email$/
   */
  public function shouldNotHaveAnEmail($to) {
    $mail_to = $this->fixStepArgument($to);

    $variables = array_map('unserialize', db_query("SELECT name, value FROM {variable} WHERE name = 'drupal_test_email_collector'")->fetchAllKeyed());
    $this->activeEmail = FALSE;
    foreach ($variables['drupal_test_email_collector'] as $message) {
      if ($message['to'] == $mail_to) {
        throw new \Exception(sprintf('Found message to %s but did not expect to', $mail_to));
      }
    }
  }

  /**
   * @Then /^the email to "([^"]*)" should contain "([^"]*)"$/
   */
  public function theEmailToShouldContain($to, $contents) {
    // We can't use variable_get() because $conf is only fetched once per
    // scenario.
    $mail_to = $this->fixStepArgument($to);
    $contents = $this->fixStepArgument($contents);

    $variables = array_map('unserialize', db_query("SELECT name, value FROM {variable} WHERE name = 'drupal_test_email_collector'")->fetchAllKeyed());
    $this->activeEmail = FALSE;
    foreach ($variables['drupal_test_email_collector'] as $message) {
      if ($message['to'] == $mail_to) {
        $this->activeEmail = $message;
        $message_found = TRUE;
        if (strpos($message['body'], $contents) !== FALSE ||
          strpos($message['subject'], $contents) !== FALSE
        ) {
          return TRUE;
        }
      }
    }
    if (isset($message_found)) {
      throw new \Exception('Did not find expected content in message body or subject.');
    }
    else {
      throw new \Exception(sprintf('Did not find expected message to %s', $mail_to));
    }
  }

  /**
   * @Given /^the email should contain "([^"]*)"$/
   */
  public function theEmailShouldContain($contents) {
    if (!$this->activeEmail) {
      throw new \Exception('No active email');
    }
    $contents = $this->fixStepArgument($contents);
    $message = $this->activeEmail;
    $body = str_replace(PHP_EOL, ' ', $message['body']);
    if (strpos($body, $contents) !== FALSE ||
      strpos($message['subject'], $contents) !== FALSE
    ) {
      return TRUE;
    }
    print $body;
    throw new \Exception('Did not find expected content in message body or subject.');
  }

  /**
   * @Given /^the email should not contain "([^"]*)"$/
   */
  public function theEmailShouldNotContain($contents) {
    if (!$this->activeEmail) {
      throw new \Exception('No active email');
    }
    $contents = $this->fixStepArgument($contents);
    $message = $this->activeEmail;
    if (strpos($message['body'], $contents) !== FALSE ||
      strpos($message['subject'], $contents) !== FALSE
    ) {
      throw new \Exception('Expected content was present in message body or subject.');
    }
    return TRUE;
  }

  public function assertErrorVisible($message) {
    $message = $this->fixStepArgument($message);
    parent::assertErrorVisible($message);
  }


  /**
   * @When /^I follow "(?P<link>(?:[^"]|\\")*)" number "(?P<number>[^"]*)"$/
   */
  public function followLinkTextIndex($text, $index) {
    $page = $this->getSession()->getPage();
    $links = $page->findAll('xpath', "//a[text()='" . $text . "']");
    $link = $links[$index];
    $link->click();
  }

  /**
   * @When /^I check radio button number "(?P<number>[^"]*)"$/
   */
  public function checkRadioIndex($index) {
    $page = $this->getSession()->getPage();
    $radios = $page->findAll('xpath', "//input[@type='radio']");
    $radio = $radios[$index];
    $value = $radio->getAttribute('value');
    $radio->selectOption($value, FALSE);
  }

  /**
   * @Then /^I follow link "(?P<number>[^"]*)" in the email$/
   */
  public function followEmailLinkByIndex($number) {
    if (!$this->activeEmail) {
      throw new \Exception('No active email');
    }
    $message = $this->activeEmail;

    $body = $message['body'];
    $body = str_replace('/.', '/ .', $body); # Separates URLs that end with a . from the end of the sentence
    $body = str_replace("\r\n", ' ', $body); # Replaces line breaks with spaces so that we can search the body

    $urls = $this->getUrls($body);

    if (isset($urls[$number])) {
      $follow_url = $urls[$number];
    }
    if (isset($follow_url)) {
      // Have to go to the driver level because visit only works for pages off the base url
      $this->getSession()->visit($follow_url);
      return TRUE;
    }
    throw new \Exception('Did not find expected content in message body or subject.');
  }

  function getUrls($string) {
    // Replace line breaks with a space so we can match them to pull the URLs out
    $string = preg_replace('#\R+#', ' ', $string);
    $regex = '/https?\:\/\/[^\" ]+/i';
    preg_match_all($regex, $string, $matches);
    return ($matches[0]);
  }

  /**
   * Fills in form field with specified id|name|label|value.
   *
   * @When /^(?:|I )should see "(?P<value>(?:[^"]|\\")*)" in the "(?P<field>(?:[^"]|\\")*)" field$/
   */
  public function assertFieldValue($field, $value) {
    $field = $this->fixStepArgument($field);
    $value = $this->fixStepArgument($value);
    $found = $this->getSession()->getPage()->findField($field);

    if (NULL === $found) {
      throw new ElementNotFoundException(
        $this->getSession(), 'form field', 'id|name|label|value', $field
      );
    }

    $actual_value = $found->getValue();
    if ($value != $actual_value) {
      throw new \Exception(sprintf("The field '%s' did not have a value of '%s'.\nInstead, it was '%s'", $field, $value, $actual_value));
    }
  }

  /**
   * @Then /^I follow the link in the email$/
   */
  public function followEmailLink() {
    $this->followEmailLinkByIndex(0);
  }

  /**
   * Visit a given path, and additionally check for HTTP response code.
   *
   * @Then /^I should get a "(?P<code>[^"]*)" HTTP response at "(?P<path>[^"]*)"$/
   *
   * @throws UnsupportedDriverActionException
   */
  public function assertResponseCodeAtPath($code, $path) {
    $this->getSession()->visit($this->locatePath($path));

    // If available, add extra validation that this is a 200 response.
    try {
      $this->getSession()->getStatusCode();
      return new Given('I should get a "' . $code . '" HTTP response');
    } catch (UnsupportedDriverActionException $e) {
      // Simply continue on, as this driver doesn't support HTTP response codes.
    }
  }

  /**
   * Accepts a confirmation dialog
   *
   * @Then /^I accept the confirmation$/
   */
  public function acceptAlert() {
    $this->getSession()->getDriver()->getWebDriverSession()->accept_alert();
  }


//

  /**
   * @Given /^I confirm the dialog$/
   */
  public function iConfirmTheDialog() {
    $this->getSession()->getDriver()->getWebDriverSession()->accept_alert();
//    $this->handleAjaxTimeout();
  }

  /**
   * @Given /^I dismiss the dialog$/
   */
  public function iDismissTheDialog() {
    $this->getSession()->getDriver()->getWebDriverSession()->dismiss_alert();
//    $this->handleAjaxTimeout();
  }

  /**
   * Needs to be in single command to avoid "unexpected alert open" errors in Selenium.
   * Example1: I press the "Remove current combo" button, confirming the dialog
   * Example2: I follow the "Remove current combo" link, confirming the dialog
   *
   * @Given /^I (?:press|follow) the "([^"]*)" (?:button|link), confirming the dialog$/
   */
  public function stepIPressTheButtonConfirmingTheDialog($button) {
    $this->clickLink($button);
    $this->iConfirmTheDialog();
  }

  /**
   * Needs to be in single command to avoid "unexpected alert open" errors in Selenium.
   * Example: I follow the "Remove current combo" link, dismissing the dialog
   *
   * @Given /^I (?:press|follow) the "([^"]*)" (?:button|link), dismissing the dialog$/
   */
  public function stepIPressTheButtonDismissingTheDialog($button) {
    $this->clickLink($button);
    $this->iDismissTheDialog();
  }

  /**
   * Moves backward one page in history and confirms the dialog.
   *
   * @When /^(?:|I )move backward one page, confirming the dialog$/
   */
  public function backAndConfirm() {
    $this->getSession()->back();
    $this->iConfirmTheDialog();
  }

  /**
   * Moves backward one page in history and dismisses the dialog.
   *
   * @When /^(?:|I )move backward one page, dismissing the dialog$/
   */
  public function backAndDismiss() {
    $this->getSession()->back();
    $this->iDismissTheDialog();
  }

  /**
   * Wait for X seconds.
   *
   * @Given /^I wait (\d+) seconds$/
   */
  public function iWaitForXSeconds($seconds) {
    $ms = $seconds * 1000;
    sleep($seconds);
//    $this->getSession()->wait($ms);
  }

  /**
   * Click on the element with the provided CSS Selector
   *
   * @When /^I click on the element with css selector "([^"]*)"$/
   */
  public function iClickOnTheElementWithCSSSelector($cssSelector) {
    $session = $this->getSession();
    $element = $session->getPage()->find(
      'xpath',
      $session->getSelectorsHandler()
        ->selectorToXpath('css', $cssSelector) // just changed xpath to css
    );
    if (NULL === $element) {
      throw new \InvalidArgumentException(sprintf('Could not evaluate CSS Selector: "%s"', $cssSelector));
    }

    $element->click();

  }


  /**
   * Check the element with the provided XPath Selector
   *
   * @When /^I check the element with xpath selector "([^"]*)"$/
   */
  public function iCheckTheElementWithXPathSelector($xpathSelector) {
    $session = $this->getSession();
    $element = $session->getPage()->find(
      'xpath',
      $session->getSelectorsHandler()->selectorToXpath('xpath', $xpathSelector)
    );
    if (NULL === $element) {
      throw new \InvalidArgumentException(sprintf('Could not evaluate XPath Selector: "%s"', $xpathSelector));
    }
    $element->check();

  }

  /**
   * Click the element with the provided XPath Selector
   *
   * @When /^I click the element with xpath selector "([^"]*)"$/
   */
  public function iClickTheElementWithXPathSelector($xpathSelector) {
    $session = $this->getSession();
    $element = $session->getPage()->find(
      'xpath',
      $session->getSelectorsHandler()->selectorToXpath('xpath', $xpathSelector)
    );
    if (NULL === $element) {
      throw new \InvalidArgumentException(sprintf('Could not evaluate XPath Selector: "%s"', $xpathSelector));
    }
    $element->click();

  }

  /**
   * Dismisses a confirmation dialog
   *
   * @Then /^I dismiss the confirmation$/
   */
  public function dismissAlert() {
    $this->getSession()->getDriver()->getWebDriverSession()->dismiss_alert();
  }

  /**
   * We are overriding this because we want to use relative paths
   * so we are changing the path here.
   * @param $field
   * @param $path
   */
  public function attachFileToField($field, $path) {
    $field = $this->fixStepArgument($field);
    $path = $this->fixStepArgument($path);

    $relative = getcwd() . '/./' . $path; //../docroot/sites/';
    $realpath = realpath($relative);

    $path = $realpath;

    parent::attachFileToField($field, $path);
  }

  /**
   * @Then /^(?:|I )should see "([^"]*)" in popup$/
   *
   * @param string $message The message.
   *
   * @return bool
   */
  public function assertPopupMessage($message) {
    return $message == $this->getSession()
      ->getDriver()
      ->getWebDriverSession()
      ->getAlert_text();
  }

  /**
   * @Then /^I should see CSV text matching "([^"]*)"$/
   */
  public function iShouldSeeCsvTextMatching($arg1) {
    $arg1 = $this->fixStepArgument($arg1);
    $actual = $this->getSession()->getPage()->getContent();
    if (strpos($actual, $arg1) === FALSE) {
      throw new \Exception(sprintf('The pattern %s was not found anywhere in the text of the current response.', $arg1));
    }
  }

  public function afterScenario($event) {
    variable_del('drupal_test_email_collector');

    if ($event->getResult()) {
      $this->recordFailedEvent($event);
    }

    // Remove any LDAP users that were created.
    if (!empty($this->users)) {
      foreach ($this->users as $user) {
        $this->deleteLdapUser($user->mail);
      }
    }

    parent::afterScenario($event);
    // Taking this out for the moment, because the dev machines can revert Features to get back to where we should be
//    $this->theDefaultEmailSystemIsEnabled();

    $this->stopJavascriptSession($event);
  }

  public function beforeScenario($event) {
    parent::beforeScenario($event);
    $this->theTestEmailSystemIsEnabled();
  }

  public function recordFailedEvent($event) {
    $event_class = get_class($event);
    if (strpos($event_class, 'OutlineExampleEvent') !== FALSE) {
      $scenario = $event->getOutline();
    }
    elseif (strpos($event_class, 'ScenarioEvent') !== FALSE) {
      $scenario = $event->getScenario();
    }
    if ($scenario) {
      $feature_file_full = $scenario->getFeature()->getFile();
    }
    else {
      $feature_file_full = 'failure';
    }

    $this->iTakeAScreenshot($feature_file_full);
  }

  /**
   * @param TableNode $nodesTable
   * @throws Exception
   */
  protected function tableNodeFixStepArguments(TableNode $table) {
    $new_rows = array();
    $original_rows = $table->getRows();
    $header_row = array_shift($original_rows);
    $new_rows[] = $header_row;

    foreach ($table->getHash() as $nodeHash) {
      foreach ($nodeHash as $key => $value) {
        $nodeHash[$key] = $this->fixStepArgument($value);
      }
      $new_rows[] = $nodeHash;
    }
    $table->setRows($new_rows);
  }

  /**
   * @param $event
   */
  protected function stopJavascriptSession($event) {
    $event_class = get_class($event);
    if (strpos($event_class, 'OutlineExampleEvent') !== FALSE) {
      $scenario = $event->getOutline();
    }
    elseif (strpos($event_class, 'ScenarioEvent') !== FALSE) {
      $scenario = $event->getScenario();
    }
    if ($scenario) {
      $has_js_tag = $scenario->hasTag('javascript');
      if ($has_js_tag) {
        $this->getSession()->stop();
      }
    }
  }
  /**
   * @defgroup "workflow steps"
   * @{
   */
  /**
   * @Given /^the last node created\'s state is "([^"]*)"$/
   */
  public function theLastNodeCreatedSStateIs($arg1) {
    if (!is_array($this->nodes) || count($this->nodes) == 0) {
      throw new Exception('No nodes have been created by this context');
    }
    $last_index = count($this->nodes) - 1;
    $last_node = $this->nodes[$last_index];
    $state_obj = state_flow_load_state_machine($last_node, TRUE);
    $state = $state_obj->get_current_state();

    if ($state !== $arg1) {
      throw new \Exception(sprintf('The nodes state was not set to %s', $arg1));
    }
  }

  /**
   * @Given /^the last node created\'s state is set to "([^"]*)"$/
   */
  public function theLastNodeCreatedSStateIsSetTo($state) {
    if (!is_array($this->nodes) || count($this->nodes) == 0) {
      throw new Exception('No nodes have been created by this context');
    }
    $last_index = count($this->nodes) - 1;
    $last_node = $this->nodes[$last_index];

    //force into a particular state
    $machine = state_flow_load_state_machine($last_node);

    // Set and save the new state.
    $machine->force_state($state);

  }

  /**
   * @} End of defgroup "workflow steps"
   */


  /**
   * @defgroup "trt browser steps"
   * @{
   */

  /**
   * @When /^I run a system check with the "([^"]*)" operating system and the "([^"]*)" browser version "([^"]*)"$/
   */
  public function iRunASystemCheckWithTheOperatingSystemAndTheBrowserVersion($os, $browser, $version) {
    $entity = NULL;
    $sysCheck = new PrcTrtSystemCheck($entity);
    $result = $sysCheck->browserOSCompatibilityCheck($browser, $version, $os);
    $this->sysCheckResult = $result;
  }

  /**
   * @When /^I run a system check with the "([^"]*)" JRE version and the "([^"]*)" operating system and the "([^"]*)" browser version "([^"]*)"$/
   */
  public function iRunASystemCheckWithTheJREVersionAndTheBrowserVersion($jre, $os, $browser, $version) {
    $entity = NULL;
    $sysCheck = new PrcTrtSystemCheck($entity);
    $result = $sysCheck->jreBrowserCheck($browser, $version, $os, $jre);
    $this->sysCheckResult = $result;
  }

  /**
   * @Then /^I should get a "([^"]*)" result$/
   */
  public function iShouldGetAResult($result) {
    $expected_result = $result === 'true';
    if ($this->sysCheckResult !== $expected_result) {
      throw new \Exception(sprintf('The result was not %s', $result));
    }
  }

  /**
   * @Given /^the school "([^"]*)" has run a system check$/
   */
  public function theSchoolHasRunASystemCheck($school_name) {
    $school_name = $this->fixStepArgument($school_name);
    foreach ($this->nodes as $node) {
      if ($node->title == $school_name) {
        $found_nid = $node->nid;
        break;
      }
    }
    if (!$found_nid) {
      throw new \Exception(sprintf('The school %s was not found', $school_name));
    }
    $school_node = node_load($found_nid);
    $entity_type = 'prc_trt';
    $entity = entity_create($entity_type, array('type' => 'system_check'));
    $wrapper = entity_metadata_wrapper($entity_type, $entity);
    $wrapper->uid = $school_node->uid;
    $wrapper->field_ref_school->set($school_node);
    $wrapper->field_name = 'Fakey Check';
    $wrapper->save();
  }

  /**
   * @Given /^the school "([^"]*)" has run a capacity check$/
   */
  public function theSchoolHasRunACapacityCheck($school_name) {
    $school_name = $this->fixStepArgument($school_name);
    foreach ($this->nodes as $node) {
      if ($node->title == $school_name) {
        $found_nid = $node->nid;
        break;
      }
    }
    if (!$found_nid) {
      throw new \Exception(sprintf('The school %s was not found', $school_name));
    }
    $school_node = node_load($found_nid);
    $entity_type = 'prc_trt';
    $entity = entity_create($entity_type, array('type' => 'capacity_check'));
    $wrapper = entity_metadata_wrapper($entity_type, $entity);
    $wrapper->uid = $school_node->uid;
    $wrapper->field_ref_school->set($school_node);
    $wrapper->field_devices_capacity->set(10);
    $wrapper->field_devices_capacity_results->set(20);
    $wrapper->field_bandwidth_capacity->set(30);
    $wrapper->field_bandwidth_capacity_results->set(40);
    $wrapper->field_number_of_students->set(2);
    $wrapper->field_number_of_devices->set(2);
    $wrapper->field_number_testing_days->set(2);
    $wrapper->field_number_of_sessions->set(2);
    $wrapper->field_sittings_per_student->set(2);
    $wrapper->field_speed_of_connection->set(2);
    $wrapper->save();
  }

  /**
   * @Given /^the school "([^"]*)" has run a capacity check to three digits$/
   */
  public function theSchoolHasRunACapacityCheckThreeDigits($school_name) {
    $school_name = $this->fixStepArgument($school_name);
    foreach ($this->nodes as $node) {
      if ($node->title == $school_name) {
        $found_nid = $node->nid;
        break;
      }
    }
    if (!$found_nid) {
      throw new \Exception(sprintf('The school %s was not found', $school_name));
    }
    $school_node = node_load($found_nid);
    $entity_type = 'prc_trt';
    $entity = entity_create($entity_type, array('type' => 'capacity_check'));
    $wrapper = entity_metadata_wrapper($entity_type, $entity);
    $wrapper->uid = $school_node->uid;
    $wrapper->field_ref_school->set($school_node);
    $wrapper->field_devices_capacity->set(58);
    $wrapper->field_devices_capacity_results->set(92);
    $wrapper->field_bandwidth_capacity->set(0.004);
    $wrapper->field_bandwidth_capacity_results->set(0.004);
    $wrapper->field_number_of_students->set(500);
    $wrapper->field_number_of_devices->set(150);
    $wrapper->field_number_testing_days->set(6);
    $wrapper->field_number_of_sessions->set(2);
    $wrapper->field_sittings_per_student->set(2);
    $wrapper->field_speed_of_connection->set(2);
    $wrapper->save();
  }
  /**
   * @} End of defgroup "trt browser steps"
   */


  /**
   * @When /^I am browsing using a "([^"]*)"$/
   */
  public function iAmBrowsingUsingA($device) {
    switch ($device) {
      case "phone":
        $this->getSession()
          ->resizeWindow((int) $this->customParameters['phone_width'], (int) $this->customParameters['phone_height'], 'current');
        break;
      case "tablet":
        $this->getSession()
          ->resizeWindow((int) $this->customParameters['tablet_width'], (int) $this->customParameters['tablet_height'], 'current');
        break;
      case "small desktop":
        $this->getSession()
          ->resizeWindow((int) $this->customParameters['desktop_sm_width'], (int) $this->customParameters['desktop_sm_height'], 'current');
        break;
      default:
        $this->getSession()
          ->resizeWindow((int) $this->customParameters['desktop_width'], (int) $this->customParameters['desktop_height'], 'current');
    }
  }

  /**
   * @Given /^"([^"]*)" should have a "([^"]*)" css value of "([^"]*)"$/
   * @param $selector , $rule, $value
   * @throws Exception
   */
  public function shouldHaveACssValueOf($selector, $rule, $value) {
    $computed = $this->getSession()->evaluateScript("
      return jQuery( '" . $selector . "' ).css('" . $rule . "');
    ");
    // Adjust background image results to use relative paths
    if ($rule == 'background-image' && !empty($computed)) {
      // Split out the URL components
      $relative = explode('/', $computed);
      $relative = array_slice($relative, 3);
      $computed = "url('" . implode('/', $relative);
    }
    // Convert double quotes to single quotes for matching purposes.
    $computed = str_replace('"', "'", $computed);
    if ($value != $computed) {
      throw new Exception("Element ({$selector}) does not have a ({$rule}) value of ({$value}).  The actual value is ({$computed})");
    }
  }

  /**
   * @When /^I hover over the element "([^"]*)"$/
   */
  public function iHoverOverTheElement($selector) {
    $element = $this->getSession()->getPage()->find('css', $selector);

    if ($element === NULL) {
      throw new Exception("Could not hover over element ({$selector})");
    }

    $element->mouseOver();
  }

  public function assertTextInTableRow($text, $row_text) {
    $text = $this->fixStepArgument($text);
    $row_text = $this->fixStepArgument($row_text);
    $row = $this->getTableRow($this->getSession()->getPage(), $row_text);
    if (strpos($row->getText(), $text) === FALSE) {
      throw new \Exception(sprintf('Found a row containing "%s", but it did not contain the text "%s".', $row_text, $text));
    }
  }

  public function assertClickInTableRow($link, $row_text) {
    $link = $this->fixStepArgument($link);
    $row_text = $this->fixStepArgument($row_text);
    $page = $this->getSession()->getPage();
    if ($link = $this->getTableRow($page, $row_text)->findLink($link)) {
      // Click the link and return.
      $link->click();
      return;
    }
    throw new \Exception(sprintf('Found a row containing "%s", but no "%s" link on the page %s', $row_text, $link, $this->getSession()
      ->getCurrentUrl()));
  }

  /**
   * @Then /^I do not see a "([^"]*)" link in the "([^"]*)" row$/
   */
  public function iDoNotSeeALinkInTheRow($link, $row_text) {
    $link = $this->fixStepArgument($link);
    $row_text = $this->fixStepArgument($row_text);

    $page = $this->getSession()->getPage();
    if ($link = $this->getTableRow($page, $row_text)->findLink($link)) {
      throw new \Exception(sprintf('Found a row containing "%s", but there was "%s" present %s', $row_text, $link, $this->getSession()
        ->getCurrentUrl()));
    }
    return;
  }

  /**
   * @Given /^at least one "([^"]*)" element should contain "([^"]*)"$/
   */
  public function atLeastOneElementShouldContain($element, $text) {
    $page = $this->getSession()->getPage();
    $elements = $page->findAll('css', $element);
    foreach ($elements as $element) {
      if (strpos($element->getText(), $text) !== FALSE) {
        return;
      }
    }
    throw new \Exception(sprintf('There was no %s element found with the text %s', $element, $text));
  }

  /**
   * @Then /^I take a screenshot$/
   */
  public function iTakeAScreenshot($feature_file_full = 'shot') {
    $fileName = time();
    // TODO: Make this a setting in behat.yml?
    $html_dump_path = 'failures';

    $message = '';
    $session = $this->getSession();
    $page = $session->getPage();
    $driver = $session->getDriver();
    $date = date('Y-m-d H:i:s');
    $url = $session->getCurrentUrl();
    $html = $page->getContent();


    $ff = explode('/', $feature_file_full);
    $feature_file_name = array_pop($ff);

    if (!file_exists($html_dump_path)) {
      mkdir($html_dump_path);
    }

    $html = "<!-- HTML dump from behat  \nDate: $date  \nUrl:  $url  -->\n " . $html;

    $htmlCapturePath = $html_dump_path . '/' . $fileName . '.' . $feature_file_name . '.html';
    file_put_contents($htmlCapturePath, $html);

    $message .= "\nHTML available at: " . $htmlCapturePath;


    if ($driver instanceof \Behat\Mink\Driver\Selenium2Driver) {
      if (!file_exists($html_dump_path)) {
        mkdir($html_dump_path);
      }

      $screenshot = $driver->getScreenshot();
      $screenshotFilePath = $html_dump_path . '/' . $fileName . '.png';
      file_put_contents($screenshotFilePath, $screenshot);

      $message .= "\nScreenshot available at: " . $screenshotFilePath;
    }

    print $message . PHP_EOL;
  }

  /**
   * @Given /^"([^"]*)" should have an "([^"]*)" attribute value of "([^"]*)"$/
   * @param $selector , $attribute, $value
   * @throws Exception
   */
  public function shouldHaveAnAttributeValueOf($selector, $attribute, $value) {
    if ($this->isJavascriptSupported()) {
      $computed = $this->getSession()->evaluateScript("
      return jQuery( '" . $selector . "' ).attr('" . $attribute . "');
    ");
      // Convert double quotes to single quotes for matching purposes.
      $computed = str_replace('"', "'", $computed);
      if ($value != $computed) {
        throw new Exception("Element ({$selector}) does not have a ({$attribute}) value of ({$value}).  The actual value is ({$computed})");
      }
    }
    else {
      $this->assertSession()
        ->elementAttributeContains('css', $selector, $attribute, $value);
    }
  }

  /**
   * @Then /^"([^"]*)" should not have an "([^"]*)" attribute$/
   */
  public function shouldNotHaveAnAttribute($selector, $attribute) {
    $element = $this->assertSession()->elementExists('css', $selector);
    if ($element->hasAttribute($attribute)) {
      throw new \Exception(sprintf('The element %s has attribute %s, but it should not.', $selector, $attribute));
    }
  }

  /**
   * @Then /^"([^"]*)" should not have an "([^"]*)" attribute value of "([^"]*)"$/
   */
  public function shouldNotHaveAnAttributeValueOf($selector, $attribute, $value) {
    try {
      $this->shouldHaveAnAttributeValueOf($selector, $attribute, $value);
      $return = TRUE;
    } catch (ElementHtmlException $ehe) {
      throw $ehe;
    } catch (Exception $e) {
      // Eat exception, we're good.
      return;
    }
    throw new \Exception(sprintf('The element %s has an %s value of %s, but it should not.', $selector, $attribute, $value));
  }

  /**
   * Create speaking-listening content.
   *
   * Provide data in following format:
   * | resource name       | resource type                 | file                          | faux standard | faux subject | grade level |
   * | Resource @timestamp | Listening logs - for students | testfiles/GreatLakesWater.pdf | Standard      | Subject      | 1st Grade   |
   *
   * @Given /^speaking-listening content:$/
   */
  public function speakingListeningContent(TableNode $table) {
    foreach ($table->getHash() as $hash) {
      // Let's have an administrator go through the motions.
      $this->assertAuthenticatedByRole("administrator");
      $this->visit("node/add/speaking-and-listening-resource");
      $this->fillField('Resource name', $hash['resource name']);
      $this->selectOption('Resource Type', $hash['resource type']);
      $this->attachFileToField('edit-field-file-single-und-0-upload', $hash['file']);

      if ($this->isJavascriptSupported()) {
        // Fill in hidden fields with javascript, because selenium2 rightfully
        // does not allow interaction with hidden elements.
        $script = "document.getElementsByName('faux_standard')[0].setAttribute('value','{$hash['faux standard']}');";
        $this->getSession()->executeScript($script);
        $script = "document.getElementsByName('faux_subject')[0].setAttribute('value','{$hash['faux subject']}');";
        $this->getSession()->executeScript($script);
      }
      else {
        $this->iFillHiddenFieldWith('faux_standard', $hash['faux standard']);
        $this->iFillHiddenFieldWith('faux_subject', $hash['faux subject']);
      }

      $this->checkOption($hash['grade level']);
      $this->pressButton('Save');
    }

  }

  /**
   * Create formative-instructional-task content.
   *
   * Provide data in following format:
   * | resource name       | resource type                 | file                          | faux standard | faux subject | grade level |
   * | Resource @timestamp | Listening logs - for students | testfiles/GreatLakesWater.pdf | Standard      | Subject      | 1st Grade   |
   *
   * @Given /^formative instructional task content:$/
   */
  public function formativeInstructionalTaskContent(TableNode $table) {
    foreach ($table->getHash() as $hash) {
      // Let's have an administrator go through the motions.
      $this->assertAuthenticatedByRole("administrator");
      $this->visit("node/add/formative-instructional-task");
      $this->fillField('Resource name', $hash['resource name']);
      $this->selectOption('Resource Type', $hash['resource type']);
      $this->attachFileToField('edit-field-file-single-und-0-upload', $hash['file']);

      if ($this->isJavascriptSupported()) {
        // Fill in hidden fields with javascript, because selenium2 rightfully
        // does not allow interaction with hidden elements.
        $script = "document.getElementsByName('faux_standard')[0].setAttribute('value','{$hash['faux standard']}');";
        $this->getSession()->executeScript($script);
        $script = "document.getElementsByName('faux_subject')[0].setAttribute('value','{$hash['faux subject']}');";
        $this->getSession()->executeScript($script);
      }
      else {
        $this->iFillHiddenFieldWith('faux_standard', $hash['faux standard']);
        $this->iFillHiddenFieldWith('faux_subject', $hash['faux subject']);
      }
      $this->checkOption($hash['grade level']);
      if ($hash['permissions'] == 'public') {
        $this->assertSelectRadioById('Public');
      }
      else {
        $this->assertSelectRadioById('PARCC members ONLY');
      }
      $this->pressButton('Save');
    }
    // I've been seeing some cases where the admin role seems to stick after creating content
    // Asserting anonymous seems to take care of it.
    $this->assertAuthenticatedByRole("anonymous user");
  }

  /**
   * Create parcc-released-item content.
   *
   * Provide data in following format:
   * | resource name       | file                          | resource type  | faux standard | faux subject | grade level | permissions |
   * | Resource @timestamp | testfiles/GreatLakesWater.pdf | Form   | Standard      | Subject      | 1st Grade   | public  |
   *
   * @Given /^parcc-released-item content:$/
   */
  public function parccReleasedItemContent(TableNode $table) {
    foreach ($table->getHash() as $hash) {
      // Let's have an administrator go through the motions.
      $this->assertAuthenticatedByRole("administrator");
      $this->visit("node/add/parcc-released-item");
      $this->fillField('Resource name', $hash['resource name']);
      $this->selectOption('Resource Type', $hash['resource type']);
      $this->attachFileToField('edit-field-file-single-und-0-upload', $hash['file']);

      if ($this->isJavascriptSupported()) {
        // Fill in hidden fields with javascript, because selenium2 rightfully
        // does not allow interaction with hidden elements.
        $script = "document.getElementsByName('faux_standard')[0].setAttribute('value','{$hash['faux standard']}');";
        $this->getSession()->executeScript($script);
        $script = "document.getElementsByName('faux_subject')[0].setAttribute('value','{$hash['faux subject']}');";
        $this->getSession()->executeScript($script);
      }
      else {
        $this->iFillHiddenFieldWith('faux_standard', $hash['faux standard']);
        $this->iFillHiddenFieldWith('faux_subject', $hash['faux subject']);
      }

      $this->checkOption($hash['grade level']);
      if ($hash['permissions'] == 'public') {
        $this->assertSelectRadioById('Public');
      }
      else {
        if ($hash['permissions'] == 'registered') {
          $this->assertSelectRadioById('Registered');
        }
        else {
          $this->assertSelectRadioById('PARCC members ONLY');
        }
      }
      $this->pressButton('Save');
    }

  }

  /**
   * @Then /^the response Content-Type should be "([^"]*)"$/
   */
  public function theResponseContentTypeShouldBe($value) {
    $response_headers = $this->getSession()->getResponseHeaders();
    $found = array();
    if ($response_headers && array_key_exists('Content-Type', $response_headers)) {
      foreach ($response_headers['Content-Type'] as $content_type) {
        if ($content_type == $value) {
          return;
        }
        else {
          $found[] = $content_type;
        }
      }
    }
    throw new \Exception(sprintf("Expecting '%s', found '%s'", $value, implode(',', $found)));
  }

  /**
   * @Then /^"([^"]*)" should be "([^"]*)" of the width of "([^"]*)" within a margin of "([^"]*)"$/
   */
  public function shouldBeOfTheWidthOfWithinAMarginOf($inner_css, $percent, $outer_css, $margin) {
    $percent = str_replace('%', '', $percent);
    $margin = str_replace('%', '', $margin);

    $inner_width = str_replace('px', '', $this->getWidth($inner_css));
    $outer_width = str_replace('px', '', $this->getWidth($outer_css));

    if ($inner_width > 0 && $outer_width > 0) {
      $actual_percent = ($inner_width / $outer_width) * 100;

      if (($actual_percent > ($percent + $margin)) || ($actual_percent < ($percent - $margin))) {
        throw new \Exception(sprintf("%s not within the defined margin of width.", $inner_css));
      }
    }
    else {
      throw new \Exception(sprintf("One of the provided elements has a width of zero."));
    }
  }

  /**
   * @Given /^"([^"]*)" should be "([^"]*)" wide within a margin of "([^"]*)"$/
   */
  public function shouldBeWideWithinAMarginOf($selector, $width, $margin) {
    $width = str_replace('px', '', $width);
    $margin = str_replace('%', '', $margin);

    $actual_width = str_replace('px', '', $this->getWidth($selector));

    if ($actual_width > 0) {
      $percent = ($width / $actual_width) * 100;

      if (($percent > (100 + $margin)) || ($percent < (100 - $margin))) {
        throw new \Exception(sprintf("%s not within the defined margin of width.", $selector));
      }
    }
    else {
      throw new \Exception(sprintf("The provided element has a width of zero."));
    }
  }

  /**
   * @Given /^"([^"]*)" should have a "([^"]*)" css value of about "([^"]*)"$/
   */
  public function shouldHaveACssValueOfAbout($selector, $attribute, $size) {
    //Call the parent step with a hard-coded margin of 5%
    $this->shouldHaveACssValueOfAboutWithAMarginOf($selector, $attribute, $size, '5%');
  }

  /**
   * @Given /^"([^"]*)" should have a "([^"]*)" css value of about "([^"]*)" with a margin of "([^"]*)"$/
   */
  public function shouldHaveACssValueOfAboutWithAMarginOf($selector, $attribute, $size, $margin) {
    $size = str_replace('px', '', $size);

    $margin = str_replace('%', '', $margin);

    $actual_size = $this->getSession()
      ->evaluateScript(
        "return jQuery( '" . $selector . "' ).css('$attribute');"
      );

    $actual_size = str_replace('px', '', $actual_size);

    if ($actual_size > 0) {
      $percent = ($size / $actual_size) * 100;

      if (($percent > (100 + $margin)) || ($percent < (100 - $margin))) {
        throw new \Exception(sprintf("%s not within the defined margin of width.", $selector));
      }
    }
    else {
      throw new \Exception(sprintf("The provided element has a width of zero."));
    }
  }

  /**
   * Helper function to retrieve an items width
   */
  public function getWidth($selector) {
    return $this->getSession()->evaluateScript("
      return jQuery( '" . $selector . "' ).css('width');
    ");
  }

  /**
   * @Given /^the edge of "([^"]*)" should line up with "([^"]*)"$/
   */
  public function theEdgeOfShouldLineUpWith($element_one, $element_two) {
    if ($this->leftOffset($element_one) !== $this->leftOffset($element_two)) {
      throw new \Exception(sprintf("The edge %s does not align with the edge of %s", $element_one, $element_two));
    }
  }

  /**
   * Helper function to return the left offset
   */
  public function leftOffset($selector) {
    $offset = $this->getSession()->evaluateScript("
      return jQuery( '" . $selector . "' ).offset();
    ");
    return $offset['left'];
  }

  /**
   * @Given /^"([^"]*)" should contain no more than "([^"]*)" elements$/
   */
  public function shouldContainNoMoreThanElements($element, $max_children) {
    $widths = $this->getChildWidths($element);
    if (count($widths) > $max_children) {
      throw new \Exception("There are more than %s elements in %s", $max_children, $element);
    }
  }

  /**
   * @param $nodeHash
   * @throws \Exception
   */
  private function createMultichoice($nodeHash) {
    $question = new stdClass();
    $question->title = $nodeHash['title'];
    $question->type = 'multichoice';
    $question->body = array(
      LANGUAGE_NONE => array(
        array(
          'value' => $nodeHash['body'],
          'format' => 'plain_text',
        ),
      )
    );
    $question->choice_multi = 0;
    $question->choice_random = 0;
    $question->choice_boolean = 0;
    $question->language = LANGUAGE_NONE;
    $question->uid = 1;
    $question->status = 1;
    $question->field_parcc_item['und'][0]['value'] = $nodeHash['parcc_item'] == 'Yes' ? 1 : 0;
    $question->alternatives = array(
      array(
        'answer' => array(
          'value' => 'Yes',
        ),
        // All these values are necessary to avoid integrity constraint errors.
        'answer_format' => 'plain_text',
        'feedback_if_chosen' => '',
        'feedback_if_not_chosen' => '',
        'feedback_if_chosen_format' => 'plain_text',
        'feedback_if_not_chosen_format' => 'plain_text',
        'score_if_chosen' => 1,
        'correct' => 1,
      ),
      array(
        'answer' => array(
          'value' => 'No',
        ),
        'answer_format' => 'plain_text',
        'feedback_if_chosen' => '',
        'feedback_if_not_chosen' => '',
        'feedback_if_chosen_format' => 'plain_text',
        'feedback_if_not_chosen_format' => 'plain_text',
        'score_if_chosen' => 0,
        'correct' => 0,
      ),
    );

    node_object_prepare($question);
    $question = node_submit($question);
    node_save($question);
    $this->nodes[] = $question;
  }


  /**
   * @Then /^I should see "(?P<link>(?:[^"]|\\")*)" number "(?P<number>[^"]*)"$/
   */
  public function findLinkTextIndex($text, $index) {
    $page = $this->getSession()->getPage();
    $links = $page->findAll('xpath', "//a[text()='" . $text . "']");
    if (!isset($links[$index])) {
      throw new Exception("{$text} number {$index} could not be found.");
    }
  }

  /**
   * @Given /^I simulate subject\/standard shs requests$/
   */
  public function iSimulateSubjectStandardShsRequests() {
    global $base_url;
    $url = $base_url . '/js/shs/json';

    $term = taxonomy_get_term_by_name('Career Clusters');

    $term = array_pop($term);

    $vid = $term->vid;
    $tid = $term->tid;

    $script = "

  window.subStandTest = {
    complete: false,
    requests: [],
    result: null,
    execute: function () {
      var data = {
        callback: \"shs_json_term_get_children\",
        arguments: {
          vid: $vid,
          parent: [$tid],
          settings: {
            create_new_levels: 0,
            create_new_terms: false,
            force_deepest: 0,
            node_count: 0,
            use_chosen: 'chosen',
            required: false
          }
        }
      };

      for (var i = 0; i < 30; i++) {
        window.subStandTest.requests.push(jQuery.post(
            '/js/shs/json',
            data,
            function (data, textStatus, xhr) {
              if (xhr.status == 500) {
                window.subStandTest.result = false;
              }
            },
            'json'
          ).fail(function () {
              window.subStandTest.result = false;
            }
          )
        );
      }
    }
  };

  window.subStandTest.execute();

  jQuery(document).ajaxStop(
    function () {
      console.log('AJAX complete.');
      window.subStandTest.complete = true;
    }
  );


    ";
    //execute the javascript test
    $this->getSession()->getDriver()->executeScript($script);
    //give it some time to complete
    sleep(3);
    //retrieve the result
    $result = $this->getSession()
      ->getDriver()
      ->evaluateScript("window.subStandTest.result");

    if ($result === FALSE) {
      throw new Exception("AJAX failures detected with SHS.");
    }
  }

  /**
   * @Given /^I visit the path "([^"]*)"$/
   */
  public function iVisitThePath($path) {
    $path = $this->fixStepArgument($path);

    return new Given("I am at \"$path\"");
  }

  /**
   * @Given /^the text "([^"]*)" should not repeat$/
   */
  public function theTextShouldNotRepeat($text) {
    $text = $this->fixStepArgument($text);
    $page = $this->getSession()->getPage();
    $items = $page->findAll('xpath', "//*[text()='" . $text . "']");
    if(count($items) > 1){
      throw new Exception("Multiple instances of '$text' found.");
    }
  }

  /**
   * @Given /^SSO is enabled$/
   */
  public function ssoIsEnabled() {
    if (!module_exists('bt_onelogin_saml')) {
      throw new Exception("SSO module is not enabled!");
    }
  }

  /**
   * Override login to use user/local-login
   */
  public function login() {
    if ($this->ssoIsOn) {
      // Check if logged in.
      if ($this->loggedIn()) {
        $this->logout();
      }

      if (!$this->user) {
        throw new \Exception('Tried to login without a user.');
      }

      $this->getSession()->visit($this->locatePath('/user/local-login'));
      $element = $this->getSession()->getPage();
      $element->fillField($this->getDrupalText('username_field'), $this->user->name);
      $element->fillField($this->getDrupalText('password_field'), $this->user->pass);
      $submit = $element->findButton($this->getDrupalText('log_in'));
      if (empty($submit)) {
        throw new \Exception(sprintf("No submit button at %s", $this->getSession()
          ->getCurrentUrl()));
      }

      // Log in.
      $submit->click();

      if (!$this->loggedIn()) {
        throw new \Exception(sprintf("Failed to log in as user '%s' with role '%s'", $this->user->name, $this->user->role));
      }
    }
    else {
      parent::login();
     }
  }
  /**
   * @Given /^I select "([^"]*)" from the "([^"]*)" Chosen widget$/
   */
  public function assertSelectFromTheChosenElement($option, $select)  {
    $select = $this->fixStepArgument($select);
    $option = $this->fixStepArgument($option);
    if (!$field = $this->getSession()->getPage()->findField($select)) {
      throw new Exception(sprintf('Unable to find select "%s".', $select));
    }
    $fieldName = $field->getAttribute('name');
    $value = $field->getValue();
    $opt = $field->find('named', array(
      'option', $this->getSession()->getSelectorsHandler()->xpathLiteral($option)
    ));
    if (!$opt) {
      throw new Exception(sprintf('Option "%s" not available for Chosen "%s".', $option, $select));
    }
    $newValue = $opt->getAttribute('value');
    if (is_array($value)) {
      if (!in_array($newValue, $value)) {
        $value[] = $newValue;
      }
    } else {
      $value = $newValue;
    }
    $valueEncoded = json_encode($value);
    $script = "(function ($) { $('select[name=\"$fieldName\"]').val($valueEncoded).change().trigger('liszt:updated').trigger('chosen:updated'); })(jQuery)";
    $this->getSession()->getDriver()->executeScript($script);
  }

  /**
   * @Given /^I have a practice test entity called "([^"]*)"$/
   */
  public function iHaveAPracticeTestEntityCalled($title) {
    $title = $this->fixStepArgument($title);

    $client = new GuzzleHttp\Client();

    $domain = $this->getDrupalParameter('base_url');

    //Retrieve the custom parameters from behat.yml
    $username = $this->customParameters['rest_user_name'];
    $password = $this->customParameters['rest_user_password'];

    /**
     * Retrieve CSRF token
     */
    $token_url = $domain . '/restws/session/token';

    $token_options = array(
      'auth' => array($username, $password),
    );

    $res = $client->request('GET', $token_url, $token_options);


    $token = $res->getBody()->getContents();


    /**
     * Create the practice_test entity
     */
    $uri = $domain . '/practice_test';

    $data = array(
      'test_key' => 'PRACT12345',
      'created' => 12345,
      'title' => $title
    );

    $options = array(
      'auth' => array($username, $password),
      'headers' => array(
        'X_CSRF_TOKEN' => $token,
        'Content-Type' => 'application/json'
      ),
      'body' => json_encode($data)
    );

    $res = $client->request('POST', $uri, $options);

    if($res->getStatusCode() != '201'){
      throw new \Exception(sprintf("Faled to create practice test entity"));
    }
  }

  /**
   * @Given /^I access the practice test link for "([^"]*)" directly$/
   */
  public function visitPracticeTest($node_title){
    $node_title = $this->fixStepArgument($node_title);
    $efq = new EntityFieldQuery();

    $efq->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'parcc_released_item')
      ->entityCondition('title', $node_title);

    $results = $efq->execute();

    $node = array_pop($results['node']);

    // send them to practice-tests/$nid
    $this->getSession()->visit($this->locatePath('/practice-tests/'.$node->nid));
  }
}