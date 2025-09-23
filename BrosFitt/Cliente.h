#pragma once
#include <iostream>
#include <sstream>
#include <string>

class ColeccionMediciones;     // forward declaration
class ContenedorClasesCliente; // forward declaration

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

public:
	Cliente(string, string, string, string, string, int, char);
	~Cliente();

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

	ColeccionMediciones* getHistorialMediciones();
};
