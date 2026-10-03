#pragma once
//collision.hpp
#include"SFML/Graphics.hpp"

inline bool CursorToShape(sf::Vector2f mouse_pos, sf::Vector2f pos , float radius) {
	
	sf::Vector2f dlt_vec = mouse_pos - pos;
	float delta = (dlt_vec.x * dlt_vec.x) + (dlt_vec.y * dlt_vec.y);
	if (delta < radius * radius) { return true; }
	return false;
}
