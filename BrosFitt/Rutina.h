#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Rutina
{
private:
	string codigo;
	string nombre;
	string descripcion;
	int duracion; // Duracion en minutos
public:
	Rutina();
	Rutina(string codigo, string nombre, string descripcion, int duracion);
	string getCodigo();
	void setCodigo(string codigo);
	string getNombre();
	void setNombre(string nombre);
	string getDescripcion();
	void setDescripcion(string descripcion);
	int getDuracion();
	void setDuracion(int duracion);
	string toString();
	~Rutina();
};

