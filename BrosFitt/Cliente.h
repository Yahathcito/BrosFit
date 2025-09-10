#pragma once
#include <iostream>
#include <sstream>
#include <string>



using namespace std;
class Cliente {
private:

	//Datos personales del cliente 
	string cedulaIdentidad;
	string nombre;
	string correoElectronico;
	string fechaNacimiento;
	string fechaInscripcion;
	int numeroCelular;
	char sexo;



public:

	//Constructores y destructor 
	Cliente();
	Cliente(string, string, string, string, string, int, char);
	~Cliente();
	//Getters y Setters 
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




};


