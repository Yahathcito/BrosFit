#pragma once
#include <string>
#include "ClaseGrupal.h"

class ColeccionClaseGrupal {
private:
	int tam;
	int cantidad;
    ClaseGrupal** clases;
	bool ocupadas[8];
	std::string nombresPredefinidos[8] = {
		"CrossFit", "HIIT", "TRX", "Pesas",
		"Spinning", "Cardio", "Yoga", "Zumba"
	};

public:
	ColeccionClaseGrupal();
	~ColeccionClaseGrupal();

	bool agregarClase(ClaseGrupal*);
	ClaseGrupal* buscarClase(int);
	bool eliminarClase(int);
	void mostrarDisponibles();
	int getCantidad();
	int getTam();
	std::string toString();
};
