//BaseShape.hpp
#pragma once
#include"Render.hpp"
class ShapeRender {
	size_t render_id;
public:
	ShapeRender(size_t value):render_id(value){};
	//ShapeRender& operator=(ShapeRender&& other)noexcept;
	//ShapeRender& operator=(ShapeRender& other)noexcept;
};