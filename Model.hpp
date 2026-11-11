//Model.hpp
#pragma once

#include<SFML/Graphics.hpp>
#include<vector>
#include<memory>
#include<numbers>

#include <cstdarg>

#include"Type.hpp"
#include"SpecialDataTypes.hpp"

//class Button;

struct ShapeInfo{
	Range range;
	sf::Vector2f pos  , scale;
	//sf::Vector2f Origin;
	float radius , angle;

	ColorShape color_1 , color_2 , color_3;

	ShapeInfo(Range range, float radius, sf::Vector2f pos, float angle) noexcept;
};


struct ModelData {
	std::vector<ShapeInfo> shapes;
	std::vector<sf::Vertex> vertices;

	ModelData() noexcept = default;
	
};

class Changed {
	bool value = false;
public:
	bool check(size_t index , size_t size){
	if (index >= size) { return true; }
	value = true;
	return false;}
	void reset() { value = false; }

	operator bool() const {return value;}
};

class ModelEditor {
	ModelData& data;

	static constexpr float p_2 = float(std::numbers::pi) * 2.f;
	static constexpr float to_radian = p_2 / 360.f;

public:
	Changed changed;
	size_t size() { return data.shapes.size(); };

	bool empty() { return data.shapes.empty(); }
	void AddShape(sf::Vector2f pos, float radius, size_t facets, float angle);
	void DeleteShape(size_t index);
	void MoveShape(size_t index, sf::Vector2f delta);
	void RotateShape(size_t index, float angle);
	void SetRotationShape(size_t index, float angle);
	void SetColorShape(size_t index , ColorShape color);
	void ScaleShape(size_t index , sf::Vector2f scale);
	ShapeInfo* getShape(size_t index);


	ModelEditor(ModelData & data) :data(data) {}
	
	ModelData& getData() { return data; }
};


class ModelRender {
	sf::VertexArray va;
public:
	void buildForm(const ModelData& data);
	void draw(sf::RenderWindow& window);

	ModelRender() :va(sf::Triangles) {}
};

class Model{
	ModelData data;
public:
	ModelEditor editor;
	ModelRender render;

	Model();

	void update(sf::Vector2f mouse_pos);
};

