//shapes_list.hpp
#pragma once
#include"ButtonVertarr.hpp"
#include"vector"
#include"memory"
#include<numbers>
#include"Type.hpp"

class Shapes_list{
	std::vector<std::unique_ptr<BaseButton>> buttons;
	BaseButton Area_buttons;
	BaseButton Area_tools;

	BaseButton ShapeTypeTool;
	BaseButton ShapeSubTypeTool;

	
	std::vector<std::unique_ptr<ButtonVertarr>> TypesButtons;

	int IndexOnButton = 0;

	ButtonVertarr deleteShapeButton, AddShapeButton;

	sf::Vector2f pos, distance_x , distance_y;
	size_t SelecterIndexShape;

public:
	Shapes_list(sf::Vector2f pos = {50.f,50.f});
	void AddObj();
	void DelObj(size_t index);
	void update();
	int get_index() const;
	bool switching();
	void draw(sf::RenderWindow & window);
};

