#pragma once
#include "Rutina.h"
class ColeccionRutina
{
private:
    int tam;
    int cantidad;
    Rutina** rutinas;
public:
    ColeccionRutina(int);
    ~ColeccionRutina();
    void agregarRutina(Rutina*);
    Rutina* buscarRutina(string);
    bool eliminarRutina(string);
    string listarRutinas();
    int getCantidad();
    int getTam();
};

