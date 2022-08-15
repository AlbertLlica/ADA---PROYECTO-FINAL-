/*
Estructura de Lista de Adyacencia para la representacion de grafo
para ser coloreado con el algoritmo de Welsh Powell.
*/

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "Vertex.h"
#include <iostream>
#include <string>
class Graph
{
public:
    std::list<Vertex> vertices;
    int size;
    int chromatic_number;
    friend class Vertex;
    friend class Edge;
    friend class Curso;
public:
    Graph();

    void insert_vertex(Curso a);
    void insert_edge(Curso a, Curso b);

    Vertex * get_vertex(Curso value);

    void colorize(); // Alogritmo Welsh Powell para colorear el grafo

    void print_to_console();
    void save_ostream(std::ostream & o);
    void show_dot(std::string filename);
    ~Graph();
};

#endif