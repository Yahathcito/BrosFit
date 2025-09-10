#include"ColeccionClientes.h"

ColeccionClientes::ColeccionClientes(int tam) {
	this->tam = tam;
	cantidad = 0;
	clientes = new Cliente * [tam];
	for (int i = 0; i < tam; i++) {
		clientes[i] = nullptr;
	}
}
ColeccionClientes::~ColeccionClientes() {
	for (int i = 0; i < cantidad; i++) {
		delete clientes[i];
	}
	delete[] clientes;
}
void ColeccionClientes::agregarCliente(Cliente* cliente) {
	if (cantidad < tam) {
		clientes[cantidad] = cliente;
		cantidad++;
	}
	else {
		cout << "No se puede agregar más clientes, capacidad máxima alcanzada." << endl;
	}
}
Cliente* ColeccionClientes::buscarCliente(string cedula) {
	for (int i = 0; i < cantidad; i++) {
		if (clientes[i]->getCedula() == cedula) {
			return clientes[i];
		}
	}
	return nullptr;
}
bool ColeccionClientes::eliminarCliente(string cedula) {
	for (int i = 0; i < cantidad; i++) {
		if (clientes[i]->getCedula() == cedula) {
			delete clientes[i];
			for (int j = i; j < cantidad - 1; j++) {
				clientes[j] = clientes[j + 1];
			}
			clientes[cantidad - 1] = nullptr;
			cantidad--;
			return true;
		}
	}
	return false;
}
string ColeccionClientes::listarClientes() {
	string resultado = "";
	for (int i = 0; i < cantidad; i++) {
		resultado += clientes[i]->toString() + "\n";
	}
	return resultado;
}
bool ColeccionClientes::insertarAlFinal(Cliente* cliente)
{
	// debes verificar si ya esta ingresado el cliente	
	// verificar que no tenga los mismo datos de otro cliente
	if (buscarCliente(cliente->getCedula()) != nullptr) {
		cout << "El cliente ya está ingresado." << endl;
		return false;
	}
	if (cantidad == tam) {
		// Redimensionar el arreglo
		int nuevoTam = tam * 2;
		Cliente** nuevoArreglo = new Cliente * [nuevoTam];
		for (int i = 0; i < cantidad; i++) {
			nuevoArreglo[i] = clientes[i];
		}
		for (int i = cantidad; i < nuevoTam; i++) {
			nuevoArreglo[i] = nullptr;
		}
		delete[] clientes;
		clientes = nuevoArreglo;
		tam = nuevoTam;
	}
	clientes[cantidad] = nullptr; // Aquí debería ir el puntero al nuevo cliente
	cantidad++;
	return true;
}


int ColeccionClientes::getCantidad() {
	return cantidad;
}
int ColeccionClientes::getTam() {
	return tam;
}
