//ShapesGenerator.hpp
#pragma once
#include<SFML/Graphics/VertexArray.hpp>
#include <unordered_map>
#include <functional>

#include"Type.hpp"

class ShapesGenerator{
	std::unordered_map<ShapeType, sf::VertexArray> ModelChanche;

public:
	ShapesGenerator();

	sf::VertexArray get(ShapeType type);
};

inline ShapesGenerator shapegenerator;

