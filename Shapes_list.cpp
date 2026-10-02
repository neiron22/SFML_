#include "Shapes_list.hpp"


Shapes_list::Shapes_list(sf::Vector2f pos) :pos(pos), Area( pos ,Type_pressed::HoveredCursor) {
	SelecterIndexShape = -1;
	distance = {0.f , 90.f}; // константа(формально) которую не собераюсь менять
	
}

void Shapes_list::add_object(){
	sf::Vector2f position = pos + (distance * float(buttons.size()));
	buttons.emplace_back(position , Type_pressed::OaneClikc);
	Area.reSize(distance , true);
}

void Shapes_list::delete_object(size_t index){
	if (index >= buttons.size()) { return; }
	buttons.erase(buttons.begin()+index);
	Area.reSize(-distance, true);
}

void Shapes_list::update(sf::Vector2f mouse_pos, bool LKM) {
	for (int i = 0; i < buttons.size(); i++) {
	buttons[i].update(mouse_pos , LKM);
	if (buttons[i].getClick()) { SelecterIndexShape = i; }
	
	}

}

int Shapes_list::get_index()
{
	return SelecterIndexShape;
}


void Shapes_list::draw(sf::RenderWindow& window) {
	for (auto& i : buttons) { i.draw(window); }
	Area.draw(window);
}