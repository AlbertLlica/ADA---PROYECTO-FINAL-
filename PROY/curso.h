#ifndef CURSO_H
#define CURSO_H

#include <bits/stdc++.h>

class Curso{
public:
    int profesor;
    int semestre;
    std::string nombreCurso;
    std::string nombreLargoCurso;

    std::map<int, std::vector<std::pair<std::string, std::string>>> profesorAsignado;
    std::vector<std::string> tiposCursos;
    std::vector<std::string> gruposCursos;

    friend class Graph;
public:
    Curso()
    {
        this->nombreCurso = "NA";
        this->nombreLargoCurso = "NAA";
        this->semestre = -1;
        this->profesor = -1;
    }
    bool operator==(const Curso c1)
    {
        if(this->nombreCurso == c1.nombreCurso)
        {
            return true;
        }
        else
            return false;
    }
    Curso(std::string nombreCorto)
    {
        this->nombreCurso = nombreCorto;
        this->nombreLargoCurso = "";
        this->semestre = -1;
        this->profesor = -1;
    }
    Curso(std::string nombreCorto, int idSemestre)
    {
        this->nombreCurso = nombreCorto;
        this->semestre = idSemestre;
        this->nombreLargoCurso = "";
        this->profesor = -1;
    }
    Curso(std::string nombreCorto, std::string nombreCompleto)
    {
        this->nombreCurso = nombreCorto;
        this->nombreLargoCurso = nombreCompleto;
        this->semestre = -1;
        this->profesor = -1;
    }
    Curso(std::string nombreCorto, std::string nombreCompleto, int idSemestre)
    {
        this->nombreCurso = nombreCorto;
        this->nombreLargoCurso = nombreCompleto;
        this->semestre = idSemestre;
        this->profesor = -1;
    }

    int asignaridProfesor(int idProfesor)
    {
        return this->profesor = idProfesor;
    }

    int asignaridSemestre(int idSemestre)
    {
        return this->semestre = idSemestre;
    }

    int buscarAsignacionProfesor(int idProfesor, std::string tipoCurso, std::string grupoCurso)
    {
        if (this->profesorAsignado.find(idProfesor) == this->profesorAsignado.end()) 
            return -1;
        for (int idx = 0; idx < this->profesorAsignado[idProfesor].size(); idx++){
            if (this->profesorAsignado[idProfesor][idx].first == tipoCurso && this->profesorAsignado[idProfesor][idx].second == grupoCurso)
                return idx;
        }
        return -1;
    }

    void mostrarValores()
    {
        std::cout << std::endl;
        std::cout << "NOMBRE CORTO: " << this->nombreCurso << std::endl;
        std::cout << "NOMBRE LARGO: " << this->nombreLargoCurso << std::endl;
        std::cout << "ID PROFESOR: " << this->profesor << std::endl;
        std::cout << "NUMERO DE SEMESTRE: " << this->semestre << std::endl;
        std::cout << "TIPOS CREADOS: ";
        for(auto & tipo: this->tiposCursos){
            std::cout << tipo << ", ";
        }
        std::cout << std::endl;
        std::cout << "GRUPOS CREADOS: ";
        for(auto & grupo: this->gruposCursos){
            std::cout << grupo << ", ";
        }
        std::cout << std::endl;
        std::cout << "PROFESOR ASIGNADO A: " << std::endl;
        for (auto & profesor: this->profesorAsignado){
            std::cout << "\t" << profesor.first << " = ";
            for (auto & asignado: profesor.second){
                std::cout << "(" << asignado.first << "-" << asignado.second << "), ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    int encontrarTipoCurso(std::string tipoCurso)
    {
        for (int idx = 0; idx < this->tiposCursos.size(); idx++)
            if (this->tiposCursos[idx] == tipoCurso)
                return idx;
        return -1;
    }

    int encontrarGrupoCurso(std::string grupoCurso)
    {
        for(int idx = 0; idx < this->gruposCursos.size(); idx++)
            if (this->gruposCursos[idx] == grupoCurso)
                return idx;
        return -1;
    }

    int asignarProfesorAlTipoYgrupo(int idProfesor, std::string tipoCurso, std::string grupoCurso)
    {
        this->profesor = -1;
        int posAsignado = this->buscarAsignacionProfesor(idProfesor, tipoCurso, grupoCurso);
        if (posAsignado < 0){
            std::pair<std::string, std::string> tipoGrupoAsignado(tipoCurso, grupoCurso);
            this->profesorAsignado[idProfesor].push_back(tipoGrupoAsignado);
            if (this->encontrarTipoCurso(tipoCurso) < 0){
                this->tiposCursos.push_back(tipoCurso);
            }
            if (this->encontrarGrupoCurso(grupoCurso) < 0){
                this->gruposCursos.push_back(grupoCurso);
            }
            return this->profesorAsignado[idProfesor].size() - 1;
        }
        return posAsignado;
    }
    
    int asignarProfesorSoloAlTipo(int idProfesor, std::string tipoCurso)
    {
        this->profesor = -1;
        int posAsignado = this->buscarAsignacionProfesor(idProfesor, tipoCurso, "");
        if (posAsignado < 0){
            std::pair<std::string, std::string> tipoGrupoAsignado(tipoCurso, "");
            this->profesorAsignado[idProfesor].push_back(tipoGrupoAsignado);
            if (this->encontrarTipoCurso(tipoCurso) < 0){
                this->tiposCursos.push_back(tipoCurso);
            }
            return this->profesorAsignado[idProfesor].size() - 1;
        }
        return posAsignado;
    }

    int asignarProfesorSoloAlGrupo(int idProfesor, std::string grupoCurso)
    {
        this->profesor = -1;
        int posAsignado = this->buscarAsignacionProfesor(idProfesor, "", grupoCurso);
        if (posAsignado < 0){
            std::pair<std::string, std::string> tipoGrupoAsignado("", grupoCurso);
            this->profesorAsignado[idProfesor].push_back(tipoGrupoAsignado);
            if (this->encontrarGrupoCurso(grupoCurso) < 0){
                this->gruposCursos.push_back(grupoCurso);
            }
            return this->profesorAsignado[idProfesor].size() - 1;
        }
        return posAsignado;
    }
};

#endif // CURSO_H
