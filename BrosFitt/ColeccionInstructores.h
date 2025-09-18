#pragma once
#include "Instructor.h"
class ColeccionInstructores {
private:
    int tam;
    int cantidad;
    Instructor** instructores;
public:
    ColeccionInstructores(int);
    ~ColeccionInstructores();
    void agregarInstructor(Instructor*);
    Instructor* buscarInstructor(string);
    bool eliminarInstructor(string);
    string listarInstructores();
    bool insertarAlFinal(Instructor*);
    int getCantidad();
    int getTam();
    string toString();
    Instructor* getPorIndice(int i);
};