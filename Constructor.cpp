//Constructor.cpp
#include "Constructor.hpp"

Constructor::Constructor() :

	shape_Counter({ 10, 10 }),
	pointer_hsape_Counter({ 10,40 }),
	poligon_Counter({ 220, 15 }, 22),

	vertex_button(ButtonType::add_vertex_Triangles),
	deleted_button(ButtonType::deleted_shape),
	shape_add({340.f , 45.f} , Type_pressed::OaneClikc),
	shape_delete({ 430.f , 45.f }, Type_pressed::OaneClikc),

	color_indicator(sf::Vector2f{ 530.f,10.f }),
	slider_1({ 500.f,170.f }),
	silder_counter({ 600.f , 140.f }),

	buttonPoligonAdd({ 260.f , 80.f }, Type_pressed::OaneClikc),
	buttonPoligonDelet({ 200.f , 80.f }, Type_pressed::OaneClikc),

	size_increase({80.f , 100.f} , Type_pressed::OaneClikc),
	size_decrease({ 140.f , 100.f }, Type_pressed::OaneClikc)
	{

	sf::Vector2f point_pos{ 340, 45 };
	float distance = 90.f;

	poligon = 3;

	buttons.push_back(&vertex_button);
	buttons.push_back(&deleted_button);


	for (auto& it : buttons) {
		it->init(point_pos);
		point_pos.x += distance;
	}
}

void Constructor::update(sf::Vector2f mouse_pos, float dt) {

	int angle = int(360.f * slider_1.getSilverLevel());

	bool LKM = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	bool PKM = sf::Mouse::isButtonPressed(sf::Mouse::Right);

	//for (auto& it : buttons) {it->update(mouse_pos, LKM, dt);}
	size_t index = shapes_list.get_index();

	shape_add.update(mouse_pos, LKM);
	shape_delete.update(mouse_pos, LKM);


	size_increase.update(mouse_pos, LKM);
	size_decrease.update(mouse_pos, LKM);
	

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
		model.Delete_shape(); 
		shapes_list.delete_object(index);
	}

	
	shapes_list.update(mouse_pos , LKM);

	model.update(mouse_pos, LKM , index);
	
	

	shape_Counter.updateint(model.get_shape_count());
	poligon_Counter.updatesize_t(poligon);
	silder_counter.updateint(angle);


	

	

	



	
}


void  Constructor::draw(sf::RenderWindow& window) {
	//for (auto& it : buttons) {it->draw(window);}

	shape_add.draw(window);
	shape_delete.draw(window);


	model.draw(window);

	shape_Counter.draw(window);
	poligon_Counter.draw(window);

	pointer_hsape_Counter.draw(window);


	color_indicator.draw(window);

	buttonPoligonAdd.draw(window);
	buttonPoligonDelet.draw(window);

	slider_1.draw(window);
	silder_counter.draw(window);


	size_increase.draw(window);
	size_decrease.draw(window);

	shapes_list.draw(window);
}