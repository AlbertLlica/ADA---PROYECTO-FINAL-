#include "horario.h"
#include <iostream>
#include <vector>

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
    
    Horario h1;

    std::string primer_semestre[] = {"RLM", "MTU", "AC", "ITP1", "FDC", "ED1"};
    std::string tercer_semestre[] = {"ADC", "CC2", "DBP", "TI1", "CVV", "ITP3","CI"};
    std::string quinto_semestre[] = {"BD2", "ADA", "IS1", "COM", "AEDE", "ECD"};
    std::string septimo_semestre[] = {"ICC", "DSE", "RC", "IS3", "CG", "IA"};
    std::string noveno_semestre[] = {"PFC2", "BGD", "EGP", "FEBT2", "ITP4", "TCC(e)","TIA(e)","TCG(e)","BIO(e)"};

    h1.crearCurso("RLM");
    h1.crearCurso("MTU");
    h1.crearCurso("AC");
    h1.crearCurso("ITP1");
    h1.crearCurso("FDC");
    h1.crearCurso("ED1");

    h1.crearCurso("ADC");
    h1.crearCurso("CC2");
    h1.crearCurso("DBP");
    h1.crearCurso("TI1");
    h1.crearCurso("CVV");
    h1.crearCurso("ITP3");
    h1.crearCurso("CI");
/*
    h1.crearCurso("BD2");
    h1.crearCurso("ADA");
    h1.crearCurso("IS1");
    h1.crearCurso("COM");
    h1.crearCurso("AEDE");
    h1.crearCurso("ECD");

    h1.crearCurso("ICC");
    h1.crearCurso("DSE");
    h1.crearCurso("RC");
    h1.crearCurso("IS3");
    h1.crearCurso("CG");
    h1.crearCurso("IA");

    h1.crearCurso("PFC2");
    h1.crearCurso("BGD");
    h1.crearCurso("EGP");
    h1.crearCurso("FEBT2");
    h1.crearCurso("ITP4");
    h1.crearCurso("TCC(e)");
    h1.crearCurso("TIA(e)");
    h1.crearCurso("TCG(e)");
    h1.crearCurso("BIO(e)");

*/
    h1.asignarSemestreAlCurso("RLM", "PrimerSemestre");
    h1.asignarSemestreAlCurso("MTU", "PrimerSemestre");
    h1.asignarSemestreAlCurso("AC", "PrimerSemestre");
    h1.asignarSemestreAlCurso("ITP1", "PrimerSemestre");
    h1.asignarSemestreAlCurso("FDC", "PrimerSemestre");
    h1.asignarSemestreAlCurso("ED1", "PrimerSemestre");


    h1.asignarSemestreAlCurso("ADC", "TercerSemestre");
    h1.asignarSemestreAlCurso("CC2", "TercerSemestre");
    h1.asignarSemestreAlCurso("DBP", "TercerSemestre");
    h1.asignarSemestreAlCurso("TI1", "TercerSemestre");
    h1.asignarSemestreAlCurso("CVV", "TercerSemestre");
    h1.asignarSemestreAlCurso("ITP3", "TercerSemestre");
    h1.asignarSemestreAlCurso("CI", "TercerSemestre");

    h1.asignarProfesorAtipoYgrupo("ADC", "TE", "a", "Pedro Rodriguez");
    h1.asignarProfesorAtipoYgrupo("ADC", "TE", "b", "Pedro Rodriguez");
    h1.asignarProfesorAtipoYgrupo("CC2", "TE", "a", "Maria Rivera");
    h1.asignarProfesorAtipoYgrupo("CC2", "TE", "b", "Yuri Toro");
    h1.asignarProfesorAtipoYgrupo("CC2", "LA", "a", "Yessenia Yari");
    h1.asignarProfesorAtipoYgrupo("CC2", "LA", "b", "Yessenia Yari");
    h1.asignarProfesorAtipoYgrupo("DBP", "TE", "a", "Edward Hinojosa");
    h1.asignarProfesorAtipoYgrupo("DBP", "TE", "b", "Edward Hinojosa");
    h1.asignarProfesorAtipoYgrupo("DBP", "LA", "a", "Edward Hinojosa");
    h1.asignarProfesorAtipoYgrupo("DBP", "LA", "b", "Edward Hinojosa");
    h1.asignarProfesorAtipoYgrupo("TI1", "TE", "a", "Yessenia Yari");
    h1.asignarProfesorAtipoYgrupo("TI1", "TE", "b", "Yessenia Yari");
    h1.asignarProfesorAtipoYgrupo("CVV", "TE", "a", "Claudio Vera");
    h1.asignarProfesorAtipoYgrupo("CVV", "TE", "b", "Judith Cruz");
    h1.asignarProfesorAtipoYgrupo("ITP3", "TE", "a", "Yesica Granda");
    h1.asignarProfesorAtipoYgrupo("ITP3", "TE", "b", "Rolando Rivas");
    h1.asignarProfesorAtipoYgrupo("CI", "TE", "a", "Yakelin Cereceda");
    h1.asignarProfesorAtipoYgrupo("CI", "TE", "b", "Segundo Ortiz");


    h1.asignarProfesorAtipoYgrupo("RLM", "TE", "a", "Jorge Chambi");
    h1.asignarProfesorAtipoYgrupo("RLM", "TE", "b", "Brayan Mujica");
    h1.asignarProfesorAtipoYgrupo("MTU", "TE", "a", "Maria Rivera");
    h1.asignarProfesorAtipoYgrupo("MTU", "TE", "b", "Yuri Toro");
    h1.asignarProfesorAtipoYgrupo("AC", "TE", "a", "Yessenia Yari");
    h1.asignarProfesorAtipoYgrupo("AC", "TE", "b", "Yessenia Yari");
    h1.asignarProfesorAtipoYgrupo("ITP1", "TE", "a", "Anny Centeno");
    h1.asignarProfesorAtipoYgrupo("ITP1", "TE", "b", "Anny Centeno");
    h1.asignarProfesorAtipoYgrupo("FDC", "TE", "a", "Eliana Adriazola");
    h1.asignarProfesorAtipoYgrupo("FDC", "TE", "b", "Eliana Adriazola");
    h1.asignarProfesorAtipoYgrupo("FDC", "LA", "a", "Eliana Adriazola");
    h1.asignarProfesorAtipoYgrupo("FDC", "LA", "b", "Eliana Adriazola");
    h1.asignarProfesorAtipoYgrupo("ED1", "TE", "a", "Roxana Quispe");
    h1.asignarProfesorAtipoYgrupo("ED1", "TE", "b", "Roxana Quispe");
    

    h1.mostrarInfoHorario();
    h1.cargarDatos();

    /*
    Graph col_graph;

    Curso c1("Teoria de la Computacion");
    c1.asignaridProfesor(5);
    Curso c2("Algoritmos y Estructuras de Datos");
    c2.asignaridProfesor(5);
    Curso c3("Base de Datos II");
    c3.asignaridProfesor(3);
    Curso c4("Ingenieria de Software");
    c4.asignaridProfesor(3);

    col_graph.insert_vertex(c1);
    col_graph.insert_vertex(c2);
    col_graph.insert_vertex(c3);
    col_graph.insert_vertex(c4);

    col_graph.insert_edge(c1,c2);
    col_graph.insert_edge(c3,c4);
    col_graph.insert_edge(c3,c2);




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
    //col_graph.show_dot("grafo");
    
    return 0;
}