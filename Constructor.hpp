//Constructor.hpp
#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include<memory>

//#include"Button.hpp"
#include"button_shape.hpp"

#include"ColorIndicator.hpp"

#include"Model.hpp"
#include"Counter.hpp"

#include"Shapes_list.hpp"

class Constructor{
	bool mouse_clic_left = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	bool mouse_clic_right = sf::Mouse::isButtonPressed(sf::Mouse::Right);

	button_shape buttonPoligonAdd , buttonPoligonDelet ,shape_add , shape_delete;
	size_t poligon;
	Model model;

	Counter shape_Counter  , pointer_hsape_Counter , poligon_Counter;

	Shapes_list shapes_list;

	ColorIndicator colorIndicator;

public:

	Constructor();

	void update(sf::Vector2f mouse_pos , float dt , float MouseSkrolled);

	void draw(sf::RenderWindow & window);

};

