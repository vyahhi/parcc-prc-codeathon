<?php

use Behat\Behat\Context\Context;
use Behat\Behat\Context\SnippetAcceptingContext;
use Behat\Gherkin\Node\PyStringNode;
use Behat\Gherkin\Node\TableNode;
use Behat\MinkExtension\Context\MinkContext;

/**
 * Defines application features from the specific context.
 */
class FeatureContext extends MinkContext implements Context, SnippetAcceptingContext
{

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
      $argument = str_replace('@timestamp', time(), $argument);
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

}
