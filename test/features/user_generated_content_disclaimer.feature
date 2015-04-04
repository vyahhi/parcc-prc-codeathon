@api @footer @user_generated_content @prc-889
Feature: PRC-889 Accessing User Generated Content Disclaimer
  As a user,
  I want to have access to PARCC User Generated Content Disclaimer when accessing PRC.
  Acceptance Criteria
  Given that I am on PRC site
  When that I have pressed on User Generated Content Disclaimer link in the footer
  Then I see the following content displayed:
  Page Name
  User Generated Content Disclaimer
  Effective Date
  January 01, 2015
  Content
  Placeholder content: Content standards apply to any and all material which you contribute to the Site ("Contributions"), and to any Interactive Services associated with it. You must comply with the spirit of the standards as well as the letter. The standards apply to each part of any Contribution as well as to its whole.

  Scenario: View UGCD
    Given I am an anonymous user
    And I click "User Generated Content Disclaimer" in the "footer_copyright" region
    Then I should see the heading "User Generated Content Disclaimer"
    And I should see the text "Effective Date"
    And I should see the text "January 01, 2015"
    And I should see the text "Placeholder content: Content standards apply to any and all material which you contribute to the Site"
    And I should see the text "and to any Interactive Services associated with it. You must comply with the spirit of the standards as well as the letter. The standards apply to each part of any Contribution as well as to its whole."
