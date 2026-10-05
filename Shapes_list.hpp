//shapes_list.hpp
#pragma once

#include"button_shape.hpp"
#include"vector"

class Shapes_list{
	std::vector<button_shape> buttons;
	button_shape Area;
	sf::Vector2f pos, distance;
	int SelecterIndexShape;
public:
	Shapes_list(sf::Vector2f pos = {50.f,50.f});

	void add_object();

	void delete_object(size_t index);

	void update(sf::Vector2f mouse_pos , bool LKM);

	int get_index();

	bool switching();

	void draw(sf::RenderWindow & window);
};

