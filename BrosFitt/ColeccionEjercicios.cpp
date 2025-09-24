#include "ColeccionEjercicios.h"

ColeccionEjercicios::ColeccionEjercicios(int tam) {
	this->tam = tam;
	cantidad = 0;
	ejercicios = new Ejercicio * [tam];
	for (int i = 0; i < tam; i++) {
		ejercicios[i] = nullptr;
	}
}
Ejercicio* ColeccionEjercicios::getPorIndice(int indice) {
	if (indice >= 0 && indice < cantidad) {
		return ejercicios[indice];
	}
	return nullptr;
}
ColeccionEjercicios::~ColeccionEjercicios() {
	for (int i = 0; i < cantidad; i++) {
		delete ejercicios[i];
	}
	delete[] ejercicios;
}
Ejercicio* ColeccionEjercicios::getEjercicio()
{
	if (cantidad > 0) {
		return ejercicios[cantidad - 1];
	}
	return nullptr;
}

bool ColeccionEjercicios::agregarEjercicio(Ejercicio* ejercicio) {
	if (cantidad >= tam) { // Usar >= por seguridad
		int nuevoTam = tam * 2;
		Ejercicio** nuevoArreglo = new Ejercicio * [nuevoTam];
		for (int i = 0; i < cantidad; i++) {
			nuevoArreglo[i] = ejercicios[i];
		}
		for (int i = cantidad; i < nuevoTam; i++) {
			nuevoArreglo[i] = nullptr;
		}
		delete[] ejercicios;
		ejercicios = nuevoArreglo;
		tam = nuevoTam;
	}
	ejercicios[cantidad] = ejercicio; // No hay saturación porque tam >= cantidad + 1
	cantidad++;
	return true;
}

Ejercicio* ColeccionEjercicios::buscarEjercicio(string codigo) {
	for (int i = 0; i < cantidad; i++) {
		if (ejercicios[i]->getCodigo() == codigo) {
			return ejercicios[i];
		}
	}
	return nullptr;
}
bool ColeccionEjercicios::eliminarEjercicio(string codigo) {
	for (int i = 0; i < cantidad; i++) {
		if (ejercicios[i]->getCodigo() == codigo) {
			delete ejercicios[i];
			for (int j = i; j < cantidad - 1; j++) {
				ejercicios[j] = ejercicios[j + 1];
			}
			ejercicios[cantidad - 1] = nullptr;
			cantidad--;
			return true;
		}
	}
	return false;
}

string ColeccionEjercicios::listarEjercicios() {
	string resultado = "";
	for (int i = 0; i < cantidad; i++) {
		resultado += ejercicios[i]->toString() + "\n";
	}
	return resultado;
}
int ColeccionEjercicios::getCantidad() {
	return cantidad;
}
int ColeccionEjercicios::getTam() {
	return tam;
}

string ColeccionEjercicios::toString() {
	string resultado = "";
	for (int i = 0; i < cantidad; i++) {
		resultado += ejercicios[i]->toString() + "\n";
	}
	return resultado;
}

