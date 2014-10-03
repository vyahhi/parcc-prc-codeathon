<?php
/**
 * Created by PhpStorm.
 * User: jfranks
 * Date: 9/29/14
 * Time: 1:14 PM
 */


use Behat\MinkExtension\Context\MinkContext;
use Behat\Behat\Exception\PendingException;
use Behat\Behat\Event\ScenarioEvent;
use Behat\Mink\Exception\UnsupportedDriverActionException;

use Drupal\Drupal;
use Drupal\DrupalExtension\Event\EntityEvent;
use Drupal\DrupalExtension\Context\DrupalSubContextInterface;

use Symfony\Component\Process\Process;
use Symfony\Component\EventDispatcher\EventDispatcher;

use Behat\Behat\Context\Step\Given;
use Behat\Behat\Context\Step\When;
use Behat\Behat\Context\Step\Then;
use Behat\Behat\Context\TranslatedContextInterface;

use Behat\Gherkin\Node\PyStringNode;
use Behat\Gherkin\Node\TableNode;

use Behat\Mink\Driver\Selenium2Driver as Selenium2Driver;

class FeatureContext extends \Drupal\DrupalExtension\Context\DrupalContext {
  protected $timestamp;

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
    return parent::fixStepArgument($argument);
  }

  /**
   * @Then /^"([^"]*)" should be visible$/
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
  public function iShouldSeeAButton($button)
  {
    $button = $this->fixStepArgument($button);
    if (!$this->getSession()->getPage()->hasButton($button)) {
      throw new Exception("Element ({$button}) not found");
    }
  }

  /**
   * Asserts that a given node type is editable.
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
   * @Then /^I should know that the user "([^"]*)" has a role of "([^"]*)"$/
   */
  public function assertUserHasRole($username, $role) {
    parent::assertDrushCommandWithArgument('user-information', $username);
    parent::assertDrushOutput($role);
  }


}