//Button.cpp

#include "Button.hpp"

button::button(): button_shape({0.f,0.f}) {}

button::button(sf::Vector2f pos , Type_pressed type , sf::VertexArray && icon):
	button_shape(pos , type){
	this->icon = std::move(icon);
	for (size_t i = 0; i < this->icon.getVertexCount(); i++) {this->icon[i].position += pos;}
	
}

void button::draw(sf::RenderWindow& window){
	window.draw(rect);
	window.draw(icon);
}
