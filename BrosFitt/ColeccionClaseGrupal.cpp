#include "ColeccionClaseGrupal.h"
#include <sstream>


ColeccionClaseGrupal::ColeccionClaseGrupal() {
	tam = 8;
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

bool ColeccionClaseGrupal::agregarClase(ClaseGrupal* clase) {
	for(int i=0;i<cantidad;i++){
		if(clases[i]->getCodigo()==clase->getCodigo()) 
		    return false; 
	}
	if (cantidad < tam) {
		clases[cantidad++] = clase;
		int indice = clase->getCodigo()-1; 
		ocupadas[indice] == true; 
	}
	return false; 
}
ClaseGrupal* ColeccionClaseGrupal::buscarClase(int codigo) {
	for (int i = 0; i < cantidad; i++) {
		if (clases[i]->getCodigo() == codigo) {
			return clases[i];
		}
	}
	return nullptr;
}
bool ColeccionClaseGrupal::eliminarClase(int codigo) {
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
void ColeccionClaseGrupal::mostrarDisponibles(){
    cout << "\nClases disponibles:\n";
    for (int i = 0; i < tam; i++) {
        if (!ocupadas[i]) {
            cout << i + 1 << ". " << nombresPredefinidos[i] << endl;
        }
    }
}
string ColeccionClaseGrupal::toString() {
	stringstream ss; 
	for(int i=0;i<cantidad;i++){
		ss << clases[i]->toString();
	}
	return ss.str();
}
int ColeccionClaseGrupal::getCantidad() {
	return cantidad;
}
int ColeccionClaseGrupal::getTam() {
	return tam;
}
