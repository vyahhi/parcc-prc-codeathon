@api @d7
Feature: Add Content: Expandable/Collapsable Controls (PRC-157)
  As a Content Author,
  I want to expand and collapse different attribute sections within the Add Content page,
  so that the most important attributes stand out at a glance.


  Scenario: AC1a  Attach a File -collapsed by default
    Given I am logged in as a user with the "Content Author" role
    And I am on "node/add/digital-library-content"
    # AC1a Attach a File -collapsed by default
    And I should see "Attach a File"
    #  AC1b  Add a Thumbnail Image -expanded by default
    And I should see "Add a Thumbnail Image"
    #  AC1c  Link to URL -collapsed by default
    And I should see "Link to URL"
    #  AC1d  Add More Information (Content Properties) -collapsed by default. In this story, this control shall stay collapsed, or shows no content when expanded (a future story addresses it)
    And I should see "Add More Information (Content Properties)"
    #MP Learn to test collapsability!