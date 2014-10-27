@api @d7
Feature: Share Content (end user) (PRC-59)
  As an educator,
  I want to share content,
  so that it can be distributed to friends and colleagues as needed.

  Background: In the Digital Library page where content is displayed...
    Given I am logged in as a user with the "Educator" role
    And I am viewing a "Digital Library Content" node with the title "PRC-59"

  Scenario: I should see E-mail
    Then I should see an ".st_email_button" element

  Scenario: I should see Facebook
    Then I should see an ".st_facebook_button" element

  Scenario: I should see Edmodo
    Then I should see an ".st_edmodo_button" element

  # Manual testing for this feature will cover the following scenarios:
  #  2.  *E-mail*
  #  - When the email share button is selected, the educator will experience the current Drupal Default Email Handling option.
  #
  #  3.  *Facebook - Already Signed In Scenario*
  #  -  When the Facebook share button is selected, the educator will be directed to the "Facebook Share" page.
  #
  #  4. *Facebook - Not Signed In*
  #  - When the Facebook share button is selected, the educator will be directed to the "Facebook Sign In" page in a new window.
  #
  #  5.  *Edmodo - Already Signed In Scenario*
  #  - When the Edmodo share button is selected, the educator will be directed to the "Edmodo Share" page.
  #
  #  6. *Edmodo - Not Signed In*
  #  - When the Edmodo share button is selected, the educator will be directed to the "Edmodo Sign In" page in a new window.