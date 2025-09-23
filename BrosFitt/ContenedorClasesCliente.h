#pragma once
#include <string>

class ClaseGrupal; // forward declaration

class ContenedorClasesCliente {
private:
	int can;
	int tam;
	ClaseGrupal** clasesCliente;

public:
	ContenedorClasesCliente();
	~ContenedorClasesCliente();

	bool agregarClase(ClaseGrupal* clase);
	std::string toString();
};
