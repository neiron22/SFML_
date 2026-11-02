//Button.hpp
#pragma once

#include"button_shape.hpp"

class button : public button_shape {
	sf::VertexArray icon;
public:
	button();
	button(sf::Vector2f pos, Type_pressed type , sf::VertexArray&& icon);

	void draw(sf::RenderWindow& window)override;
};

