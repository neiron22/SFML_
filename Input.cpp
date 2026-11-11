#include "Input.hpp"
#include<SFML/Window/Mouse.hpp>
#include<SFML/Window/Keyboard.hpp>

bool Input::pkm = false;
bool Input::lkm = false;
float Input::mouseskroll = 0.f;
sf::Vector2f Input::Mouse_Pos = { 0.f,0.f };


void Input::update(float MouseSkroll, sf::Vector2f MousePos){
	Mouse_Pos = MousePos;
	lkm = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	pkm = sf::Mouse::isButtonPressed(sf::Mouse::Right);
	mouseskroll = MouseSkroll;
}

