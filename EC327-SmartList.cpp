// Copyright Megan Freeman 2021 megfree@bu.edu
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Algorithm.h"
using std::vector;
using std::cin;
using std::cout;
using std::atoi;
using std::string;
using std::to_string;



int main() {
  // creating window
  sf::RenderWindow window(sf::VideoMode(1500, 1000), "SmartList");
  window.setFramerateLimit(10);
  // setting view to scale for DPI
  sf::View view(sf::FloatRect(0, 0, 1500, 1000));
  view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
  window.setView(view);

  // creating app elements
  sf::RectangleShape background;
  background.setSize(sf::Vector2f(1500, 1000));
  background.setFillColor(sf::Color::White);

  sf::RectangleShape topbanner;
  topbanner.setSize(sf::Vector2f(1500, 60));
  topbanner.setFillColor(sf::Color(102, 178, 255, 255));

  sf::RectangleShape hidescroll;
  hidescroll.setSize(sf::Vector2f(1500, 300));
  hidescroll.setFillColor(sf::Color::White);

  sf::RectangleShape hidescroll2;
  hidescroll2.setSize(sf::Vector2f(1500, 110));
  hidescroll2.setFillColor(sf::Color::White);
  hidescroll2.setPosition(0, 890);

  sf::RectangleShape datebox;
  datebox.setSize(sf::Vector2f(300, 30));
  datebox.setOutlineColor(sf::Color::Black);
  datebox.setFillColor(sf::Color(246, 246, 246, 255));

  sf::RectangleShape taskbox;
  taskbox.setSize(sf::Vector2f(300, 30));
  taskbox.setOutlineColor(sf::Color::Black);
  taskbox.setFillColor(sf::Color(246, 246, 246, 255));

  sf::RectangleShape rankbox;
  rankbox.setSize(sf::Vector2f(300, 30));
  rankbox.setOutlineColor(sf::Color::Black);
  rankbox.setFillColor(sf::Color(246, 246, 246, 255));

  sf::RectangleShape add;
  add.setSize(sf::Vector2f(150, 50));
  add.setOutlineColor(sf::Color::Black);
  add.setFillColor(sf::Color(102, 178, 255, 255));

  sf::RectangleShape deletebutton;
  deletebutton.setSize(sf::Vector2f(250, 50));
  deletebutton.setOutlineColor(sf::Color::Black);
  deletebutton.setFillColor(sf::Color(102, 178, 255, 255));

  sf::RectangleShape clearbutton;
  clearbutton.setSize(sf::Vector2f(150, 50));
  clearbutton.setOutlineColor(sf::Color::Black);
  clearbutton.setFillColor(sf::Color(102, 178, 255, 255));

  sf::RectangleShape genbutton;
  genbutton.setSize(sf::Vector2f(350, 50));
  genbutton.setOutlineColor(sf::Color::Black);
  genbutton.setFillColor(sf::Color(102, 178, 255, 255));

  // creating string and displayed text objects
  sf::Font font;
  font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-BI.ttf");

  sf::Text bannertxt("SmartList", font);
  bannertxt.setCharacterSize(50);
  bannertxt.setStyle(sf::Text::Bold);
  bannertxt.setFillColor(sf::Color::White);

  // Date field
  sf::Text datetitle("Due Date (mm/dd)", font);
  datetitle.setCharacterSize(25);
  datetitle.setFillColor(sf::Color::Black);

  sf::String userdInput;
  sf::Text userdText("", font, 25);

  // Task field
  sf::Text tasktitle("Task", font);
  tasktitle.setCharacterSize(25);
  tasktitle.setFillColor(sf::Color::Black);

  sf::String usertInput;
  sf::Text usertText("", font, 25);

  // Rank field
  sf::Text ranktitle("Priority: 1 (low) - 10 (high)", font);
  ranktitle.setCharacterSize(25);
  ranktitle.setFillColor(sf::Color::Black);

  sf::String userrInput;
  sf::Text userrText("", font, 25);

  // Add button text
  sf::Text addtext("ADD", font);
  addtext.setCharacterSize(30);
  addtext.setFillColor(sf::Color::White);

  // Tasks header
  sf::Text tasksheader("Tasks:", font);
  tasksheader.setCharacterSize(30);
  tasksheader.setFillColor(sf::Color::Black);

  // Delete last entry button text
  sf::Text deletelast("Delete Last Item", font);
  deletelast.setCharacterSize(30);
  deletelast.setFillColor(sf::Color::White);

  // Clear All button text
  sf::Text clearall("Clear All", font);
  clearall.setCharacterSize(30);
  clearall.setFillColor(sf::Color::White);

  // Generate my list button text
  sf::Text genlist("Generate my SmartList", font);
  genlist.setCharacterSize(30);
  genlist.setFillColor(sf::Color::White);

  // creating app elements
  sf::RectangleShape background2;
  background2.setSize(sf::Vector2f(1500, 1000));
  background2.setFillColor(sf::Color::White);

  sf::RectangleShape topbanner2;
  topbanner2.setSize(sf::Vector2f(1500, 60));
  topbanner2.setFillColor(sf::Color(102, 178, 255, 255));

  sf::RectangleShape clickbox;
  clickbox.setSize(sf::Vector2f(1400, 60));
  clickbox.setFillColor(sf::Color::White);

  sf::RectangleShape checkbox;
  checkbox.setSize(sf::Vector2f(50, 50));
  checkbox.setOutlineColor(sf::Color::Black);
  checkbox.setFillColor(sf::Color(sf::Color(246, 246, 246, 255)));

  sf::RectangleShape hidescroll3;
  hidescroll3.setSize(sf::Vector2f(1500, 300));
  hidescroll3.setFillColor(sf::Color::White);
  hidescroll3.setPosition(0, 0);

  sf::RectangleShape hidescroll4;
  hidescroll4.setSize(sf::Vector2f(1500, 50));
  hidescroll4.setFillColor(sf::Color::White);
  hidescroll4.setPosition(0, 950);

  // add text

  sf::Text bannertxt2("Your SmartList", font);
  bannertxt2.setCharacterSize(50);
  bannertxt2.setStyle(sf::Text::Bold);
  bannertxt2.setFillColor(sf::Color::White);

  // date header
  sf::Text datetitle2("Due Date (mm/dd)", font);
  datetitle2.setCharacterSize(30);
  datetitle2.setFillColor(sf::Color::Black);

  // Task header
  sf::Text tasktitle2("Task", font);
  tasktitle2.setCharacterSize(30);
  tasktitle2.setFillColor(sf::Color::Black);

  // Completed header
  sf::Text donetitle("Complete", font);
  donetitle.setCharacterSize(30);
  donetitle.setFillColor(sf::Color::Black);

  // Instructions list
  sf::Text instruct("Click on your task to mark as complete", font);
  instruct.setCharacterSize(25);
  instruct.setFillColor(sf::Color(54, 120, 231, 255));

  // Tasks list
  sf::Text tasksheader2("Tasks (in order of priority):", font);
  tasksheader2.setCharacterSize(35);
  tasksheader2.setFillColor(sf::Color::Black);

  // Dates output
  sf::Text dated("", font);
  dated.setCharacterSize(25);
  dated.setFillColor(sf::Color::Black);

  // Text output
  sf::Text tasked("", font);
  tasked.setCharacterSize(25);
  tasked.setFillColor(sf::Color::Black);

  // Completed output
  sf::Text complete("", font);
  complete.setCharacterSize(25);
  complete.setFillColor(sf::Color(45, 216, 17, 255));


  window.display();

  // creating blinking cursor
  sf::Text cursor("|", font, 25);
  cursor.setFillColor(sf::Color::Black);
  bool Shown = false;
  const int blinkFreq = 10;
  int blinkCnt = 0;
  bool showcurs = false;

  // booleans to tell whether date, task, or rank box have been clicked
  bool dateentry = false;
  bool taskentry = false;
  bool rankentry = false;

  // initialzing running display strings
  string date_disp = "";
  string task_disp = "";
  string rank_disp = "";

  // creating text that will display user's added input
  sf::Text dates("", font);
  dates.setCharacterSize(25);
  dates.setFillColor(sf::Color::Black);

  sf::Text tasks("", font);
  tasks.setCharacterSize(25);
  tasks.setFillColor(sf::Color::Black);

  sf::Text ranks("", font);
  ranks.setCharacterSize(25);
  ranks.setFillColor(sf::Color::Black);

  // initializing vector of vector of strings that will store
  // all valid user inputs and will be used when generate
  // button is pressed
  vector<vector<string>> allinput;

  // initializing vector of vector of strings that will store
  // tasks marked as completed in window2
  vector<vector<string>> done;
  // done = {{"06/10", "hello"}, {"04/23", "hey"}};

  // second window launched by generate my list button
  sf::RenderWindow window2;

  // setting initial positions of some elements
  tasksheader.setPosition(80, 200);
  dates.setPosition(80, 250);
  tasks.setPosition(460, 250);
  ranks.setPosition(840, 250);


  while (window.isOpen() || window2.isOpen()) {
    if (window2.isOpen()) {
      sf::Event event2;
      while (window2.pollEvent(event2)) {
        // when window2 is closed, completed tasks are removed from
        // vector allinputs and from displayed tasks in window
        if (event2.type == sf::Event::Closed)
          window2.close();

        // creating SmartList Interface elements
        sf::RectangleShape background2;
        background2.setSize(sf::Vector2f(1500, 1000));
        background2.setFillColor(sf::Color::White);

        sf::RectangleShape topbanner2;
        topbanner2.setSize(sf::Vector2f(1500, 60));
        topbanner2.setFillColor(sf::Color(102, 178, 255, 255));

        sf::RectangleShape clickbox;
        clickbox.setSize(sf::Vector2f(1400, 60));
        clickbox.setFillColor(sf::Color::White);

        sf::RectangleShape checkbox;
        checkbox.setSize(sf::Vector2f(50, 50));
        checkbox.setOutlineColor(sf::Color::Black);
        checkbox.setFillColor(sf::Color(sf::Color(246, 246, 246, 255)));

        sf::RectangleShape hidescroll3;
        hidescroll3.setSize(sf::Vector2f(1500, 300));
        hidescroll3.setFillColor(sf::Color::White);
        hidescroll3.setPosition(0, 0);

        sf::RectangleShape hidescroll4;
        hidescroll4.setSize(sf::Vector2f(1500, 50));
        hidescroll4.setFillColor(sf::Color::White);
        hidescroll4.setPosition(0, 950);

        // add text

        sf::Text bannertxt2("Your SmartList", font);
        bannertxt2.setCharacterSize(50);
        bannertxt2.setStyle(sf::Text::Bold);
        bannertxt2.setFillColor(sf::Color::White);

        // date header
        sf::Text datetitle2("Due Date (mm/dd)", font);
        datetitle2.setCharacterSize(30);
        datetitle2.setFillColor(sf::Color::Black);

        // Task header
        sf::Text tasktitle2("Task", font);
        tasktitle2.setCharacterSize(30);
        tasktitle2.setFillColor(sf::Color::Black);

        // Completed header
        sf::Text donetitle("Complete", font);
        donetitle.setCharacterSize(30);
        donetitle.setFillColor(sf::Color::Black);

        // Instructions list
        sf::Text instruct("Click on your task to mark as complete", font);
        instruct.setCharacterSize(25);
        instruct.setFillColor(sf::Color(54, 120, 231, 255));

        // Tasks list
        sf::Text tasksheader2("Tasks (in order of priority):", font);
        tasksheader2.setCharacterSize(35);
        tasksheader2.setFillColor(sf::Color::Black);

        // Dates output
        sf::Text dated("", font);
        dated.setCharacterSize(25);
        dated.setFillColor(sf::Color::Black);

        // Text output
        sf::Text tasked("", font);
        tasked.setCharacterSize(25);
        tasked.setFillColor(sf::Color::Black);

        // Completed output
        sf::Text complete("", font);
        complete.setCharacterSize(25);
        complete.setFillColor(sf::Color(45, 216, 17, 255));

        // Declaring input/output
        string compl_display = "";

        // Initialize our output variable, the variable that is displayed
        // on our SmartList interface
        vector<vector<string>> output;
        vector<vector<string>> SmartList;
        // running our algorithm
        if (allinput.size() != 0) {
          SmartList = algorithm(allinput);
          for (int i = 0; i < SmartList.size(); i++) {
            output.push_back({SmartList.at(i).at(0), SmartList.at(i).at(1)});
          }
        } else {
          output.push_back({"00/00", "No task entered"});
        }

        int numtask = output.size();
        string date_display = "";
        string task_display = "";
        string temp = "";

        for (int i = 0; i < output.size(); i++) {
          date_display = date_display + "\n\n" + output.at(i).at(0);
          task_display = task_display + "\n\n" + output.at(i).at(1);
          compl_display = compl_display + "\n\n ";
        }
        dated.setPosition(80, 250);
        tasked.setPosition(460, 250);
        complete.setPosition(900, 250);
        clickbox.setPosition(40, 280);

        // Window is open
        while (window2.isOpen()) {
          sf::Event event2;
          while (window2.pollEvent(event2)) {
            if (event2.type == sf::Event::Closed) {
              window2.close();
              vector<vector<string>> fixedinput;
              for (auto d : done) {
                string thisdate = d.at(0);
                string thistask = d.at(1);
                bool keep = true;
                for (int i = 0; i < allinput.size(); i++) {
                  if (allinput.at(i).at(0) == thisdate && \
                      allinput.at(i).at(1) == thistask)
                    keep = false;
                }
                if (keep) {
                  fixedinput.push_back(d);
                }
                bool rm = false;
                int b = 0;
                for (int i = 0; i < date_disp.length(); i = i + 7) {
                  b++;
                  if (date_disp.substr(i + 2, 5) == thisdate) {
                    // dates.setString(thisdate);
                    int lb = 0;
                    for (int j = 0; j < task_disp.length(); j++) {
                      if (task_disp.at(j) == '\n') lb++;
                      if (lb / 2 == b && lb % 2 == 0) {
                        if (task_disp.substr(j + 1, \
                                             thistask.length()) == thistask) {
                          date_disp = date_disp.substr(0, i) + \
                                      date_disp.substr(i + 7,
                                                       date_disp.length() - (i + 7));
                          task_disp = task_disp.substr(0, j - 1) + \
                                      task_disp.substr(j + thistask.length() + 1
                                                       , \task_disp.length() - (j + 1 + \
                                                           thistask.length()));
                          dates.setString(date_disp);
                          tasks.setString(task_disp);
                          rm = true;
                          break;
                        }
                      }
                    }
                    if (rm) {
                      int lb = 0;
                      for (int j = 0; j < rank_disp.length(); j++) {
                        if (rank_disp.at(j) == '\n') lb++;
                        if (lb / 2 == b && lb % 2 == 0) {
                          string thisrank = rank_disp.substr(j + 1, 2);
                          int change = 2;
                          if (thisrank == "10") change += 1;
                          rank_disp = rank_disp.substr(0, j - 1) + \
                                      rank_disp.substr(j + change, \
                                                       rank_disp.length() - (j + change));
                          ranks.setString(rank_disp);
                          break;
                        }
                      }
                    }
                  }
                  if (rm) break;
                }
              }
              allinput = fixedinput;
            }

            int lineh = tasked.getGlobalBounds().height;
            // account for the tasks printing with \n\n before the first task
            clickbox.setSize(sf::Vector2f(1400, lineh));
            int clickpos;
            int linesize = (lineh) / numtask;
            // user clicked in box
            auto mouse_pos = sf::Mouse::getPosition(window2);
            auto translated_pos = window2.mapPixelToCoords(mouse_pos);
            if (event2.type == sf::Event::MouseButtonPressed) {
              if (clickbox.getGlobalBounds().contains(translated_pos)) {
                clickpos = translated_pos.y - clickbox.getPosition().y;
                // normalize position to box coordinates
                clickpos = clickpos / linesize;
                char wait = compl_display.at(((clickpos + 1) * 3) - 1);
                vector<string> checked;
                checked.push_back(output.at(clickpos).at(0));
                checked.push_back(output.at(clickpos).at(1));
                if (wait == ' ') {
                  compl_display.at(((clickpos + 1) * 3) - 1) = 'x';
                  // add to output
                  done.push_back(checked);
                } else if (wait == 'x') {
                  compl_display.at(((clickpos + 1) * 3) - 1) = ' ';
                  auto pos = find(done.begin(), done.end(), checked);
                  done.erase(pos);
                }

                complete.setString(compl_display);
              }
            }
            if (event2.type == sf::Event::MouseWheelScrolled) {
              // allow scrolling if displayed input long enough
              int scrolled = event2.mouseWheelScroll.delta;
              int datey = dated.getPosition().y;
              int dateh = dated.getLocalBounds().height;
              int tasky = tasked.getPosition().y;
              int compy = complete.getPosition().y;
              int boxy = clickbox.getPosition().y;
              if (dateh > 600) {
                if (scrolled < 0) {
                  if (dateh + datey >= 900) {
                    dated.setPosition(80, datey + 10 * scrolled);
                    tasked.setPosition(460, tasky + 10 * scrolled);
                    complete.setPosition(900, compy + 10 * scrolled);
                    clickbox.setPosition(40, boxy + 10 * scrolled);
                  }
                } else if (scrolled > 0) {
                  if (datey <= 251) {
                    dated.setPosition(80, datey + 10 * scrolled);
                    tasked.setPosition(460, tasky + 10 * scrolled);
                    complete.setPosition(900, compy + 10 * scrolled);
                    clickbox.setPosition(40, boxy + 10 * scrolled);
                  }
                }
              }
            }
          }

          // setting positions of title elements
          topbanner2.setPosition(0, 0);
          datetitle2.setPosition(80, 250);
          tasktitle2.setPosition(460, 250);
          donetitle.setPosition(840, 250);
          tasksheader2.setPosition(80, 100);
          instruct.setPosition(80, 180);


          // setting positions of output

          dated.setString(date_display);
          tasked.setString(task_display);
          complete.setString(compl_display);
          // dated.setPosition(80, 250);
          // tasked.setPosition(460, 250);
          // complete.setPosition(900, 250);

          // creating clickable box for check marks


          window2.draw(background2);

          window2.draw(clickbox);
          window2.draw(dated);
          window2.draw(tasked);
          window2.draw(complete);


          window2.draw(hidescroll3);
          window2.draw(hidescroll4);
          window2.draw(topbanner2);
          window2.draw(bannertxt2);
          window2.draw(instruct);
          window2.draw(donetitle);
          window2.draw(tasksheader2);

          window2.draw(datetitle2);
          window2.draw(tasktitle2);

          window2.display();
          window2.clear();
        }
      }
    }
    // setting button fill color in the loop so that it can briefly change
    // to darker and back when a user clicks a button
    add.setFillColor(sf::Color(102, 178, 255, 255));
    deletebutton.setFillColor(sf::Color(102, 178, 255, 255));
    clearbutton.setFillColor(sf::Color(102, 178, 255, 255));
    genbutton.setFillColor(sf::Color(102, 178, 255, 255));

    // finding size of user input to check for valid input
    int datelength = userdInput.getSize();
    int tasklength = usertInput.getSize();
    int ranklength = userrInput.getSize();
    bool valid = false;

    // setting proper position of blinking cursor if textbox is hot
    if (dateentry == true)
      cursor.setPosition(85 + userdText.getLocalBounds().width, 125);
    if (taskentry == true)
      cursor.setPosition(465 + usertText.getLocalBounds().width, 125);
    if (rankentry == true)
      cursor.setPosition(845 + userrText.getLocalBounds().width, 125);
    if (dateentry == false && taskentry\
        == false && rankentry == false)
      showcurs = false;
    else
      showcurs = true;

    // setting blink rate of cursor
    if (++blinkCnt >= blinkFreq) {
      Shown = !Shown;
      blinkCnt = 0;
    }

    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
      // getting coordinates of mouse to check where user clicks
      auto mouse_pos = sf::Mouse::getPosition(window);
      auto translated_pos = window.mapPixelToCoords(mouse_pos);
      if (event.type == sf::Event::MouseButtonPressed) {
        if (datebox.getGlobalBounds().contains(translated_pos)) {
          // clicked in datebox
          userdText.setFillColor(sf::Color::Black);
          dateentry = true;
          taskentry = false;
          rankentry = false;
        } else if (taskbox.getGlobalBounds().contains(translated_pos)) {
          // clicked in taskbox
          dateentry = false;
          taskentry = true;
          rankentry = false;
        } else if (rankbox.getGlobalBounds().contains(translated_pos)) {
          // clicked in rankbox
          dateentry = false;
          taskentry = false;
          rankentry = true;
        } else if (add.getGlobalBounds().contains(translated_pos)) {
          // clicked add button
          add.setFillColor(sf::Color(92, 158, 225, 255));
          // only add if input is valid
          if (datelength == 5 && tasklength > 0 && ranklength > 0) {
            // cursor not blinking anymore
            dateentry = false;
            taskentry = false;
            rankentry = false;
            // checking validity of date
            string smonth = userdInput.substring(0, 2);
            string sday = userdInput.substring(3, 2);
            int month = stoi(smonth);
            int day = stoi(sday);
            if (month > 0 && month < 13) {
              if (month == 9 || month == 4 || month == 6 || month == 11) {
                if (day > 0 && day <= 30) valid = true;
              } else if (month == 2) {
                if (day > 0 && day <= 29) valid = true;
              } else if (day > 0 && day <= 31) {
                valid = true;
              }
            }
            if (valid) {
              // add new entry to display and vector and delete text from fields
              date_disp = date_disp + "\n\n" + userdInput;
              task_disp = task_disp + "\n\n" + usertInput;
              rank_disp = rank_disp + "\n\n" + userrInput;
              vector<string> input;
              input.push_back(userdInput);
              input.push_back(usertInput);
              input.push_back(userrInput);
              allinput.push_back(input);
              dates.setString(date_disp);
              tasks.setString(task_disp);
              ranks.setString(rank_disp);
              userdText.setString("");
              usertText.setString("");
              userrText.setString("");
              userdInput.clear();
              usertInput.clear();
              userrInput.clear();
            } else {
              // if date invalid
              userdText.setFillColor(sf::Color::Red);
            }
          }
        } else if (deletebutton.getGlobalBounds().contains(translated_pos)) {
          // delete button clicked
          deletebutton.setFillColor(sf::Color(92, 158, 225, 255));
          allinput.pop_back();
          char check = ' ';
          int j;
          for (j = date_disp.length() - 1; j >= 0 ; j--) {
            check = date_disp.at(j);
            if (check == '\n') {
              break;
            }
          }
          date_disp = date_disp.substr(0, j + 1);
          dates.setString(date_disp);
          date_disp = date_disp.substr(0, j - 1);

          for (j = task_disp.length() - 1; j >= 0 ; j--) {
            check = task_disp.at(j);
            if (check == '\n') {
              break;
            }
          }
          task_disp = task_disp.substr(0, j + 1);
          tasks.setString(task_disp);
          task_disp = task_disp.substr(0, j - 1);

          for (j = rank_disp.length() - 1; j >= 0 ; j--) {
            check = rank_disp.at(j);
            if (check == '\n') {
              break;
            }
          }
          rank_disp = rank_disp.substr(0, j + 1);
          ranks.setString(rank_disp);
          rank_disp = rank_disp.substr(0, j - 1);
        } else if (clearbutton.getGlobalBounds().contains(translated_pos)) {
          // clear all button clicked
          clearbutton.setFillColor(sf::Color(92, 158, 225, 255));
          date_disp = " ";
          task_disp = " ";
          rank_disp = " ";
          dates.setString(date_disp);
          tasks.setString(task_disp);
          ranks.setString(rank_disp);
          allinput = {};
        } else if (genbutton.getGlobalBounds().contains(translated_pos)) {
          // generate button clicked: open window2
          genbutton.setFillColor(sf::Color(92, 158, 225, 255));
          window2.create(sf::VideoMode(1000, 1000), "Your SmartList");
          window2.setFramerateLimit(10);
          window2.setView(view);
          window2.display();
        }
      }
      if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode == 13 && datelength == 5 && \
            tasklength > 0 && ranklength > 0) {
          // enter key pressed (check validity of input)
          string smonth = userdInput.substring(0, 2);
          string sday = userdInput.substring(3, 2);
          int month = stoi(smonth);
          int day = stoi(sday);
          if (month > 0 && month < 13) {
            if (month == 9 || month == 4 || month == 6 || month == 11) {
              if (day > 0 && day <= 30) valid = true;
            } else if (month == 2) {
              if (day > 0 && day <= 29) valid = true;
            } else if (day > 0 && day <= 31) {
              valid = true;
            }
          }
          if (valid) {
            // cursor not blinking anymore
            dateentry = false;
            taskentry = false;
            rankentry = false;
            // add new entry and delete text from fields
            date_disp = date_disp + "\n\n" + userdInput;
            task_disp = task_disp + "\n\n" + usertInput;
            rank_disp = rank_disp + "\n\n" + userrInput;
            vector<string> input;
            input.push_back(userdInput);
            input.push_back(usertInput);
            input.push_back(userrInput);
            allinput.push_back(input);
            dates.setString(date_disp);
            tasks.setString(task_disp);
            ranks.setString(rank_disp);
            userdText.setString("");
            usertText.setString("");
            userrText.setString("");
            userdInput.clear();
            usertInput.clear();
            userrInput.clear();
          } else {
            // invalid date
            userdText.setFillColor(sf::Color::Red);
          }
        }
        if (dateentry == true) {
          // user typing in date box (can only type ##/##)
          if (event.text.unicode == '\b' && datelength > 0) {
            userdInput.erase(datelength - 1, 1);
          } else if (event.text.unicode == 9) {
            dateentry = false;
            taskentry = true;
            break;
          } else if (event.text.unicode < 128 && datelength < 5) {
            if (datelength == 2 && event.text.unicode == 47)
              userdInput += event.text.unicode;
            else if (datelength != 2 && event.text.unicode >= 48\
                     && event.text.unicode <= 57)
              userdInput += event.text.unicode;
          }
          userdText.setString(userdInput);
          userdText.setCharacterSize(25);
          userdText.setFillColor(sf::Color::Black);
          userdText.setPosition(85, 125);
        } else if (taskentry == true) {
          // user typing in task box
          if (event.text.unicode == '\b' && tasklength > 0) {
            usertInput.erase(tasklength - 1, 1);
          } else if (event.text.unicode == 9) {
            taskentry = false;
            rankentry = true;
            break;
          } else if (event.text.unicode < 128 && \
                     usertText.getLocalBounds().width < \
                     taskbox.getLocalBounds().width - 12) {
            usertInput += event.text.unicode;
          }
          usertText.setString(usertInput);
          usertText.setCharacterSize(25);
          usertText.setFillColor(sf::Color::Black);
          usertText.setPosition(465, 125);
        } else if (rankentry == true) {
          // user typing in rank box (only 1-10)
          if (event.text.unicode == '\b' && ranklength > 0) {
            userrInput.erase(ranklength - 1, 1);
          } else if (event.text.unicode == 9) {
            dateentry = true;
            rankentry = false;
            break;
          } else if (event.text.unicode < 58 && \
                     event.text.unicode > 47 && ranklength < 2) {
            if (ranklength == 0 && event.text.unicode != '0')
              userrInput += event.text.unicode;
            else if (userrInput == "1" && event.text.unicode == '0')
              userrInput += event.text.unicode;
          }
          userrText.setString(userrInput);
          userrText.setCharacterSize(25);
          userrText.setFillColor(sf::Color::Black);
          userrText.setPosition(845, 125);
        }
      }
      if (event.type == sf::Event::MouseWheelScrolled) {
        // allow scrolling if displayed input long enough
        int scrolled = event.mouseWheelScroll.delta;
        int datey = dates.getPosition().y;
        int dateh = dates.getLocalBounds().height;
        int tasky = tasks.getPosition().y;
        int ranky = ranks.getPosition().y;
        if (dateh > 600) {
          if (scrolled < 0) {
            if (dateh + datey >= 850) {
              dates.setPosition(80, datey - 10 * scrolled);
              tasks.setPosition(460, tasky - 10 * scrolled);
              ranks.setPosition(840, ranky - 10 * scrolled);
            }
          } else if (scrolled > 0) {
            if (datey <= 250) {
              dates.setPosition(80, datey - 10 * scrolled);
              tasks.setPosition(460, tasky - 10 * scrolled);
              ranks.setPosition(840, ranky - 10 * scrolled);
            }
          }
        }
      }
    }
    // setting positions of elements
    topbanner.setPosition(0, 0);

    datebox.setPosition(80, 128);
    datetitle.setPosition(80, 100);

    taskbox.setPosition(460, 128);
    tasktitle.setPosition(460, 100);

    rankbox.setPosition(840, 128);
    ranktitle.setPosition(840, 100);

    add.setPosition(1200, 115);
    addtext.setPosition(1240, 120);

    deletebutton.setPosition(550, 900);
    deletelast.setPosition(560, 905);
    clearbutton.setPosition(850, 900);
    clearall.setPosition(860, 905);
    genbutton.setPosition(1060, 900);
    genlist.setPosition(1070, 905);

    // draw and display elements in window
    window.draw(background);

    window.draw(dates);
    window.draw(tasks);
    window.draw(ranks);

    window.draw(hidescroll);
    window.draw(hidescroll2);
    window.draw(topbanner);
    window.draw(bannertxt);

    window.draw(datebox);
    window.draw(datetitle);
    window.draw(userdText);

    window.draw(taskbox);
    window.draw(tasktitle);
    window.draw(usertText);

    window.draw(rankbox);
    window.draw(ranktitle);
    window.draw(userrText);
    if (Shown && showcurs == true)
      window.draw(cursor);

    window.draw(add);
    window.draw(addtext);

    window.draw(tasksheader);

    window.draw(deletebutton);
    window.draw(deletelast);
    window.draw(clearbutton);
    window.draw(clearall);
    window.draw(genbutton);
    window.draw(genlist);

    window.display();
    window.clear();
  }
  return 0;
}
