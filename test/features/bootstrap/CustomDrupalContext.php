<?php
/**
 * Created by PhpStorm.
 * User: jfranks
 * Date: 9/29/14
 * Time: 1:14 PM
 */


use Behat\Behat\Context\Step\Then;
use Behat\Behat\Context\Step\Given;
use Behat\Mink\Exception\ExpectationException;
use Drupal\DrupalExtension\Event\EntityEvent;
use Behat\Gherkin\Node\TableNode;
class FeatureContext extends \Drupal\DrupalExtension\Context\DrupalContext {
  protected $timestamp;
  protected $originalMailSystem;
  protected $customParameters;
  /**
   * Initializes context.
   *
   * Every scenario gets its own context instance.
   * You can also pass arbitrary arguments to the
   * context constructor through behat.yml.
   */
  public function __construct($parameters)
  {
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
      $whole_token = "@nid[$node_name]";
      $argument = str_replace($whole_token, $found_nid, $argument);
    }
    if (strpos($argument, '@currentuid') !== FALSE) {
      if ($this->user) {
        $current_uid = $this->user->uid;
        $argument = str_replace('@currentuid', $current_uid, $argument);
      } else {
        throw new Exception("Must be logged in as a user");
      }
    }
    return parent::fixStepArgument($argument);
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
    foreach($this->nodes as $node) {
      if ($node->title == $node_title) {
        $found_node = $node;
        break;
      }
    }
    if (!$found_node) {
      throw new \Exception(sprintf("Node '%s' not found", $node_title));
    }

    $nid = $found_node->nid;
    $found_flag->flag('flag', $nid, NULL, TRUE);
  }

  /**
   * @Given /^I follow meta refresh$/
   */
  public function iFollowMetaRefresh() {
    while ($refresh = $this->getMainContext()->getSession()->getPage()->find('css', 'meta[http-equiv="Refresh"]')) {
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
    } elseif (!$el->isVisible()) {
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
    } elseif ($el->isVisible()) {
      throw new Exception("Element ({$selector}) is visible");
    }
  }

  /**
   * @Then /^the "([^"]*)" radio button should be selected$/
   * @When /^the radio button "(?P<label>[^"]*)" with the id "(?P<id>[^"]*)" should be selected$/
   */
  public function assertRadioButtonSelected($label, $id = FALSE) {
    $element = $this->getSession()->getPage();
    $radiobutton = $id ? $element->findById($id) : $element->find('named', array('radio', $this->getSession()->getSelectorsHandler()->xpathLiteral($label)));
    if ($radiobutton === NULL) {
      throw new \Exception(sprintf('The radio button with "%s" was not found on the page %s', $id ? $id : $label, $this->getSession()->getCurrentUrl()));
    }
    $value = $radiobutton->getAttribute('value');
    $labelonpage = $radiobutton->getParent()->getText();
    if ($label != $labelonpage) {
      throw new \Exception(sprintf("Button with id '%s' has label '%s' instead of '%s' on the page %s", $id, $labelonpage, $label, $this->getSession()->getCurrentUrl()));
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


  /**
   * @Then /^"([^"]*)" in "([^"]*)" should be selected$/
   */
  public function inShouldBeSelected($optionValue, $select) {
    $selectElement = $this->getSession()->getPage()->find('named', array('select', "\"{$select}\""));
    $optionElement = $selectElement->find('named', array('option', "\"{$optionValue}\""));
    //it should have the attribute selected and it should be set to selected
    if (!$optionElement->hasAttribute("selected")) {
      throw new \Exception(sprintf('The select box with "%s" has nothing selected', $select));
    }
    if (!$optionElement->getAttribute("selected") == "selected") {
      throw new \Exception(sprintf('The select box "%s" should have had %s selected.', $select, $optionValue));
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
    $node = (object)array('type' => $type);
    $saved = $this->getDriver()->createNode($node);
    $this->nodes[] = $saved;

    // Set internal browser on the node edit page.
    $this->getSession()->visit($this->locatePath('/node/' . $saved->nid . '/edit'));

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
    $drupal_user = user_load($this->user->uid);
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

      $user = (object)$userHash;

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
          } else {
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
    } else {
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
    $node = (object)array(
      'title' => $this->getDrupal()->random->string(255),
      'type' => $type,
      'body' => $this->getDrupal()->random->string(255),
      'uid' => $this->user->uid,
    );
    $saved = $this->getDriver()->createNode($node);
    $this->nodes[] = $saved;

    // Set internal browser on the node edit page.
    $this->getSession()->visit($this->locatePath('/node/' . $saved->nid . '/edit'));

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
    parent::createNodes($type, $nodesTable);
  }

  public function createNode($type, $title) {
    $node = (object)array(
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

    $node = (object)array(
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
    $user = $this->users[$username];
    $uid = $user->uid;

    $expected_path = "user/$uid/edit";

    $this->assertAtPath($expected_path);
  }

  /**
   * @Then /^I should see the checkbox "(?P<label>[^"]*)"$/
   */
  public function assertCheckboxByIdPresent($label, $id = FALSE) {
    $element = $this->getSession()->getPage();
    $checkbox = $id ? $element->findById($id) : $element->find('named', array('checkbox', $this->getSession()->getSelectorsHandler()->xpathLiteral($label)));
    if ($checkbox === NULL) {
      throw new \Exception(sprintf('The checkbox with "%s" was not found on the page %s', $id ? $id : $label, $this->getSession()->getCurrentUrl()));
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
    $checkbox = $id ? $element->findById($id) : $element->find('named', array('checkbox', $this->getSession()->getSelectorsHandler()->xpathLiteral($label)));
    if ($checkbox !== NULL) {
      throw new \Exception(sprintf('The checkbox with "%s" was found on the page %s', $id ? $id : $label, $this->getSession()->getCurrentUrl()));
    }
  }

  /**
   * @Then /^I should see the radio button "(?P<label>[^"]*)"$/
   */
  public function assertRadioByIdPresent($label, $id = FALSE) {
    $element = $this->getSession()->getPage();
    $radiobutton = $id ? $element->findById($id) : $element->find('named', array('radio', $this->getSession()->getSelectorsHandler()->xpathLiteral($label)));
    if ($radiobutton === NULL) {
      throw new \Exception(sprintf('The radio button with "%s" was not found on the page %s', $id ? $id : $label, $this->getSession()->getCurrentUrl()));
    }
  }

  /**
   * @Then /^I should not see the radio button "(?P<label>[^"]*)"$/
   */
  public function assertRadioByIdNotPresent($label, $id = FALSE) {
    $element = $this->getSession()->getPage();
    $radiobutton = $id ? $element->findById($id) : $element->find('named', array('radio', $this->getSession()->getSelectorsHandler()->xpathLiteral($label)));
    if ($radiobutton !== NULL) {
      throw new \Exception(sprintf('The radio button with "%s" was found on the page %s', $id ? $id : $label, $this->getSession()->getCurrentUrl()));
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
    } else {
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
    } else {
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
        return $element->getText();
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
      'option', $this->getSession()->getSelectorsHandler()->xpathLiteral('*')
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
    } else {
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
    if (strpos($message['body'], $contents) !== FALSE ||
      strpos($message['subject'], $contents) !== FALSE
    ) {
      return TRUE;
    }
    print $message['body'];
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

    if (null === $found) {
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
    $this->getSession()->wait($ms);
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
      $session->getSelectorsHandler()->selectorToXpath('css', $cssSelector) // just changed xpath to css
    );
    if (null === $element) {
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
    if (null === $element) {
      throw new \InvalidArgumentException(sprintf('Could not evaluate XPath Selector: "%s"', $xpathSelector));
    }
    $element->check();

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
    return $message == $this->getSession()->getDriver()->getWebDriverSession()->getAlert_text();
  }

  public function afterScenario($event) {
    if ($event->getResult()) {
      $this->recordFailedEvent($event);
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
    $fileName = $this->timestamp;
    // TODO: Make this a setting in behat.yml?
    $html_dump_path = 'failures';

    $message = '';
    $session = $this->getSession();
    $page = $session->getPage();
    $driver = $session->getDriver();
    $date = date('Y-m-d H:i:s');
    $url = $session->getCurrentUrl();
    $html = $page->getContent();


    $event_class = get_class($event);
    if (strpos($event_class, 'OutlineExampleEvent') !== FALSE) {
      $scenario = $event->getOutline();
    } elseif (strpos($event_class, 'ScenarioEvent') !== FALSE) {
      $scenario = $event->getScenario();
    }
    if ($scenario) {
      $feature_file_full = $scenario->getFeature()->getFile();
    } else {
      $feature_file_full = 'failure';
    }
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
    } elseif (strpos($event_class, 'ScenarioEvent') !== FALSE) {
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
   * @When /^I am browsing using a "([^"]*)"$/
   */
  public function iAmBrowsingUsingA($device) {
    switch($device) {
      case "phone":
        $this->getSession()->resizeWindow((int)$this->customParameters['phone_width'], (int)$this->customParameters['phone_height'], 'current');
        break;
      case "tablet":
        $this->getSession()->resizeWindow((int)$this->customParameters['tablet_width'], (int)$this->customParameters['tablet_height'], 'current');
        break;
      case "small desktop":
        $this->getSession()->resizeWindow((int)$this->customParameters['desktop_sm_width'], (int)$this->customParameters['desktop_sm_height'], 'current');
        break;
      default:
        $this->getSession()->resizeWindow((int)$this->customParameters['desktop_width'], (int)$this->customParameters['desktop_height'], 'current');
    }
  }

  /**
   * @Given /^"([^"]*)" should have a "([^"]*)" css value of "([^"]*)"$/
   * @param $selector, $rule, $value
   * @throws Exception
   */
  public function shouldHaveACssValueOf($selector, $rule, $value) {
    $computed = $this->getSession()->evaluateScript("
      return jQuery( '" . $selector . "' ).css('" . $rule . "');
    ");
    // Convert double quotes to single quotes for matching purposes.
    $computed = str_replace('"',"'",$computed);
    if ($value != $computed) {
      throw new Exception("Element ({$selector}) does not have a ({$rule}) value of ({$value}).  The actual value is ({$computed})");
    }
  }

  /**
   * @When /^I hover over the element "([^"]*)"$/
   */
  public function iHoverOverTheElement($selector)
  {
    $element = $this->getSession()->getPage()->find('css', $selector);

    if ($element === NULL) {
      throw new Exception("Could not hover over element ({$selector})");
    }

    $element->mouseOver();
  }

  /**
   * @todo: The following all have to do with diglib_workflow_revisions.feature and should be moved to a subcontext
   */

  /**
   * @Given /^I click on the revision id link in row number "([^"]*)" of the table$/
   */
  public function iClickOnTheRevisionIdLinkInRowNumberOfTheTable($arg1) {
    throw new PendingException();
  }

  /**
   * @Given /^I should see the link in the "([^"]*)"$/
   */
  public function iShouldSeeTheLinkInThe($arg1) {
    throw new PendingException();
  }

  /**
   * @Given /^the history table is displayed in reverse chronological order$/
   */
  public function theHistoryTableIsDisplayedInReverseChronologicalOrder() {
    throw new PendingException();
  }
}
