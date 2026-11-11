//Input.hpp
#pragma once
#include<SFML/System/Vector2.hpp>


class Input{
	static bool lkm , pkm;
	static float mouseskroll;
	static sf::Vector2f Mouse_Pos;
	
public:

	static void update(float MouseSkroll , sf::Vector2f MousePos);

	static sf::Vector2f MousePos() {return Mouse_Pos;}
	static bool LKM() { return lkm; }
	//static bool PKM() { return pkm; }
	static float MouseSckroll() { return mouseskroll; }
};

