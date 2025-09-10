#include "Instructor.h"
#include "Instructor.h"

Instructor::Instructor()
{
}

Instructor::Instructor(string cedula, string nombre, int telefono, string fechaNacimiento, string correo)
{
	this->cedula = cedula;
	this->nombre = nombre;
	this->telefono = telefono;
	this->fechaNacimiento = fechaNacimiento;
	this->correo = correo;
}

string Instructor::getCedula()
{
	return cedula;
}

void Instructor::setCedula(string cedula)
{
	this->cedula = cedula;
}

string Instructor::getNombre()
{
	return nombre;
}
void Instructor::setNombre(string nombre)
{
	this->nombre = nombre;
}
int Instructor::getTelefono()
{
	return telefono;
}

void Instructor::setTelefono(int telefono)
{
	this->telefono = telefono;
}
string Instructor::getFechaNacimiento()
{
	return fechaNacimiento;
}
void Instructor::setFechaNacimiento(string fechaNacimiento)
{
	this->fechaNacimiento = fechaNacimiento;
}
string Instructor::getCorreo()
{
	return correo;
}
void Instructor::setCorreo(string correo)
{
	this->correo = correo;
}
string Instructor::toString()
{
	stringstream s;
	s << "Cedula: " << cedula << endl;
	s << "Nombre: " << nombre << endl;
	s << "Telefono: " << telefono << endl;
	s << "Fecha de Nacimiento: " << fechaNacimiento << endl;
	s << "Correo: " << correo << endl;
	return s.str();
}
Instructor::~Instructor()
{
}


