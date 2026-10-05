#include "Shapes_list.hpp"


Shapes_list::Shapes_list(sf::Vector2f pos) :pos(pos), Area({60.f,50.f} , 5.f ,pos, Type_pressed::HoveredCursor) {
	SelecterIndexShape = -1;
	distance = {0.f , 90.f}; // константа(формально) которую не собераюсь менять
	
}

void Shapes_list::add_object(){
	sf::Vector2f position = pos + (distance * float(buttons.size()));
	buttons.emplace_back(position , Type_pressed::OneClick);
	Area.reSize(distance , true);
	Area.move(distance*0.5f);

	SelecterIndexShape++;
}

void Shapes_list::delete_object(size_t index){
	if (index >= buttons.size()) { return; }
	buttons.erase(buttons.begin()+index);

	for (size_t i = index; i < buttons.size(); i++) { buttons[i].move(-distance); }

	Area.reSize(-distance, true);
	Area.move(-distance*0.5f);

	SelecterIndexShape = std::clamp(SelecterIndexShape , -1 , int(buttons.size()-1));
}

void Shapes_list::update(sf::Vector2f mouse_pos, bool LKM) {
	for (int i = 0; i < buttons.size(); i++) {
	buttons[i].update(mouse_pos , LKM);
	if (buttons[i].getClick()) { SelecterIndexShape = i; }
	
	}

	Area.update(mouse_pos , LKM);

}

int Shapes_list::get_index()
{
	return SelecterIndexShape;
}

bool Shapes_list::switching()
{
	for (int i = 0; i < buttons.size(); i++) {
		if (buttons[i].getClick()) { return true; }
	}
	return false;
}


void Shapes_list::draw(sf::RenderWindow& window) {
	for (auto& i : buttons) { i.draw(window); }
	Area.draw(window);
}