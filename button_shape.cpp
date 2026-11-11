//button_shape.cpp
#include "button_shape.hpp"
#include"Render.hpp"

button_shape::button_shape(): pos({0.f ,0.f}) , type(TypePressed::OneClick) , state(false){ }

button_shape::button_shape(sf::Vector2f pos, TypePressed type , bool default_status) : pos(pos),type(type){
	state = default_status; flag = false;

	float size = 40.f , out_size = 5.f;
	
	rect.setSize({size,size});
	rect.setOrigin(sf::Vector2f{ size,size } * 0.5f);

	rect.setOutlineThickness(out_size);

	rect.setFillColor({0,0,0,0});
	rect.setOutlineColor({70,70,70});

	rect.setPosition(pos);

}

button_shape::button_shape(sf::Vector2f size, float outSize, sf::Vector2f pos, TypePressed type, bool default_status, bool centerOrigin)
: pos(pos) , type(type)
{
	state = default_status; flag = false;

	rect.setSize(size);
	if (centerOrigin) { rect.setOrigin(size * 0.5f); }

	rect.setOutlineThickness(outSize);

	rect.setFillColor({ 0,0,0,0 });
	rect.setOutlineColor({ 70,70,70 });

	rect.setPosition(pos);
}

void button_shape::reSize(sf::Vector2f newSize, bool AddToCuttentValue){
	if (AddToCuttentValue) { newSize += rect.getSize(); }

	newSize = { std::fabs(newSize.x)  , std::fabs(newSize.y) };

	rect.setSize(newSize);
	rect.setOrigin(newSize*0.5f);

}

void button_shape::move(sf::Vector2f vec) { rect.move(vec); pos += vec; }

void button_shape::update(sf::Vector2f mouse_pos, bool LKM) {
	sf::Vector2f delta = pos - mouse_pos;
	sf::Vector2f distance = rect.getSize() * 0.5f;

	bool isHovered = (std::fabs(delta.x) < distance.x && std::fabs(delta.y) < distance.y);

	

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

		if (isHovered && LKM ) {
			state = true;
		}
		
		break;	
	case TypePressed::Pressed:

		if (isHovered && LKM && !flag) {
			state = true;}
		else{ state = false; }
		break;
	default:
		break;
	}

	


	if (state && type != TypePressed::HoveredCursor) {
		rect.setFillColor({ 200,200,200,200 });
	}
	else if (isHovered) { rect.setFillColor({255,255,255,30}); }
	else { rect.setFillColor({ 0,0,0,0 }); }
}


void button_shape::draw(sf::RenderWindow& window) {
	window.draw(rect);
}

void button_shape::setClick(bool value){
	state = value;
}

sf::Vector2f button_shape::get_pos(){return pos;}
