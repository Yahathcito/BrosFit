#pragma once
#include <iostream>
#include <string>
#include <sstream>

#include "ColeccionEjercicios.h"



using namespace std;

class Rutina
{
private:

	int duracion;
	ColeccionEjercicios* coleccionEjercicios;

	string cedulaCliente; 
public:
	Rutina(string);
	void limpiarRutina();
	void setNombre(string nombre);
	string getNombre();



	string getCedulaCliente();
	void setCedulaCliente(string cedula);

	int getDuracion();
	void setDuracion(int duracion);
	//ocupo ver un toString de Rutina con los ejercicios que tiene el cliente, hazlo ya

	string toString();
	
	ColeccionEjercicios* getColeccionEjercicios();


	~Rutina();


	
};

