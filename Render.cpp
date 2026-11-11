//Render.сpp
#include "Render.hpp"
size_t Render::id = 0;
std::unordered_map<size_t, RenderItem> Render::items;

size_t Render::addDrawble(sf::Drawable& obj)
{items.emplace(id,RenderItem{ &obj , true ,  } );
id++; //>>
return id - 1;
}

void Render::deleteDrawble(size_t id){
	auto it = items.find(id);
	if (it != items.end()) {
		items.erase(it);
	}
}


void Render::setVisible(size_t id, bool state){
	auto it = items.find(id);
	if (it != items.end()) {
		it->second.flag = state;
	}
}

void Render::draw(sf::RenderWindow& window){
	for (auto& i : items) {	
		if (i.second.flag) {
		window.draw(*i.second.obgect);
		}
}}
