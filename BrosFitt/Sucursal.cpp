#include "Sucursal.h"
#include <sstream>

Sucursal::Sucursal()
{


}
Sucursal::Sucursal(string nombre, string provincia, string canton, string correoElectronico, string telefono, int tamClientes, int tamInstructores)
{
	this->nombre = nombre;
	this->canton = canton;
	this->provincia = provincia;
	this->telefono = telefono;
	this->correoElectronico = correoElectronico;
	this->capacidadMaxima = tamClientes;
	clientes = new ColeccionClientes(tamClientes);
	instructores = new ColeccionInstructores(tamInstructores);
}
string Sucursal::getNombre()
{
	return nombre;
}
void Sucursal::setNombre(string nombre)
{
	this->nombre = nombre;
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



bool Sucursal::existenInstructores() {

	if (instructores->getCantidad() > 0) {
		return true;
	}
	return false;
}

void Sucursal::setInstructores(ColeccionInstructores*)
{
	this->instructores = instructores;
}

void Sucursal::agregarInstructorXSucursal(Instructor* instructor)
{
	instructores->insertarAlFinal(instructor);



}



void Sucursal::agregarClienteXSucursal(Cliente* cliente)
{
	clientes->agregarCliente(cliente);
}


ColeccionInstructores* Sucursal::getColeccionInstructores()
{
	return instructores;
}

string Sucursal::toString()
{
	stringstream s;
	s << "Nombre: " << nombre << endl;
	s << "Provincia: " << provincia << endl;
	s << "Canton: " << canton << endl;
	s << "Telefono: " << telefono << endl;
	s << "Correo Electronico: " << correoElectronico << endl;
	s << "Capacidad Maxima: " << capacidadMaxima << endl;
	return s.str();
}
Sucursal::~Sucursal()
{
}


