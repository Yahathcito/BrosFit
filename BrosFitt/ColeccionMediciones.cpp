#include "ColeccionMediciones.h"

ColeccionMediciones::ColeccionMediciones(int tam) {
	this->tam = tam;
	cantidad = 0;
	mediciones = new Medicion * [tam];
	for (int i = 0; i < tam; i++) {
		mediciones[i] = nullptr;
	}
}
ColeccionMediciones::~ColeccionMediciones() {
	for (int i = 0; i < cantidad; i++) {
		delete mediciones[i];
	}
	delete[] mediciones;
}
void ColeccionMediciones::agregarMedicion(Medicion* medicion) {
	if (cantidad < tam) {
		mediciones[cantidad] = medicion;
		cantidad++;
	}
	else {
		cout << "No se puede agregar más mediciones, capacidad máxima alcanzada." << endl;
	}
}
Medicion* ColeccionMediciones::buscarMedicion(string idCliente, string fechaMedicion) {
	for (int i = 0; i < cantidad; i++) {
		if (mediciones[i]->getIdCliente() == idCliente && mediciones[i]->getFechaMedicion() == fechaMedicion) {
			return mediciones[i];
		}
	}
	return nullptr;
}
bool ColeccionMediciones::eliminarMedicion(string idCliente, string fechaMedicion) {
	for (int i = 0; i < cantidad; i++) {
		if (mediciones[i]->getIdCliente() == idCliente && mediciones[i]->getFechaMedicion() == fechaMedicion) {
			delete mediciones[i];
			for (int j = i; j < cantidad - 1; j++) {
				mediciones[j] = mediciones[j + 1];
			}
			mediciones[cantidad - 1] = nullptr;
			cantidad--;
			return true;
		}
	}
	return false;
}
string ColeccionMediciones::listarMediciones() {
	string resultado = "";
	for (int i = 0; i < cantidad; i++) {
		resultado += mediciones[i]->toString() + "\n";
	}
	return resultado;
}
int ColeccionMediciones::getCantidad() {
	return cantidad;
}
int ColeccionMediciones::getTam() {
	return tam;
}


