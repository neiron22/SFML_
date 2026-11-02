//button_shape.hpp
#pragma once
#include<SFML/Graphics.hpp>

enum class Type_pressed {OneClick , On_off , Pressed , HoveredCursor};


class button_shape{
protected:
	Type_pressed type;
	sf::RectangleShape rect;
	sf::Vector2f pos;
	bool activate_diactivate, flag;


public:
	button_shape();

	button_shape(sf::Vector2f pos, Type_pressed type = Type_pressed::On_off, bool default_status = false);

	button_shape( sf::Vector2f size , float outSize,sf::Vector2f pos, Type_pressed type = Type_pressed::On_off, bool default_status = false , bool centerOrigin = true);

	void reSize(sf::Vector2f newSize , bool AddToCuttentValue = false);

	void move(sf::Vector2f vec);

	void update(sf::Vector2f mouse_pos, bool LKM);

	void virtual draw(sf::RenderWindow& window);

	bool getClick() { return activate_diactivate; }

	void setClick();

	sf::Vector2f get_pos();

	virtual ~button_shape() = default;
};

