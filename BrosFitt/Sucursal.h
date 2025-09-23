
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

	string codigo;
	string canton;
	string provincia;
	string telefono;
	string correoElectronico;
	int capacidadMaximaClientes;
	int capacidadMaximaInstructores;
	ColeccionClientes* clientes;
	ColeccionInstructores* instructores;

public:
	Sucursal();
	Sucursal(string codigo, string provincia,string canton, string correoElectronico, string telefono,  int tamClientes, int tamInstructores);
	string getNombre();
	void setNombre(string nombre);

	string getTelefono();
	void setTelefono(string telefono);
	string getCorreoElectronico();
	void setCorreoElectronico(string correoElectronico);

	string getCodigo();
	void setCodigo(string codigo);
	int getCapacidadMaximaInstructores();
	void setCapacidadMaximaInstructores(int capacidadMaximaInstructores);
	int getCapacidadMaximaClientes();


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

