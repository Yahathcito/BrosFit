#pragma once
#include <iostream>	
#include <sstream>
#include <string>
#include "Instructor.h"
#include "ColeccionClientes.h"

using namespace std;
class ClaseGrupal
{
private:
	string codigo;
	string nombreClase;
	string horario;
	string duracion;
	int capacidadMaxima;
	string salon;
	ColeccionClientes* clientesMatriculados;
public:
	ClaseGrupal();
	ClaseGrupal(string, string, string, string, int, string);
	string getCodigo();
	void setCodigo(string);
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

