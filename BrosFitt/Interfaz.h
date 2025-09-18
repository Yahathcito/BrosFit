#pragma once
#include <iostream>
#include <string>
#include "ColeccionSucursal.h"
using namespace std;

class Interfaz{
private:

	static ColeccionSucursal* coleccionSucursales;
	static ColeccionClientes* coleccionClientes;

public: 
	static void menu();
	static void ingresoDatosGenerales();
	static void informeDeClientes();
};

