//ColorIndicator.hpp
#pragma once
#include<SFML/Graphics.hpp>

class ColorIndicator {
	sf::VertexArray color_ton_area;
	sf::VertexArray color_area , point_color;
	sf::Vector2f pos_point_color;
	
	sf::Color colors[7];
	
	sf::Color current_color , final_color;
	sf::CircleShape point_tone;
	sf::RectangleShape rect_ton , rect_color , final_color_rect;
	float segment = 63.75f, point_radius;
	float length;

	int to_sector;

	bool select_tone , select_color;

	sf::Vector2f posBegin ,posEnd;
	sf::Vector2f pos_color_aera , size_color_area;
public:

	ColorIndicator(sf::Vector2f pos);

	void point_color_init(sf::Vector2f pos);

	void add_color_tranglines_rect(sf::Vector2f pos, sf::Vector2f size, sf::Color color_1 , sf::Color color_2 , bool add_size = false);

	void add_color_rect(sf::Vector2f pos, sf::Vector2f size, sf::Color color);
	
	void update(sf::Vector2f mousePos , bool LKM);

	void draw(sf::RenderWindow& window);

	sf::Color get_color();

};

