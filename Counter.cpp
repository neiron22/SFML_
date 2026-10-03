//Counter.cpp
#include "Counter.hpp"
#include"FontManager.hpp"

Counter::Counter(sf::Vector2f pos , int characterSize , sf::Color color) {
	text_num.setFont(FontManager::get());

	text_num.setPosition(pos);

	text_num.setCharacterSize(characterSize);
	text_num.setFillColor(color);

	text_num.setString("0");
}
//


void Counter::draw(sf::RenderWindow& window) {window.draw(text_num);}

void  Counter::updatef(float num) {
text_num.setString(std::to_string(num));
}
void  Counter::updateint(int num) {
	text_num.setString(std::to_string(num));
}
void Counter::updatesize_t(size_t num){
	text_num.setString(std::to_string(num));
}
