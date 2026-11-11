//color_in_shape.hpp
#pragma once
#include <SFML/System/Vector2.hpp> // Для sf::Vector2f
#include <SFML/Graphics/Color.hpp>  // Для sf::Color

struct ColorShape {
	sf::Vector2f hsv_VS;
	float tone;
	sf::Color rgb;

	ColorShape(float tone = 0.f, float hsv_V = 0.f, float hsv_S = 0.f , sf::Color rgb = sf::Color::White);
	ColorShape(float tone = 0.f, sf::Vector2f hsv_VS = {0.f,0.f} ,sf::Color rgb = sf::Color::White);
	ColorShape();
};

struct Range {
	size_t begin = 0, end = 0;
	Range()noexcept = default;

	Range(size_t b, size_t e) noexcept : begin(b), end(e) {}

	size_t count() const noexcept {
		return (end > begin) ? (end - begin) : 0;
	}

	Range& operator-=(size_t value) {
		if (begin >= value) begin -= value; else begin = 0;
		if (end >= value) end -= value; else end = 0;
		return *this;
	}

	Range operator-(size_t value) const {
		Range r = *this;
		r -= value;
		return r;
	}
};