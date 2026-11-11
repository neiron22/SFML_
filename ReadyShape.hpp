//ReadyShape.hpp
#pragma once
#include<SFML/Graphics/VertexArray.hpp>
#include<cmath>
#include"constants.hpp"
#include"TransformShape.hpp"

namespace sh {
	void VAaddVA(sf::VertexArray& baseVA, sf::VertexArray& addVA);
	void VAaddVA(sf::VertexArray & baseVA  , sf::VertexArray addVA);

	sf::VertexArray Rect(float angle = 0.f, sf::Vector2f size = { 10.f,10.f }, sf::Color color = sf::Color::White);
	void Rect(sf::VertexArray& Va , float angle = 0.f, sf::Vector2f size = { 10.f,10.f }, sf::Color color = sf::Color::White);

	sf::VertexArray Cross(float angle = 0.f, float radius = 20.f, sf::Color color = { 50,50,50 });
	void Cross(sf::VertexArray& Va, float angle = 0.f, float radius = 20.f, sf::Color color = { 50,50,50 });

	sf::VertexArray RegularPoligon(size_t facets = 3, float radius = 14.f, float angle = 0.f , sf::Color color = sf::Color::White);
	void RegularPoligon(sf::VertexArray& Va, size_t facets = 3, float radius = 14.f, float angle = 0.f, sf::Color color = sf::Color::White);

	sf::VertexArray RegularPoligonAndBorder(size_t facets = 3, float radius = 10.f, float outRadius = 4.f, float angle = 0.f, sf::Color color = sf::Color::White, sf::Color color_2 = sf::Color::White);
	void RegularPoligonAndBorder(sf::VertexArray& Va, size_t facets = 3, float radius = 10.f, float outRadius = 4.f, float angle = 0.f, sf::Color color = sf::Color::White, sf::Color color_2 = sf::Color::White);

	sf::VertexArray HollovRegularPoligon(size_t facets = 3, float radius = 10.f , float outRadius = 4.f, float angle = 0.f, sf::Color color = sf::Color::White);
	void HollovRegularPoligon(sf::VertexArray& Va, size_t facets = 3, float radius = 10.f, float outRadius = 4.f, float angle = 0.f, sf::Color color = sf::Color::White);

	sf::VertexArray Trangle(float radius = 14.f, float angle = 0.f, sf::Color color = sf::Color::White);
	void Trangle(sf::VertexArray& Va, float radius = 14.f, float angle = 0.f, sf::Color color = sf::Color::White);

}