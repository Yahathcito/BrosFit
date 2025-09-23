#include "ColeccionInstructores.h"


ColeccionInstructores::ColeccionInstructores(int tam) {
	this->tam = tam;
	cantidad = 0;
	instructores = new Instructor * [tam];
	for (int i = 0; i < tam; i++) {
		instructores[i] = nullptr;
	}
}
ColeccionInstructores::~ColeccionInstructores() {
	for (int i = 0; i < cantidad; i++) {
		delete instructores[i];
	}
	delete[] instructores;
}

    bool ColeccionInstructores::insertarAlFinal(Instructor* instructor)
    {
					// debes verificar si ya esta ingresado el instructor	
					// verificar que no tenga los mismo datos de otro instructor
					if (buscarInstructor(instructor->getCedula()) != nullptr) {
						cout << "El instructor ya está ingresado." << endl;
						return false;
					}
					if (cantidad == tam) {
						// Redimensionar el arreglo
						int nuevoTam = tam * 2;
						Instructor** nuevoArreglo = new Instructor * [nuevoTam];
						for (int i = 0; i < cantidad; i++) {
							nuevoArreglo[i] = instructores[i];
						}
						for (int i = cantidad; i < nuevoTam; i++) {
							nuevoArreglo[i] = nullptr;
						}
						delete[] instructores;
						instructores = nuevoArreglo;
						tam = nuevoTam;
					}
					instructores[cantidad] = instructor; // Corregido: asignar el puntero al nuevo instructor
					cantidad++;
					return true;
    }

Instructor* ColeccionInstructores::buscarInstructor(string cedula) {
	for (int i = 0; i < cantidad; i++) {
		if (instructores[i]->getCedula() == cedula) {
			return instructores[i];
		}
	}
	return nullptr;
}
bool ColeccionInstructores::eliminarInstructor(string cedula) {
	for (int i = 0; i < cantidad; i++) {
		if (instructores[i]->getCedula() == cedula) {
			delete instructores[i];
			for (int j = i; j < cantidad - 1; j++) {
				instructores[j] = instructores[j + 1];
			}
			instructores[cantidad - 1] = nullptr;
			cantidad--;
			return true;
		}
	}
	return false;
}
string ColeccionInstructores::listarInstructores() {
	string resultado = "";
	for (int i = 0; i < cantidad; i++) {
		resultado += instructores[i]->toString() + "\n";
	}
	return resultado;
}
int ColeccionInstructores::getCantidad() {
	return cantidad;
}

Instructor* ColeccionInstructores::getPorIndice(int i) {    // <-- NUEVO
	return (i >= 0 && i < cantidad) ? instructores[i] : nullptr;
}
int ColeccionInstructores::getTam() {
	return tam;
}

string ColeccionInstructores::toString() {
	string resultado = "";
	for (int i = 0; i < cantidad; i++) {
		resultado += instructores[i]->toString() + "\n";
	}
	return resultado;
}

