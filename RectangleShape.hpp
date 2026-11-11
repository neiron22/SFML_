//RectangleShape.hpp
#pragma once
#include <SFML/Graphics/RectangleShape.hpp>  // Для sf::RectangleShape
#include"Render.hpp"

class RectangleShape {
	sf::RectangleShape R;
	size_t render_id;
public:
	RectangleShape() { render_id = Render::addDrawble(R); }
	size_t id() const { return render_id; }
		
	sf::RectangleShape* operator->() { return &R; }
	const sf::RectangleShape* operator->() const { return &R; }
	operator sf::RectangleShape& () { return R; }
	operator const sf::RectangleShape& () const { return R; }

	RectangleShape& operator=(RectangleShape&& other)noexcept;
	RectangleShape& operator=(RectangleShape& other);

	~RectangleShape() { Render::deleteDrawble(render_id); }
};