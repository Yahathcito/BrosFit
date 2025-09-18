#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "ColeccionClientes.h"
#include "ColeccionMediciones.h"
#include "ColeccionRutina.h"
#include "ColeccionEjercicios.h"

using namespace std;


class Instructor
{
private:
	string cedula;
	string nombre;
	int telefono;
	string fechaNacimiento;
	string correo;
	string especialidades[8];
	ColeccionClientes* clientes;
	ColeccionMediciones* mediciones;
	ColeccionRutina* rutinas;
	ColeccionEjercicios* ejercicios;
	

	 

public:
	Instructor();
	Instructor(string, string, int, string ,string, string[],int,int);
	string getCedula();
	void setCedula(string);
	string getNombre();
	void setNombre(string);
	int getTelefono();
	void setTelefono(int);
	string getFechaNacimiento();
	void setFechaNacimiento(string);
	string getCorreo();
	void setCorreo(string);
	Instructor* getPorIndice(int);
	string getEspecialidad();
	void setEspecialidad(string);
	ColeccionClientes* getClientes();
	void setClientes(ColeccionClientes*);
	ColeccionMediciones* getMediciones();
	void setMediciones(ColeccionMediciones*);
	ColeccionRutina* getRutinas();
	void setRutinas(ColeccionRutina*);
	ColeccionEjercicios* getEjercicios();
	void setEjercicios(ColeccionEjercicios*);
	string toString();
	~Instructor();

};

