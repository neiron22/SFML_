//ShapesGenerator.cpp
#include "ShapesGenerator.hpp"
#include "ReadyShape.hpp"

ShapesGenerator::ShapesGenerator() {
	ModelChanche[ShapeType::RegularPolygon] = sh::RegularPoligon(5);
	ModelChanche[ShapeType::Rect] = sh::Rect();
	ModelChanche[ShapeType::Rtangle] = sh::Trangle();
}

sf::VertexArray ShapesGenerator::get(ShapeType type)
{
	return ModelChanche[type];
}