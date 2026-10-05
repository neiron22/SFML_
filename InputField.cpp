////InputField.cpp
//#include "InputField.hpp"
//
//InputField::InputField(sf::Vector2f pos, sf::Vector2f size, const sf::Font& font)
//{
//    background.setSize(size);
//    background.setPosition(pos);
//    background.setFillColor(sf::Color(30, 30, 30));
//    background.setOutlineThickness(2.f);
//    background.setOutlineColor(sf::Color(100, 100, 100));
//
//    text.setFont(font);
//    text.setCharacterSize(20);
//    text.setFillColor(sf::Color::White);
//    text.setPosition(pos.x + 5, pos.y + 2); // Отступ внутри рамки
//}
//
//void InputField::handleEvent(const sf::Event& event){
//    if (!isActive) return;
//
//    if (event.type == sf::Event::TextEntered) {
//        if (event.text.unicode < 128) { // Проверяем, что это ASCII символ
//            char c = static_cast<char>(event.text.unicode);
//
//            if (c == '\b' && !inputString.empty()) { // Backspace
//                inputString.pop_back();
//            }
//            else if (c >= '0' && c <= '9') { // Разрешаем только цифры (для чисел)
//                inputString += c;
//            }
//            // Если нужен полный текст, убери проверку на цифры выше
//
//            text.setString(inputString);
//        }
//    }
//    // Клик по полю для активации
//
//    if (event.type == sf::Event::MouseButtonPressed) {
//        if (background.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
//            isActive = true;
//            background.setOutlineColor(sf::Color::Yellow); // Подсветка активного поля
//        }
//        else {
//            isActive = false;
//            background.setOutlineColor(sf::Color(100, 100, 100));
//        }
//    }
//}
//
//void InputField::draw(sf::RenderWindow& window) {
//    window.draw(background);
//    window.draw(text);
//}
//
//float InputField::getValue(){
//if (inputString.empty()) return 0.f;
//return std::stof(inputString);
//}
//
//void InputField::clear(){
//    inputString.clear(); 
//    text.setString("");
//}