//slider.hpp
#pragma once

#include<SFML/Graphics.hpp>

class Slider{
	sf::CircleShape circle_point;
	sf::RectangleShape rect_path;

	bool toVertical;

	sf::Vector2f pos_begin;
	float len , InteractionRadius;
	bool select;
public:

	Slider(sf::Vector2f pos, float len, sf::Color color1 = { 70,70,70,255 },
		sf::Color color2 = { 190,190,190,255 }, bool toVertical = false, float InteractionRadius = 60.f);

	void draw(sf::RenderWindow& window);

	void update(sf::Vector2f mouse_pos , bool LKM);

	float getProcess();

	float getValue(float min , float max);
};

