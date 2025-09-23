#include "ContenedorClasesCliente.h"
#include "ClaseGrupal.h"
#include <sstream>
ContenedorClasesCliente::ContenedorClasesCliente() {
    tam = 3;    
    can = 0;    
    clasesCliente = new ClaseGrupal * [tam];
    for (int i = 0; i < tam; i++) {
        clasesCliente[i] = nullptr;
    }
}


ContenedorClasesCliente::~ContenedorClasesCliente() {
    delete[] clasesCliente; 
}



bool ContenedorClasesCliente::agregarClase(ClaseGrupal* clase) {

    for (int i = 0; i < can; i++) {
        if (clasesCliente[i]->getCodigo() == clase->getCodigo())
            return false;
    }


    if (can < tam) {
        clasesCliente[can++] = clase;
        return true;
    }

    return false; 
}

string ContenedorClasesCliente::toString() {
    stringstream ss;
    ss << "--- Clases del Cliente---\n";
    if (can == 0) {
        ss << "No tiene clases asignadas.\n";
    }
    else {
        for (int i = 0; i < can; i++) {
            if (clasesCliente[i])
                ss << clasesCliente[i]->toString() << "\n";
        }
    }
    return ss.str();
}
