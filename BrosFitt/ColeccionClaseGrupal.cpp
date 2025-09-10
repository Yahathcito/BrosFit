#include "ColeccionClaseGrupal.h"
#include <sstream>


ColeccionClaseGrupal::ColeccionClaseGrupal(int)
{
	tam = 5;
	cantidad = 0;
	clases = new ClaseGrupal * [tam];
	for (int i = 0; i < tam; i++) {
		clases[i] = nullptr;
	}
}
ColeccionClaseGrupal::~ColeccionClaseGrupal() {
	for (int i = 0; i < cantidad; i++) {
		delete clases[i];
	}
	delete[] clases;
}

void ColeccionClaseGrupal::agregarClase(ClaseGrupal* clase) {
	if (cantidad == tam) {
		// Redimensionar el arreglo
		int nuevoTam = tam * 2;
		ClaseGrupal** nuevoArreglo = new ClaseGrupal * [nuevoTam];
		for (int i = 0; i < cantidad; i++) {
			nuevoArreglo[i] = clases[i];
		}
		for (int i = cantidad; i < nuevoTam; i++) {
			nuevoArreglo[i] = nullptr;
		}
		delete[] clases;
		clases = nuevoArreglo;
		tam = nuevoTam;
	}
	clases[cantidad] = clase;
	cantidad++;
}
ClaseGrupal* ColeccionClaseGrupal::buscarClase(string codigo) {
	for (int i = 0; i < cantidad; i++) {
		if (clases[i]->getCodigo() == codigo) {
			return clases[i];
		}
	}
	return nullptr;
}
bool ColeccionClaseGrupal::eliminarClase(string codigo) {
	for (int i = 0; i < cantidad; i++) {
		if (clases[i]->getCodigo() == codigo) {
			delete clases[i];
			for (int j = i; j < cantidad - 1; j++) {
				clases[j] = clases[j + 1];
			}
			clases[cantidad - 1] = nullptr;
			cantidad--;
			return true;
		}
	}
	return false;
}
string ColeccionClaseGrupal::listarClases() {
	string resultado = "";
	for (int i = 0; i < cantidad; i++) {
		resultado += clases[i]->toString() + "\n";
	}
	return resultado;
}
int ColeccionClaseGrupal::getCantidad() {
	return cantidad;
}
int ColeccionClaseGrupal::getTam() {
	return tam;
}
