//Render.hpp
#pragma once
//#include<vector>
#include<unordered_map>
#include<SFML/Graphics/Drawable.hpp>
#include<SFML/Graphics/RenderWindow.hpp>

struct RenderItem {
	sf::Drawable* obgect;
	bool flag;};

class Render{
	static std::unordered_map<size_t, RenderItem> items;
	static size_t id;
public:
	
	Render() = default;
	Render(const Render&) = delete;
	Render& operator=(const Render&) = delete;
	static size_t addDrawble(sf::Drawable& obj);
	static void deleteDrawble(size_t id);
	static void setVisible(size_t id, bool state);
	static void draw(sf::RenderWindow& window);
};

