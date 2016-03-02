@PRC-1632 @api @PRC-1757 @javascript
Feature: As a user on the site, I want breadcrumbs to always be displayed consistently so that I can orient myself within the site without confusion.

  Scenario: Breadcrumbs not on Homepage
    When I am on "homepage"
    Then I should not see "PRC" in the "sub_header" region


#  /library -> PRC >> Library
  Scenario: Breadcrumbs on Library
    When I am on "library"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Library" in the ".breadcrumb" element
    And I should not see "Library" in the ".breadcrumb a" element

#  /library/[node:title] -> PRC >> Library >> [node:title]
  Scenario: Breadcrumbs on Library Content
    Given I have no "Digital Library Content" nodes
    # Use existing Subject, Grade Level, Media Type, because these are set up on install
    And "Digital Library Content" nodes:
      | title      | body           | field_permissions | uid | status |
      | Public     | This is public | public            | 1   | 1      |
    When I am on "library/public"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Library" in the ".breadcrumb a[href='/library']" element
    And I should see "Public" in the ".breadcrumb" element
    And I should not see "Public" in the ".breadcrumb a" element

#  node/*/edit -> PRC >> Library >> [node:title] Edit
    Scenario: Breadcrumbs Library Content editing page
      Given I am logged in as a user with the "PRC Admin" role
      And I have no "Digital Library Content" nodes
    # Use existing Subject, Grade Level, Media Type, because these are set up on install
      And "Digital Library Content" nodes:
        | title      | body           | field_permissions | uid | status |
        | Public     | This is public | public            | 1   | 1      |
      And I am on "library/public"
      When I click "Edit"
      Then I should see "PRC" in the ".breadcrumb a[href='/']" element
      And I should see "Library" in the ".breadcrumb a[href='/library/']" element
      And I should see "Public Edit" in the ".breadcrumb" element
      And I should not see "Public Edit" in the ".breadcrumb a" element

#  node/*/prc_revisions -> PRC >> Library >> Revisions for [node:title]
  Scenario: Breadcrumbs Library Content Revisions page
    Given I am logged in as a user with the "PRC Admin" role
    And I have no "Digital Library Content" nodes
      # Use existing Subject, Grade Level, Media Type, because these are set up on install
    And "Digital Library Content" nodes:
      | title      | body           | field_permissions | uid | status |
      | Public     | This is public | public            | 1   | 1      |
    And I am on "library/public"
    When I click "Edit"
    And I press "Save"
    And I click "Revisions"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Library" in the ".breadcrumb a[href='/library']" element
    And I should see "Revisions for Public" in the ".breadcrumb" element
    And I should not see "Revisions for Public" in the ".breadcrumb a" element


#    /instruction -> PRC >> Instruction
  Scenario: Breadcrumbs on Instruction
    Given I am logged in as a user with the "PRC Admin" role
    When I am on "instructional-tools"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Instructional Tools" in the ".breadcrumb" element
    And I should not see "Instructional Tools" in the ".breadcrumb a" element

#    /instruction/formative-instruction-tasks -> PRC >> Instruction >> Formative Instructional Tasks
  Scenario: Breadcrumbs on Formative Instructional Tasks
    Given I am logged in as a user with the "PRC Admin" role
    When I am on "instructional-tools/formative-instructional-tasks"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Instructional Tools" in the ".breadcrumb a[href='/instructional-tools']" element
    And I should see "Formative Instructional Tasks" in the ".breadcrumb" element
    And I should not see "Formative Instructional Tasks" in the ".breadcrumb a" element

#    /node/add/formative-instructional-task?destination=instructional-tools/formative-instructional-tasks -> PRC » Instructional Tools » Formative Instructional Task » Create Formative Instructional Task
  Scenario: Breadcrumbs on Formative Instructional Tasks Creating content
    Given I am logged in as a user with the "PRC Admin" role
    When I am on "instructional-tools/formative-instructional-tasks"
    And I click "Add Resource"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Instructional Tools" in the ".breadcrumb a[href='/instructional-tools']" element
    And I should see "Formative Instructional Task" in the ".breadcrumb a[href='/instructional-tools/formative-instructional-tasks']" element
    Then I should see "Create Formative Instructional Task" in the ".breadcrumb" element
    And I should not see "Create Formative Instructional Task" in the ".breadcrumb a" element


#    /node/*/edit?destination=instruction/formative-instructional-tasks -> PRC >> Formative Instructional Task >> [node:title]
  Scenario: Breadcrumbs on Formative Instructional Tasks Edit form
    Given I am logged in as a user with the "PRC Admin" role
    And "Formative Instructional Task" nodes:
      | title               | status | uid         | field_permissions |
      | Public | 1      | @currentuid | public            |
    And I visit the first node created
    And I click "Edit"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Instructional Tools" in the ".breadcrumb a[href='/instructional-tools/']" element
    And I should see "Formative Instructional Tasks" in the ".breadcrumb a[href='/instructional-tools/formative-instructional-tasks/']" element
    And I should see "Public Edit" in the ".breadcrumb" element
    And I should not see "Public Edit" in the ".breadcrumb a" element

#    /instruction/formative-instructional-tasks/[node:title] -> PRC >> » Instruction » Formative Instructional Task >> [node:title]
  Scenario: Breadcrumbs on Formative Instructional Tasks Node View
    Given I am logged in as a user with the "PRC Admin" role
    And "Formative Instructional Task" nodes:
      | title               | status | uid         | field_permissions |
      | Public | 1      | @currentuid | public            |
    When I am on "instructional-tools/formative-instructional-tasks/public"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Instructional Tools" in the ".breadcrumb a[href='/instructional-tools']" element
    And I should see "Formative Instructional Tasks" in the ".breadcrumb a[href='/instructional-tools/formative-instructional-tasks']" element
    And I should see "Public" in the ".breadcrumb" element
    And I should not see "Public" in the ".breadcrumb a" element

#    /instruction/speaking-listening -> PRC » Instruction » Speaking and Listening
  Scenario: Breadcrumbs on Speaking and Listening
    Given I am logged in as a user with the "PRC Admin" role
    When I am on "instructional-tools/speaking-listening"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Instructional Tools" in the ".breadcrumb a[href='/instructional-tools']" element
    And I should see "Speaking and Listening" in the ".breadcrumb" element
    And I should not see "Speaking and Listening" in the ".breadcrumb a" element

#    /node/add/speaking-and-listening-resource?destination=instruction/speaking-listening -> PRC » Instruction » Speaking and Listening » Create Speaking and Listening Resource
  Scenario: Breadcrumbs on Speaking and Listening Creating Content
    Given I am logged in as a user with the "PRC Admin" role
    When I am on "instructional-tools/speaking-listening"
    And I click "Add Resource"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Instructional Tools" in the ".breadcrumb a[href='/instructional-tools']" element
    And I should see "Speaking and Listening" in the ".breadcrumb a[href='/instructional-tools/speaking-listening']" element
    Then I should see "Create Speaking and Listening Resource" in the ".breadcrumb" element
    And I should not see "Create Speaking and Listening Resource" in the ".breadcrumb a" element

#    /node/*/edit?destination=instruction/speaking-listening -> PRC » Speaking and Listening » [node:title]
  Scenario: Breadcrumbs on Speaking and Listening Edit form
    Given I am logged in as a user with the "PRC Admin" role
    And "Speaking and Listening Resource" nodes:
      | title               | status | uid         | field_permissions |
      | Public | 1      | @currentuid | public            |
    And I visit the first node created
    And I click "Edit"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Instructional Tools" in the ".breadcrumb a[href='/instructional-tools/']" element
    And I should see "Speaking and Listening" in the ".breadcrumb a[href='/instructional-tools/speaking-listening/']" element
    And I should see "Public Edit" in the ".breadcrumb" element
    And I should not see "Public Edit" in the ".breadcrumb a" element

#    /instruction/speaking-listening/[node:title] -> PRC » Instruction » Speaking and Listening » [node:title]
  Scenario: Breadcrumbs on Speaking and Listening Node View
    Given I am logged in as a user with the "PRC Admin" role
    And "Speaking and Listening Resource" nodes:
      | title               | status | uid         | field_permissions |
      | Public | 1      | @currentuid | public            |
    When I am on "instructional-tools/speaking-listening/public"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Instructional Tools" in the ".breadcrumb a[href='/instructional-tools']" element
    And I should see "Speaking and Listening" in the ".breadcrumb a[href='/instructional-tools/speaking-listening']" element
    And I should see "Public" in the ".breadcrumb" element
    And I should not see "Public" in the ".breadcrumb a" element


#    /assessments -> PRC >> Assessment
  Scenario: Breadcrumbs on Assessment
    When I am on "assessments/practice-assessments"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Assessment" in the ".breadcrumb" element
    And I should not see "Assessment" in the ".breadcrumb a" element

#    /assessments/[node:title] -> PRC >> Assessment >> [node:title]
  Scenario: Breadcrumbs on Assessment page
    Given I am logged in as a user with the "PRC Admin" role
    And "Grade Level" terms:
      | name          |
      | Middle School |
    And "Assessment" nodes:
      | title                      | body   | field_grade_level_unlimited | field_subject                | field_quiz_type   | uid         |
      | PRC-1632 | Body 1 | Middle School     | Educational Leadership, Math | Custom Assessment | @currentuid |
    When I am on "assessments/PRC-1632"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Assessment" in the ".breadcrumb a[href='/assessments']" element
    And I should see "PRC-1632" in the ".breadcrumb" element
    And I should not see "PRC-1632" in the ".breadcrumb a" element

#    node/*/edit -> PRC >> Assessment >> [node:title] Edit
  Scenario: Breadcrumbs on Assessment Detail Page Edit
    Given I am logged in as a user with the "PRC Admin" role
    And "Grade Level" terms:
      | name          |
      | Middle School |
    And "Assessment" nodes:
      | title                      | body   | field_grade_level_unlimited | field_subject                | field_quiz_type   | uid         |
      | PRC-1632 | Body 1 | Middle School     | Educational Leadership, Math | Custom Assessment | @currentuid |
    When I am on "assessments/PRC-1632"
    And I click "Edit"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Assessment" in the ".breadcrumb a[href='/assessments/']" element
    And I should see "PRC-1632 Edit" in the ".breadcrumb" element
    And I should not see "PRC-1632 Edit" in the ".breadcrumb a" element

#    node/add/quiz -> PRC » Assessment » Item Bank » Create Assessment
  Scenario: Breadcrumbs on Create Assessment page
    When I am logged in as a user with the "PRC Admin" role
    And I am on "node/add/quiz"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Assessment" in the ".breadcrumb a[href='/assessments']" element
    And I should see "Create Assessment" in the ".breadcrumb" element
    And I should not see "Create Assessment" in the ".breadcrumb a" element

#    assessments/item-bank -> PRC » Assessment » Item Bank
  Scenario: Breadcrumbs on Item Bank Page
    When I am on "assessments/item-bank"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Assessment" in the ".breadcrumb a[href='/assessments']" element
    And I should see "Item Bank" in the ".breadcrumb" element
    And I should not see "Item Bank" in the ".breadcrumb a" element

#    /node/add/quiz-directions?destination=assessments/item-bank -> PRC » Assessment » Item Bank » Create Non-interactive Item (text only)
  Scenario: Breadcrumbs on Create Non-interactive Item (text only) in the Item Bank
    When I am logged in as a user with the "PRC Admin" role
    And I am on "/node/add/quiz-directions?destination=assessments/item-bank"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Assessment" in the ".breadcrumb a[href='/assessments']" element
    And I should see "Item Bank" in the ".breadcrumb a[href='/assessments/item-bank']" element
    And I should see "Create Non-interactive Item (text only)" in the ".breadcrumb" element
    And I should not see "Create Non-interactive Item (text only)" in the ".breadcrumb a" element

#TODO:Make this a Scenario Outline for the 3 question types
      #    /node/*/edit?destination=assessments/item-bank -> PRC » Assessment » [node:title]
        Scenario: Breadcrumbs on Create Non-interactive Item (text only) Edit form
          Given I am logged in as a user with the "PRC Admin" role
          And I am on "assessments/item-bank"
          And I click "Non-interactive (text only)"
          Then I fill in "Title" with "This One"
          And I fill in "Question" with "Why is it this way?"
          And I press "Save"
          When I am on "assessments/item-bank"
          And I click on the element with css selector ".views-field-edit-node a"
          Then I should see "PRC" in the ".breadcrumb a[href='/']" element
          And I should see "Assessment" in the ".breadcrumb a[href='/assessments/']" element
          And I should see "Item Bank" in the ".breadcrumb a[href='/assessments/item-bank/']" element
          And I should see "This One" in the ".breadcrumb" element
          And I should not see "This One Edit" in the ".breadcrumb a" element

#    assessments/item-bank/[node:title] -> PRC » Assessment » Item Bank » [node:title]
  Scenario: Breadcrumbs on Create Non-interactive Item (text only) Form View
    Given I am logged in as a user with the "PRC Admin" role
    And I am on "assessments/item-bank"
    And I click "Non-interactive (text only)"
    Then I fill in "Title" with "This One"
    And I fill in "Question" with "Why is it this way?"
    And I press "Save"
    When I am on "assessments/item-bank"
    And I click on the element with css selector ".views-field-edit-node a"
    Then I click "View"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Assessment" in the ".breadcrumb a[href='/assessments']" element
    And I should see "Item Bank" in the ".breadcrumb a[href='/assessments/item-bank']" element
    And I should see "This One" in the ".breadcrumb" element
    And I should not see "This One Edit" in the ".breadcrumb a" element

#    /node/add/multichoice?destination=assessments/item-bank -> PRC » Assessment » Item Bank » Create Interactive Choice Item
  Scenario: Breadcrumbs on Create Interactive Choice Item in the Item Bank
    When I am logged in as a user with the "PRC Admin" role
    And I am on "/node/add/multichoice?destination=assessments/item-bank"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Assessment" in the ".breadcrumb a[href='/assessments']" element
    And I should see "Item Bank" in the ".breadcrumb a[href='/assessments/item-bank']" element
    And I should see "Create Interactive Choice Item" in the ".breadcrumb" element
    And I should not see "Create Interactive Choice Item" in the ".breadcrumb a" element

#    /assessments/item-bank/multichoice/[node:title] -> PRC » Assessment » Item Bank » [node:title]
  Scenario: Breadcrumbs on Interactive Choice Item Form View
    Given I am logged in as a user with the "PRC Admin" role
    And I am on "assessments/item-bank"
    And I click "Interactive choice"
    And I fill in "Item Title" with "Multi Test"
    And I fill in "Question (Item Stem)" with "Stem 1"
    And I select "Common Core English Language Arts" from "edit-field-standard-und-0-tid-select-1"
    And I fill in "edit-alternatives-0-answer-value" with "One"
    And I fill in "edit-alternatives-1-answer-value" with "Two"
    And I check the box "edit-alternatives-1-correct"
    And I check the box "Pre-K"
    And I press "Save"
    When I am on "assessments/item-bank"
    And I click on the element with css selector ".views-field-edit-node a"
    Then I click "View"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Assessment" in the ".breadcrumb a[href='/assessments']" element
    And I should see "Item Bank" in the ".breadcrumb a[href='/assessments/item-bank']" element
    And I should see "Multi Test" in the ".breadcrumb" element
    And I should not see "Multi Test" in the ".breadcrumb a" element

#    /node/add/short-answer?destination=assessments/item-bank -> PRC » Assessment » Item Bank » Create Short Answer Item
  Scenario: Breadcrumbs on Create Short Answer in the Item Bank
    When I am logged in as a user with the "PRC Admin" role
    And I am on "/node/add/short-answer?destination=assessments/item-bank"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Assessment" in the ".breadcrumb a[href='/assessments']" element
    And I should see "Item Bank" in the ".breadcrumb a[href='/assessments/item-bank']" element
    And I should see "Create Short Answer Item" in the ".breadcrumb" element
    And I should not see "Create Short Answer Item" in the ".breadcrumb a" element

#    /assessments/item-bank/short-answer/[node:title] -> PRC » Assessment » Item Bank » [node:title]
  Scenario: Breadcrumbs on Short Answer Edit form
    Given I am logged in as a user with the "PRC Admin" role
    And I am on "assessments/item-bank"
    And I am on "assessments/item-bank"
    And I click "Short answer"
    And I fill in "Title" with "Short Answer Test"
    And I fill in "Question" with "Stem 1"
    And I fill in "Correct answer" with "Correct"
    And I select "Common Core English Language Arts" from "edit-field-standard-und-0-tid-select-1"
    And I check the box "Pre-K"
    And I press "Save"
    When I am on "assessments/item-bank"
    And I click on the element with css selector ".views-field-edit-node a"
    And I click "View"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Assessment" in the ".breadcrumb a[href='/assessments']" element
    And I should see "Item Bank" in the ".breadcrumb a[href='/assessments/item-bank']" element
    And I should see "Short Answer Test" in the ".breadcrumb" element
    And I should not see "Short Answer Test" in the ".breadcrumb a" element


#    /@TRT
#    /@/assessments/technology-readiness -> PRC >> Assessment >> Technology Readiness
#    /@/assessments/technology-readiness/system-check -> PRC >> Assessment >> Technology Readiness >> System Check

#    /professional-learning -> PRC >> Professional Learning
  Scenario: Breadcrumbs on Professional Learning
    When I am on "professional-learning"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Professional Learning" in the ".breadcrumb" element
    And I should not see "Professional Learning" in the ".breadcrumb a" element

#    /professional-learning/[node:title] -> PRC >> Professional Learning >> [node:title]
  Scenario: Breadcrumbs on Professional Learning Course Page
    Given I am logged in as a user with the "PRC Admin" role
    And I have no "PD Course" nodes
    And "PD Course" nodes:
      | title      | body           | field_permissions | uid | status |
      | PRC-1632     | This is public | public            | 1   | 1      |
    When I am on "professional-learning"
    And I click "PRC-1632"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Professional Learning" in the ".breadcrumb a[href='/professional-learning']" element
    And I should see "PRC-1632"
    And I should not see "PRC-1632" in the ".breadcrumb a" element

#  /node/*/courseaudience -> PRC >> Professional Learning >> [node:title]
  Scenario: Breadcrumbs on Professional Learning Course Audience Page
    Given I am logged in as a user with the "PRC Admin" role
    And I have no "PD Course" nodes
    And "PD Course" nodes:
      | title      | body           | field_permissions | uid | status |
      | PRC-1632     | This is public | public            | 1   | 1      |
    When I am on "professional-learning"
    And I click "PRC-1632"
    And I click "Course Audience"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Professional Learning" in the ".breadcrumb a[href='/professional-learning']" element
    And I should see "'PRC-1632' Course Audience"
    And I should not see "'PRC-1632' Course Audience" in the ".breadcrumb a" element

#  /node/*/course-outline -> PRC >> Professional Learning >> [node:title]
  Scenario: Breadcrumbs on Professional Learning Course Outline Page
    Given I am logged in as a user with the "PRC Admin" role
    And I have no "PD Course" nodes
    And "PD Course" nodes:
      | title      | body           | field_permissions | uid | status |
      | PRC-1632     | This is public | public            | 1   | 1      |
    When I am on "professional-learning"
    And I click "PRC-1632"
    And I click "Course outline"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Professional Learning" in the ".breadcrumb a[href='/professional-learning']" element
    And I should see "PRC-1632"
    And I should not see "PRC-1632" in the ".breadcrumb a" element

#  /node/*/course-enrollments -> PRC >> Professional Learning
  Scenario: Breadcrumbs on Professional Learning Course Enrollment Page
    Given I am logged in as a user with the "PRC Admin" role
    And I have no "PD Course" nodes
    And "PD Course" nodes:
      | title      | body           | field_permissions | uid | status |
      | PRC-1632     | This is public | public            | 1   | 1      |
    When I am on "professional-learning"
    And I click "PRC-1632"
    And I click "Enrollments"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Professional Learning" in the ".breadcrumb a[href='/professional-learning/']" element
    And I should see "PRC-1632"
    And I should not see "PRC-1632" in the ".breadcrumb a" element

#  /node/*/course-enrollments/lists -> PRC >> Professional Learning
  Scenario: Breadcrumbs on Professional Learning Course Enrollment Page, Edit Enrollment tab
    Given I am logged in as a user with the "PRC Admin" role
    And I have no "PD Course" nodes
    And "PD Course" nodes:
      | title      | body           | field_permissions | uid | status |
      | PRC-1632     | This is public | public            | 1   | 1      |
    When I am on "professional-learning"
    And I click "PRC-1632"
    And I click "Enrollments"
    And I click on the element with css selector "#edit-actioncourse-edit-enrollment-action"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Professional Learning" in the ".breadcrumb a[href='/professional-learning']" element
    And I should see "PRC-1632"
    And I should not see "PRC-1632" in the ".breadcrumb a" element

    #  /node/*/course-enrollments/search-add -> PRC >> Professional Learning
  Scenario: Breadcrumbs on Professional Learning Course Enrollment Page, Search and Enroll tab
    Given I am logged in as a user with the "PRC Admin" role
    And I have no "PD Course" nodes
    And "PD Course" nodes:
      | title      | body           | field_permissions | uid | status |
      | PRC-1632     | This is public | public            | 1   | 1      |
    When I am on "professional-learning"
    And I click "PRC-1632"
    And I click "Enrollments"
    And I click "Search and Enroll"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Professional Learning" in the ".breadcrumb a[href='/professional-learning']" element
    And I should see "PRC-1632"
    And I should not see "PRC-1632" in the ".breadcrumb a" element

#  /node/*/course-reports -> PRC >> Professional Learning >> [node:title]
  Scenario: Breadcrumbs on Professional Learning Course Reporting Page
    Given I am logged in as a user with the "PRC Admin" role
    And I have no "PD Course" nodes
    And "PD Course" nodes:
      | title      | body           | field_permissions | uid | status |
      | PRC-1632     | This is public | public            | 1   | 1      |
    When I am on "professional-learning"
    And I click "PRC-1632"
    And I click "Reporting"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Professional Learning" in the ".breadcrumb a[href='/professional-learning']" element
    And I should see "PRC-1632"
    And I should not see "PRC-1632" in the ".breadcrumb a" element

#  /node/*/course-reports/objects -> PRC >> Professional Learning >> [node:title]
  Scenario: Breadcrumbs on Professional Learning Course Reporting Page
    Given I am logged in as a user with the "PRC Admin" role
    And I have no "PD Course" nodes
    And "PD Course" nodes:
      | title      | body           | field_permissions | uid | status |
      | PRC-1632     | This is public | public            | 1   | 1      |
    When I am on "professional-learning"
    And I click "PRC-1632"
    And I click "Reporting"
    And I click "Course objects"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Professional Learning" in the ".breadcrumb a[href='/professional-learning']" element
    And I should see "PRC-1632"
    And I should not see "PRC-1632" in the ".breadcrumb a" element

#    node/*/edit -> PRC >> [node:content-type] >> [node:title]
  Scenario: Breadcrumbs Course editing page from Course page
    Given I am logged in as a user with the "PRC Admin" role
    And I have no "PD Course" nodes
  # Use existing Subject, Grade Level, Media Type, because these are set up on install
    And "PD Course" nodes:
      | title      | body           | field_permissions | uid | status |
      | PRC-1632     | This is public | public            | 1   | 1      |
    And I am on "professional-learning"
    And I click "PRC-1632"
    When I click "Edit"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Professional Learning" in the ".breadcrumb a[href='/professional-learning/']" element
    And I should see "PRC-1632 Edit" in the ".breadcrumb" element
    And I should not see "PRC-1632 Edit" in the ".breadcrumb a" element



#    /prc/admin -> PRC >> Admin
  Scenario: Breadcrumbs on the PRC Admin Top Level Page
    Given I am logged in as a user with the "PRC Admin" role
    When I am on "prc/admin"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Admin" in the ".breadcrumb" element
    And I should not see "Admin" in the ".breadcrumb a" element

#    /prc/admin/admin-content -> PRC >> Admin >> PRC Website Content
  Scenario: Breadcrumbs on PRC Website Content Page
    Given I am logged in as a user with the "PRC Admin" role
    When I am on "prc/admin/admin-content"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Admin" in the ".breadcrumb a[href='/prc/admin']" element
    And I should see "PRC Website Content" in the ".breadcrumb" element
    And I should not see "PRC Website Content" in the ".breadcrumb a" element

#    /node/add/digital-library-content -> PRC >> Admin >> Digital Library Content » Create Digital Library Content
  Scenario: Breadcrumbs on Admin Create Digital Library Content Page
    Given I am logged in as a user with the "PRC Admin" role
    And I am on "prc/admin/admin-content"
    When I click "Add content"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Admin" in the ".breadcrumb a[href='/prc/admin']" element
    And I should see "PRC Website Content" in the ".breadcrumb a[href='/prc/admin/admin-content']" element
    And I should see "Create Digital Library Content" in the ".breadcrumb" element
    And I should not see "Create Digital Library Content" in the ".breadcrumb a" element

#    node/*/revisions/*/edit?destination=prc/admin/admin-content -> PRC >> Digital Library Content » [node:title]
  Scenario: Breadcrumbs on Admin Create Digital Library Content Edit a Revision Page
    Given I am logged in as a user with the "PRC Admin" role
    And "Digital Library Content" nodes:
      | title     | body            | uid         | created    | field_permissions |
      | PRC-1632       | One@timestamp   | @currentuid | 1410000100 | public       |
    And I am on "prc/admin/admin-content"
    When I click "edit" in the "PRC-1632" row
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Admin" in the ".breadcrumb a[href='/prc/admin']" element
    And I should see "PRC Website Content" in the ".breadcrumb a[href='/prc/admin/admin-content']" element
    And I should see "PRC-1632" in the ".breadcrumb a[href='/library/prc-1632']" element
    And I should see "Edit an earlier revision" in the ".breadcrumb" element
    And I should not see "Edit an earlier revision" in the ".breadcrumb a" element

#    /node/*/revisions/*/view
  Scenario: Breadcrumbs on Admin Create Digital Library Content View a Revision Page
    Given I am logged in as a user with the "PRC Admin" role
    And "Digital Library Content" nodes:
      | title     | body            | uid         | created    | field_permissions |
      | PRC-1632       | One@timestamp   | @currentuid | 1410000100 | public       |
    And I am on "prc/admin/admin-content"
    And I click "edit" in the "PRC-1632" row
    And I press "Save"
    Then I click "edit" in the "PRC-1632" row
    When I follow "View Revision"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Admin" in the ".breadcrumb a[href='/prc/admin/']" element
    And I should see "PRC Website Content" in the ".breadcrumb a[href='/prc/admin/admin-content']" element
    And I should see "PRC-1632" in the ".breadcrumb" element
    And I should not see "PRC-1632" in the ".breadcrumb a" element


#    /prc/admin/admin-course -> PRC » Admin » PRC Courses
  Scenario: Breadcrumbs on Admin PRC Courses Page
    Given I am logged in as a user with the "PRC Admin" role
    When I am on "prc/admin/admin-course"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Admin" in the ".breadcrumb a[href='/prc/admin']" element
    And I should see "PRC Courses" in the ".breadcrumb" element
    And I should not see "PRC Courses" in the ".breadcrumb a" element

#    /node/add/pd-course -> PRC » Admin » Course Management » Create Course
  Scenario: Breadcrumbs on Admin Create Digital Library Content Page
    Given I am logged in as a user with the "PRC Admin" role
    And I am on "prc/admin/admin-course"
    When I click "Add course"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Admin" in the ".breadcrumb a[href='/prc/admin']" element
    And I should see "Course Management" in the ".breadcrumb a[href='/prc/admin/admin-course']" element
    And I should see "Create Course" in the ".breadcrumb" element
    And I should not see "Create Course" in the ".breadcrumb a" element

#    /node/*/edit?destination=prc/admin/admin-course -> PRC >> Admin >> PRC Courses >> [node:title] Edit
  Scenario: Breadcrumbs Course editing page
    Given I am logged in as a user with the "PRC Admin" role
    And I have no "PD Course" nodes
   # Use existing Subject, Grade Level, Media Type, because these are set up on install
    And "PD Course" nodes:
      | title      | body           | field_permissions | uid | status |
      | PRC-1632     | This is public | public            | 1   | 1      |
    And I am on "prc/admin/admin-course"
    And I click "Edit" in the "PRC-1632" row
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Admin" in the ".breadcrumb a[href='/prc/admin/']" element
    And I should see "PRC Courses" in the ".breadcrumb a[href='/prc/admin/admin-course']" element
    And I should see "PRC-1632 Edit" in the ".breadcrumb" element
    And I should not see "PRC-1632 Edit" in the ".breadcrumb a" element

#    /prc/admin/admin-users -> PRC » Admin » PRC Website Users
  Scenario: Breadcrumbs on PRC Users Page
    Given I am logged in as a user with the "PRC Admin" role
    When I am on "prc/admin/admin-users"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Admin" in the ".breadcrumb a[href='/prc/admin']" element
    And I should see "Users" in the ".breadcrumb" element
    And I should not see "Users" in the ".breadcrumb a" element

#    /invite/add/invite_by_email -> PRC » Admin » PRC Website Users » Invite New PRC Website User
  Scenario: Breadcrumbs on Invite New PRC Website User
    Given I am logged in as a user with the "PRC Admin" role
    And I am on "prc/admin/admin-users"
    When I click "Invite New User"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Admin" in the ".breadcrumb a[href='/prc/admin']" element
    And I should see "PRC Website Users" in the ".breadcrumb a[href='/prc/admin/admin-users']" element
    And I should see "Invite New PRC Website User" in the ".breadcrumb" element
    And I should not see "Invite New PRC Website User" in the ".breadcrumb a" element

#  assessments/parcc-released-items -> PRC >> Assessment >> PARCC Released Items
   Scenario: Breadcrumbs on PARCC Released Items Page
     When I am on "assessments/parcc-released-items"
     Then I should see "PRC" in the ".breadcrumb a[href='/']" element
     And I should see "Assessment" in the ".breadcrumb a[href='/assessments']" element
     And I should see "PARCC Released Items" in the ".breadcrumb" element
     And I should not see "PARCC Released Items" in the ".breadcrumb a" element

#  /node/add/parcc-released-item?destination=assessments/parcc-released-items -> PRC >> Assessment >> PARCC Released Items >> Create PARCC Released Items
  Scenario: Breadcrumbs on PARCC Released Items Creating content
    Given I am logged in as a user with the "PRC Admin" role
    When I am on "assessments/parcc-released-items"
    And I click "Add Resource"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Assessment" in the ".breadcrumb a[href='/assessments']" element
    And I should see "PARCC Released Items" in the ".breadcrumb a[href='/assessments/parcc-released-items']" element
    Then I should see "Create PARCC Released Item" in the ".breadcrumb" element
    And I should not see "Create PARCC Released Item" in the ".breadcrumb a" element

#  node/*/edit?destination=assessments/parcc-released-items -> PRC >> Assessment >> PARCC Released Items >> [node:title] Edit
  Scenario: Breadcrumbs on PARCC Released Items on Edit content
    Given I am logged in as a user with the "PRC Admin" role
    And I have no "PARCC Released Item" nodes
    And parcc-released-item content:
      | resource name       | file                          | resource type | faux standard | faux subject | grade level | permissions  |
      | PRC-1757 | testfiles/GreatLakesWater.pdf | Item Set | Standard One      | Subject One      | 1st Grade   | public                 |
    And I am on "assessments/parcc-released-items"
    When I click on the element with css selector ".page-assessments-parcc-released-items .views-field-edit-node a"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Assessment" in the ".breadcrumb a[href='/assessments/']" element
    And I should see "PARCC Released Items" in the ".breadcrumb a[href='/assessments/parcc-released-items/']" element
    And I should see "PRC-1757 Edit" in the ".breadcrumb" element
    And I should not see "PRC-1757 Edit" in the ".breadcrumb a" element

#  assessments/parcc-released-items/[node:title} -> PRC >> Assessment >> PARCC Released Items >> [node:title]
  Scenario: Breadcrumbs on PARCC Released Items on Edit content
    Given I am logged in as a user with the "PRC Admin" role
    And I have no "PARCC Released Item" nodes
    And parcc-released-item content:
      | resource name       | file                          | resource type | faux standard | faux subject | grade level | permissions |
      | PRC-1757 | testfiles/GreatLakesWater.pdf | Item Set | Standard One      | Subject One      | 1st Grade   | public               |
    When I am on "assessments/parcc-released-items/prc-1757"
    Then I should see "PRC" in the ".breadcrumb a[href='/']" element
    And I should see "Assessment" in the ".breadcrumb a[href='/assessments']" element
    And I should see "PARCC Released Items" in the ".breadcrumb a[href='/assessments/parcc-released-items']" element
    And I should see "PRC-1757" in the ".breadcrumb" element
    And I should not see "PRC-1757" in the ".breadcrumb a" element