//Button.cpp

#include "Button.hpp"
#include"Render.hpp"

button::button() : button_shape({ 0.f,0.f }) { }

button::button(sf::Vector2f pos , TypePressed type , sf::VertexArray && icon):
	button_shape(pos , type){
	this->icon = std::move(icon);
	for (size_t i = 0; i < this->icon.getVertexCount(); i++) {this->icon[i].position += pos;}
	
}
button::button(sf::Vector2f pos, TypePressed type, std::vector<sf::Vertex>& vertices) :
button_shape(pos, type)
{
	size_t count = vertices.size();
	
	for (size_t i = 0; i < count; i++) { 
		icon[i] = vertices[i];
		icon[i].position += pos; }

}
void button::draw(sf::RenderWindow& window){
	window.draw(rect);
	window.draw(icon);
}
