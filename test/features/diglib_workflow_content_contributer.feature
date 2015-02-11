
Feature: As a Content Contributor, I need to have specific access to the Digital Library
  content that I have created so I can develop the content that I have a deep understanding [of] (PRC-629).

  Background:
  Given I am logged in as a user with the "Content Contributor" role
  And I have created Digital Library Content

  Scenario: Can View Draft when state is Draft
  When the digital library content's state is "Draft"
  Then I am able to view it

  Scenario: Can Edit Draft whens state is Draft
  When the digital library content's state is "Draft"
  Then I am able to edit it.

  Scenario: Can View Draft when state is Approval Requested
  When the digital library content's state is "Approval Requested"
  Then I am able to view it.

  Scenario: Can *not* Edit Draft when state is "Approval Requested"
  When the digital library content's state is "Approval Requested"
  Then I am not able to edit it.

  Scenario: Can View content when state is Published
  When the digital library content's state is "Published"
  Then I am able to view it.

  Scenario: Can Edit content when state is Published
  When the digital library content's state is "Published"
  Then I am able to edit it.

  Scenario: Can View content when state is Unpublished
  When the digital library content's state is "Unpublished"
  Then I am able to view it.

  Scenario: Can *not* Edit content when state is Unpublished
  When the digital library content's state is "Unpublished"
  Then I am not able to edit it.


  # Can submit something for review?

  # editing and saving creates a new revision?

