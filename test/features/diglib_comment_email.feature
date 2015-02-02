@api @diglib @comment
Feature: PRC-58 End User Comments to Content
  As an educator, I want to send a comment to the content contributor, so that future posts can be enhanced based on end users' feedback.
  BACKGROUND: In December workshops, the stakeholders agreed upon not allowing end users to post comments visible to the public; instead, to send a comment to the author. Instead of a direct email, it was decided to use a form to capture the user's comments.
  Acceptance Criteria
#  AC1 In the Digital Library page that content is displayed, by the Add to My Lists link/icon, a link Comment shall be available to the user.
#  AC2 At click, it opens a new form with the following specifications.
#    Form Title: _Send Comment to the Content Contributor
#    Instructions: (to be added)
#    Comment
#    A Submit button allows the user to submit the Form.
#  AC3 The following attributes are captured at each comment form:
#    Content ID
#    Content Title (not for storing, but to displaying when sending/displaying comment
#    Comment
#    User ID of the individual who provided the comment
#    Comment timestamp
#  AC4 Once submitted, the system sends an email to the following distribution list
#    User who created the content
#    User who updated the content (if all not available, the last one)
#    Curator(s): All users with Curator role
#    PRC Admin(s): All users with PRC Admin role
#  AC5 The email Subject shall be: User's Comment to Content '<Content Title>' (Added on 12/31/2014)
#  AC6 The email body shall contain the following information (Added on 12/31/2014):
#    A text such as: A user commented on a content you provided (or updated).
#    Content ID
#    Content Title
#    Comment Timestamp
#    User First Name + Last Name + Email Address
#    Comment
#    A user commented on a content you provided (or updated).
#    Content: 'Frozen' (123)
#    Comment Date: Friday, January 30, 2015 - 18:57
#    Comment By: John Smith (johnsmith@email.com)
#    Comment: 'This is by far the best article I have ever read. Thank you for sharing it in PRC!'
#  AC7 This feature is available to all authenticated users.
#  AC8 No messaging will be handled in the system. Reply to the feedback happens outside of the PRC system. The author/admin will use the provided email address in their own email system (outlook).

  Scenario Outline: Comment link
    Given I am logged in as a user with the "Content Contributor" role
    And I am viewing my "Digital Library Content" node with the title "PRC-58 Comment"
    Then I am logged in as a user with the "<role>" role
    And I visit the last node created
    Then I should see the link "Comment"

    Examples:
      | role                            |
      | Educator                        |
      | Content Contributor             |
      | PRC Admin                       |
      | Content Administrator (Curator) |
      | authenticated user              |

  Scenario: Comment link not available to anonymous users
    Given I am an anonymous user
    And I am viewing a "Digital Library Content" node with the title "No Anonymous!"
    Then I should not see the link "Comment"

  Scenario: Comment form
    Given users:
      | name                       | mail                                | pass   | field_first_name | field_last_name | status | roles                           |
      | Joe Educator @timestamp    | joe_1prc_58ed@timestamp@example.com | xyz123 | Joe              | Educator        | 1      | Educator                        |
      | Joe Contributor @timestamp | joe_1prc_58cc@timestamp@example.com | xyz123 | Joe              | Contributor     | 1      | Content Contributor             |
      | Joe Curator @timestamp     | joe_1prc_58ca@timestamp@example.com | xyz123 | Joe              | Curator         | 1      | Content Administrator (Curator) |
      | Joe Admin @timestamp       | joe_1prc_58ad@timestamp@example.com | xyz123 | Joe              | Admin           | 1      | PRC Admin                       |
    And I am logged in as "Joe Contributor @timestamp"
    And I am viewing my "Digital Library Content" node with the title "PRC-58 Comment"
    And I am logged in as "Joe Educator @timestamp"
    And I visit the last node created
    When I follow "Comment"
    Then I should see the text "Send Comment to the Content Contributor"
    And I should see the text "Instructions"
    And I fill in "Comment" with "PRC-58 @timestamp"
    And I press "Submit"
    Then I should see the text "PRC-58 Comment"
    Then the email to "joe_1prc_58cc@timestamp@example.com" should contain "Comment: 'PRC-58 @timestamp'"
    And the email should contain "A user commented on a content you provided (or updated)."
    And the email should contain "Content: 'PRC-58 Comment' ("
    And the email should contain "Comment Date:"
    And the email should contain "Comment By: Joe Educator (joe_1prc_58ed@timestamp@example.com)"
    And the email should contain "User's Comment to Content 'PRC-58 Comment'"

    Then the email to "joe_1prc_58ca@timestamp@example.com" should contain "Comment: 'PRC-58 @timestamp'"
    Then the email to "joe_1prc_58ad@timestamp@example.com" should contain "Comment: 'PRC-58 @timestamp'"
