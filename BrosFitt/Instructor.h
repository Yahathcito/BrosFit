#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Instructor
{
private:
	string cedula;
	string nombre;
	int telefono;
	string fechaNacimiento;
	string correo;

public:

	Instructor();
	Instructor(string cedula, string nombre, int telefono, string fechaNacimiento, string correo);
	string getCedula();
	void setCedula(string cedula);
	string getNombre();
	void setNombre(string nombre);
	int getTelefono();
	void setTelefono(int telefono);
	string getFechaNacimiento();
	void setFechaNacimiento(string fechaNacimiento);
	string getCorreo();
	void setCorreo(string correo);
	string toString();
	~Instructor();

};

