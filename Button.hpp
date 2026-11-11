//Button.hpp
#pragma once

#include"button_shape.hpp"
#include<vector>

class button : public button_shape {
	
public:
	sf::VertexArray icon;
	button();
	button(sf::Vector2f pos, TypePressed type , sf::VertexArray&& icon);
	button(sf::Vector2f pos, TypePressed type, std::vector<sf::Vertex>& vertices);

	void draw(sf::RenderWindow& window)override;
};

