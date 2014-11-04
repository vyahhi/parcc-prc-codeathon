@api @d7

Feature: Add Content: Expandable/Collapsible Controls (PRC-157)
  As a Content Contributor,
  I want to expand and collapse different attribute sections within the Add Content page,
  so that the most important attributes stand out at a glance.

  @javascript
  Scenario: AC1a  Attach a File -collapsed by default
    Given I am logged in as a user with the "Content Contributor" role
    And I am on "node/add/digital-library-content"
    # AC1a Attach a File -collapsed by default
    And I should not see "Allowed file types: txt pdf doc docx xls xlsx."
    And I click "Show Attach a File"
    And I should see "Allowed file types: txt pdf doc docx xls xlsx."
    #  AC1b  Add a Thumbnail Image -expanded by default
    And I should see "Add a Thumbnail"
    And I should see "Allowed file types: png gif jpg jpeg."
    And I click "Hide Add a Thumbnail"
    And I should not see "Allowed file types: png gif jpg jpeg."
    #  AC1c  Link to URL -collapsed by default
    And I should see "Link to URL"
    And I should not see "The link title is limited to 128 characters maximum."
    And I click "Show Link to URL"
    And I should see "The link title is limited to 128 characters maximum."
    #  AC1d  Add More Information (Content Properties) -collapsed by default. In this story, this control shall stay collapsed, or shows no content when expanded (a future story addresses it)
    And I should see "Add More Information (Content Properties)"
    And I should not see "Grade Level"
    And I click "Show Add More Information (Content Properties)"
    And I should see "Grade Level"
