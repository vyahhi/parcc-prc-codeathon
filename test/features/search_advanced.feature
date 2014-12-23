@api
Feature: PRC-106 Search Content- Advanced
  As an educator,
  I want to narrow down my search results by entering advanced filtering criteria,
  so that I can find the specific content I'm looking for.

  #  BACKGROUND: The Search functionality in the header is global, and will search through all types of content in PRC, including:
  #  i. Digital Library
  #  ii. Professional Development
  #  iii. Assessments (Not implemented yet)
  #  Acceptance Criteria
  #  AC1 When a user searches for content by entering a keyword in Quick Search section (defined in PRC-31),
  #  the system redirects the user to the Search Results page (currently available), where a new left panel shall be
  #  available to display the filtering criteria in the Search Results page, titled as: Filters
  #  AC2 A Clear All link shall be available by Filters title. At click, it resets the filters to no filter.
  #  AC3 The system shall provide each the following filters:
  #  By Content Type
  #  By Author
  #  By Media Type
  #  By Subject
  #  By Standard
  #  AC4 Each of the above filters are followed by their available values, along with the results count in the parentheses. See example below:
  #  By Subject
  #  Math (23)
  #  Fractions (120)
  #  Algebra (14)
  #  AC5 Only the filter values with a non-zero count shall be displayed. For example, do not show:
  #  Geometry (0)
  #  AC6 Filters with no value shall be invisible (For example, if none of the search results' content has an associated Standard , do not display Standard as a filter).
  #  AC7 Clicking a filter value shall display the associated content only.
  
  Scenario: Quick search takes user to new search page
    #  AC1 When a user searches for content by entering a keyword in Quick Search section (defined in PRC-31),
    #  the system redirects the user to the Search Results page (currently available), where a new left panel shall be
    #  available to display the filtering criteria in the Search Results page, titled as: Filters
    Given I am an anonymous user
    And I am on the homepage
    When I fill in "something" for "Search" in the "header" region
    And I press "Search" in the "header" region
    Then |I should be on "<string>"