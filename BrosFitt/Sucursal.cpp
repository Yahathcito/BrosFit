#include "Sucursal.h"
#include <sstream>

Sucursal::Sucursal()
{


}
Sucursal::Sucursal(string codigo, string provincia, string canton, string correoElectronico, string telefono, int tamClientes, int tamInstructores)
{
	this->codigo = codigo;
	this->canton = canton;
	this->provincia = provincia;
	this->telefono = telefono;
	this->correoElectronico = correoElectronico;
	this->capacidadMaximaClientes = tamClientes;
	this->capacidadMaximaInstructores = tamInstructores;
	clientes = new ColeccionClientes(tamClientes);
	instructores = new ColeccionInstructores(tamInstructores);
	clasesOfrecidas = new ColeccionClaseGrupal();
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
	clientes->insertarAlFinal(cliente);
}


string Sucursal::getCodigo()
{
	return codigo;
}
void Sucursal::setCodigo(string codigo)
{
	this->codigo = codigo;
}
int Sucursal::getCapacidadMaximaInstructores()
{
	return capacidadMaximaInstructores;
}
void Sucursal::setCapacidadMaximaInstructores(int capacidadMaximaInstructores)
{
	this->capacidadMaximaInstructores = capacidadMaximaInstructores;
}
int Sucursal::getCapacidadMaximaClientes()
{
	return capacidadMaximaClientes;
}
ColeccionClientes* Sucursal::getClientes()
{
	return clientes;
}
void Sucursal::setClientes(ColeccionClientes* clientes)
{
	this->clientes = clientes;
}

ColeccionInstructores* Sucursal::getColeccionInstructores()
{
	return instructores;
}

ColeccionClaseGrupal* Sucursal::getClasesOfrecidas(){
	return clasesOfrecidas;
}

string Sucursal::toString()
{
	stringstream s;
	s << "Codigo: " << codigo << endl;
	s << "Provincia: " << provincia << endl;
	s << "Canton: " << canton << endl;
	s << "Telefono: " << telefono << endl;
	s << "Correo Electronico: " << correoElectronico << endl;
	
	return s.str();
}
Sucursal::~Sucursal(){
	delete clientes;
	delete instructores;
	delete clasesOfrecidas;
}


