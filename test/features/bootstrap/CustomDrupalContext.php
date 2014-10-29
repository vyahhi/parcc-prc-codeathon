<?php
/**
 * Created by PhpStorm.
 * User: jfranks
 * Date: 9/29/14
 * Time: 1:14 PM
 */


use Behat\Behat\Context\Step\Then;
use Behat\Behat\Context\Step\Given;
use Drupal\DrupalExtension\Event\EntityEvent;

class FeatureContext extends \Drupal\DrupalExtension\Context\DrupalContext {
  protected $timestamp;
  protected $originalMailSystem;
  /**
   * Initializes context.
   *
   * Every scenario gets its own context instance.
   * You can also pass arbitrary arguments to the
   * context constructor through behat.yml.
   */
  public function __construct()
  {
    $this->timestamp = time();
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
   * Checks for a field with specified id|name|title|alt|value.
   *
   * @Then /^(?:|I )should see an? "(?P<element>[^"]*)" field$/
   */
  public function iShouldSeeAField($field)
  {
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
  public function iShouldNotSeeAField($field)
  {
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
  public function iShouldSeeALink($field)
  {
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
  public function   iShouldSeeAButton($button)
  {
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
    $this->getSession()->visit($this->locatePath('/node/' . $saved->nid . '/edit'));

    // Test status.
    return new Then("I should get a \"403\" HTTP response");

  }

  /**
   * Asserts that a given user has the specified role.
   *
   * @Then /^the user "([^"]*)" should have a role of "([^"]*)"$/
   */
  public function assertUserHasRole($username, $role) {
    parent::assertDrushCommandWithArgument('user-information', $username);
    parent::assertDrushOutput($role);
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
   * Creates multiple users.
   * Overrides parent::createUsers().
   */
  public function createUsers(\Behat\Gherkin\Node\TableNode $usersTable) {
    foreach ($usersTable->getHash() as $userHash) {

      // If we have roles convert it to array.
      if (isset($userHash['roles'])) {
        $userHash['roles'] = explode(',', $userHash['roles']);
        $userHash['roles'] = array_map('trim', $userHash['roles']);
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

      foreach($userHash as $key => $value) {
        if (strpos($key, 'field_') === 0) {
          // This is a field_something so we have to assign it
          $w->{$key}->set($value);
        }
      }
      $w->save();

      $this->users[$user->name] = $user;
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
    $this->getSession()->visit($this->locatePath('/node/' . $saved->nid . '/edit'));

    // Test status.
    return new Then("I should get a \"200\" HTTP response");

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

        if (strpos($message['body'], $contents) !== FALSE ||
          strpos($message['subject'], $contents) !== FALSE) {
          return TRUE;
        }
        throw new \Exception('Did not find expected content in message body or subject.');
      }
    }
    throw new \Exception(sprintf('Did not find expected message to %s', $mail_to));
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
      strpos($message['subject'], $contents) !== FALSE) {
      return TRUE;
    }
    throw new \Exception('Did not find expected content in message body or subject.');
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
  public function assertFieldValue($field, $value)
  {
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
//    if (!$this->activeEmail) {
//      throw new \Exception('No active email');
//    }
//    $message = $this->activeEmail;
//
//    $body = $message['body'];
//    // The Regular Expression to look for URLs
//    $reg_exUrl = '`([^"=\'>])((http|https|ftp)://[^\s<]+[^\s<\.)])`i';
//    if(preg_match($reg_exUrl, $body, $url)) {
//      // It does return multiple matches. In this particular case we only care about the first one (so far)
//      $follow_url = $url[0];
//    }
//    if (isset($follow_url)) {
//      // Have to go to the driver level because visit only works for pages off the base url
//      $this->getSession()->visit($follow_url);
//      return TRUE;
//    }
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
    }
    catch (UnsupportedDriverActionException $e) {
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
  public function backAndConfirm()
  {
    $this->getSession()->back();
    $this->iConfirmTheDialog();
  }

  /**
   * Moves backward one page in history and dismisses the dialog.
   *
   * @When /^(?:|I )move backward one page, dismissing the dialog$/
   */
  public function backAndDismiss()
  {
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
  public function iClickOnTheElementWithCSSSelector($cssSelector)
  {
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
   * Dismisses a confirmation dialog
   *
   * @Then /^I dismiss the confirmation$/
   */
  public function dismissAlert() {
    $this->getSession()->getDriver()->getWebDriverSession()->dismiss_alert();
  }

  /**
   * @Then /^(?:|I )should see "([^"]*)" in popup$/
   *
   * @param string $message The message.
   *
   * @return bool
   */
  public function assertPopupMessage($message)
  {
    return $message == $this->getSession()->getDriver()->getWebDriverSession()->getAlert_text();
  }

  public function afterScenario($event) {
    if ($event->getResult()) {
      $this->recordFailedEvent($event);
    }

    parent::afterScenario($event);
    $this->theDefaultEmailSystemIsEnabled();
    //print $this->getDrupalParameter('selectors')['success_message_selector'];
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

    $feature_file_full = $event->getScenario()->getFeature()->getFile();
    $ff = explode('/', $feature_file_full);
    $feature_file_name = array_pop($ff);

    if (!file_exists($html_dump_path))
    {
      mkdir($html_dump_path);
    }

    $html = "<!-- HTML dump from behat  \nDate: $date  \nUrl:  $url  -->\n " . $html;

    $htmlCapturePath = $html_dump_path . '/' . $fileName . '.' . $feature_file_name . '.html';
    file_put_contents($htmlCapturePath, $html);

    $message .= "\nHTML available at: " . $html_dump_path  . "/". $fileName . ".html";


    if ($driver instanceof \Behat\Mink\Driver\Selenium2Driver)
    {
      if (!file_exists($html_dump_path))
      {
        mkdir($html_dump_path);
      }

      $screenshot = $driver->getScreenshot();
      $screenshotFilePath = $html_dump_path . '/' . $fileName . '.png';
      file_put_contents($screenshotFilePath, $screenshot);

      $message .= "\nScreenshot available at: " . $screenshotFilePath;
    }

    print $message . PHP_EOL;
  }
}

