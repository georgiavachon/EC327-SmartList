// Copyright Dasha Smolina 2021 dsmolina@bu.edu
// Copyright Megan Freeman 2021 megfree@bu.edu
// Copyright Ayrton Reulet 2021 reulayrt@bu.edu
// Copyright Georgia Vachon gvachon@bu.edu

# EC327 Group 24 SmartList
Once you have opened the program, click on any of the textboxes at the top of the screen to begin entering your first task. 
You can only enter dates in the format ##/## and can only enter numbers 1-10 for the priority, but you can name the task whatever you would like. 
Once you have entered your task in the proper format, press the enter key or click on the “ADD” button to see your task listed below. 
Repeat this process until you have entered all of your tasks. If necessary, you can delete the last item added at any time by clicking the corresponding button at the bottom of the screen.
When you are ready to generate your smart list you can click the button in the bottom right and open the Your SmartList window. 
In this window you can click anywhere on the tasks to check them off as you complete them. You can also uncheck them if you make a mistake. 
Completed tasks will remain on the screen until the window is closed, when they will then be deleted from your list of tasks. 
When you are done with Your SmartList, close the window to return to the welcome screen where you can add to your existing list or start a new one by clicking the “Clear All” button. 

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
