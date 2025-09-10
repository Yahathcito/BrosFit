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
int ColeccionClientes::getCantidad() {
	return cantidad;
}
int ColeccionClientes::getTam() {
	return tam;
}
