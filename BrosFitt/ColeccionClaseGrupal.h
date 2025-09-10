#pragma once
#include "ClaseGrupal.h"
class ColeccionClaseGrupal
{
private:
	int tam;
	int cantidad;
	ClaseGrupal** clases;
public:
	ColeccionClaseGrupal(int);
	~ColeccionClaseGrupal();
	void agregarClase(ClaseGrupal*);
	ClaseGrupal* buscarClase(string);
	bool eliminarClase(string);
	string listarClases();
	int getCantidad();
	int getTam();
};

