#include "Shapes_list.hpp"

float p_2 = float(std::numbers::pi) * 2.f;
float to_radian = p_2 / 360.f;

static sf::VertexArray return_vert_delet(float anglefactor = 0.f) {
	sf::VertexArray vertarr(sf::Triangles);
	float radius = 20.f;

	sf::Color color = { 50,50,50 };

	for (int i = 0; i < 2; i++) {
		float angle = p_2 * ((i + 0.5f) / (4.f)) + (p_2 * 0.5f * anglefactor);
		float angle_1 = angle + (p_2 / 24);
		float angle_2 = angle - (p_2 / 24);

		sf::Vector2f pos_1 = sf::Vector2f(std::cosf(angle_1) ,std::sinf(angle_1)) * radius;
		sf::Vector2f pos_2 = sf::Vector2f(std::cosf(angle_2), std::sinf(angle_2)) * radius;

		sf::Vector2f pos_3 = sf::Vector2f(std::cosf(angle_1), std::sinf(angle_1)) * -radius;
		sf::Vector2f pos_4 = sf::Vector2f(std::cosf(angle_2), std::sinf(angle_2)) * -radius;

		vertarr.append(sf::Vertex(pos_1 , color));vertarr.append(sf::Vertex(pos_2, color));vertarr.append(sf::Vertex(pos_3, color));
		vertarr.append(sf::Vertex(pos_3, color));vertarr.append(sf::Vertex(pos_4, color));vertarr.append(sf::Vertex(pos_1, color));
	}
	return vertarr;
}


Shapes_list::Shapes_list(sf::Vector2f pos) :pos(pos), 
Area_buttons({60.f,50.f} , 5.f ,pos, Type_pressed::HoveredCursor),
Area_tools({ 180.f,120.f }, 5.f ,pos + sf::Vector2f(60.f, -30.f), Type_pressed::HoveredCursor ,false ,false){

	SelecterIndexShape = -1;
	distance = {0.f , 90.f}; // константа(формально) постараюсь не менять

	sf::Vector2f posDeleteButton = pos + sf::Vector2f(90.f, 0.f);
	deleteShapeButton = button(posDeleteButton, Type_pressed::OneClick, return_vert_delet());

	sf::Vector2f posAddButton = pos + sf::Vector2f(90.f, 60.f);
	AddShapeButton = button(posAddButton, Type_pressed::OneClick, return_vert_delet(0.25f));
	
}

void Shapes_list::add_object(){
	sf::Vector2f position = pos + (distance * float(buttons.size()));
	buttons.emplace_back(position , Type_pressed::OneClick);
	Area_buttons.reSize(distance , true);
	Area_buttons.move(distance*0.5f);

	SelecterIndexShape++;
}

void Shapes_list::delete_object(size_t index){
	buttons.erase(buttons.begin()+index);

	for (size_t i = index; i < buttons.size(); i++) { buttons[i].move(-distance); }

	Area_buttons.reSize(-distance, true);
	Area_buttons.move(-distance*0.5f);

	SelecterIndexShape = std::clamp(SelecterIndexShape , -1 , int(buttons.size()-1));
}

void Shapes_list::update(sf::Vector2f mouse_pos, bool LKM) {
	for (int i = 0; i < buttons.size(); i++) {
	buttons[i].update(mouse_pos , LKM);
	if (buttons[i].getClick()) { SelecterIndexShape = i; }
	
	}

	Area_buttons.update(mouse_pos , LKM);
	deleteShapeButton.update(mouse_pos , LKM);
	AddShapeButton.update(mouse_pos, LKM);

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
	Area_buttons.draw(window);
	Area_tools.draw(window);
	deleteShapeButton.draw(window);
	AddShapeButton.draw(window);
}