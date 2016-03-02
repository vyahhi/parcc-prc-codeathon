@api @course
Feature: PRC-34 View Available PD Courses
  As an Educator,
  I want to view available PD Courses on the PRC website,
  so that I can select, view, and complete a PD course.

  # AC1 The Professional Development tab shall be available to the top navigation bar for all roles.
  # Tested in PRC-159, PRC-160, PRC-151, PRC-347
  Scenario: AC2 At click, it opens the Professional Development page where each user shall see the courses to which she has permission to see.
    Given "PD Course" nodes:
    | title       | field_course_objectives | field_permissions | field_length_quantity | field_length_unit | status | uid |
    | PD Course 1 | Obj1                    | public            | 1                     | week              | 1      | 1   |
    | PD Course 2 | Obj2                    | public            | 2                     | month             | 1      | 1   |
    | PD Course 3 | Obj3                    | public            | 3                     | year              | 0      | 1   |
    And I am logged in as a user with the "Educator" role
    And I am on the homepage
    When I click "Professional Learning"
    Then I should see the heading "Professional Learning" in the "sub_header" region
    And the url should match "professional-learning"
    And I should not see the text "Welcome to PRC Professional Development page. There are no courses available to your account. Please contact your school/district to benefit from PARCC Professional Development courses exported to your district learning management system."
    # AC6 The following components are displayed for each course:
    And I should see the link "PD Course 1"
    And I should see the link "PD Course 2"
    # AC4 Only the Published courses that the user has permission to shall be displayed. The layout of PD page is similar to Digital Library layout implemented in PRC-32 (specified in the following AC). Variances from Digital Library functionality are in green font.
    And I should not see the link "PD Course 3"
    # AC5 In this page, the courses are listed based on the sort definition. Default by date: the most recent on the top
    # Manually test this because the create dates are the same for the nodes created above: And "PD Course 2" should precede "PD Course 1" for the query "a"
    # Course Length (if available), such as:
    # (12-week)
    And I should see the text "(1-week)"
    And I should see the text "Course Objectives:"
    And I should see the text "Obj1"
    # Thumbnail (when available) -Can we use the 1st module image as thumbnail?
    # AC7 Social and sharing: The following icons are available and redirect the user to the selected application:
    Then I should not see an ".st_email_button" element
    Then I should not see an ".st_facebook_button" element
    Then I should not see an ".st_edmodo_button" element
    # AC8 A Sort dropdown menu allows the user to change the order. The only available option for now is: Date: most recent on the top

  Scenario: AC3 A user who has permission to no course, shall see the following generic statement:
    Given I have no "PD Course" nodes
    And I am logged in as a user with the "Educator" role
    And I am on the homepage
    When I click "Professional Learning"
    Then I should see the heading "Professional Learning" in the "sub_header" region
    And the url should match "professional-learning"
    Then I should see the text "Welcome to PRC Professional Development page. There are no courses available to your account. Please contact your school/district to benefit from PARCC Professional Development courses exported to your district learning management system."

  Scenario: PRC-468 View Available PD Courses- Sort terms on PD page not same as Digital Library
    Given "PD Course" nodes:
      | title       | field_course_objectives | field_permissions | field_length_quantity | field_length_unit | status | uid |
      | PD Course 1 | Obj1                    | public            | 1                     | week              | 1      | 1   |
      | PD Course 2 | Obj2                    | public            | 2                     | month             | 1      | 1   |
      | PD Course 3 | Obj3                    | public            | 3                     | year              | 0      | 1   |
    And I am logged in as a user with the "Educator" role
    And I am on the homepage
    When I click "Professional Learning"
    And I select "Date" from "Sort by"
    And I select "most recent on top" from "Order"
    And I select "oldest on top" from "Order"

  Scenario: PRC-519 Add a Thumbnail Image text in results
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am viewing my "PD Course" node with the title "PRC-519"
    When I click "Edit"
    Then I check the box "Published"
    Then I attach the file "testfiles/lovelythumbnail.png" to "edit-field-thumbnail-und-0-upload"
    And I select the radio button "Public"
    And I fill in "Course Objectives" with "Objectives"
    And I press "Save"
    And I should see the success message containing "PD Course PRC-519 has been updated."
    Then I click "Professional Learning"
    And I should not see the text "Add a Thumbnail Image"
    When I click "PRC-519"
    Then I should not see the text "Add a Thumbnail Image"

  Scenario: PRC-520 Add a Thumbnail Image text in results
    Given I am logged in as a user with the "Content Administrator (Curator)" role
    And I am viewing my "PD Course" node with the title "PRC-519"
    When I click "Edit"
    Then I check the box "Published"
    Then I attach the file "testfiles/lovelythumbnail.png" to "edit-field-thumbnail-und-0-upload"
    And I select the radio button "Public"
    And I fill in "Course Objectives" with "Objectives"
    And I press "Save"
    And I should see the success message containing "PD Course PRC-519 has been updated."
    Then I click "Professional Learning"
    And I should not see the text "Add a Thumbnail Image"
    But I should see an ".field-name-field-thumbnail img" element