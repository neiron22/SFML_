//RectangleShape.cpp
#include "RectangleShape.hpp"

RectangleShape& RectangleShape::operator=(RectangleShape&& other) noexcept
{
    if (this != &other){
        Render::deleteDrawble(this->render_id);
        this->R = other.R;  
    }

    return *this;
}

RectangleShape& RectangleShape::operator=(RectangleShape& other)
{
    if (this != &other) {
        Render::deleteDrawble(this->render_id);
        this->R = other.R;
    }

    return *this;
}
