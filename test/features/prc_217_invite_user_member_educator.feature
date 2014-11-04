@api
Feature: PRC-217  Invite User with Additional Role Selection
  As a PRC Admin,
  I want to specify the user's state when I invite a state lead as Content Contributor role,
  so that the system can offer additional functionality using this new attribute.

#  Acceptance Criteria
#  PARCC-Member Educator exists (new role in addition of the current Educator ).

  Scenario: PARCC-Member Educator exists
    Given I am logged in as a user with the "PARCC-Member Educator" role

  Scenario:  The role Content Author shall be renamed to Content Contributor.
    Given I am logged in as a user with the "Content Contributor" role

#  In the Invite User page, the Role options will display the new role (PARCC-Member Educator) and role name (Content Contributor instead of Content Author). The new list of Role options shall be:
#  Educator
#  PARCC-Member Educator
#  Content Contributor
#  PRC Admin
#  Role is a required field.
#  Only one of the role radio buttons can be selected.
#  When Content Contributor or PARCC-member Educator role is selected in the Invite User page, a new attribute State appears with a dropdown menu. The State field is invisible when PRC Admin or Educator role is selected.
#  The State dropdown menu contains the following options (notice they're in alphabetical order):
#  Select a state (default- keeps (or resets value to: NULL)
#  Arkansas
#  Colorado
#  District of Columbia
#  Illinois
#  Louisiana
#  Maryland
#  Massachusetts
#  Mississippi
#  New Jersey
#  New Mexico
#  New York
#  Ohio
#  Rhode Island
#  The State field is optional. One or no option can be selected.
#  The email sending shall be the same as implemented currently