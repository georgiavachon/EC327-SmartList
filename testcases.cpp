// Copyright Dasha Smolina 2021 dsmolina@bu.edu
// Copyright Megan Freeman 2021 megfree@bu.edu
// Copyright Ayrton Reulet 2021 reulayrt@bu.edu
// Copyright Georgia Vachon gvachon@bu.edu

// TEST CASES
// to be added to README.md

// Test 1 - standard
allinput = {{"04/26","Project Report","10"},{"04/28","Project Demo","8"},{"04/28","Project Video","6"}};

// Test 2 - testing the prioritization of tasks over 5 point threshold
allinput = {{"04/26","Project Report","2"},{"04/28","Project Demo","8"},{"04/27","Project Video","7"}};

// Test 3 - testing the prioritization of tasks 2 days apart
allinput = {{"04/26","Project Report","8"},{"04/28","Project Demo","10"},{"04/27","Project Video","7"}};

// Test 4 - earliest task = lowest priority, task 2 days later = highest priority 
allinput = {{"04/26","Project Report","1"},{"04/28","Project Demo","10"},{"04/27","Project Video","3"}};

// Test 4 - testing the end of the month
allinput = {{"04/30","Project Report","2"},{"05/01","Project Demo","8"},{"05/02","Project Video","10"}};

// Test 5 - testing scrolling function
// Copy and paste the following code at line ___ of GUI.cpp to test scrolling
 
std::vector<std::vector<std::string>> allinput;

for (int i = 10; i < 30; i++) {
  std::string testdate = "";
  std::string testtask = "";
  std::string testrank = "";
  std::vector<std::string> testcombined;
  testdate = "05/" + std::to_string(i);
  testtask = "Task " + std::to_string(i-9);
  testrank = std::to_string(i%10 + 1);
  testcombined = {testdate, testtask, testrank};
  allinput.push_back(testcombined);
}
