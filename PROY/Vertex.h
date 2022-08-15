#ifndef _NODE_H_
#define _NODE_H_

#include <list>
#include "Edge.h"
#include "curso.h"
enum Color
{
    nocolor,
    red, // 1
    orange, // 2
    yellow,  // 3
    green, // 4
    blue, // 5
    purple, //6
    turquoise, // 7
    cyan, // 8
    pink, // 9
    olive, // 10
    gold, // 11
    chocolate, // 12
};

class Vertex
{
public:
    Curso course;
    int order; // Orden
    Color color;
    std::list<Edge> edge_list;
public:
    Curso get_course();
    Vertex(Curso);
    
    void increase_order();

    int get_order() const; 


};

#endif