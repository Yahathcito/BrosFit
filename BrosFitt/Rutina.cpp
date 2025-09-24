#include "Rutina.h"






Rutina::Rutina(string codigo) {


	this->duracion = 0;
	this->cedulaCliente = "";
	this->cedulaCliente = codigo;
	coleccionEjercicios = new ColeccionEjercicios(10); // Tamaño inicial de 10, puede ajustarse según necesidad

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
	ss << "Ejercicios:\n";
	for (int i = 0; i < coleccionEjercicios->getCantidad(); ++i) {
		ss << "- " << coleccionEjercicios->getEjercicio(i)->getNombre() << "\n";
	}
	return ss.str();
}




Rutina::~Rutina()
{

	delete coleccionEjercicios;

}







