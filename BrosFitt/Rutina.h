#pragma once
#include <iostream>
#include <string>
#include <sstream>

#include "Ejercicio.h"



using namespace std;

class Rutina
{
private:

	string codigo;
	string nombre;
	string descripcion;
	int duracion;

	string cedulaCliente; 
public:
	Rutina(string);
	void limpiarRutina();
	void setNombre(string nombre);
	string getNombre();


	string getCodigo();
	void setCodigo(string codigo);

	string getCedulaCliente();
	void setCedulaCliente(string cedula);
	string getDescripcion();
	void setDescripcion(string descripcion);
	int getDuracion();
	void setDuracion(int duracion);
	//ocupo ver un toString de Rutina con los ejercicios que tiene el cliente, hazlo ya

	string toString();
	bool agregarEjercicio(Ejercicio* ejercicio);



	~Rutina();


	
};

