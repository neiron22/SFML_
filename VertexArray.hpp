//VertexArray.hpp
#pragma once
#include"Render.hpp"
#include<SFML/Graphics/VertexArray.hpp>
class VertexArray{
	size_t render_id;
	sf::VertexArray VA;
public:
	VertexArray() { render_id = Render::addDrawble(VA); }
	rsize_t id() const { return render_id; }
	sf::VertexArray& get() { return VA; }
	sf::VertexArray* operator->() { return &VA; }
	const sf::VertexArray* operator->() const { return &VA; }
	operator sf::VertexArray& () { return VA; }
	operator const sf::VertexArray& () const { return VA; }

	VertexArray& operator=(VertexArray&& other)noexcept;
	VertexArray& operator=(VertexArray& other);

	VertexArray& operator=(sf::VertexArray&& other)noexcept;
	VertexArray& operator=(sf::VertexArray& other);

	~VertexArray();
	};
