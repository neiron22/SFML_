#include "Shapes_list.hpp"
#include"ReadyShape.hpp"
#include"ShapesGenerator.hpp"
#include"ButtonDefaultValue.hpp"

Shapes_list::Shapes_list(sf::Vector2f pos) :pos(pos), 
Area_buttons(pos , { 60.f,50.f }, TypePressed::HoveredCursor),
Area_tools((pos + sf::Vector2f(60.f, -30.f)), { 180.f,120.f }, { 0.f,0.f },
	ButtonDefault::color, ButtonDefault::outsize, ButtonDefault::Outcolor,TypePressed::HoveredCursor)
{
	Area_tools.HorvedColor = {120,120,120,35};

	SelecterIndexShape = 0;
	distance_y = {0.f , 90.f}; // константа(формально) постараюсь не менять
	distance_x = { 60.f , 0.f };
	sf::Vector2f posDeleteButton = pos + sf::Vector2f(90.f, 0.f);
	deleteShapeButton = ButtonVertarr(posDeleteButton  ,sh::Cross(45.f) , ButtonDefault::size , TypePressed::OneClick);

	sf::Vector2f posAddButton = pos + sf::Vector2f(90.f, 60.f);
	AddShapeButton = ButtonVertarr(posAddButton, sh::Cross(), ButtonDefault::size, TypePressed::OneClick);
	
	sf::Vector2f posShapeTypetool = posAddButton + distance_x;
	ShapeTypeTool = BaseButton(posShapeTypetool);

	TypesButtons.reserve(ShapeTypeCount);
	sf::Vector2f posTypeShapeButton = posShapeTypetool + distance_y;
	for (size_t i = 0;i < ShapeTypeCount;i++) {
		TypesButtons.emplace_back(std::make_unique<ButtonVertarr>(posTypeShapeButton , TypePressed::On ,shapegenerator.get(static_cast<ShapeType>(i))));
		posTypeShapeButton += distance_y * 0.5f;
	}
	TypesButtons[0]->setState(true);
}

void Shapes_list::AddObj(){
	sf::Vector2f position = pos + (distance_y * float(buttons.size()));
	buttons.emplace_back(std::make_unique<BaseButton>(position , ButtonDefault::size , TypePressed::On));
	sf::Vector2f newSize(Area_buttons.sfRect().getSize() + distance_y);
	Area_buttons.sfRect().setSize(newSize);
	Area_buttons.sfRect().setOrigin(newSize*0.5f);
	Area_buttons.sfRect().move(distance_y*0.5f);
}

void Shapes_list::DelObj(size_t index){
	if (index >= buttons.size()) { return; }
	buttons.erase(buttons.begin()+index);

	for (size_t i = index; i < buttons.size(); i++) { buttons[i]->sfRect().move(-distance_y); }

	sf::Vector2f newSize = Area_buttons.sfRect().getSize() - distance_y;

	Area_buttons.sfRect().setSize(newSize);
	Area_buttons.sfRect().setOrigin(newSize * 0.5f);
	Area_buttons.sfRect().move(-distance_y*0.5f);

	SelecterIndexShape = std::clamp(SelecterIndexShape , size_t(0), buttons.size()-1);
}

void Shapes_list::update() {
	Area_tools.update();
	Area_buttons.update();
	deleteShapeButton.update();
	AddShapeButton.update();
	ShapeTypeTool.update();
	{
		static size_t IndexOnButton = 0;
		for (size_t i = 0;i < buttons.size();i++) {
			buttons[i]->update();
			if (buttons[i]->getstate() && IndexOnButton != i) {
				buttons[IndexOnButton]->setState(false);
				IndexOnButton = i; }
		}
	}
	for (int i = 0;i < TypesButtons.size();i++) {
		TypesButtons[i]->setVisible(ShapeTypeTool);
		if(ShapeTypeTool){
		TypesButtons[i]->update();
		if(TypesButtons[i]->getstate() && IndexOnButton != i) {
			TypesButtons[IndexOnButton]->setState(false);
			IndexOnButton = i;}
		}
	}
	if (AddShapeButton) { AddObj(); }
	if (deleteShapeButton) { DelObj(SelecterIndexShape); }
}

int Shapes_list::get_index() const
{return SelecterIndexShape;}

bool Shapes_list::switching()
{
	for (int i = 0; i < buttons.size(); i++) {
	if (buttons[i]->getstate()) { return true; }}
	return false;
}


void Shapes_list::draw(sf::RenderWindow& window) {}

