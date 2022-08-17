#ifndef HORARIO_H
#define HORARIO_H
#include "Graph.h"
#include <bits/stdc++.h>
#include <map>
#include <vector>

class Horario{
private:

    std::vector<int> paleta;
    std::vector<std::string> grupos; 
    std::vector<std::string> tiposDeCursos;   
    std::vector<std::string> semestres;
    std::vector<std::string> profesores;

    std::map<std::string, Curso *> cursos;

    unsigned int cantidadCursos;

    Graph grafo;
    std::string extrarNombreCurso(std::string nombreCurso){
        size_t pos = nombreCurso.find(":");
        if (pos == std::string::npos){
            pos = nombreCurso.find("-");
            if (pos == std::string::npos)
                return nombreCurso;
        }

        std::string soloNombre = "";
        for (size_t i = 0; i < pos; i++){
            soloNombre += nombreCurso[i];
        }

        return soloNombre;
    }

    char extraerGrupoCurso(std::string nombreCurso){
        std::size_t pos = nombreCurso.find(":");
        if (pos == std::string::npos)
            return ' ';

        return nombreCurso[pos + 1];
    }

    std::string extraerTipoCurso(std::string nombreCurso){
        size_t pos = nombreCurso.find("-");
        if (pos == std::string::npos)
            return "  ";

        return nombreCurso.substr(pos + 1, 2);
    }

public:
    Horario(){
        //this->grafo = nullptr;
        this->cantidadCursos = 0;
    }

    bool crearCurso(std::string nombreCorto){
        this->cursos[nombreCorto] = new Curso(nombreCorto);
        this->cantidadCursos++;
        return true;
    }

    bool crearCurso(std::string nombreCorto, std::string nombreLargo){
        this->cursos[nombreCorto] = new Curso(nombreCorto, nombreLargo);
        this->cantidadCursos++;
        return true;
    }

    bool existeCurso(std::string nombreCortoCurso){
        return !(this->cursos.find(nombreCortoCurso) == this->cursos.end());
    }

    void mostrarInfoHorario(){
        std::cout << "-------- SEMESTRES ---------" << std::endl;
        for (auto & semestre: this->semestres){
            std::cout << semestre << ", ";
        }
        std::cout << std::endl << std::endl;
        std::cout << "----- TIPOS DE CURSOS ------" << std::endl;
        for (auto & tipos: this->tiposDeCursos){
            std::cout << tipos << ", ";
        }
        std::cout << std::endl << std::endl;
        std::cout << "---------- GRUPOS ----------" << std::endl;
        for (auto & grupo: this->grupos){
            std::cout << grupo << ", ";
        }
        std::cout << std::endl << std::endl;
        std::cout << "-------- PROFESORES --------" << std::endl;
        for (auto & profesor: this->profesores){
            std::cout << profesor << ", ";
        }
        std::cout << std::endl << std::endl;
        std::cout << "---------- CURSOS ----------" << std::endl;
        for(auto & curso: this->cursos){
            curso.second->mostrarValores();
        }
    }

    int encontrarSemestre(std::string nombreSemestre){
        for (int i = 0; i < this->semestres.size(); i++){
            if (this->semestres[i] == nombreSemestre)
                return i;
        }
        return -1;
    }

    int encontrarProfesor(std::string nombreProfesor){
        for (int i = 0; i < this->profesores.size(); i++){
            if (this->profesores[i] == nombreProfesor)
                return i;
        }
        return -1;
    }

    int encontrarGrupo(std::string nombreGrupo){
        for (int i = 0; i < this->grupos.size(); i++){
            if (this->grupos[i] == nombreGrupo)
                return i;
        }
        return -1;
    }

    int encontrarTipo(std::string nombreTipo){
        for (int i = 0; i < this->tiposDeCursos.size(); i++){
            if (this->tiposDeCursos[i] == nombreTipo)
                return i;
        }
        return -1;
    }

    int crearProfesor(std::string nombreProfesor){
        int idProfesor = this->encontrarProfesor(nombreProfesor);
        if (idProfesor < 0){
            this->profesores.push_back(nombreProfesor);
            return this->profesores.size() - 1;
        }
        return idProfesor;
    }

    int crearSemestre(std::string nombreSemestre){
        int idSemestre = this->encontrarSemestre(nombreSemestre);
        if (idSemestre < 0){
            this->semestres.push_back(nombreSemestre);
            return this->semestres.size() - 1;
        }
        return idSemestre;
    }

    int crearGrupo(std::string nombreGrupo){
        int idGrupo = this->encontrarGrupo(nombreGrupo);
        if (idGrupo < 0){
            this->grupos.push_back(nombreGrupo);
            return this->grupos.size() - 1;
        }
        return idGrupo;
    }

    int crearTipoCurso(std::string nombreCortoTipo){
        int idTipoCurso = this->encontrarTipo(nombreCortoTipo);
        if (idTipoCurso < 0){
            this->tiposDeCursos.push_back(nombreCortoTipo);
            return this->tiposDeCursos.size() - 1;
        }
        return idTipoCurso;
    }


    bool asignarProfesorAlCurso(std::string nombreCortoCurso, std::string nombreProfesor){
        if (this->cursos.find(nombreCortoCurso) == this->cursos.end())
            return false;
        this->cursos[nombreCortoCurso]->asignaridProfesor(this->crearProfesor(nombreProfesor));
        return true;
    }

    bool asignarProfesorAtipoYgrupo(std::string nombreCortoCurso, std::string nombreTipo, std::string nombreGrupo, std::string nombreProfesor){
        if (!this->existeCurso(nombreCortoCurso)) return false;
        if (nombreTipo.length() < 1){
            if (this->cursos[nombreCortoCurso]->asignarProfesorSoloAlGrupo(this->crearProfesor(nombreProfesor), nombreGrupo) >= 0){
                this->crearGrupo(nombreGrupo);
                return true;
            }
            return false;
        }else if (nombreGrupo.length() < 1){
            if (this->cursos[nombreCortoCurso]->asignarProfesorSoloAlTipo(this->crearProfesor(nombreProfesor), nombreTipo) >= 0){
                this->crearTipoCurso(nombreTipo);
                return true;
            }
            return false;
        }else{
            std::cout << "# INSERTANDO AMBOS GRUPOS" << std::endl;
            if (this->cursos[nombreCortoCurso]->asignarProfesorAlTipoYgrupo(this->crearProfesor(nombreProfesor), nombreTipo, nombreGrupo) >= 0){
                this->crearGrupo(nombreGrupo);
                this->crearTipoCurso(nombreTipo);
                return true;
            }
            return false;
        }
    }

    bool asignarSemestreAlCurso(std::string nombreCortoCurso, std::string nombreSemestre){
        if (this->cursos.find(nombreCortoCurso) == this->cursos.end())
            return false;
        this->cursos[nombreCortoCurso]->asignaridSemestre(this->crearSemestre(nombreSemestre));
        return true;
    }

    bool asignarSemestreAlCurso(std::string nombreCortoCurso, int idSemestre){
        if (this->cursos.find(nombreCortoCurso) == this->cursos.end()) 
            return false;
        this->cursos[nombreCortoCurso]->asignaridSemestre(idSemestre);
        return true;
    }
    bool asignarProfesorAlCurso(std::string nombreCortoCurso, int idProfesor){
        if (this->cursos.find(nombreCortoCurso) == this->cursos.end())
            return false;
        this->cursos[nombreCortoCurso]->asignaridProfesor(idProfesor);
        return true;
    }

    void Mostrar_Insertar(std::map<std::string,Curso*> nombresCursos){
    for (auto & curso: nombresCursos){
        this->grafo.insert_vertex(*(curso.second));
        std::cout << "CURSO: " << curso.first << std::endl;
    }
}
    bool cargarDatos(){
        std::map<std::string, Curso *> nombresCursos;

        for (auto & curso1: this->cursos){
            if (curso1.second->profesor == -1 && curso1.second->profesorAsignado.size() > 0){
                for (auto & profesor: curso1.second->profesorAsignado){
                    for(auto & tipoGrupo: profesor.second){
                        std::string nombreCurso = curso1.first;
                        if (tipoGrupo.second != "" && tipoGrupo.first != ""){
                            nombreCurso += ":" + tipoGrupo.second + "-" + tipoGrupo.first;
                        }else if(tipoGrupo.second != "" && tipoGrupo.first == ""){
                            nombreCurso += ":" + tipoGrupo.second;
                        }else if(tipoGrupo.second == "" && tipoGrupo.first != ""){
                            nombreCurso += "-" + tipoGrupo.first;
                        }
                        nombresCursos[nombreCurso] = curso1.second;
                    }
                }
            }else{
                std::string nombreCurso = curso1.first;
                nombresCursos[nombreCurso] = curso1.second;
            }

        }
        
        Mostrar_Insertar(nombresCursos);
        
        for (auto & cursoPivote: nombresCursos){
            for (auto & curso: nombresCursos){
                if (cursoPivote.first != curso.first){ // Aseguramos de no crear lazos en el grafo
                    // Crearmos aristas con los cursos que son del mismo semestre
                    if (cursoPivote.second->semestre == curso.second->semestre && cursoPivote.second->semestre != -1){
                        // Pero tenemos que tomar en cuenta que aún siendo del mismo semestre
                        // pueden ser de diferente grupo y esos no tendrían que tener una arista
                        std::string nombreCursoPivote = this->extrarNombreCurso(cursoPivote.first);
                        std::string nombreCurso = this->extrarNombreCurso(curso.first);
                        char grupoCursoPivote = this->extraerGrupoCurso(cursoPivote.first);
                        char grupoCurso = this->extraerGrupoCurso(curso.first);
                        std::string tipoCursoPivote = this->extraerTipoCurso(cursoPivote.first);
                        std::string tipoCurso = this->extraerTipoCurso(curso.first);

                        // Si son del mismo grupo y del mismo tipo de curso, no se pueden llevar en simultaneo
                        // a su vez si no tienen ni tipo ni grupo también se creara aristas
                        if (grupoCursoPivote == grupoCurso && tipoCursoPivote == tipoCurso){
                            this->grafo.insert_edge(*(cursoPivote.second), *(curso.second));
                        }

                        // Si no tiene grupo pero el otro curso si lo tiene, entonces se uniran (arista)
                        if (grupoCursoPivote == ' ' && grupoCurso != ' '){
                            this->grafo.insert_edge(*(cursoPivote.second), *(curso.second));
                        }

                        // si no tiene tipo y el otro si, entonces se uniran (arista)
                        if (tipoCursoPivote == "  " && tipoCurso != "  "){
                            this->grafo.insert_edge(*(cursoPivote.second), *(curso.second));
                        }

                        // LA otra condición es que si tienen el mismo profesor
                        if (cursoPivote.second->profesor == curso.second->profesor && cursoPivote.second->profesor != -1){
                            this->grafo.insert_edge(*(cursoPivote.second), *(curso.second));
                        }
                    }

                }
            }

        }

        this->grafo.colorize();
        this->grafo.print_to_console();
        this->grafo.show_dot("grafo");

        return true;

    }
};


#endif // HORARIO_H
