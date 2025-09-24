#include "Rutina.h"






Rutina::Rutina(string codigo) {

	this->codigo = codigo;
	this->nombre = "";
	this->descripcion = "";
	this->duracion = 0;
	this->cedulaCliente = "";
}

void Rutina::limpiarRutina() {
	codigo = "";
	nombre = "";
	descripcion = "";
	duracion = 0;
	cedulaCliente = "";
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


string Rutina::getCedulaCliente()
{
	return cedulaCliente;
}
void Rutina::setCedulaCliente(string cedula)
{
	this->cedulaCliente = cedula;
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

bool Rutina::agregarEjercicio(Ejercicio* ejercicio)
{
	if (ejercicio) {
		// Actualizar duracion total de la rutina
		duracion += ejercicio->getDuracion();
		return true;
	}
	return false;
}

string Rutina::toString()
{
	stringstream ss;

	ss << "Duracion total: " << duracion << " mins\n";
	
	return ss.str();
}




Rutina::~Rutina()
{


}







