//Constructor.cpp
#include "Constructor.hpp"



Constructor::Constructor() :

	shape_Counter({ 10, 10 }),
	pointer_hsape_Counter({ 10,40 }),
	poligon_Counter({ 220, 15 }, 22),

	shape_add({ 340.f , 45.f }, Type_pressed::OneClick),
	shape_delete({ 430.f , 45.f }, Type_pressed::OneClick),

	buttonPoligonAdd({ 260.f , 80.f }, Type_pressed::OneClick),
	buttonPoligonDelet({ 200.f , 80.f }, Type_pressed::OneClick),
	colorIndicator({750.f, 10.f})

	{

	sf::Vector2f point_pos{ 340, 45 };
	float distance = 90.f;

	poligon = 3;

}

void Constructor::update(sf::Vector2f mouse_pos, float dt, float MouseSkrolled){

	bool LKM = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	bool PKM = sf::Mouse::isButtonPressed(sf::Mouse::Right);

	//for (auto& it : buttons) {it->update(mouse_pos, LKM, dt);}
	size_t index = shapes_list.get_index();

	shape_add.update(mouse_pos, LKM);
	shape_delete.update(mouse_pos, LKM);


	colorIndicator.update(mouse_pos , LKM);
	

	buttonPoligonAdd.update(mouse_pos, LKM);
	buttonPoligonDelet.update(mouse_pos, LKM);

	if (buttonPoligonAdd.getClick()) { poligon++; }
	if (buttonPoligonDelet.getClick() && poligon > 3) { poligon--; }


	/*if (model.get_zahvat_index() >= 0) {
		slider_1.update(mouse_pos, LKM, model.get_zahvat_index(), model.get_angle_zahvat_index());
		color_indicator.update(mouse_pos, LKM, model.get_zahvat_index(), model.get_ColorShape());}*/

	if (shape_add.getClick()) {
		model.AddShape({450.f , 350.f} , 30.f , poligon , 0.f);
		shapes_list.add_object();
	}
	if (shape_delete.getClick()) {
		model.DeleteShape(index);
		shapes_list.delete_object(index);
	}

	
	shapes_list.update(mouse_pos , LKM);

	model.update(mouse_pos, LKM , index);
	
	

	shape_Counter.updateint(model.get_shape_count());
	poligon_Counter.updatesize_t(poligon);
	
}


void  Constructor::draw(sf::RenderWindow& window) {
	//for (auto& it : buttons) {it->draw(window);}

	shape_add.draw(window);
	shape_delete.draw(window);

	colorIndicator.draw(window);

	model.draw(window);

	shape_Counter.draw(window);
	poligon_Counter.draw(window);

	pointer_hsape_Counter.draw(window);

	buttonPoligonAdd.draw(window);
	buttonPoligonDelet.draw(window);

	shapes_list.draw(window);
}