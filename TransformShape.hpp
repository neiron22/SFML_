//TransformShape.hpp
#pragma once
#include<SFML/Graphics/VertexArray.hpp>
#include<vector>
#include<cmath>

#include"SpecialDataTypes.hpp"
#include"constants.hpp"
namespace trsh {
	 void RotationVA(sf::VertexArray& va,float angle,  sf::Vector2f center, Range range);
	 void RotationVA(sf::VertexArray& va, float angle, sf::Vector2f center);

	 void SetRotationVA(sf::VertexArray& va, float currentAngle , float angle, sf::Vector2f center);

	 void RotationVAInNullPos(sf::VertexArray& va , float angle);
	 void setScileVA(sf::Vector2f NewScale, sf::Vector2f OldScale, sf::VertexArray& va, sf::Vector2f center, float angle, Range diaposon);
	 void moveVA(sf::VertexArray& va, sf::Vector2f vec);
	 void moveVA(sf::VertexArray& va, sf::Vector2f vec , Range range);

	 void Setfillcolor(sf::VertexArray& va, sf::Color color, Range range);
	 void Setfillcolor(sf::VertexArray& va, sf::Color color);

	 void RotationVV(float angle, std::vector<sf::Vertex>& vv, sf::Vector2f center, Range range);
	 void RotationVVInNullPos(std::vector<sf::Vertex>& vv, float angle);
	 void setScileVV(sf::Vector2f NewScale, sf::Vector2f OldScale, std::vector<sf::Vertex>& vv, sf::Vector2f center, float angle, Range diaposon);
	 void moveVV(std::vector<sf::Vertex>& vv, sf::Vector2f vec);

}