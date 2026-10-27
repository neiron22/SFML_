//slider.cpp
#include "slider.hpp"


Slider::Slider(sf::Vector2f pos, float len, sf::Color color1, sf::Color color2
, bool toVertical,float InteractionRadius ):
len(len) , InteractionRadius(InteractionRadius),toVertical(toVertical)
{
	select = false;

	pos_begin = pos;

	if (!toVertical) {
		float size_y = len * 0.02f;
		float radius_point = len * 0.032f;

		InteractionRadius += radius_point;

		sf::Vector2f size = { len , size_y };
		rect_path.setPosition(pos);
		rect_path.setSize(size);
		rect_path.setOrigin({ 0.f , size.y * 0.5f });

		circle_point.setPosition(pos);
		circle_point.setRadius(radius_point);
		circle_point.setOrigin({ radius_point , radius_point });

	}
	else{
		float size_x = len * 0.02f;
		float radius_point = len * 0.032f;
		

		InteractionRadius += radius_point;

		sf::Vector2f size = { size_x , len };
		rect_path.setPosition(pos);
		rect_path.setSize(size);
		rect_path.setOrigin({ size.x * 0.5f , 0.f });

		circle_point.setPosition(pos);
		circle_point.setRadius(radius_point);
		circle_point.setOrigin({ radius_point , radius_point });
	}
	float out_line = 2.2f;

	rect_path.setOutlineThickness(out_line);
	circle_point.setOutlineThickness(out_line);

	rect_path.setFillColor(color2);
	circle_point.setFillColor(color2);

	rect_path.setOutlineColor(color1);
	circle_point.setOutlineColor(color1);
}

void Slider::draw(sf::RenderWindow& window) {
	window.draw(rect_path);
	window.draw(circle_point);}

void Slider::update(sf::Vector2f mouse_pos , bool LKM)
{
	sf::Vector2f point_pos = circle_point.getPosition();

	if ((circle_point.getGlobalBounds().contains(mouse_pos) && LKM) || select) {
		select = true;
	if(toVertical){
	float to_mouse = std::clamp(mouse_pos.y, pos_begin.y, pos_begin.y + len);

	circle_point.setPosition(pos_begin.x, to_mouse);
	}
	else {
		float to_mouse = std::clamp(mouse_pos.x, pos_begin.x, pos_begin.x + len);

		circle_point.setPosition(to_mouse, pos_begin.y);
	}

	}


	sf::Vector2f abs_delta = {point_pos.x - mouse_pos.x,point_pos.y - mouse_pos.y };
	bool to_InteractionRadius = (abs_delta.x * abs_delta.x + abs_delta.y * abs_delta.y) > InteractionRadius*InteractionRadius;
	
	
	if (!LKM || to_InteractionRadius) { select = false; }


}

float Slider::getProcess(){
	if (toVertical) {
		float current_x = circle_point.getPosition().y;

		return (current_x - pos_begin.y) / len;
	}
	float current_x = circle_point.getPosition().x;

	return (current_x - pos_begin.x) / len;	
}

float Slider::getValue(float min, float max)
{
	return min + getProcess() * (max-min);
}

void Slider::setProcess(float factor){
	factor = std::clamp(factor , 0.f , 1.f);
	factor = 1.f - factor;

	if (toVertical) {
		circle_point.setPosition(circle_point.getPosition().x , pos_begin.y + (factor * len));}
	else{
		circle_point.setPosition(pos_begin.x + (factor * len), circle_point.getPosition().y);
	}

}



