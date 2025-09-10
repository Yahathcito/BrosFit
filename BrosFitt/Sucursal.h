
#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "ColeccionInstructores.h"
#include "ColeccionClientes.h"
#include "ColeccionClaseGrupal.h"

using namespace std;
class Sucursal
{
private:

	string nombre;
	string direccion;
	string telefono;
	string correoElectronico;
	int capacidadMaxima;
	ColeccionClientes* clientes;
	ColeccionInstructores* instructores;

public:
	Sucursal();
	Sucursal(string nombre, string direccion, string telefono, string correoElectronico, int tamClientes, int tamInstructores);
	string getNombre();
	void setNombre(string nombre);
	string getDireccion();
	void setDireccion(string direccion);
	string getTelefono();
	void setTelefono(string telefono);
	string getCorreoElectronico();
	void setCorreoElectronico(string correoElectronico);
	int getCapacidadMaxima();
	void setCapacidadMaxima(int capacidadMaxima);
	ColeccionClientes* getClientes();
	ColeccionInstructores* getColeccionInstructores();
	void setClientes(ColeccionClientes*);
	bool existenInstructores();
	void setInstructores(ColeccionInstructores*);
	void agregarInstructorXSucursal(Instructor*);
	void agregarClienteXSucursal(Cliente*);
	string toString();
	~Sucursal();



};

