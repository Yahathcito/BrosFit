#pragma once
#include "Sucursal.h"
class ColeccionSucursal
{
private:
	int tam;
	int cantidad;
	Sucursal** sucursales;

public:
	ColeccionSucursal(int);
	~ColeccionSucursal();
	void agregarSucursal(Sucursal*);
	Sucursal* buscarSucursal(string);
	string listarSucursales();
	int getCantidad();
	int getTam();
	bool insertarAlInicio(Sucursal*);

		bool insertarAlFinal(Sucursal*);
		string toString();


};

