#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "ContenedorClasesCliente.h"
#include "ColeccionMediciones.h"
#include "ColeccionRutina.h"

using namespace std;

class Cliente {
private:
	// Datos personales del cliente 
	string cedulaIdentidad;
	string nombre;
	string correoElectronico;
	string fechaNacimiento;
	string fechaInscripcion;
	int numeroCelular;
	char sexo;

	ColeccionMediciones* coleccionMediciones;
	ContenedorClasesCliente* clasesCliente; // relación con clases grupales
	ColeccionRutina* rutinaActual; // relación con la rutina actual del cliente

public:
	Cliente(string, string, string, string, string, int, char);
	~Cliente();
	void setHistorialMediciones(ColeccionMediciones*);
	string getCedula();
	void setCedula(string);
	string getNombre();
	void setNombre(string);
	string getCorreo();
	void setCorreo(string);
	string getFechaNacimiento();
	void setFechaNacimiento(string);
	string getFechaInscripcion();
	void setFechaInscripcion(string);
	int getCelular();
	void setCelular(int);
	char getSexo();
	void setSexo(char);
	
	
	string toString();
	ColeccionRutina* getColeccionRutinaActual();

	ColeccionMediciones* getHistorialMediciones();
	ContenedorClasesCliente* getClasesCliente();
};
