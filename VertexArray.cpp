//VertexArray.cpp
#include "VertexArray.hpp"

VertexArray& VertexArray::operator=(VertexArray&& other) noexcept
{
    if (this != &other) {
        Render::deleteDrawble(this->render_id);
        this->VA = std::move(other.VA);
    }

    return *this;
}

VertexArray& VertexArray::operator=(VertexArray& other)
{
    if (this != &other) {
        Render::deleteDrawble(this->render_id);
        this->VA = std::move(other.VA);
    }

    return *this;
}

VertexArray& VertexArray::operator=(sf::VertexArray&& other) noexcept
{
    this->VA = other;
    return *this;
}

VertexArray& VertexArray::operator=(sf::VertexArray& other)
{
    this->VA = other;
    return *this;
}


VertexArray::~VertexArray()
{Render::deleteDrawble(render_id);}
