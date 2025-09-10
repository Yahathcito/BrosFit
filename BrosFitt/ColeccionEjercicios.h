#pragma once
#include"Ejercicio.h"

class ColeccionEjercicios
{
private:
	int tam;
	int cantidad;
	Ejercicio** ejercicios;
public:
	ColeccionEjercicios();
	~ColeccionEjercicios();
	void agregarEjercicio(Ejercicio*);
	Ejercicio* buscarEjercicio(string);
	bool eliminarEjercicio(string);
	string listarEjercicios();
	int getCantidad();
	int getTam();

};

