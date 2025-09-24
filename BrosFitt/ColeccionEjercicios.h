#pragma once
#include"Ejercicio.h"

class ColeccionEjercicios
{
private:
	int tam;
	int cantidad;
	Ejercicio** ejercicios;
public:
	ColeccionEjercicios(int);
	Ejercicio* getPorIndice(int);
	~ColeccionEjercicios();
	Ejercicio* getEjercicio();
	bool agregarEjercicio(Ejercicio*);
	Ejercicio* buscarEjercicio(string);
	bool eliminarEjercicio(string);
	string listarEjercicios();
	int getCantidad();
	int getTam();
	string toString();
};

