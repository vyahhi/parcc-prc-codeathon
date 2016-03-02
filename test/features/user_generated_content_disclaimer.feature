@api @footer @user_generated_content @prc-889 @prc-1254
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
    And I should see the text "Parcc Inc. User Generated Content and Resources Terms of Use"
    And I should see the text "Effective Date"
    And I should see the text "September 18, 2015"
    And I should see the text "Current Version Date"
    And I should see the text "September 18, 2015"
    And I should see the text "Thank you for reviewing the terms and conditions for submitting resources on Parcc Inc.’s Partnership Resource Center \(PRC\)."
    And I should see the text "Parcc Inc. is the project management partner for the PARCC consortium of states. Parcc Inc. oversees the development of the PARCC assessment system and related tools, supports the governance and decision-making of consortium states, provides day-to-day management of the project, and develops and maintains plans for the consortium’s long-term sustainability."
    And I should see the text "Parcc Inc. allows for the uploading to the PRC content and resources by the users on the PRC."
    And I should see the text "By submitting content or resources to the PRC, you agree that you and your submission\(s\) is \(are\) subject to the following definitions, terms, and conditions:"

  Scenario: PRC-1254 - No submitted by author or date
    Given I am an anonymous user
    And I click "User Generated Content Disclaimer" in the "footer_copyright" region
    Then I should not see the text "Submitted by"