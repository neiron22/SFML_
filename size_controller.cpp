#include "size_controller.hpp"

Size_controller::Size_controller(sf::Vector2f pos) :
	distance(100.f , 0.f),
	size_slider_x(pos , 180.f , { 70,70,70 }),
	size_slider_y(pos + sf::Vector2f{50 , 0.f}, 180.f, {70,70,70}),
	size_multipler_angle(pos , 30.f , 5.f , sf::Color::Yellow),
	to_x_y(pos + distance) , 
	to_multipler_angle(pos + distance*2.f)
{



}

void Size_controller::update(sf::Vector2f mouse_pos, bool LKM , float mouse_skroll){
	to_x_y.update(mouse_pos , LKM);
	to_multipler_angle.update(mouse_pos, LKM);

	size_slider_x.update(mouse_pos , mouse_skroll);
	if (to_x_y.getClick()) {

		size_slider_y.update(mouse_pos, mouse_skroll);


		size_multipler_angle.update();
	}
}

void Size_controller::draw(sf::RenderWindow& window)
{
	size_slider_x.draw(window);

	to_x_y.draw(window);

	if (to_x_y.getClick()) {
		size_slider_y.draw(window);
		to_multipler_angle.draw(window);

		if (to_multipler_angle.getClick()) {
			size_multipler_angle.draw(window);
		}
	}
}
