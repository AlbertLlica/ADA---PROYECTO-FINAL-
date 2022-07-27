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
private:
    std::list<Vertex> vertices;
    int size;
    int chromatic_number;
    friend class Vertex;
    friend class Edge;
public:
    Graph();

    void insert_vertex(char a);
    void insert_edge(char a, char b);

    Vertex * get_vertex(char value);

    void colorize(); // Alogritmo Welsh Powell para colorear el grafo

    void print_to_console();
    void save_ostream(std::ostream & o);
    void show_dot(std::string filename);
    ~Graph();
};

#endif