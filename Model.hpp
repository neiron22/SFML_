//Model.hpp
#pragma once

#include<SFML/Graphics.hpp>
#include<vector>
#include<numbers>

#include"Type.hpp"

class Button;

struct Shape_in_VertexArray{
	size_t begin, end;
	sf::Vector2f pos;
	float radius , angle;
	sf::Color color;
	Shape_in_VertexArray(size_t begin, size_t end  , float radius ,sf::Vector2f pos, float angle = 0) noexcept:
		begin(begin), radius(radius), end(end), pos(pos), angle(angle), color(sf::Color::White) {}
};

class Model{
	sf::VertexArray Vertarr;
	std::vector<Shape_in_VertexArray> shapes;
	size_t count_vertex;
	sf::Vector2f mouse_delta_pos;

	float p_2 = float(std::numbers::pi) * 2.f;
	float to_radian = p_2 / 360.f;
public:
	
	Model() noexcept {
		Vertarr.setPrimitiveType(sf::Triangles); count_vertex = 0;
		 mouse_delta_pos = { 0.f,0.f };
	};

	void draw(sf::RenderWindow& window);

	void AddShape(sf::Vector2f pos = { 450.f,350.f }, float size_shape = 30.f, size_t facets = 3, float angle = 0 );

	void DeleteShape(size_t index);

	void Delete_shape();

	void move_1_shape(Shape_in_VertexArray& zahvat_shape, sf::Vector2f vec);

	void setSelectedAngle(size_t index , float angle);

	bool CursorToShape(sf::Vector2f point, size_t index);

	void update(sf::Vector2f mouse_pos, bool lkm, size_t indexSelectShape);


	int get_shape_count() { return int(shapes.size()); }

	void set_shape_color(size_t index, sf::Color color);

	void size_shape_multipler(size_t index, float factor);

	void set_point_color(size_t index_point, sf::Color color);
};

