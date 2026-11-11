//BaseButton.cpp
#include"BaseButton.hpp"
#include"Input.hpp"
#include"ButtonDefaultValue.hpp"

void BaseButton::stateUpdate(TypePressed type)
{

}

BaseButton::BaseButton(){
	Color = ButtonDefault::color;
	HorvedColor = ButtonDefault::HorvedColor;
	OnColor = ButtonDefault::OnColor;
	rect->setPosition({0.f,0.f});
	rect->setSize(ButtonDefault::size);
	rect->setOrigin({0.f,0.f});
	rect->setFillColor(ButtonDefault::color);
	state = false;
	flag = false;
	this->type = type;
}

BaseButton::BaseButton(sf::Vector2f pos, sf::Vector2f size , sf::Vector2f Origin , sf::Color color , TypePressed type)
{
	Color = color;
	HorvedColor = ButtonDefault::HorvedColor;
	OnColor = ButtonDefault::OnColor;
	rect->setPosition(pos);
	rect->setSize(size);
	rect->setOrigin(Origin);
	rect->setFillColor(color);
	state = false;
	flag = false;
	this->type = type;
}

BaseButton::BaseButton(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f Origin, sf::Color color, float OutLine, sf::Color colorOutLine , TypePressed type):
	BaseButton(pos, size, Origin, color , type) 
{
	rect->setOutlineThickness(OutLine);
	rect->setOutlineColor(colorOutLine);
}

BaseButton::BaseButton(sf::Vector2f pos, TypePressed type, sf::Vector2f size, float OutLine, sf::Color colorOutLine):
	BaseButton(pos, size, (size*0.5f), {0,0,0,0} , OutLine , colorOutLine , type){}

BaseButton::BaseButton(sf::Vector2f pos, sf::Vector2f size, TypePressed type, float OutLine, sf::Color colorOutLine):
	BaseButton(pos, size, (size * 0.5f), { 0,0,0,0 }, OutLine, colorOutLine , type){}

void BaseButton::setTypePressed(TypePressed type) {
this->type = type;}

void BaseButton::update()
{
	sf::Vector2f mousepos = Input::MousePos();
	bool LKM = Input::LKM();
	bool isHovered = rect->getGlobalBounds().contains(mousepos);
	switch (type)
	{
	case TypePressed::HoveredCursor:

		if (isHovered) { state = true; }
		else { state = false; }

		break;
	case TypePressed::OneClick:

		if (isHovered && LKM && !flag) {
			state = true;
			flag = LKM;
		}
		else { state = false; }
		if (!LKM) { flag = false; }

		break;
	case TypePressed::OnOff:

		if (isHovered && LKM && !flag) {
			state = !state;
			flag = LKM;
		}
		if (!LKM) { flag = false; }

		break;
	case TypePressed::On:

		if (isHovered && LKM) {
			state = true;
		}

		break;
	case TypePressed::Pressed:

		if (isHovered && LKM && !flag) {
			state = true;
		}
		else { state = false; }
		break;
	default:
		break;
	}

	if (state && type != TypePressed::HoveredCursor) {
		rect->setFillColor(OnColor);
	}
	else if (isHovered) { rect->setFillColor(HorvedColor); }
	else { rect->setFillColor({ 0,0,0,0 }); }
}

void BaseButton::setVisible(bool state){
	Render::setVisible(rect.id(), state);
}

BaseButton& BaseButton::operator=(BaseButton & other)
{if (this != &other) {
	this->sfRect() = other.sfRect();
	this->Color = other.Color;
	this->OnColor = other.OnColor;
	this->HorvedColor = other.HorvedColor;
	this->state = other.state;
	this->flag = other.flag;
	this->type = other.type;}
	return *this;
}

BaseButton& BaseButton::operator=(BaseButton&& other)noexcept
{if (this != &other) {
	this->sfRect() = other.sfRect();
	this->Color = other.Color;
	this->OnColor = other.OnColor;
	this->HorvedColor = other.HorvedColor;
	this->state = other.state;
	this->flag = other.flag;
	this->type = other.type;}
	return *this;
}
