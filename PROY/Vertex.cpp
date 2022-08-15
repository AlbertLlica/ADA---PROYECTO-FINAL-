#include "Vertex.h"

Vertex::Vertex(Curso course)
{
    this->course = course;
    this->color = Color::nocolor;
    this->order = 0;
}

Curso Vertex::get_course()
{
    return this->course;
}

void Vertex::increase_order()
{
    this->order++;
}

int Vertex::get_order() const
{
    return this->order;
}