#include "Rutina.h"




Rutina::Rutina()
{
	codigo = "";
	nombre = "";
	descripcion = "";
	duracion = 0;
}
Rutina::Rutina(string codigo, string nombre, string descripcion, int duracion)
{
	this->codigo = codigo;
	this->nombre = nombre;
	this->descripcion = descripcion;
	this->duracion = duracion;
}
string Rutina::getCodigo()
{
	return codigo;
}
void Rutina::setCodigo(string codigo)
{
	this->codigo = codigo;
}
string Rutina::getNombre()
{
	return nombre;
}
void Rutina::setNombre(string nombre)
{
	this->nombre = nombre;
}
string Rutina::getDescripcion()
{
	return descripcion;
}
void Rutina::setDescripcion(string descripcion)
{
	this->descripcion = descripcion;
}
int Rutina::getDuracion()
{
	return duracion;
}
void Rutina::setDuracion(int duracion)
{
	this->duracion = duracion;
}
string Rutina::toString()
{
	stringstream s;
	s << "Codigo: " << codigo << endl;
	s << "Nombre: " << nombre << endl;
	s << "Descripcion: " << descripcion << endl;
	s << "Duracion: " << duracion << " minutos" << endl;
	return s.str();
}
Rutina::~Rutina()
{
}



