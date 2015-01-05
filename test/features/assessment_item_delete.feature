@api @assessment
Feature: PRC-528 Delete Item in Test Customization
  As an educator,
  I want to remove an item from a test,
  so that it fits my classroom needs.

  Acceptance Criteria
  In the _Assessment Details page where items are displayed (implemented in PRC-490), in addition to the edit functionality, removing an item from the assessment shall be also available. Note that a user cannot modify the original PARCC Released Tests. They can however create a duplicate where their changes are stored as a new user-created test.
  AC1 Provide a link or button to each of the displayed items for the user to remove an item from the assessment. At click, the system shall remove that item from the list of items displayed (not saved yet).
  AC2 The Save Draft functionality is the same as described in PRC-525, AC copied below:
  If the original test is a PARCC Released Test: The system prompts the user to provide a new test name, labeled as New Quiz Title --Required, String(255)
  If the original test is a user-created test, the system prompts the user to define whether to create a new test, or to override the existing one. For the former, the system prompts the user to provide a new test name, labeled as New Quiz Title --Required, String(255)
  AC3 For the New Quiz Title textbox, populate the original test name concatenated with -copy (example below)
  Algebra Grade 8 - copy
  AC4 Once above information is provided, the system stores the changes associated to that user as the new or existing user-created quiz.
  AC5 If a user navigates away from the page without saving the changes, the system prompts the user to confirm.
  AC6 Permissions: All the above features are available to all roles, except for anonymous users (separated anonymous users into PRC-526)
  AC7 A user cannot save draft of a test with no item. At least, one item should remain in the quiz before it is saved.