//BaseButton.hpp
#pragma once
//#include<SFML/Graphics/CircleShape.hpp>
#include"RectangleShape.hpp"
#include"Type.hpp"

class BaseButton {
protected:
	RectangleShape rect;
	TypePressed type;
	bool state , flag , isHovered;
	
public:
	sf::Color Color ,HorvedColor , OnColor;
	BaseButton();
	BaseButton(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f Origin, sf::Color color= {255,255,255}, TypePressed type = TypePressed::OnOff);
	BaseButton(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f Origin, sf::Color color, float OutLine, sf::Color colorOutLine, TypePressed type);
	BaseButton(sf::Vector2f pos, TypePressed type, sf::Vector2f size, float OutLine = 5.f, sf::Color colorOutLine = { 70,70,70 });
	BaseButton(sf::Vector2f pos ,  sf::Vector2f size  = {40.f,40.f} ,TypePressed type=TypePressed::OnOff, float OutLine = 5.f, sf::Color colorOutLine = {70,70,70});

	void setTypePressed(TypePressed type);
	void update();
	void stateUpdate(TypePressed type);
	//bool updateType(TypePressed type) ;

	bool getstate() const { return state; }
	void setState(bool value) { state = value; }
	
	operator bool() { return state; }
	operator bool() const { return state; }

	virtual void setVisible(bool state);

	sf::RectangleShape& sfRect() { return rect; }
	RectangleShape& Rect() { return rect; }

	BaseButton& operator=(BaseButton& other);
	BaseButton& operator=(BaseButton&& other) noexcept;

	~BaseButton() = default;
};