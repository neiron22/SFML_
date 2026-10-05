#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <stdexcept>

class NumberInputField {
    sf::RectangleShape background;
    sf::Text text;
    std::string inputString;
    bool isActive = false;
    bool allowFloat;

public:
    NumberInputField(sf::Vector2f pos, sf::Vector2f size, const sf::Font& font, bool allowFloat = true)
        : allowFloat(allowFloat) {
        background.setSize(size);
        background.setPosition(pos);
        background.setFillColor(sf::Color(30, 30, 30)); // Темный фон
        background.setOutlineThickness(2.f);
        background.setOutlineColor(sf::Color(100, 100, 100));

        text.setFont(font);
        text.setCharacterSize(20);
        text.setFillColor(sf::Color::White);
        // Центрируем текст по вертикали
        text.setPosition(pos.x + 5, pos.y + (size.y - 20) * 0.5f);
    }

    // ВАЖНО: вызывается внутри while(window.pollEvent(event))
    void handleEvent(const sf::Event& event) {
        // 1. Обработка клика мыши для активации/деактивации поля
        if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
            if (background.getGlobalBounds().contains(mousePos)) {
                isActive = true;
                background.setOutlineColor(sf::Color::Yellow); // Подсветка фокуса
            }
            else {
                isActive = false;
                background.setOutlineColor(sf::Color(100, 100, 100));
            }
        }

        // Снятие фокуса по Enter
        if (event.type == sf::Event::KeyPressed && isActive) {
            if (event.key.code == sf::Keyboard::Enter || event.key.code == sf::Keyboard::Tab) {
                isActive = false;
                background.setOutlineColor(sf::Color(100, 100, 100));
            }
        }

        if (!isActive) return; // Если поле не в фокусе, ввод игнорируем

        // 2. Обработка самого ввода символов
        if (event.type == sf::Event::TextEntered) {
            sf::Uint32 unicode = event.text.unicode;

            if (unicode == 8 && !inputString.empty()) {
                // Backspace (ASCII 8)
                inputString.pop_back();
            }
            else if (unicode >= '0' && unicode <= '9') {
                // Цифры
                inputString += static_cast<char>(unicode);
            }
            else if (unicode == '-' && inputString.empty()) {
                // Минус только в самом начале
                inputString += '-';
            }
            else if (allowFloat && unicode == '.' && inputString.find('.') == std::string::npos) {
                // Точка только одна и если разрешены дробные
                inputString += '.';
            }

            text.setString(inputString);
        }
    }

    void draw(sf::RenderWindow& window) {
        window.draw(background);
        window.draw(text);
    }

    // Получить текущее число
    float getValue() const {
        if (inputString.empty() || inputString == "-") return 0.f;
        try {
            return std::stof(inputString);
        }
        catch (...) {
            return 0.f; // Защита от кривого ввода
        }
    }

    // Установить число извне (например, когда выбрал фигуру и хочешь показать её угол)
    void setValue(float val) {
        inputString = std::to_string(val);
        // Убираем лишние нули в конце (например, 45.000000 -> 45)
        if (inputString.find('.') != std::string::npos) {
            inputString.erase(inputString.find_last_not_of('0') + 1, std::string::npos);
            if (inputString.back() == '.') inputString.pop_back();
        }
        text.setString(inputString);
    }

    bool getIsActive() const { return isActive; }
};