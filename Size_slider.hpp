//Size_slider.hpp
#pragma once
#include<SFML/Graphics.hpp>
#include<memory>

#include"Button.hpp"

struct two_rect_data {
	sf::Vector2f pos;
	int begin_index, end_index;
	sf::Color color;
	two_rect_data(int begin_index, int end_index, sf::Vector2f pos, sf::Color color);
	two_rect_data();

};

class Size_slider{
	bool select;

	int count_segments;
	float lengh;

	sf::VertexArray vertarr;
	sf::RectangleShape rect_1, rect_2;

	std::unique_ptr<two_rect_data[]> rects;

	

public:
	Size_slider(sf::Vector2f pos , float size , sf::Color color_1, sf::Color color_2);

	void draw(sf::RenderWindow & window);

	void update(sf::Vector2f mouse_pos , float ckroll , bool tap_tab);
};

