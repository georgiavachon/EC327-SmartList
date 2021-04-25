// Copyright 2021 Georgia Vachon gvachon@bu.edu

#include <string>
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using std::cin;
using std::cout;
using std::atoi;
using std::string;
using std::to_string;
using std::vector;

// creating prioritized window


int main() {
  sf::RenderWindow window2(sf::VideoMode(1500, 1000), "Your SmartList");
  window2.setFramerateLimit(10);

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
  sf::Font font;
  font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-BI.ttf");

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
  vector<vector<string>> done;
  string compl_display = "";

  vector<vector<string>> output;
  output = {{"06/10", "Birthday"}};
  for (int i = 0; i < 15; i++) {
    output.push_back({"04/26", "Project Report"});
    output.push_back({"04/28", "Project Demo"});
  }
  output.push_back({"05/16", "Grad"});
  // ,{"04/28","Project Demo"},{"04/23","Project Video"}};
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
      if (event2.type == sf::Event::Closed)
        window2.close();

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
  return 0;
}
