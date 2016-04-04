@api @course
Feature: PRC-346 Admin: Course Audience
  As a Content Admin,
  I want to manage the course enrollment process for anonymous and authenticated users,
  so that I can assign public or private rosters to any available courses as needed.

  # AC1 The Content Admin will select Course Management from the top navigation bar.
  # Tested in PRC-348

  # AC2 The Content Admin will selecting the Course ID link within the course table, and will be directed to the Edit Course Page.
  # Tested in PRC-349

  Scenario Outline: Course Audience does not exist for other node types
    Given I am logged in as a user with the "PRC Admin" role
    And I am viewing my "<type>" node with the title "PRC-346 <type>"
    And I click "Edit"
    Then I should not see the link "Course Audience"
  Examples:
    | type                    |
    | PD Module               |
    | Digital Library Content |
    | Favorites List          |
    | Assessment              |

  Scenario Outline: Course Audience exists for Curators and Admins
    Given I am logged in as a user with the "<role>" role
    And I am viewing a "PD Course" node with the title "PRC-346 Course"
    Then I should see the link "Course Audience"
  Examples:
    | role                            |
    | administrator                   |
    | PRC Admin                       |
    | Content Administrator (Curator) |

  Scenario Outline: Course Audience exists for Curators and Admins
    Given I am logged in as a user with the "<role>" role
    And I am viewing a "PD Course" node with the title "PRC-346 Course"
    Then I should not see the link "Course Audience"
  Examples:
    | role                  |
    | Educator              |
    | PARCC-Member Educator |
    | Content Contributor   |

  Scenario: AC3 From the Edit Course page, the Content Admin will select the Course Audience tab, and will be directed to the "Course Audience" page.
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am viewing my "PD Course" node with the title "PD Course PRC-346 AC3"
    Then I click "Course Audience"
    # AC4 A course label and the following options will display on the "Course Audience" page:
    # Course Audience label
    Then I should see the heading "'PD Course PRC-346 AC3' Course Audience"
    And I should see the text "Course Audience/Permissions"
    And I should see the radio button "Public"
    And I should see the radio button "PARCC members ONLY"
    #  AC5 If the PARCC Members Only option is selected, the following options will display:
    #  All PARCC Members This option is selected by default when the PARCC Members Only radio button is selected.
    #  Select By State
    #  Select By Rostering

    And I should see a "Public" field
    And I should see a "PARCC members ONLY" field

    And I should see an "All PARCC Members" field
    And I should see a "Select By State" field
    And I should see a "Select By Rostering" field

    #  AC6 The following will display when the Select By State option is selected:
    #  A "Select By State" drop down menu
    #  The State field is required if the "Select By State" option is selected.
    #  AC7 The State drop down menu will contain the following options in alphabetical order:
    #  Select a state (default- keeps (or resets value to: NULL)
    And I should see 1 "#edit-by-state" elements
    And I select "- Select a state -" from "edit-by-state"
    And I select "Colorado" from "edit-by-state"
    And I select "Colorado" from "edit-by-state"
    And I select "District of Columbia" from "edit-by-state"
    And I select "Illinois" from "edit-by-state"
    And I select "Maryland" from "edit-by-state"
    And I select "Massachusetts" from "edit-by-state"
    And I select "New Jersey" from "edit-by-state"
    And I select "New Mexico" from "edit-by-state"
    And I select "New York" from "edit-by-state"
    And I select "Rhode Island" from "edit-by-state"

    And I should see the text "Input all email addresses of those you want to roster."

  Scenario: AC8 Validations: state is required
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am viewing my "PD Course" node with the title "PD Course PRC-346 AC3"
    Then I click "Course Audience"
    And I select the radio button "PARCC members ONLY"
    And I select the radio button "Select By State"
    Then I press "Save audience"
    Then I should see the error message containing "State field is required."

  Scenario: AC8 Validations: email is required
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am viewing my "PD Course" node with the title "PD Course PRC-346 AC3"
    Then I click "Course Audience"
    And I select the radio button "PARCC members ONLY"
    And I select the radio button "Select By Rostering"
    Then I press "Save audience"
    Then I should see the error message containing "E-mail field is required."

  Scenario: AC9 AC10 If Select By Rostering is selected, E-mail address must be in email format
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am viewing my "PD Course" node with the title "PD Course PRC-346 AC3"
    Then I click "Course Audience"
    And I select the radio button "PARCC members ONLY"
    And I select the radio button "Select By Rostering"
    And I fill in "E-mail" with "badaddress.com"
    When I press "Save audience"
    Then I should see the error message containing "badaddress.com is not a valid e-mail address."
    And I fill in "E-mail" with "otherbadone,badaddress.com"
    Then I press "Save audience"
    Then I should see the error message containing "otherbadone, badaddress.com are not valid e-mail addresses."

  Scenario: AC9 If Select By Rostering is selected, The E-mail address must be an existing E-mail associated with current users.
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    Given users:
      | name            | mail                               | pass   | field_first_name | field_last_name | status |
      | Joe Educator    | joe_prc_346a@timestamp@example.com | xyz123 | Joe              | Educator        | 1      |
      | Joe Contributor | joe_prc_346b@timestamp@example.com | xyz123 | Joe              | Contributor     | 1      |
    And I am viewing my "PD Course" node with the title "PD Course PRC-346 AC3"
    Then I click "Course Audience"
    And I select the radio button "PARCC members ONLY"
    And I select the radio button "Select By Rostering"
    And I fill in "E-mail" with "joe_prc_356fake@example.com"
    When I press "Save audience"
    Then I should see the error message containing "joe_prc_356fake@example.com does not exist."
    And I fill in "E-mail" with "joe_prc_356fake@example.com, joe_prc_356other@example.com"
    Then I press "Save audience"
    Then I should see the error message containing "joe_prc_356fake@example.com, joe_prc_356other@example.com do not exist."

  Scenario: Public saves
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am viewing my "PD Course" node with the title "PD Course PRC-346 Public"
    When I click "Course Audience"
    And I select the radio button "Public"
    And the "Public" radio button should be selected
    And I press "Save audience"
    Then I should see the message containing "PD Course PRC-346 Public"
    Then I should see the message containing "course audience updated."
    And the "Public" radio button should be selected

  Scenario: Members only all saves
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am viewing my "PD Course" node with the title "PD Course PRC-346 All Members"
    When I click "Course Audience"
    And I select the radio button "PARCC members ONLY"
    And I select the radio button "All PARCC Members"
    And I press "Save audience"
    Then I should see the message containing "PD Course PRC-346 All Members"
    Then I should see the message containing "course audience updated."
    And the "PARCC members ONLY" radio button should be selected
    And the "All PARCC Members" radio button should be selected

  Scenario: Members only state saves
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am viewing my "PD Course" node with the title "PD Course PRC-346 All Members"
    When I click "Course Audience"
    And I select the radio button "PARCC members ONLY"
    And I select the radio button "Select By State"
    And I select "Illinois" from "edit-by-state"
    And I press "Save audience"
    Then I should see the message containing "PD Course PRC-346 All Members"
    Then I should see the message containing "course audience updated."
    And the "PARCC members ONLY" radio button should be selected
    And the "Select By State" radio button should be selected
    # @todo: following line fails for no apparent reason
    And "Illinois" in "by-state" should be selected

  Scenario: Rostering saves
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    Given users:
      | name            | mail                               | pass   | field_first_name | field_last_name | status |
      | Joe Educator    | joe_prc_346a@timestamp@example.com | xyz123 | Joe              | Educator        | 1      |
      | Joe Contributor | joe_prc_346b@timestamp@example.com | xyz123 | Joe              | Contributor     | 1      |
    And I am viewing my "PD Course" node with the title "PD Course PRC-346 Rostering"
    Then I click "Course Audience"
    And I select the radio button "PARCC members ONLY"
    And I select the radio button "Select By Rostering"
    And I fill in "E-mail" with "joe_prc_346a@timestamp@example.com"
    When I press "Save audience"
    Then I should see the message containing "PD Course PRC-346 Rostering"
    Then I should see the message containing "course audience updated."
    And the "PARCC members ONLY" radio button should be selected
    And the "Select By Rostering" radio button should be selected
    And I should see "joe_prc_346a@timestamp@example.com" in the "E-mail" field

  Scenario: Saving content as Public; accessible to anonymous
    Given "PD Course" nodes:
      | title  | field_course_objectives | field_permissions | uid | status |
      | Public | This is public          | public            | 1   | 1      |
    And I am an anonymous user
    And I visit the last node created
    Then I should see the text "This is public"

  Scenario: Saving content as Members Only; hidden from anonymous
    Given "PD Course" nodes:
      | title        | field_course_objectives | field_permissions | uid | status |
      | Members Only | This is private         | members           | 1   | 1      |
    And I am an anonymous user
    And I cannot visit the last node created

  Scenario: Saving anonymous content as Members Only; hidden from anonymous
    Given "PD Course" nodes:
      | title        | field_course_objectives | field_permissions | uid | status |
      | Members Only | This is private         | members           | 0   | 1      |
    And I am an anonymous user
    And I cannot visit the last node created

  Scenario Outline: Saving content as Public; accessible to roles
    Given "PD Course" nodes:
      | title  | field_course_objectives | field_permissions | uid | status |
      | Public | This is public          | public            | 1   | 1      |
    And I am logged in as a user with the "<role>" role
    And I visit the last node created
    Then I should see the text "This is public"
  Examples:
    | role                            |
    | Educator                        |
    | Content Contributor             |
    | PRC Admin                       |
    | administrator                   |
    | Content Administrator (Curator) |
    | authenticated user              |

  Scenario Outline: Saving content as Members Only; hidden from role
    Given "PD Course" nodes:
      | title        | field_course_objectives | field_permissions | uid | status |
      | Members Only | This is private         | members           | 1   | 1      |
    And I am logged in as a user with the "<role>" role
    And I cannot visit the last node created
  Examples:
    | role               |
    | Educator           |
    | authenticated user |

  Scenario Outline: Saving content as Members Only - All members; hidden from role
    Given "PD Course" nodes:
      | title        | field_course_objectives | field_permissions | uid | status |
      | Members Only | This is private         | members           | 1   | 1      |
    And I am logged in as a user with the "<role>" role
    And I visit the last node created
  Examples:
    | role                            |
    | Content Contributor             |
    | Content Administrator (Curator) |
    | PRC Admin                       |
    | administrator                   |

  Scenario Outline: Saving content as Members Only - All members; hidden from role
    Given "PD Course" nodes:
      | title        | field_course_objectives | field_permissions | uid | status |
      | Members Only | This is private         | members           | 1   | 1      |
    And I am logged in as a user with the "<role>" role
    And I visit the last node created
  Examples:
    | role                            |
    | Content Contributor             |
    | Content Administrator (Curator) |
    | PRC Admin                       |
    | administrator                   |

  Scenario: Audience by state
    Given "PD Course" nodes:
      | title         | field_course_objectives | field_permissions | uid | status |
      | Illinois Only | This is private         | public            | 1   | 1      |
    Given users:
      | name         | mail                                | pass   | field_first_name | field_last_name | status |
      | Joe Illinois | joe_prc_346il@timestamp@example.com | xyz123 | Joe              | Illinois        | 1      |
      | Joe Colorado | joe_prc_346ar@timestamp@example.com | xyz123 | Joe              | Colorado        | 1      |
    And I am logged in as a user with the "PRC Admin" role
    And I am on "prc/admin/admin-users"
    Then I click "User ID"
    Then I click on the edit link for the user "Joe Illinois"
    Then I check the box "PARCC-Member Educator"
    Then I select "Illinois" from "Member State"
    And I select "Illinois" from "State Where I Teach"
    Then I press "Save"
    And I am on "prc/admin/admin-users"
    Then I click "User ID"
    Then I click on the edit link for the user "Joe Colorado"
    Then I check the box "PARCC-Member Educator"
    Then I select "Colorado" from "Member State"
    And I select "Colorado" from "State Where I Teach"
    Then I press "Save"
    Then I visit the last node created
    When I click "Course Audience"
    And I select the radio button "PARCC members ONLY"
    And I select the radio button "Select By State"
    And I select "Illinois" from "edit-by-state"
    And I press "Save audience"
    Then I click "Log out"
    Then the url should match "/"
    Then I follow "Log in"
    Then I fill in "E-mail *" with "joe_prc_346il@timestamp@example.com"
    Then I fill in "Password *" with "xyz123"
    And I press "Log in"
    When I click "Professional Learning"
    Then I should see the link "Illinois Only"
    Then I click "Log out"
    Then the url should match "/"
    Then I follow "Log in"
    Then I fill in "E-mail *" with "joe_prc_346ar@timestamp@example.com"
    Then I fill in "Password *" with "xyz123"
    And I press "Log in"
    When I click "Professional Learning"
    Then I should not see the link "Illinois Only"

  Scenario: Audience by roster
    Given "PD Course" nodes:
      | title         | field_course_objectives | field_permissions | uid | status |
      | Illinois Only | This is private         | public            | 1   | 1      |
    Given users:
      | name         | mail                                | pass   | field_first_name | field_last_name | status |
      | Joe Illinois | joe_prc_346il@timestamp@example.com | xyz123 | Joe              | Illinois        | 1      |
      | Joe Colorado | joe_prc_346ar@timestamp@example.com | xyz123 | Joe              | Colorado        | 1      |
    And I am logged in as a user with the "PRC Admin" role
    And I am on "prc/admin/admin-users"
    Then I click "User ID"
    Then I click on the edit link for the user "Joe Illinois"
    Then I check the box "PARCC-Member Educator"
    Then I select "Illinois" from "Member State"
    Then I press "Save"
    And I am on "prc/admin/admin-users"
    Then I click "User ID"
    Then I click on the edit link for the user "Joe Colorado"
    Then I check the box "PARCC-Member Educator"
    Then I select "Colorado" from "Member State"
    Then I press "Save"
    Then I visit the last node created
    When I click "Course Audience"
    And I select the radio button "PARCC members ONLY"
    And I select the radio button "Select By Rostering"
    And I fill in "E-mail" with "joe_prc_346il@timestamp@example.com"
    When I press "Save audience"
    Then I click "Log out"
    Then the url should match "/"
    Then I follow "Log in"
    Then I fill in "E-mail *" with "joe_prc_346il@timestamp@example.com"
    Then I fill in "Password *" with "xyz123"
    And I press "Log in"
    When I click "Professional Learning"
    Then I should see the link "Illinois Only"
    Then I click "Log out"
    Then the url should match "/"
    Then I follow "Log in"
    Then I fill in "E-mail *" with "joe_prc_346ar@timestamp@example.com"
    Then I fill in "Password *" with "xyz123"
    And I press "Log in"
    When I click "Professional Learning"
    Then I should not see the link "Illinois Only"

  Scenario: PRC-480 Admin: Course Audience- Course disappears after rostering audience
    Given "PD Course" nodes:
      | title         | field_course_objectives | field_permissions | uid | status |
      | PRC-480 Allow | This is private         | public            | 1   | 1      |
    Given users:
      | name       | mail                          | pass   | field_first_name | field_last_name | status |
      | Joe PRC480 | prc_480@timestamp@example.com | xyz123 | Joe              | Illinois        | 1      |
    And I am logged in as a user with the "PRC Admin" role
    And I am on "prc/admin"
    When I click "Course Management"
    Then I click "ID"
    Then I should see the text "PRC-480 Allow"
    Then I visit the last node created
    When I click "Course Audience"
    And I select the radio button "PARCC members ONLY"
    And I select the radio button "Select By Rostering"
    And I fill in "E-mail" with "prc_480@timestamp@example.com"
    When I press "Save audience"
    And I am on "prc/admin"
    Then I click "Course Management"
    Then I click "ID"
    Then I should see the text "PRC-480 Allow"

  Scenario: Multiple roster emails
    Given "PD Course" nodes:
      | title                 | field_course_objectives | field_permissions | uid | status |
      | Two Emails @timestamp | This is private         | public            | 1   | 1      |
    Given users:
      | name         | mail                                | pass   | field_first_name | field_last_name | status |
      | Joe Illinois | joe_prc_346il@timestamp@example.com | xyz123 | Joe              | Illinois        | 1      |
      | Joe Colorado | joe_prc_346ar@timestamp@example.com | xyz123 | Joe              | Colorado        | 1      |
      | Joe Rhode    | joe_prc_346ri@timestamp@example.com | xyz123 | Joe              | Rhode           | 1      |
    And I am logged in as a user with the "PRC Admin" role
    And I am on "prc/admin/admin-users"
    Then I click "User ID"
    Then I click on the edit link for the user "Joe Illinois"
    Then I check the box "PARCC-Member Educator"
    Then I select "Illinois" from "Member State"
    Then I press "Save"
    And I am on "prc/admin/admin-users"
    Then I click "User ID"
    Then I click on the edit link for the user "Joe Colorado"
    Then I check the box "PARCC-Member Educator"
    Then I select "Colorado" from "Member State"
    Then I press "Save"
    And I am on "prc/admin/admin-users"
    Then I click "User ID"
    Then I click on the edit link for the user "Joe Rhode"
    Then I check the box "PARCC-Member Educator"
    Then I select "Rhode Island" from "Member State"
    Then I press "Save"
    Then I visit the last node created
    When I click "Course Audience"
    And I select the radio button "PARCC members ONLY"
    And I select the radio button "Select By Rostering"
    And I fill in "E-mail" with "joe_prc_346il@timestamp@example.com,joe_prc_346ar@timestamp@example.com"
    When I press "Save audience"
    Then I click "Log out"
    Then the url should match "/"
    Then I follow "Log in"
    Then I fill in "E-mail *" with "joe_prc_346il@timestamp@example.com"
    Then I fill in "Password *" with "xyz123"
    And I press "Log in"
    When I click "Professional Learning"
    Then I should see the link "Two Emails @timestamp"
    Then I click "Log out"
    Then the url should match "/"
    Then I follow "Log in"
    Then I fill in "E-mail *" with "joe_prc_346ar@timestamp@example.com"
    Then I fill in "Password *" with "xyz123"
    And I press "Log in"
    When I click "Professional Learning"
    Then I should see the link "Two Emails @timestamp"
    Then I click "Log out"
    Then the url should match "/"
    Then I follow "Log in"
    Then I fill in "E-mail *" with "joe_prc_346ri@timestamp@example.com"
    Then I fill in "Password *" with "xyz123"
    And I press "Log in"
    When I click "Professional Learning"
    Then I should not see the link "Two Emails @timestamp"

  Scenario: All PARCC Members displays for PARCC-Member Educator with a state
    Given "PD Course" nodes:
      | title         | field_course_objectives | field_permissions | uid | status |
      | Illinois Only | This is private         | public            | 1   | 1      |
    Given users:
      | name         | mail                                | pass   | field_first_name | field_last_name | status |
      | Joe Illinois | joe_prc_346il@timestamp@example.com | xyz123 | Joe              | Illinois        | 1      |
      | Joe Colorado | joe_prc_346ar@timestamp@example.com | xyz123 | Joe              | Colorado        | 1      |
    And I am logged in as a user with the "PRC Admin" role
    And I am on "prc/admin/admin-users"
    Then I click "User ID"
    Then I click on the edit link for the user "Joe Illinois"
    Then I check the box "PARCC-Member Educator"
    Then I select "Illinois" from "Member State"
    And I select "Illinois" from "State Where I Teach"
    Then I press "Save"
    And I am on "prc/admin/admin-users"
    Then I click "User ID"
    Then I click on the edit link for the user "Joe Colorado"
    Then I check the box "PARCC-Member Educator"
    Then I select "Colorado" from "Member State"
    And I select "Colorado" from "State Where I Teach"
    Then I press "Save"
    Then I visit the last node created
    When I click "Course Audience"
    And I select the radio button "PARCC members ONLY"
    And I select the radio button "All PARCC Members"
    When I press "Save audience"
    Then I click "Log out"
    Then the url should match "/"
    Then I follow "Log in"
    Then I fill in "E-mail *" with "joe_prc_346il@timestamp@example.com"
    Then I fill in "Password *" with "xyz123"
    And I press "Log in"
    When I click "Professional Learning"
    Then I should see the link "Illinois Only"
    Then I click "Log out"
    Then the url should match "/"
    Then I follow "Log in"
    Then I fill in "E-mail *" with "joe_prc_346ar@timestamp@example.com"
    Then I fill in "Password *" with "xyz123"
    And I press "Log in"
    When I click "Professional Learning"
    Then I should see the link "Illinois Only"

  @javascript
  Scenario: PRC-488 All members doesn't save after another audience selected
    Given "PD Course" nodes:
      | title         | field_course_objectives | field_permissions | uid | status |
      | Illinois Only | This is private         | public            | 1   | 1      |
    And I am logged in as a user with the "PRC Admin" role
    Then I visit the last node created
    When I click "Course Audience"
    And I select the radio button "PARCC members ONLY"
    And I select the radio button "Select By State"
    And I select "Illinois" from "edit-by-state"
    When I press "Save audience"
    Then I should see the message containing "course audience updated."
    And the "PARCC members ONLY" radio button should be selected
    And the "Select By State" radio button should be selected
    Then I select the radio button "All PARCC Members"
    When I press "Save audience"
    Then I should see the message containing "course audience updated."
    And the "PARCC members ONLY" radio button should be selected
    And the "All PARCC Members" radio button should be selected
