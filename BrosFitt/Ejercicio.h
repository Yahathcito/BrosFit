#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Ejercicio
{
private:
	string codigo;
	string nombre;
	string descripcion;
	string area;
	int duracion; // Duracion en minutos

public:
	Ejercicio();
	Ejercicio(string, string, string, string, int);
	string getCodigo();
	void setCodigo(string);
	string getNombre();
	void setNombre(string);
	string getDescripcion();
	void setDescripcion(string);
	string getArea();
	void setArea(string);
	int getDuracion();
	void setDuracion(int);
	string toString();
	~Ejercicio();
};
