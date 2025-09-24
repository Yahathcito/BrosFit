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

Rutina* ColeccionRutina::getRutina()
{
	if (cantidad > 0) {
		return rutinas[cantidad - 1];
	}
	return nullptr;
}

void ColeccionRutina::setRutinaActual(Rutina* rutina)
{
	if (cantidad > 0) {
		delete rutinas[cantidad - 1];
		rutinas[cantidad - 1] = rutina;
	}
	else {
		agregarRutina(rutina);
	}
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

	rutinas[cantidad] = rutina; // No hay saturaci�n porque tam >= cantidad + 1
	cantidad++;
}





string ColeccionRutina::toString() {
	string resultado = "";
	for (int i = 0; i < cantidad; i++) {
		resultado += rutinas[i]->toString() + "\n";
	}
	return resultado;
}