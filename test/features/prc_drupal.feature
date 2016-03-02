@api @drupalcore @patch-1074214 @patch-2301527
Feature: Tests Drupal core functionality operating as expected.

  @filewidget @javascript @prc-1512 @prc-1513 @prc-1518
  Scenario Outline: PRC-1512 Stacked file error messages after upload button is pressed. Occurs in any node with with a file.
  field using the core general upload file widget. This is a core bug, and more details can be found at
  http://drupal.org/node/1074214.
    Given I am logged in as a user with the "<role>" role
    And I am at "<node add url>"
    When I attach the file "testfiles/test1.csv" to "<file field>"
    Then I should see the error message "The selected file test1.csv cannot be uploaded. Only files with the following extensions are allowed: <extensions>."

    When I attach the file "testfiles/test2.csv" to "<file field>"
    Then I should see the error message "The selected file test2.csv cannot be uploaded. Only files with the following extensions are allowed: <extensions>."
    But I should not see the error message "The selected file test1.csv cannot be uploaded. Only files with the following extensions are allowed: <extensions>."

    When I press the "Upload" button
    And I wait for AJAX to finish
    And I attach the file "testfiles/test1.csv" to "<file field>"
    And I wait for AJAX to finish
    And I attach the file "testfiles/test2.csv" to "<file field>"
    Then I should see the error message "The selected file test2.csv cannot be uploaded. Only files with the following extensions are allowed: <extensions>."
    But I should not see the error message "The selected file test1.csv cannot be uploaded. Only files with the following extensions are allowed: <extensions>."

  Examples:
    | role      | node add url                             | file field                     | extensions                     |
    | PRC Admin | node/add/formative-instructional-task    | files[field_file_single_und_0] | brf, doc, docx, mp4, pdf, xls, xlsx, pptx |
    | PRC Admin | node/add/speaking-and-listening-resource | files[field_file_single_und_0] | brf, doc, docx, mp4, pdf, xls, xlsx |

  @javascript @prc-1560
  Scenario Outline: Patch #1074214, comment #13 (https://www.drupal.org/node/1074214). After uploading a good file and
  and removing it, validateExtension should still work.
    Given I am logged in as a user with the "<role>" role
    And I am at "<node add url>"
    And I attach the file "testfiles/<valid file>" to "<file field>"
    And I press the "Upload" button
    And I wait for AJAX to finish
    And I press the "Remove" button
    And I wait for AJAX to finish
    When I attach the file "testfiles/<invalid file>" to "<file field>"
    And I wait for AJAX to finish
    Then I should see the error message "The selected file <invalid file> cannot be uploaded. Only files with the following extensions are allowed: <extensions>."
  Examples:
    | role      | node add url                             | valid file | file field                     | invalid file | extensions                     |
    | PRC Admin | node/add/formative-instructional-task    | test1.docx | files[field_file_single_und_0] | test1.csv    | brf, doc, docx, mp4, pdf, xls, xlsx, pptx |
    | PRC Admin | node/add/speaking-and-listening-resource | test1.docx | files[field_file_single_und_0] | test1.csv    | brf, doc, docx, mp4, pdf, xls, xlsx |
