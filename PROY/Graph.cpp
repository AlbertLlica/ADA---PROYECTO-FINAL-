#include "Graph.h"

#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

Graph::Graph()
{
    this->size = 0;
}

Graph::~Graph()
{

}

void Graph::insert_vertex(char value)
{
    this->vertices.push_back(Vertex(value));
    this->size++;
}

void Graph::insert_edge(char a, char b)
{
    Vertex * v1 = this->get_vertex(a);
    Vertex * v2 = this->get_vertex(b);

    if (v1 && v2) 
    {
        v1->edge_list.push_back(Edge(v2));
        v2->edge_list.push_back(Edge(v1));
    }

    v1->increase_connection();
    v2->increase_connection();
}

Vertex * Graph::get_vertex(char value)
{
    for (std::list<Vertex>::iterator i = this->vertices.begin(); i != this->vertices.end(); ++i)
    {
        if (i->get_value() == value)
        {
            return &(*i);
        }
    }
    return nullptr;
}

bool sort_by_connections(const Vertex & v1, const Vertex & v2)
{
    return v1.get_connections() <= v2.get_connections();
}

/*
    Algoritmo de Welsh Powell para la coloracion de grafos
*/
void Graph::colorize()
{
    this->vertices.sort(sort_by_connections);
    this->vertices.reverse();
    int coloured_nodes = 0;

    for (int i = Color::red; i != Color::chocolate; i++)
    {
        // Si todos los nodos fueron coloreados, terminara el algoritmo
        if (coloured_nodes == this->size) break;

        this->chromatic_number++;

        std::vector<Vertex*> restricted_vertices;
        
        for (std::list<Vertex>::iterator it = this->vertices.begin(); it != this->vertices.end(); ++it)
        {
            bool flag = true;
            // Viendo si no existen colisiones
            if (it->color == Color::nocolor)
            {
                for (std::vector<Vertex*>::iterator it2 = restricted_vertices.begin(); it2 != restricted_vertices.end(); ++it2)
                {
                    if ((*it2)->get_value() == (*it).get_value())
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (!flag) continue;
            if (it->color == Color::nocolor)
            {
                coloured_nodes++;
                (*it).color = static_cast<Color>(i);

                restricted_vertices.push_back(&(*it));

                for (std::list<Edge>::iterator it2 = it->edge_list.begin(); it2 != it->edge_list.end(); ++it2)
                {
                    restricted_vertices.push_back(it2->get_vertex());
                }

            }
        }
    }
    
}

void Graph::print_to_console()
{
    for (std::list<Vertex>::iterator it = this->vertices.begin(); it != this->vertices.end(); ++it)
    {
        std::cout << it->get_value() << " : ";
        switch(it->color)
        {
        case Color::red:
            std::cout << "red"; 
            break;  
        case Color::orange:
            std::cout << "orange"; 
            break;  
        case Color::yellow:
            std::cout << "yellow"; 
            break;  
        case Color::green:
            std::cout << "green"; 
            break;  
        case Color::blue:
            std::cout << "blue"; 
            break;  
        case Color::purple:
            std::cout << "purple"; 
            break;  
        case Color::turquoise:
            std::cout << "turquoise"; 
            break;  
        case Color::cyan:
            std::cout << "cyan"; 
            break;  
        case Color::pink:
            std::cout << "pink";
            break;
        case Color::olive:
            std::cout << "olive";
            break;  
        case Color::gold:
            std::cout << "gold";
            break;  
        case Color::chocolate:
            std::cout << "chocolate";
            break;  
        case Color::nocolor:
            std::cout << "Sin color";
            break;  
        }
        std::cout << " ::= ";
        for (std::list<Edge>::iterator it2 = it->edge_list.begin(); it2 != it->edge_list.end(); ++it2)
        {
            std::cout << it2->get_vertex()->value << ", ";
        }
        std::cout << '\n';
    }
}

void Graph::save_ostream(std::ostream & o)
{

    for (const auto &vertex : this->vertices)
    {
        for (const auto &edge : vertex.edge_list)
        {
            o << '\"' << vertex.value << '\"' << "--" << '\"' << edge.get_vertex()->value << '\"' << ";\n";
        }

    }

    for (const auto &vertex : this->vertices)
    {
        o << '\"' << vertex.value << '\"' << " [fillcolor=";
        switch(vertex.color)
        {
        case Color::red:
            o << "red"; 
            break;  
        case Color::orange:
            o << "orange"; 
            break;  
        case Color::yellow:
            o << "yellow"; 
            break;  
        case Color::green:
            o << "green"; 
            break;  
        case Color::blue:
            o << "blue"; 
            break;  
        case Color::purple:
            o << "purple"; 
            break;  
        case Color::turquoise:
            o << "turquoise"; 
            break;  
        case Color::cyan:
            o << "cyan"; 
            break;  
        case Color::pink:
            o << "pink";
            break;
        case Color::olive:
            o << "olive";
            break;  
        case Color::gold:
            o << "gold";
            break;  
        case Color::chocolate:
            o << "chocolate";
            break;  
        case Color::nocolor:
            o << "Sin color";
            break;
        }
        o << ", style=filled];\n";
    }
}

void Graph::show_dot(std::string filename)
{
    std::ofstream file;
    file.open("Graphviz\\bin\\" + filename + ".dot");
    file << "graph Z {";
    this->save_ostream(file);
    file << "}";
    system("cd Graphviz\\bin && dot -Tpng grafo.dot -o grafo.png");
}