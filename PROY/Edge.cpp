#include "Edge.h"

Edge::Edge(Vertex * vertex)
{
    this->vertex = vertex;
}

Vertex * Edge::get_vertex() const
{
    return this->vertex;
}