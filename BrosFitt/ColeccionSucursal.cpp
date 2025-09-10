#include "ColeccionSucursal.h"

ColeccionSucursal::ColeccionSucursal(int)
{
	tam = 5;
	cantidad = 0;
	sucursales = new Sucursal * [tam];
	for (int i = 0; i < tam; i++) {
		sucursales[i] = nullptr;
	}
}
ColeccionSucursal::~ColeccionSucursal()
{
	for (int i = 0; i < cantidad; i++) {
		delete sucursales[i];
	}
	delete[] sucursales;
}
void ColeccionSucursal::agregarSucursal(Sucursal* sucursal)
{
	if (cantidad == tam) {
		// Redimensionar el arreglo
		int nuevoTam = tam * 2;
		Sucursal** nuevoArreglo = new Sucursal * [nuevoTam];
		for (int i = 0; i < cantidad; i++) {
			nuevoArreglo[i] = sucursales[i];
		}
		for (int i = cantidad; i < nuevoTam; i++) {
			nuevoArreglo[i] = nullptr;
		}
		delete[] sucursales;
		sucursales = nuevoArreglo;
		tam = nuevoTam;
	}
	sucursales[cantidad] = sucursal;
	cantidad++;
}
Sucursal* ColeccionSucursal::buscarSucursal(string nombre)
{
	for (int i = 0; i < cantidad; i++) {
		if (sucursales[i]->getNombre() == nombre) {
			return sucursales[i];
		}
	}
	return nullptr;
}

// explica donde se esta insertando la nueva sucursal al final del arreglo?


bool ColeccionSucursal::eliminarSucursal(string nombre)
{
	for (int i = 0; i < cantidad; i++) {
		if (sucursales[i]->getNombre() == nombre) {
			delete sucursales[i];
			for (int j = i; j < cantidad - 1; j++) {
				sucursales[j] = sucursales[j + 1];
			}
			sucursales[cantidad - 1] = nullptr;
			cantidad--;
			return true;
		}
	}
	return false;
}
string ColeccionSucursal::listarSucursales()
{
	string resultado = "";
	for (int i = 0; i < cantidad; i++) {
		resultado += sucursales[i]->toString() + "\n";
	}
	return resultado;
}
int ColeccionSucursal::getCantidad()
{
	return cantidad;
}
int ColeccionSucursal::getTam()
{
	return tam;
}

bool ColeccionSucursal::insertarAlInicio(Sucursal* v)
{
	if (cantidad == tam) {
		// Redimensionar el arreglo
		int nuevoTam = tam * 2;
		Sucursal** nuevoArreglo = new Sucursal * [nuevoTam];
		for (int i = 0; i < cantidad; i++) {
			nuevoArreglo[i] = sucursales[i];
		}
		for (int i = cantidad; i < nuevoTam; i++) {
			nuevoArreglo[i] = nullptr;
		}
		delete[] sucursales;
		sucursales = nuevoArreglo;
		tam = nuevoTam;
	}
	// Desplazar elementos a la derecha
	for (int i = cantidad; i > 0; i--) {
		sucursales[i] = sucursales[i - 1];
	}
	sucursales[0] = nullptr; // Aquí debería ir el puntero a la nueva sucursal
	cantidad++;
	return true;
}




bool ColeccionSucursal::insertarAlFinal(Sucursal* v)
{

	if (buscarSucursal(v->getNombre()) != nullptr) {
		cout << "La sucursal ya está ingresada." << endl;
		delete v;
		return false;
	}
	if (cantidad == tam) {
		// Redimensionar el arreglo
		int nuevoTam = tam * 2;
		Sucursal** nuevoArreglo = new Sucursal * [nuevoTam];
		for (int i = 0; i < cantidad; i++) {
			nuevoArreglo[i] = sucursales[i];
		}
		for (int i = cantidad; i < nuevoTam; i++) {
			nuevoArreglo[i] = nullptr;
		}
		delete[] sucursales;
		sucursales = nuevoArreglo;
		tam = nuevoTam;
	}
	sucursales[cantidad] = v; // Aquí se inserta la nueva sucursal al final del arreglo
	cantidad++;
	return true;
}

string ColeccionSucursal::toString()
{
	string resultado = "";
	for (int i = 0; i < cantidad; i++) {
		resultado += sucursales[i]->toString() + "\n";
	}
	return resultado;
}