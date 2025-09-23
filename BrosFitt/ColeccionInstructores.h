#pragma once
#include <string>
#include "Instructor.h"


class ColeccionInstructores {
private:
	int tam;
	int cantidad;
	Instructor** instructores;

public:
	ColeccionInstructores(int);
	~ColeccionInstructores();

	void agregarInstructor(Instructor*);
	Instructor* buscarInstructor(std::string);
	bool eliminarInstructor(std::string);
	std::string listarInstructores();
	bool insertarAlFinal(Instructor*);
	int getCantidad();
	int getTam();
	std::string toString();
	Instructor* getPorIndice(int i);
};
