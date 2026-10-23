//color_in_shape.hpp
#pragma once
#include <SFML/System/Vector2.hpp> // Для sf::Vector2f
#include <SFML/Graphics/Color.hpp>  // Для sf::Color


struct color_in_shape {
	sf::Vector2f hsv_VS;
	float tone;
	sf::Color rgb;

	color_in_shape(float tone = 0.f, float hsv_V = 0.f, float hsv_S = 0.f , sf::Color rgb = sf::Color::White);
	color_in_shape(float tone = 0.f, sf::Vector2f hsv_VS = {0.f,0.f} ,sf::Color rgb = sf::Color::White);
	color_in_shape();
};