#ifndef HORARIO_H
#define HORARIO_H
#include "Graph.h"
class Horario{
private:

    vector<int> paleta;
    vector<string> grupos; 
    vector<string> tiposDeCursos;   
    vector<string> semestres;
    vector<string> profesores;

    map<string, Curso *> cursos;

    unsigned int cantidadCursos;

    Graph<string> * grafo;
    string extrarNombreCurso(string nombreCurso){
        size_t pos = nombreCurso.find(":");
        if (pos == string::npos){
            pos = nombreCurso.find("-");
            if (pos == string::npos)
                return nombreCurso;
        }

        string soloNombre = "";
        for (size_t i = 0; i < pos; i++){
            soloNombre += nombreCurso[i];
        }

        return soloNombre;
    }

    char extraerGrupoCurso(string nombreCurso){
        size_t pos = nombreCurso.find(":");
        if (pos == string::npos)
            return ' ';

        return nombreCurso[pos + 1];
    }

    string extraerTipoCurso(string nombreCurso){
        size_t pos = nombreCurso.find("-");
        if (pos == string::npos)
            return "  ";

        return nombreCurso.substr(pos + 1, 2);
    }

public:
    Horario(vector<int> paleta){
        this->grafo = nullptr;
        this->cantidadCursos = 0;
        this->paleta = paleta;
    }

    bool crearCurso(string nombreCorto){
        this->cursos[nombreCorto] = new Curso(nombreCorto);
        this->cantidadCursos++;
        return true;
    }

    bool crearCurso(string nombreCorto, string nombreLargo){
        this->cursos[nombreCorto] = new Curso(nombreCorto, nombreLargo);
        this->cantidadCursos++;
        return true;
    }

    bool existeCurso(string nombreCortoCurso){
        return !(this->cursos.find(nombreCortoCurso) == this->cursos.end());
    }

    void mostrarInfoHorario(){
        cout << "-------- SEMESTRES ---------" << endl;
        for (auto & semestre: this->semestres){
            cout << semestre << ", ";
        }
        cout << endl << endl;
        cout << "----- TIPOS DE CURSOS ------" << endl;
        for (auto & tipos: this->tiposDeCursos){
            cout << tipos << ", ";
        }
        cout << endl << endl;
        cout << "---------- GRUPOS ----------" << endl;
        for (auto & grupo: this->grupos){
            cout << grupo << ", ";
        }
        cout << endl << endl;
        cout << "-------- PROFESORES --------" << endl;
        for (auto & profesor: this->profesores){
            cout << profesor << ", ";
        }
        cout << endl << endl;
        cout << "---------- CURSOS ----------" << endl;
        for(auto & curso: this->cursos){
            curso.second->mostrarValores();
        }
    }

    int encontrarSemestre(string nombreSemestre){
        for (int i = 0; i < this->semestres.size(); i++){
            if (this->semestres[i] == nombreSemestre)
                return i;
        }
        return -1;
    }

    int encontrarProfesor(string nombreProfesor){
        for (int i = 0; i < this->profesores.size(); i++){
            if (this->profesores[i] == nombreProfesor)
                return i;
        }
        return -1;
    }

    int encontrarGrupo(string nombreGrupo){
        for (int i = 0; i < this->grupos.size(); i++){
            if (this->grupos[i] == nombreGrupo)
                return i;
        }
        return -1;
    }

    int encontrarTipo(string nombreTipo){
        for (int i = 0; i < this->tiposDeCursos.size(); i++){
            if (this->tiposDeCursos[i] == nombreTipo)
                return i;
        }
        return -1;
    }

    int crearProfesor(string nombreProfesor){
        int idProfesor = this->encontrarProfesor(nombreProfesor);
        if (idProfesor < 0){
            this->profesores.push_back(nombreProfesor);
            return this->profesores.size() - 1;
        }
        return idProfesor;
    }

    int crearSemestre(string nombreSemestre){
        int idSemestre = this->encontrarSemestre(nombreSemestre);
        if (idSemestre < 0){
            this->semestres.push_back(nombreSemestre);
            return this->semestres.size() - 1;
        }
        return idSemestre;
    }

    int crearGrupo(string nombreGrupo){
        int idGrupo = this->encontrarGrupo(nombreGrupo);
        if (idGrupo < 0){
            this->grupos.push_back(nombreGrupo);
            return this->grupos.size() - 1;
        }
        return idGrupo;
    }

    int crearTipoCurso(string nombreCortoTipo){
        int idTipoCurso = this->encontrarTipo(nombreCortoTipo);
        if (idTipoCurso < 0){
            this->tiposDeCursos.push_back(nombreCortoTipo);
            return this->tiposDeCursos.size() - 1;
        }
        return idTipoCurso;
    }


    bool asignarProfesorAlCurso(string nombreCortoCurso, string nombreProfesor){
        if (this->cursos.find(nombreCortoCurso) == this->cursos.end())
            return false;
        this->cursos[nombreCortoCurso]->asignarProfesor(this->crearProfesor(nombreProfesor));
        return true;
    }

    bool asignarProfesorAtipoYgrupo(string nombreCortoCurso, string nombreTipo, string nombreGrupo, string nombreProfesor){
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
            cout << "# INSERTANDO AMBOS GRUPOS" << endl;
            if (this->cursos[nombreCortoCurso]->asignarProfesorAlTipoYgrupo(this->crearProfesor(nombreProfesor), nombreTipo, nombreGrupo) >= 0){
                this->crearGrupo(nombreGrupo);
                this->crearTipoCurso(nombreTipo);
                return true;
            }
            return false;
        }
    }

    bool asignarSemestreAlCurso(string nombreCortoCurso, string nombreSemestre){
        if (this->cursos.find(nombreCortoCurso) == this->cursos.end())
            return false;
        this->cursos[nombreCortoCurso]->asignarSemestre(this->crearSemestre(nombreSemestre));
        return true;
    }

    bool asignarSemestreAlCurso(string nombreCortoCurso, int idSemestre){
        if (this->cursos.find(nombreCortoCurso) == this->cursos.end()) 
            return false;
        this->cursos[nombreCortoCurso]->asignarSemestre(idSemestre);
        return true;
    }
    bool asignarProfesorAlCurso(string nombreCortoCurso, int idProfesor){
        if (this->cursos.find(nombreCortoCurso) == this->cursos.end())
            return false;
        this->cursos[nombreCortoCurso]->asignarProfesor(idProfesor);
        return true;
    }
};


#endif // HORARIO_H
