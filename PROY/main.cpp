#include "Graph.h"
#include <iostream>


Graph create_graph(std::vector<Curso> cursos)
{
    Graph col_graph;
    std::vector<std::vector<bool>> checker;
    for (int i = 0; i < cursos.size(); i++)
    {
        for (int j = 0; j < cursos.size(); j++)
        {
            checker[i][j] = false;
        }
    }

    for (const auto& curso : cursos)
    {
        col_graph.insert_vertex(curso);
    }
    int i = 0;
    for (auto& curso : col_graph.vertices)
    {
        int j = 0;
        for (auto& curso2 : col_graph.vertices)
        {
            if (&curso != &curso2)
            {
                if ((!checker[i][j] && !checker[i][j]) && ((curso.get_course().nombreCurso == curso2.get_course().nombreCurso) || (curso.get_course().profesor == curso2.get_course().profesor)))
                {
                    col_graph.insert_edge(curso.get_course(),curso2.get_course());
                    checker[i][j] = true;
                }
            }
            j++;
        }
        i++;
    }

}

int main()
{
    Graph col_graph;

    Curso c1("Teoria de la Computacion");
    c1.asignaridProfesor(5);
    Curso c2("Algoritmos y Estructuras de Datos");
    c2.asignaridProfesor(5);
    Curso c3("Base de Datos II");
    c3.asignaridProfesor(3);
    Curso c4("Ingenieria de Software");
    c4.asignaridProfesor(3);


/*
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
*/
    col_graph.colorize();

    col_graph.print_to_console();

    col_graph.show_dot("grafo");
    
    return 0;
}