#pragma once
#include "Cliente.h"

using namespace std;
class ColeccionClientes {
private:
	int tam;
	int cantidad;
	Cliente** clientes;
public:
	ColeccionClientes(int);
	~ColeccionClientes();
	void agregarCliente(Cliente*);
	Cliente* buscarCli(string);
	Cliente* buscarCliente(const string& cedula);  
	bool eliminarCliente(string);
	string listarClientes();
	bool insertarAlFinal(Cliente*);	
	int getCantidad();
	int getTam();

};

