//Size_slider.cpp
#include "Size_slider.hpp"

static void add_rect(sf::VertexArray& vertarr, sf::Vector2f pos, float size_x, float size_y, sf::Color color , sf::Color color_2) {
	float out_line_len = (size_x + size_y) * 0.25;

	float size_out_x = size_x + out_line_len;
	float size_out_y = size_y + out_line_len;

	vertarr.append({ pos + sf::Vector2f(-size_out_x , -size_out_y) , color_2 });
	vertarr.append({ pos + sf::Vector2f(-size_out_x , size_out_y) , color_2 });
	vertarr.append({ pos + sf::Vector2f(size_out_x , size_out_y) , color_2 });

	vertarr.append({ pos + sf::Vector2f(size_out_x , size_out_y) , color_2 });
	vertarr.append({ pos + sf::Vector2f(size_out_x , -size_out_y) , color_2 });
	vertarr.append({ pos + sf::Vector2f(-size_out_x , -size_out_y) , color_2 });

	vertarr.append({ pos + sf::Vector2f(-size_x , -size_y) , color });
	vertarr.append({ pos + sf::Vector2f(-size_x , size_y) , color });
	vertarr.append({ pos + sf::Vector2f(size_x , size_y) , color });

	vertarr.append({ pos + sf::Vector2f(size_x , size_y) , color });
	vertarr.append({ pos + sf::Vector2f(size_x , -size_y) , color });
	vertarr.append({ pos + sf::Vector2f(-size_x , -size_y) , color });

}
static void add_2_rect(sf::VertexArray& vertarr, sf::Vector2f pos, float size_x, sf::Color color, sf::Color color_2) {
	float size_y = size_x * 0.4f;
	float factor = 3.f;
	sf::Vector2f center_1(size_x * -factor, 0.f); center_1 += pos;
	sf::Vector2f center_2(size_x * factor, 0.f); center_2 += pos;

	add_rect(vertarr, center_1, size_x, size_y, color , color_2);
	add_rect(vertarr, center_2, size_x, size_y, color, color_2);
}

two_rect_data::two_rect_data(int begin_index, int end_index ,  sf::Vector2f pos , sf::Color color):
begin_index(begin_index) , end_index(end_index) , pos(pos) , color(color)
{}

two_rect_data::two_rect_data():
	begin_index(0), end_index(0), pos({0.f,0.f}), color(sf::Color::White) { }


Size_slider::Size_slider(sf::Vector2f pos, float lengh, sf::Color color_1, sf::Color color_2) :
	vertarr(sf::Triangles) ,
	select(false) , lengh(lengh)
{
	float size_x = lengh * 0.02f , out_size = 2.5f;
	float distance = lengh * 0.1f;
	count_segments = std::max(1 ,int(lengh) / 20);

	rects = std::make_unique<two_rect_data[]>((count_segments));

	rect_1.setSize({size_x, lengh});
	//rect_1.setOutlineThickness(out_size);

	rect_1.setFillColor(color_1);
	//rect_1.setOutlineColor(color_2);

	rect_1.setOrigin({size_x*0.5f , 0.f});

	rect_2 = rect_1;

	rect_1.setPosition({pos.x - distance ,pos.y });
	rect_2.setPosition({ pos.x + distance ,pos.y });

	for (int i = 0; i < count_segments; i++) {
		sf::Vector2f position( pos.x , pos.y + (lengh * (float(i + 0.5f) / count_segments)));
		int oldVertexCount = int(vertarr.getVertexCount());
		add_2_rect(vertarr , position , size_x * 1.7f , color_1 , color_2);

		rects[i] = two_rect_data{oldVertexCount , int(vertarr.getVertexCount()) , position , color_1 };
	}

	//последняя дополнительная пара прямоугольнков
	{
		sf::Vector2f position(pos.x, pos.y + lengh * 0.5f);
		add_2_rect(vertarr, position, size_x * 1.5f, {230,230,230}, {0,0,0,0});
	}
	//if (vertarr.getVertexCount() >= 30) { rect_1.setFillColor(sf::Color::Red); }
}

void Size_slider::draw(sf::RenderWindow& window){
	window.draw(rect_1);
	window.draw(rect_2);
	window.draw(vertarr);
}

void Size_slider::update(sf::Vector2f mouse_pos, float ckroll, bool tap_tab){

	
}

