#include "ClaseGrupal.h"


ClaseGrupal::ClaseGrupal()
{
}
ClaseGrupal::ClaseGrupal(string codigo, string nombreClase, string horario, string duracion, int capacidadMaxima, string salon)
{
	this->codigo = codigo;
	this->nombreClase = nombreClase;
	this->horario = horario;
	this->duracion = duracion;
	this->capacidadMaxima = capacidadMaxima;
	this->salon = salon;
}
string ClaseGrupal::getCodigo()
{
	return codigo;
}
void ClaseGrupal::setCodigo(string codigo)
{
	this->codigo = codigo;
}
string ClaseGrupal::getNombreClase()
{
	return nombreClase;
}
void ClaseGrupal::setNombreClase(string nombreClase)
{
	this->nombreClase = nombreClase;
}
string ClaseGrupal::getHorario()
{
	return horario;
}
void ClaseGrupal::setHorario(string horario)
{
	this->horario = horario;
}
string ClaseGrupal::getDuracion()
{
	return duracion;
}
void ClaseGrupal::setDuracion(string duracion)
{
	this->duracion = duracion;
}
int ClaseGrupal::getCapacidadMaxima()
{
	return capacidadMaxima;
}
void ClaseGrupal::setCapacidadMaxima(int capacidadMaxima)
{
	this->capacidadMaxima = capacidadMaxima;
}
string ClaseGrupal::getSalon()
{
	return salon;
}
void ClaseGrupal::setSalon(string salon)
{
	this->salon = salon;
}
string ClaseGrupal::toString()
{
	stringstream s;
	s << "Codigo: " << codigo << endl;
	s << "Nombre de la clase: " << nombreClase << endl;
	s << "Horario: " << horario << endl;
	s << "Duracion: " << duracion << endl;
	s << "Capacidad Maxima: " << capacidadMaxima << endl;
	s << "Salon: " << salon << endl;
	return s.str();
}

ClaseGrupal::~ClaseGrupal()
{
}
