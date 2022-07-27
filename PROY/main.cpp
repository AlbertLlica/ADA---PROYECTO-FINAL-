#include "Graph.h"
#include <iostream>

int main()
{
    Graph col_graph;

    col_graph.insert_vertex('A');
    col_graph.insert_vertex('B');
    col_graph.insert_vertex('C');
    col_graph.insert_vertex('D');
    col_graph.insert_vertex('E');
    col_graph.insert_vertex('F');
    col_graph.insert_vertex('G');
    col_graph.insert_vertex('H');

    col_graph.insert_edge('A','B');
    col_graph.insert_edge('A','H');
    col_graph.insert_edge('B','C');
    col_graph.insert_edge('B','D');
    col_graph.insert_edge('C','E');
    col_graph.insert_edge('D','E');
    col_graph.insert_edge('D','H');
    col_graph.insert_edge('E','F');
    col_graph.insert_edge('E','H');
    col_graph.insert_edge('F','G');
    col_graph.insert_edge('F','H');

    col_graph.colorize();

    col_graph.print_to_console();

    col_graph.show_dot("grafo");
    
    return 0;
}