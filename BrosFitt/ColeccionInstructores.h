#pragma once
#include "Instructor.h"	

class ColeccionInstructores
{
private:
	int tam;
	int cantidad;
	Instructor** instructores;
public:
	ColeccionInstructores(int);
	~ColeccionInstructores();
	void agregarInstructor(Instructor*);
	Instructor* buscarInstructor(string);
	bool eliminarInstructor(string);
	string listarInstructores();
	int getCantidad();
	int getTam();

};

