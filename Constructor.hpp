//Constructor.hpp
#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include<memory>

//#include"Button.hpp"
#include"button_shape.hpp"

#include"slider.hpp"
#include"Size_slider.hpp"

#include"ColorIndicator.hpp"

#include"Model.hpp"
#include"Counter.hpp"

#include"Shapes_list.hpp"

#include"CircularSlider.hpp"

class Constructor{
	bool mouse_clic_left = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	bool mouse_clic_right = sf::Mouse::isButtonPressed(sf::Mouse::Right);

	button_shape buttonPoligon ,shape_add , shape_delete ,
		button_color,
		button_color_1 , button_color_2, button_color_3;
	size_t poligon;
	Model model;
	
	//---------
	CircularSlider circularSlider;

	//Slider slider , multiplerSilder_x , multiplerSilder_y;

	Size_slider size_slider;
	//---------


	Counter poligon_Counter , angleCounter , color_rgb_counter;

	Shapes_list shapes_list;

	ColorIndicator colorIndicator;

public:

	Constructor();

	void update(sf::Vector2f mouse_pos , float dt , float MouseSkrolled);

	void draw(sf::RenderWindow & window);

};

