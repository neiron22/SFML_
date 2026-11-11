//CircularSlider.hpp
#pragma once

//#include<SFML/Graphics.hpp>
#include<SFML/Window/Keyboard.hpp>
#include"SpecialDataTypes.hpp"
#include"VertexArray.hpp"

class CircularSlider{
	VertexArray vert_arr;
	std::vector<Range> rects;
	VertexArray Point;
	sf::Vector2f PointPos;
	sf::Color color;
	float Angle;
public:
	CircularSlider(sf::Vector2f pos , float Radius , float Out_Radius = 8.f , sf::Color color = { 130,130,130,200 }	, sf::Color color_2 = { 40,40,40,255 });

	void update();

	float getRotation();

	void setRotation(float Angle);

	void draw(sf::RenderWindow& window);
};

