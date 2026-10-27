//Size_slider.cpp
#include "Size_slider.hpp"

static void add_rect(sf::VertexArray& vertarr, sf::Vector2f pos, float size_x, float size_y, sf::Color color) {

	vertarr.append({ pos + sf::Vector2f(-size_x , -size_y) , color });
	vertarr.append({ pos + sf::Vector2f(-size_x , size_y) , color });
	vertarr.append({ pos + sf::Vector2f(size_x , size_y) , color });

	vertarr.append({ pos + sf::Vector2f(size_x , size_y) , color });
	vertarr.append({ pos + sf::Vector2f(size_x , -size_y) , color });
	vertarr.append({ pos + sf::Vector2f(-size_x , -size_y) , color });

}
static void add_2_rect(sf::VertexArray& vertarr, sf::Vector2f pos, float size_x , float factor, sf::Color color) {
	float size_y = size_x * 0.25f;
	sf::Vector2f center_1(-factor, 0.f); center_1 += pos;
	sf::Vector2f center_2(factor, 0.f); center_2 += pos;

	add_rect(vertarr, center_1, size_x, size_y, color);
	add_rect(vertarr, center_2, size_x, size_y, color);
}

two_rect_data::two_rect_data(int begin_index, int end_index ,  sf::Vector2f pos , sf::Color color):
begin_index(begin_index) , end_index(end_index) , pos(pos) , color(color)
{}

two_rect_data::two_rect_data():
	begin_index(0), end_index(0), pos({0.f,0.f}), color(sf::Color::White) { }


Size_slider::Size_slider(sf::Vector2f pos, float lengh, sf::Color color_1) :
	vertarr(sf::Triangles),
	select(false), lengh(lengh), center(pos),

	update_multiplier(0.1f),

	counter({pos.x - 5.f , pos.y - 25.f}),

	value(1.f) , active_flag(false),
	min_size_shape(0.1f)
{
	update_flag = true;

	float size_x = lengh * 0.02f  , size_y = lengh * 0.7f, out_size = 2.5f;
	float distance = lengh * 0.1f;
	count_segments = std::max(1 ,int(lengh) / 12);

	rects = std::make_unique<two_rect_data[]>((count_segments));

	rect_1.setSize({size_x, size_y });
	//rect_1.setOutlineThickness(out_size);

	rect_1.setFillColor(color_1);
	//rect_1.setOutlineColor(color_2);

	rect_1.setOrigin({size_x*0.5f ,size_y*0.5f });

	rect_2 = rect_1;

	rect_1.setPosition({pos.x - distance ,pos.y });
	rect_2.setPosition({ pos.x + distance ,pos.y });

	float factor = size_x * 4.5f;
	for (int i = 0; i < count_segments; i++) {
		float rect_size = size_x * 2.f;
		sf::Vector2f position( pos.x , pos.y + (lengh * (float(i + 0.5f) / count_segments)));
		int oldVertexCount = int(vertarr.getVertexCount());
		if ((i + 1) % 5 == 0) { rect_size *= 1.5f; }
		add_2_rect(vertarr , position , rect_size , factor, color_1);

		rects[i] = two_rect_data{oldVertexCount , int(vertarr.getVertexCount()) , position , color_1 };
	}

	//последняя дополнительная пара прямоугольнков
	{
		sf::Vector2f position(pos);
		add_2_rect(vertarr, position, size_x, 4.f,  {220,220,220});
	}
	//if (vertarr.getVertexCount() >= 30) { rect_1.setFillColor(sf::Color::Red); }
}

void Size_slider::draw(sf::RenderWindow& window){
	window.draw(rect_1);
	window.draw(rect_2);
	window.draw(vertarr);

	counter.draw(window);
}

void Size_slider::update(sf::Vector2f mouse_pos, float ckroll, bool tap_tab){
	counter.updatef(value);

	active_flag = !vertarr.getBounds().contains(mouse_pos);
	if (active_flag && !update_flag) { return; }
	update_flag = false;

	float lengh05 = lengh * 0.5f;

	value += ckroll * update_multiplier;

	if (value < min_size_shape) { value = min_size_shape; }

	float ckroll_2 = ckroll * 2.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) { value = 1.f; }

	for (int i = 0; i < count_segments;i++) {

		float to_centerY = std::fabs((center.y) - rects[i].pos.y) / lengh05;
		float singl = (center.y - rects[i].pos.y) > 0.f ? 1.f : -1.f;

		if ((value <= min_size_shape && ckroll < 0.f)) { break; }

	bool to_move = false;
	if (to_centerY > 1.f) {
		rects[i].pos.y += (lengh * singl);
		to_centerY = std::fabs((center.y) - rects[i].pos.y) / lengh05;
		to_move = true;}
	
	sf::Color newColor = rects[i].color;
	newColor.a = sf::Uint8(255.f * (1.f - to_centerY));

	rects[i].color = newColor;
	rects[i].pos.y += ckroll_2;

	for (int j = rects[i].begin_index;j < rects[i].end_index; j++) {
			vertarr[j].color = newColor;
			
			if (to_move) {vertarr[j].position.y += (lengh * singl);}

				vertarr[j].position.y += ckroll_2;
	}

	}
}

