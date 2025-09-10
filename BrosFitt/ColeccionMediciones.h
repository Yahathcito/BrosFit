#pragma once
#include "Medicion.h"
class ColeccionMediciones
{
private:
	int tam;
	int cantidad;
	Medicion** mediciones;
public:
	ColeccionMediciones(int);
	~ColeccionMediciones();
	void agregarMedicion(Medicion*);
	Medicion* buscarMedicion(string, string);
	bool eliminarMedicion(string, string);
	string listarMediciones();
	int getCantidad();
	int getTam();
};

