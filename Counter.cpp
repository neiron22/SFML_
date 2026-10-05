//Counter.cpp
#include "Counter.hpp"
#include"FontManager.hpp"

static std::string trimZeros(std::string str) {
    // Ищем точку, если её нет - возвращаем как есть (например, для "45")
    if (str.find('.') == std::string::npos) return str;

    // Удаляем все нули с конца
    str.erase(str.find_last_not_of('0') + 1, std::string::npos);

    // Если после удаления нулей в конце осталась точка, удаляем и её
    if (!str.empty() && str.back() == '.') {
        str.pop_back();
    }
    return str;
}

Counter::Counter(sf::Vector2f pos , int characterSize , sf::Color color) {
	text_num.setFont(FontManager::get());

	text_num.setPosition(pos);

	text_num.setCharacterSize(characterSize);
	text_num.setFillColor(color);

	text_num.setString("0");
}
//


void Counter::draw(sf::RenderWindow& window) {window.draw(text_num);}

void Counter::updatef(float num) {
    char buffer[64];
    // %.2f означает: выводить float с 2 знаками после запятой
    std::snprintf(buffer, sizeof(buffer), "%.2f", num);

    std::string str(buffer);
    text_num.setString(trimZeros(str));
}
void  Counter::updateint(int num) {
	text_num.setString(std::to_string(num));
}
void Counter::updatesize_t(size_t num){
	text_num.setString(std::to_string(num));
}
