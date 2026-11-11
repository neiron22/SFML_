//CircularSlider.cpp
#include"CircularSlider.hpp"
#include"ReadyShape.hpp"
#include"TransformShape.hpp"

#include"Input.hpp"

#include<numbers>


CircularSlider::CircularSlider(sf::Vector2f pos, float Radius, float Out_Radius, sf::Color color, sf::Color color_2)
{
	PointPos = pos;
	Angle = 0.f;

	this->color = color_2;

	vert_arr->setPrimitiveType(sf::Triangles);
	Point->setPrimitiveType(sf::Triangles);

	Out_Radius += Radius;

	float p_2 = float(std::numbers::pi) * 2.f;
	int facets = 24;

	sh::HollovRegularPoligon(vert_arr, facets , Radius , Out_Radius , 0.f , color);
	trsh::moveVA(vert_arr,  pos);

	for (int i = 0; i < facets; i ++) {
		float angle = ((float(i) / facets) * 360.f) + 90.f;
		float rad = ((float(i) / facets) * Constants::P_2)-(90.f * Constants::ToRad);
		size_t count = vert_arr->getVertexCount();
		Range range = { count , count + 6 };

		float size_x = (i % 3 == 0) ? 8.f : 4.5f;
		size_x = (i % 6 == 0)? 10.f : size_x;

		rects.emplace_back(Range{vert_arr->getVertexCount() , 0});
		sh::Rect(vert_arr , angle , {size_x, 2.5f} , color_2);
		rects.back().end = vert_arr->getVertexCount();

		sf::Vector2f position = pos + sf::Vector2f{ std::cosf(rad) ,std::sinf(rad) } * (Radius);
		trsh::moveVA(vert_arr , position, range);}
	float point_radius = Radius * 0.13f;

	size_t poligon = 16;

	sh::RegularPoligonAndBorder(Point, poligon, point_radius , point_radius+2.f, 0.f, color_2 , color);


	trsh::moveVA(Point, { pos.x  , pos.y - (Radius - point_radius) });

}

void CircularSlider::update(){
	sf::Vector2f mousepos = Input::MousePos();
	if(vert_arr->getBounds().contains(mousepos)){
		
		int procces = int(std::roundf((Angle / 360.f) * (rects.size())));
		if (procces < 0) { procces = rects.size() - 1; }
		if (procces >= rects.size()) { procces = 0; }
		static int targetProcess = 0;
		trsh::Setfillcolor(vert_arr, color, rects[targetProcess]);
		trsh::Setfillcolor(vert_arr , sf::Color::White , rects[procces]);

		targetProcess = procces;

		if (Input::LKM()) {
		sf::Vector2f delta = mousepos - PointPos;
		float angle = std::atan2(delta.y, delta.x);
		angle *= Constants::ToGradus;
		angle += 90.f;

		Angle = angle>=0.f ? std::roundf(angle) : 360.f + std::roundf(angle);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
			Angle = 10.f * std::roundf(Angle*0.1f);
		}

		{	static float targetAngle = 0;
			trsh::RotationVA(Point, Angle-targetAngle, PointPos);
			targetAngle = Angle;
		}
		
		}
	}
}

float CircularSlider::getRotation() { return Angle; }

void CircularSlider::setRotation(float Angle) { /*shape_point.setRotation(Angle);*/ }

void CircularSlider::draw(sf::RenderWindow& window) {}
