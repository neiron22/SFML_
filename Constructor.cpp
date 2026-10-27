//Constructor.cpp
#include "Constructor.hpp"



Constructor::Constructor() :
	poligon_Counter({ 200.f, 72.5f }, 22),

	shape_add({ 140.f , 45.f }, Type_pressed::OneClick),
	shape_delete({ 140.f , 100.f }, Type_pressed::OneClick),

	buttonPoligon({ 40.f,60.f }, 6.f, { 200.f, 72.5f }, Type_pressed::HoveredCursor),
	colorIndicator({ 750.f, 10.f }),

	angleCounter({ 590.f , 40.f }),
	color_rgb_counter({1000.f , 320.f}),
	//---------
	circularSlider({ 630.f,80.f }, 60.f, 6.f),
	//slider({ 300.f, 30.f }, 220.f , {100,100,100} ,{30,30,30} ),
	//multiplerSilder_x({ 300.f, 50.f }, 100.f),
	//multiplerSilder_y({ 300.f, 80.f }, 100.f),
	size_slider({ 300.f, 80.f } , 200.f , {70,70,70}),

	//---------
	button_color_1({ 15.f , 15.f }, 2.f, { 750.f, 160.f }, Type_pressed::On_off, true),
	button_color_2({ 15.f , 15.f }, 2.f, { 750.f , 185.f }, Type_pressed::On_off, true),
	button_color_3({ 15.f , 15.f }, 2.f, { 750.f , 210.f }, Type_pressed::On_off, true),
	button_color({ 790.f , 183.f } , Type_pressed::On_off , false)
	{

	sf::Vector2f point_pos{ 340, 45 };
	float distance = 90.f;

	poligon = 3;

}

void Constructor::update(sf::Vector2f mouse_pos, float dt, float MouseSkrolled){

	bool LKM = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	bool PKM = sf::Mouse::isButtonPressed(sf::Mouse::Right);

	//for (auto& it : buttons) {it->update(mouse_pos, LKM, dt);}
	shapes_list.update(mouse_pos , LKM);

	size_t index = shapes_list.get_index();

	//---------
	circularSlider.update(mouse_pos , MouseSkrolled, LKM);

	if (shape_add.getClick()) {
		model.AddShape({450.f , 350.f} , 10.f , poligon , 0.f);
		shapes_list.add_object();
	}
	if (shape_delete.getClick()) {
		model.DeleteShape(index);
		shapes_list.delete_object(index);
	}

	if (shapes_list.switching()) {
		size_slider.value = model.get_shape(index).scail_x;
		circularSlider.setRotation(model.get_shape(index).angle);
		colorIndicator.set_HSVcolor(model.get_shape(index).color_1);
	}

	float angle = circularSlider.getRotation();

	

	angleCounter.updatef(angle);

	//---------
	//slider.update(mouse_pos , LKM);

	size_slider.update(mouse_pos , MouseSkrolled , LKM);

	//multiplerSilder_x.update(mouse_pos, LKM);
	//multiplerSilder_y.update(mouse_pos, LKM);

	shape_add.update(mouse_pos, LKM);
	shape_delete.update(mouse_pos, LKM);


	colorIndicator.update(mouse_pos , LKM);

	sf::Color color = colorIndicator.get_RGBcolor();
	color_rgb_counter.update_string(std::to_string(color.r) + " " + std::to_string(color.g) + " " + std::to_string(color.b) + " " + std::to_string(color.a));


	button_color.update(mouse_pos, LKM);

	bool flag_color_1 = true;
	bool flag_color_2 = true;
	bool flag_color_3 = true;

	if (button_color.getClick()) {
		button_color_1.update(mouse_pos, LKM);
		button_color_2.update(mouse_pos, LKM);
		button_color_3.update(mouse_pos, LKM);

		flag_color_1 = button_color_1.getClick();
		flag_color_2 = button_color_2.getClick();
		flag_color_3 = button_color_3.getClick();
	}

	buttonPoligon.update(mouse_pos, LKM);

	if (buttonPoligon.getClick()) { poligon += int(MouseSkrolled); poligon = size_t(std::clamp(int(poligon), 3 ,36)); }
	


	/*if (model.get_zahvat_index() >= 0) {
		slider_1.update(mouse_pos, LKM, model.get_zahvat_index(), model.get_angle_zahvat_index());
		color_indicator.update(mouse_pos, LKM, model.get_zahvat_index(), model.get_ColorShape());}*/
	//if (index >= 0) {
	//	
	//}
	

	model.update(mouse_pos, LKM , index);
	model.setSelectedAngle(index , angle);
	if (size_slider.get_active()) {
		model.scaleVerticesGlobal(index, size_slider.value, size_slider.value);
	}

	model.set_shape_color(index ,colorIndicator.get_HSVColor(),
		flag_color_1, flag_color_2, flag_color_3);
	
	poligon_Counter.updatesize_t(poligon);
	
}


void  Constructor::draw(sf::RenderWindow& window) {
	size_slider.draw(window);
	//for (auto& it : buttons) {it->draw(window);}

	//---------
	circularSlider.draw(window);
	angleCounter.draw(window);
	//---------
	//slider.draw(window);
	//multiplerSilder_x.draw(window);
	//multiplerSilder_y.draw(window);


	shape_add.draw(window);
	shape_delete.draw(window);

	colorIndicator.draw(window);

	button_color.draw(window);

	if (button_color.getClick()) {
		button_color_1.draw(window);
		button_color_2.draw(window);
		button_color_3.draw(window);
	}

	model.draw(window);


	poligon_Counter.draw(window);

	color_rgb_counter.draw(window),

	buttonPoligon.draw(window);

	shapes_list.draw(window);
}