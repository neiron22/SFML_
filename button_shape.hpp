//button_shape.hpp
#pragma once
#include<SFML/Graphics.hpp>

enum class Type_pressed {OaneClikc , On_off , Prpessed , HoveredCursor};


class button_shape{
	Type_pressed type;
	sf::RectangleShape rect;
	sf::Vector2f pos;
	bool activate_diactivate, flag;


public:

	button_shape(sf::Vector2f pos, Type_pressed type = Type_pressed::On_off);

	//button_shape(sf::Vector2f pos, Type_pressed type , sf::Vector2f size , float outSize = 5.f);

	void reSize(sf::Vector2f newSize , bool AddToCuttentValue = false);

	void update(sf::Vector2f mouse_pos, bool LKM);

	void draw(sf::RenderWindow& window);

	bool getClick() { return activate_diactivate; }

	sf::Vector2f get_pos();
};

