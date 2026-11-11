//ButtonDefault.hpp
#pragma once

#include<SFML/System/Vector2.hpp>
#include<SFML/Graphics/Color.hpp>

namespace ButtonDefault {
	// если не найдётся конструктора для конкретного случая
	const static sf::Vector2f size = { 40.f,40.f };
	const static float outsize = 5.f;
	const static sf::Color color = { 0,0,0,0 };
	const static sf::Color Outcolor = { 70,70,70 };
	const static sf::Color HorvedColor = { 200,200,200,30 };
	const static sf::Color OnColor = { 170,170,170,200 };
}