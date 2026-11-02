//Text.hpp
#pragma once

#include<SFML/Graphics.hpp>

//*
class Text{
	sf::Text text_num;

public:
	Text(sf::Vector2f pos = {0.f,0.f}, int characterSize = 20, sf::Color color = {255,255,255});

	void draw(sf::RenderWindow & window);

	void update_string(std::string text);
	void updatef(float num);
	void updateint(int num);
	void updatesize_t(size_t num);
};

