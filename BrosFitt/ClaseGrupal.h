#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "ColeccionClientes.h"
using namespace std;

class ClaseGrupal {
private:
	int codigo;
	string nombreClase;
	string horario;
	string duracion;
	int capacidadMaxima;
	string salon;
	ColeccionClientes* clientesMatriculados; 

public:
	ClaseGrupal(int, string, string, string, int, string);
	int getCodigo();
	void setCodigo(int);
	string getNombreClase();
	void setNombreClase(string);
	string getHorario();
	void setHorario(string);
	string getDuracion();
	void setDuracion(string);
	int getCapacidadMaxima();
	void setCapacidadMaxima(int);
	string getSalon();
	void setSalon(string);
	string toString();
	~ClaseGrupal();
};
