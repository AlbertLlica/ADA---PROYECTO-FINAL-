#ifndef _EDGE_H_
#define _EDGE_H_

class Vertex;

class Edge
{
private:
    Vertex * vertex;
public:
    Edge(Vertex *);
    Vertex * get_vertex() const;
};

#endif