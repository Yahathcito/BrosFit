#include "ColeccionRutina.h"


ColeccionRutina::ColeccionRutina(int)
{
	tam = 5;
	cantidad = 0;
	rutinas = new Rutina * [tam];
	for (int i = 0; i < tam; i++) {
		rutinas[i] = nullptr;
	}
}
ColeccionRutina::~ColeccionRutina() {
	for (int i = 0; i < cantidad; i++) {
		delete rutinas[i];
	}
	delete[] rutinas;
}


void ColeccionRutina::agregarRutina(Rutina* rutina) {
	if (cantidad >= tam) { // Usar >= por seguridad
		int nuevoTam = tam * 2;
		Rutina** nuevoArreglo = new Rutina * [nuevoTam];
		for (int i = 0; i < cantidad; i++) {
			nuevoArreglo[i] = rutinas[i];
		}
		for (int i = cantidad; i < nuevoTam; i++) {
			nuevoArreglo[i] = nullptr;
		}
		delete[] rutinas;
		rutinas = nuevoArreglo;
		tam = nuevoTam;
	}

	rutinas[cantidad] = rutina; // No hay saturación porque tam >= cantidad + 1
	cantidad++;
}
Rutina* ColeccionRutina::buscarRutina(string codigo) {
	for (int i = 0; i < cantidad; i++) {
		if (rutinas[i]->getCodigo() == codigo) {
			return rutinas[i];
		}
	}
	return nullptr;
}
bool ColeccionRutina::eliminarRutina(string codigo) {
	for (int i = 0; i < cantidad; i++) {
		if (rutinas[i]->getCodigo() == codigo) {
			delete rutinas[i];
			for (int j = i; j < cantidad - 1; j++) {
				rutinas[j] = rutinas[j + 1];
			}
			rutinas[cantidad - 1] = nullptr;
			cantidad--;
			return true;
		}
	}
	return false;
}
string ColeccionRutina::listarRutinas() {
	string resultado = "";
	for (int i = 0; i < cantidad; i++) {
		resultado += rutinas[i]->toString() + "\n";
	}
	return resultado;
}
int ColeccionRutina::getCantidad() {
	return cantidad;
}
int ColeccionRutina::getTam() {
	return tam;
}

