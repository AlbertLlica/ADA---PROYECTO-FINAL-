#include "Vertex.h"

Vertex::Vertex(char value)
{
    this->value = value;
    this->color = Color::nocolor;
    this->connections = 0;
}

char Vertex::get_value()
{
    return this->value;
}

void Vertex::increase_connection()
{
    this->connections++;
}

int Vertex::get_connections() const
{
    return this->connections;
}