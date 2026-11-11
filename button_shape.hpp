//button_shape.hpp
#pragma once
#include<SFML/Graphics.hpp>
#include"Type.hpp"

class button_shape{
protected:
	TypePressed type;
	sf::RectangleShape rect;
	sf::Vector2f pos;
	bool state, flag;


public:
	button_shape();

	button_shape(sf::Vector2f pos, TypePressed type = TypePressed::OnOff, bool default_status = false);

	button_shape( sf::Vector2f size , float outSize,sf::Vector2f pos, TypePressed type = TypePressed::OnOff, bool default_status = false , bool centerOrigin = true);

	void reSize(sf::Vector2f newSize , bool AddToCuttentValue = false);

	void move(sf::Vector2f vec);

	void update(sf::Vector2f mouse_pos, bool LKM);

	void virtual draw(sf::RenderWindow& window);

	bool getClick() const { return state; }

	operator bool() {return state;}

	void setClick(bool value);

	sf::Vector2f get_pos();

	virtual ~button_shape() = default;
};

