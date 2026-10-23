//Model.hpp
#pragma once

#include<SFML/Graphics.hpp>
#include<vector>
#include<numbers>

#include"Type.hpp"
#include"color_in_shape.hpp"

class Button;

struct Shape_in_VertexArray{
	size_t begin, end;
	sf::Vector2f pos , size_multipler;
	float radius , angle;
	color_in_shape color_1 , color_2 , color_3;

	Shape_in_VertexArray(size_t begin, size_t end  , float radius ,sf::Vector2f pos, float angle = 0) noexcept:
	begin(begin), radius(radius), end(end), pos(pos), angle(angle),
	color_1(0,0,0,sf::Color::White), color_2(0,0,0, sf::Color::White),color_3(0,0,0, sf::Color::White),

	size_multipler({1.f , 1.f})
	
	{ }
};

class Model{
	sf::VertexArray Vertarr;
	size_t count_vertex;

	std::vector<Shape_in_VertexArray> shapes;

	sf::Vector2f mouse_delta_pos;

	bool selecter_shape;

	float p_2 = float(std::numbers::pi) * 2.f;
	float to_radian = p_2 / 360.f;
public:
	
	Model() noexcept;

	void draw(sf::RenderWindow& window);

	void AddShape(sf::Vector2f pos = { 450.f,350.f }, float size_shape = 30.f, size_t facets = 3, float angle = 0 );

	void DeleteShape(size_t index);

	void Delete_shape();

	void move_1_shape(Shape_in_VertexArray& zahvat_shape, sf::Vector2f vec);

	void setSelectedAngle(size_t index , float angle);

	void set_shape_color(size_t index, color_in_shape color, bool color_1, bool color_2, bool color_3);

	bool CursorToShape(sf::Vector2f point, size_t index);

	void update(sf::Vector2f mouse_pos, bool lkm, size_t indexSelectShape);

	float get_shape_angle(size_t index);

	const color_in_shape & get_shape_color(size_t index);

	int get_shape_count() { return int(shapes.size()); }

	void size_shape_multipler(size_t index, float factor);

	void set_point_color(size_t index_point, sf::Color color);
};

