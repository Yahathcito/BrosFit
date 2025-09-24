#include "Ejercicio.h"


Ejercicio::Ejercicio(string codigo, string nombre, string area, int duracion, int repeticiones, int series, float pesoRecomendado)
{
	this->codigo = codigo;
	this->nombre = nombre;
	this->repeticiones = repeticiones;
	this->series = series;
	this->area = area;
	this->duracion = duracion;
	this->pesoRecomendado = pesoRecomendado;

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

string Ejercicio::getAreaCuerpo()
{
	return area;
}
void Ejercicio::setAreaCuerpo(string area)
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
	stringstream ss;
	ss << "Codigo: " << codigo << ", Nombre: " << nombre << ", Area: " << area
		<< ", Duracion: " << duracion << " mins, Repeticiones: " << repeticiones
		<< ", Series: " << series << ", Peso Recomendado: " << pesoRecomendado << " kg";
	return ss.str();
}
Ejercicio::~Ejercicio()
{
}
