// Plan (pseudoc�digo):
// - Detectar duplicidad de la firma agregarMedicion(Medicion*) con distinto tipo de retorno.
// - Conservar la versi�n existente m�s probable en el c�digo (void) para no romper implementaciones .cpp.
// - Eliminar la segunda declaraci�n (bool) que causa el error E0311.
// - No modificar otras firmas.

// C�digo corregido:
#pragma once
#include "Medicion.h"

class ColeccionMediciones
{
private:
	int tam;
	int cantidad;
	Medicion** mediciones;

public:
	ColeccionMediciones(int);
	~ColeccionMediciones();

	bool agregarMedicion(Medicion*);
	
	Medicion* getPorIndice(int);

	
	
	Medicion* buscarMedicion(string, string);
	bool eliminarMedicion(string, string);
	string listarMediciones();
	int getCantidad();
	int getTam();
	
};
