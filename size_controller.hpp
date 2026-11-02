//size_controller.hpp
#pragma once

#include"Size_slider.hpp"
#include"button_shape.hpp"
#include"CircularSlider.hpp"



class Size_controller{

	Size_slider size_slider_x , size_slider_y;

	sf::Vector2f distance;

	button_shape to_x_y , to_multipler_angle;

	CircularSlider size_multipler_angle;

public:
	Size_controller(sf::Vector2f pos);
	
	void update(sf::Vector2f mouse_pos , bool LKM , float mouse_skroll);

	void draw(sf::RenderWindow& window);
};

