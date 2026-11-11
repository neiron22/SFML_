//ButtonVertarr.cpp
#include "ButtonVertarr.hpp"
#include "TransformShape.hpp"
ButtonVertarr::ButtonVertarr() :BaseButton(){}



ButtonVertarr::ButtonVertarr(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f Origin, sf::VertexArray&& Va, sf::Color color, TypePressed type):
	BaseButton(pos,size,Origin,color,type)
{
	this->Va = Va;
	trsh::moveVA(this->Va, pos);
}	

ButtonVertarr::ButtonVertarr(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f Origin, sf::Color color, float OutLine, sf::Color colorOutLine, TypePressed type, sf::VertexArray&& Va):
	BaseButton(pos,size,Origin,color,OutLine,colorOutLine,type)
{
	this->Va = Va;
	trsh::moveVA(this->Va, pos);
}

ButtonVertarr::ButtonVertarr(sf::Vector2f pos, TypePressed type,  sf::VertexArray&& Va,sf::Vector2f size, float OutLine, sf::Color colorOutLine):
	BaseButton(pos,type,size,OutLine,colorOutLine)
{
	this->Va = Va;
	trsh::moveVA(this->Va, pos);
}

ButtonVertarr::ButtonVertarr(sf::Vector2f pos, sf::VertexArray&& Va, sf::Vector2f size, TypePressed type, float OutLine, sf::Color colorOutLine):
	BaseButton(pos,size,type,OutLine,colorOutLine)
{
	this->Va = Va;
	trsh::moveVA(this->Va, pos);
}

void ButtonVertarr::setVisible(bool state){
	BaseButton::setVisible(state);
	Render::setVisible(Va.id() , state);
}

ButtonVertarr& ButtonVertarr::operator=(ButtonVertarr& other)
{
	if (this != &other) {
		BaseButton::operator=(other);
		this->Va = other.Va;}
	return *this;
}

ButtonVertarr& ButtonVertarr::operator=(ButtonVertarr&& other) noexcept
{
	if (this != &other) {
		BaseButton::operator=(other);
		this->Va = sf::VertexArray(other.Va);
	}
	return *this;
}


