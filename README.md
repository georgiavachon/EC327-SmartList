// Copyright Dasha Smolina 2021 dsmolina@bu.edu
// Copyright Megan Freeman 2021 megfree@bu.edu
// Copyright Ayrton Reulet 2021 reulayrt@bu.edu
// Copyright Georgia Vachon gvachon@bu.edu

# EC327 Group 24 SmartList
Instructions on how to compile and run our program:
To compile, open terminal in this directory and run the command:

   $make smart

Then, run the program by executing the command:

   $smart

Test Cases:
To experience the full effect of our app, you may type in the test cases one at a time into the program and see your SmartList!
Otherwise, you may accelerate the process by copy and pasting one of the Test Cases below at line 361 of EC327-SmartList.cpp.

// TEST CASES

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
// Copy and paste the following code at line 361 of EC327-SmartList.cpp to test scrolling
 
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
