#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "ColeccionClientes.h"
#include "ColeccionMediciones.h"
#include "ColeccionRutina.h"
#include "ColeccionEjercicios.h"
#include "ColeccionClaseGrupal.h"
using namespace std;

class Instructor {
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
	ColeccionClaseGrupal* clasesAsociadas; 
public:
	Instructor();
	Instructor(string, string, int, string, string, string[], int, int);

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
	string* getEspecialidades();
	bool tieneEspecialidad(string);
	Instructor* getPorIndice(int);
	string getEspecialidad();
	void setEspecialidad(string);
	int getCantEspecialidades();
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

