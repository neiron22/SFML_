//FontManager.hpp
#pragma once
#include<SFML/Graphics.hpp>

// и тут тоже

class FontManager {
	static sf::Font font;
public:
	static sf::Font& get();
	static void init();
};

