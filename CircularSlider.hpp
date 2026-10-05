//CircularSlider.hpp
#pragma once

#include<SFML/Graphics.hpp>

class CircularSlider{
	sf::VertexArray vert_arr;
	sf::CircleShape shape_point;
	sf::Vector2f PointPos;

	float to_radian , offset;
public:
	CircularSlider(sf::Vector2f pos , float Radius , float Out_Radius = 6.5f);

	void update(sf::Vector2f mouse_pos , float mouse_csrolled, bool LKM);

	float getRotation();

	void setRotation(float Angle);

	void draw(sf::RenderWindow& window);
};

