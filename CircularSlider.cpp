//CircularSlider.cpp
#include"CircularSlider.hpp"

#include<numbers>


CircularSlider::CircularSlider(sf::Vector2f pos, float Radius, float Out_Radius)
{
	PointPos = pos;
	to_radian = float(180.f / std::numbers::pi_v<float>);

	offset = Radius * 0.75f;

	vert_arr.setPrimitiveType(sf::Triangles);
	Out_Radius += Radius;

	sf::Color color = { 130,130,130,200 };

	float p_2 = float(std::numbers::pi) * 2.f;
	int facets = 16;


	for (int i = 0; i < facets; i++) {
		float angle_1 = (p_2 * i / facets);
		float angle_2 = (p_2 * (i + 1.f) / facets);

		float size_2 = 15.f;
		if (i % 2 != 0) { size_2 += 2.f; }

		sf::Vector2f pos_00 = pos + sf::Vector2f{ sinf(angle_1) , cosf(angle_1) } *Radius;
		sf::Vector2f pos_01 = pos + sf::Vector2f{ sinf(angle_1) , cosf(angle_1) } *Out_Radius;

		sf::Vector2f pos_10 = pos + sf::Vector2f{ sinf(angle_2) , cosf(angle_2) } *Radius;
		sf::Vector2f pos_11 = pos + sf::Vector2f{ sinf(angle_2) , cosf(angle_2) } *Out_Radius;

		vert_arr.append(sf::Vertex(pos_00, color));
		vert_arr.append(sf::Vertex(pos_01, color));
		vert_arr.append(sf::Vertex(pos_10, color));

		vert_arr.append(sf::Vertex(pos_10, color));
		vert_arr.append(sf::Vertex(pos_11, color));
		vert_arr.append(sf::Vertex(pos_01, color));
	}

	color = { 40,40,40,255 };
	
	facets = 8 * 2;

	Radius *= 0.9f;

	for (int i = 0; i < facets; i += 2) {
		float angle_1 = (p_2 * (i - 0.125f) / facets);
		float angle_2 = (p_2 * (i + 0.125f) / facets);

		float size_2 = 15.f;
		if (i % 2 != 0) { size_2 += 2.f; }

		sf::Vector2f pos_00 = pos + sf::Vector2f{ sinf(angle_1) , cosf(angle_1) } *Radius;
		sf::Vector2f pos_01 = pos + sf::Vector2f{ sinf(angle_1) , cosf(angle_1) } *Out_Radius;

		sf::Vector2f pos_10 = pos + sf::Vector2f{ sinf(angle_2) , cosf(angle_2) } *Radius;
		sf::Vector2f pos_11 = pos + sf::Vector2f{ sinf(angle_2) , cosf(angle_2) } *Out_Radius;

		vert_arr.append(sf::Vertex(pos_00, color));
		vert_arr.append(sf::Vertex(pos_01, color));
		vert_arr.append(sf::Vertex(pos_10, color));

		vert_arr.append(sf::Vertex(pos_10, color));
		vert_arr.append(sf::Vertex(pos_11, color));
		vert_arr.append(sf::Vertex(pos_01, color));
	}
	float point_radius = Radius * 0.15f;
	shape_point.setPosition(pos);
	shape_point.setRadius(point_radius);

	shape_point.setOutlineThickness(3.f);
	
	shape_point.setFillColor({90,90,90});
	shape_point.setOutlineColor({ 190,190,190 });

	shape_point.setOrigin({ point_radius ,point_radius+offset });
}

void CircularSlider::update(sf::Vector2f mouse_pos, float mouse_csrolled, bool LKM , float factor){
	if(vert_arr.getBounds().contains(mouse_pos)){

	if (mouse_csrolled != 0.f) { shape_point.rotate(mouse_csrolled); return; }

	if (LKM) { 

	sf::Vector2f delta = mouse_pos - PointPos;

	float angle = std::atan2(delta.y , delta.x);
	angle *= to_radian;
	angle = std::roundf(angle);
	angle += factor;

	shape_point.setRotation(angle + 90.f);

	 }

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
		int angleint = int(shape_point.getRotation());
		shape_point.setRotation(float(angleint - angleint % 10));
	}

	}
}

float CircularSlider::getRotation() { return shape_point.getRotation(); }

void CircularSlider::setRotation(float Angle) { shape_point.setRotation(Angle); }

void CircularSlider::draw(sf::RenderWindow& window) {
	window.draw(vert_arr);
	window.draw(shape_point);
}
