#include "Rutina.h"






Rutina::Rutina(string codigo) {


	this->duracion = 0;
	this->cedulaCliente = "";
}

void Rutina::limpiarRutina() {

	duracion = 0;
	cedulaCliente = "";
}








string Rutina::getCedulaCliente()
{
	return cedulaCliente;
}
void Rutina::setCedulaCliente(string cedula)
{
	this->cedulaCliente = cedula;
}


int Rutina::getDuracion()
{
	return duracion;
}
void Rutina::setDuracion(int duracion)
{
	this->duracion = duracion;
}



ColeccionEjercicios* Rutina::getColeccionEjercicios()
{
	return coleccionEjercicios;
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







