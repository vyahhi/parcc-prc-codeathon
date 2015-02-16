@api @d7 @diglib @search
Feature: PRC-647 Deep Search: PDF Documents
  As an educator,
  I want to search for a keyword through PDF documents,
  so that I can find the specific content I'm looking for even though it’s buried inside attached documents.
#    AC1 During scheduled job run, documents' textual content is to be indexed and available for the search function
#    AC2 Restrictions on the file format include: PDF
#    AC3 When a user enters a keyword in a Search textbox, whether in the Global Search or on the Search Results page, document search results are displayed along other search results
#      Upon getting document search results, results can inherit all sort and filter functions of the search page
#    AC4 A search result with attached documents are appended with following attached document information
#      Document title
#      Link to document
#      File format

  Scenario: Attach a PDF file and search on it
    Given I have no "Digital Library Content" nodes
    And I have no "PD Course" nodes
    And I am logged in as a user with the "Content Contributor" role
    When I fill in "Quidditch" for "Search" in the "header" region
    And I press "Search" in the "header" region
    Then I should not see the text "Digital Library Content"
    And I am viewing my "Digital Library Content" node with the title "Search-text-o-rama"
    And I follow "Edit"
    Then I attach the file "testfiles/TT_Rules_2015.pdf" to "edit-field-document-und-0-upload"
    And I select the radio button "Public"
    And I press "Save"
    And I should see the success message containing "Digital Library Content Search-text-o-rama has been updated."
    Then I follow "Edit"
    And I should see the link "TT_Rules_2015.pdf"
    And I run drush "sapi-i"
    When I fill in "Abarth" for "Search" in the "header" region
    And I press "Search" in the "header" region
    Then I should see the text "Search-text-o-rama"
    And I should see the link "TT_Rules_2015.pdf"
    When I fill in "Not in the file" for "Search" in the "header" region
    And I press "Search" in the "header" region
    Then I should not see the text "Search-text-o-rama"