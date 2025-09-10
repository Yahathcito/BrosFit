#include "Ejercicio.h"

Ejercicio::Ejercicio()
{
	codigo = "";
	nombre = "";
	descripcion = "";
	area = "";
	duracion = 0;
}
Ejercicio::Ejercicio(string codigo, string nombre, string descripcion, string area, int duracion)
{
	this->codigo = codigo;
	this->nombre = nombre;
	this->descripcion = descripcion;
	this->area = area;
	this->duracion = duracion;
}
string Ejercicio::getCodigo()
{
	return codigo;
}
void Ejercicio::setCodigo(string codigo)
{
	this->codigo = codigo;
}
string Ejercicio::getNombre()
{
	return nombre;
}
void Ejercicio::setNombre(string nombre)
{
	this->nombre = nombre;
}
string Ejercicio::getDescripcion()
{
	return descripcion;
}
void Ejercicio::setDescripcion(string descripcion)
{
	this->descripcion = descripcion;
}
string Ejercicio::getArea()
{
	return area;
}


void Ejercicio::setArea(string area)
{
	this->area = area;
}
int Ejercicio::getDuracion()
{
	return duracion;
}
void Ejercicio::setDuracion(int duracion)
{
	this->duracion = duracion;
}
string Ejercicio::toString()
{
	stringstream s;
	s << "Codigo: " << codigo << endl;
	s << "Nombre: " << nombre << endl;
	s << "Descripcion: " << descripcion << endl;
	s << "Area: " << area << endl;
	s << "Duracion: " << duracion << " minutos" << endl;
	return s.str();
}
Ejercicio::~Ejercicio()
{
}
