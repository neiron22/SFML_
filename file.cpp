//file.cpp
#include<SFML\Graphics.hpp>

#include <iostream>
//#include<thread>
//#include<string>
//#include<fstream>

#include"Constructor.hpp"
#include"FontManager.hpp"

//std::string CONSOLE_INPUT;
bool hasInput = false;

//void inputThread() {
//	while (true) {
//		//hasInput = false;
//		std::string input;
//		std::getline(std::cin , input);
//		CONSOLE_INPUT = input;
//		hasInput = true;
//	}
//}

int main() {
	//std::thread t(inputThread);
	//t.detach();

	FontManager::init();

	sf::RenderWindow window(sf::VideoMode({1200,900}), "SFML_EDITOR" , sf::Style::Titlebar | sf::Style::Close);

	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	//std::setlocale(LC_ALL , "RU");

	sf::Vector2f window_size = sf::Vector2f{window.getSize()};


	Constructor constructor;


	sf::Clock clock;
	
	while (window.isOpen()){sf::Event event;

	float MouseSrtoled = 0;

	while (window.pollEvent(event)){
	if (event.type == event.Closed) { window.close(); }

	if (event.type == sf::Event::MouseWheelScrolled) {
		if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {MouseSrtoled = event.mouseWheelScroll.delta;}
	}
	
	

	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){ window.close(); }

	

	float delta_time = clock.restart().asSeconds();

	sf::Vector2f mouse_pos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

	bool mouse_clic_left = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	bool mouse_clic_right = sf::Mouse::isButtonPressed(sf::Mouse::Right);

	

	//if (hasInput) {
	//	float float_input = std::stof(CONSOLE_INPUT);


	
	

	//hasInput = false;}
	

	constructor.update(mouse_pos, delta_time , MouseSrtoled);

	window.clear();

	constructor.draw(window);

	window.display();

}return 0;}