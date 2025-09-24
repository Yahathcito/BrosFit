#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Ejercicio
{
private:
	string nombre;
	string area;
	int duracion; // Duracion en minutos
	int repeticiones;
	int series;
	float pesoRecomendado;
	string codigo; // Codigo unico para cada ejercicio

public:
	
	Ejercicio(string, string,string, int, int, int, float);
	string getCodigo();
	void setCodigo(string);
	string getNombre();
	void setNombre(string);
	string getDescripcion();
	void setDescripcion(string);
	string getAreaCuerpo();
	void setAreaCuerpo(string);
	int getDuracion();
	void setDuracion(int);
	string toString();
	~Ejercicio();
};
