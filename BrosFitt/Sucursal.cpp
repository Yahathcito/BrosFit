#include "Sucursal.h"
#include <sstream>
Sucursal::Sucursal()
{
}

Sucursal::Sucursal(string nombre, string direccion, string telefono, string correoElectronico, int capacidadMaxima)
{
	this->nombre = nombre;
	this->direccion = direccion;
	this->telefono = telefono;
	this->correoElectronico = correoElectronico;
	this->capacidadMaxima = capacidadMaxima;
}
string Sucursal::getNombre()
{
	return nombre;
}
void Sucursal::setNombre(string nombre)
{
	this->nombre = nombre;
}
string Sucursal::getDireccion()
{
	return direccion;
}
void Sucursal::setDireccion(string direccion)
{
	this->direccion = direccion;
}
string Sucursal::getTelefono()
{
	return telefono;
}
void Sucursal::setTelefono(string telefono)
{
	this->telefono = telefono;
}
string Sucursal::getCorreoElectronico()
{
	return correoElectronico;
}
void Sucursal::setCorreoElectronico(string correoElectronico)
{
	this->correoElectronico = correoElectronico;
}
int Sucursal::getCapacidadMaxima()
{
	return capacidadMaxima;
}
void Sucursal::setCapacidadMaxima(int capacidadMaxima)
{
	this->capacidadMaxima = capacidadMaxima;
}
string Sucursal::toString()
{
	stringstream s;
	s << "Nombre: " << nombre << endl;
	s << "Direccion: " << direccion << endl;
	s << "Telefono: " << telefono << endl;
	s << "Correo Electronico: " << correoElectronico << endl;
	s << "Capacidad Maxima: " << capacidadMaxima << endl;
	return s.str();
}
Sucursal::~Sucursal()
{
}


