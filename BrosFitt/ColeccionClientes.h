#pragma once
#include <string>
#include"Cliente.h"

class ColeccionClientes {
private:
	int tam;
	int cantidad;
	Cliente** clientes;

public:
	ColeccionClientes(int);
	~ColeccionClientes();
	
	
	Cliente* getClientesxIndice(int);
	void agregarCliente(Cliente*);
	Cliente* buscarCli(std::string);
	Cliente* buscarCliente(const std::string& cedula);
	bool eliminarCliente(std::string);
	std::string listarClientes();
	bool insertarAlFinal(Cliente*);
	int getCantidad();
	int getTam();
	std::string toString();
};
