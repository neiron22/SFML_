//InputField.hpp
#pragma once
#include<SFML/Graphics.hpp>
#include<string>

class InputField{
    sf::RectangleShape background;
    sf::Text text;
    std::string inputString;
    bool isActive = false; // Активен ли сейчас ввод

public:
    InputField(sf::Vector2f pos, sf::Vector2f size, const sf::Font& font);

    // Обработка событий (вызывать внутри while(window.pollEvent(event)))
    void handleEvent(const sf::Event& event);

    void draw(sf::RenderWindow& window);

    // Получить введенное число
    float getValue();

    void clear();

};

