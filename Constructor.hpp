//Constructor.hpp
#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include<memory>

#include"Button.hpp"
#include"button_shape.hpp"

#include"Model.hpp"
#include"Counter.hpp"

#include"slider.hpp"

#include"Shapes_list.hpp"

class Constructor{
	bool mouse_clic_left = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	bool mouse_clic_right = sf::Mouse::isButtonPressed(sf::Mouse::Right);

	Button deleted_button , vertex_button;

	button_shape buttonPoligonAdd , buttonPoligonDelet , size_increase , size_decrease ,
		shape_add , shape_delete;
	size_t poligon;

	std::vector<Button*> buttons;

	Model model;
	Counter shape_Counter  , pointer_hsape_Counter , poligon_Counter;

	Shapes_list shapes_list;


	Color_indikator color_indicator;
	One_slider slider_1;
	Counter silder_counter;
public:

	Constructor();

	void update(sf::Vector2f pouse_pos , float dt);

	void draw(sf::RenderWindow & window);

};

