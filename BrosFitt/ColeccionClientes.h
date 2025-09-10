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
	Cliente* buscarCliente(string);
	bool eliminarCliente(string);
	string listarClientes();
	int getCantidad();
	int getTam();
};

