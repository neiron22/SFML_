//Size_slider.hpp
#pragma once
#include<SFML/Graphics.hpp>
#include<memory>

//#include"Button.hpp"

#include"Counter.hpp"

struct two_rect_data {
	sf::Vector2f pos;
	int begin_index, end_index;
	sf::Color color;
	two_rect_data(int begin_index, int end_index, sf::Vector2f pos, sf::Color color);
	two_rect_data();

};

class Size_slider{
	bool select , update_flag, active_flag;
	int count_segments;
	float lengh;

	const float min_size_shape;


	float update_multiplier;

	

	sf::VertexArray vertarr;
	sf::RectangleShape rect_1, rect_2;
	sf::Vector2f center;

	std::unique_ptr<two_rect_data[]> rects;

	Counter counter;

public:

	float value;

	Size_slider(sf::Vector2f pos , float size , sf::Color color_1);

	void draw(sf::RenderWindow & window);

	void update(sf::Vector2f mouse_pos , float ckroll , bool tap_tab);

	float getValue() { return value; };

	void setValue(float new_value) { value = new_value; };

	bool get_active() { return !active_flag; }
};

