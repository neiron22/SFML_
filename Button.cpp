//Button.cpp

#include "Button.hpp"

button::button(sf::Vector2f pos , Type_pressed type , sf::VertexArray icon):button_shape(pos , type) , icon(icon){

}

void button::draw(sf::RenderWindow& window){
	window.draw(rect);
	window.draw(icon);
}
