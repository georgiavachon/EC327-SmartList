#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using std::cin;
using std::cout;
using std::atoi;
using std::string;
using std::to_string;

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

  sf::RectangleShape checkbox;
  checkbox.setSize(sf::Vector2f(50, 50));
  checkbox.setOutlineColor(sf::Color::Black);
  checkbox.setFillColor(sf::Color(sf::Color(246, 246, 246, 255)));

  // add text
  sf::Font font;
  font.loadFromFile("/usr/share/fonts/truetype/ubuntu/Ubuntu-BI.ttf");

  sf::Text bannertxt2("SmartList: To Do", font);
  bannertxt2.setCharacterSize(50);
  bannertxt2.setStyle(sf::Text::Bold);
  bannertxt2.setFillColor(sf::Color::White);

  // date header
  sf::Text datetitle2("Due Date (mm/dd)", font);
  datetitle2.setCharacterSize(25);
  datetitle2.setFillColor(sf::Color::Black);

  // Task header
  sf::Text tasktitle2("Task", font);
  tasktitle2.setCharacterSize(25);
  tasktitle2.setFillColor(sf::Color::Black);

  // Rank header
  // remove priority
  sf::Text ranktitle2("Priority (1-10)", font);
  ranktitle2.setCharacterSize(25);
  ranktitle2.setFillColor(sf::Color::Black);

  // Completed header
  sf::Text donetitle("Completed?", font);
  donetitle.setCharacterSize(25);
  donetitle.setFillColor(sf::Color::Black);

  // Tasks list
  sf::Text tasksheader2("Tasks (in order of priority):", font);
  tasksheader2.setCharacterSize(30);
  tasksheader2.setFillColor(sf::Color::Black);

  bool checkentry = false;
  //string xbox = "x";

  sf::Event event2;
  while (window2.isOpen()) {
    while (window2.pollEvent(event2)) {
        if (event2.type == sf::Event::Closed)
          window2.close();
      }
    
    auto mouse_pos = sf::Mouse::getPosition(window2);
      auto translated_pos = window2.mapPixelToCoords(mouse_pos);
      if (event2.type == sf::Event::MouseButtonPressed) {
        if(checkbox.getGlobalBounds().contains(translated_pos)) {
          // clicked in checkbox
              //userdText.setFillColor(sf::Color::Black);
          checkentry = true;
          // DISPLAY CHECK BOX
          // ADD CHECK BOX TO DATA STRUCT
        }
      }
    // setting positions of elements
    topbanner2.setPosition(0, 0);

    datetitle2.setPosition(80, 180);
    tasktitle2.setPosition(460, 180);
    ranktitle2.setPosition(840, 180);
    donetitle.setPosition(1220, 180);
    tasksheader2.setPosition(80,100);
    checkbox.setPosition(1260, 230);

    window2.draw(background2);
    window2.draw(topbanner2);
    window2.draw(bannertxt2);
    window2.draw(donetitle);
    window2.draw(checkbox);

    window2.draw(tasksheader2);

    window2.draw(datetitle2);
    window2.draw(tasktitle2);
    window2.draw(ranktitle2);

    window2.display();
    window2.clear();
  }
  return 0;
}