#pragma once
#include <iostream>
#include <string>
#include "ColeccionSucursal.h"
using namespace std;

class Interfaz{
private:

	static ColeccionSucursal* coleccionSucursales;
	static ColeccionClientes* coleccionClientes;
	static ColeccionInstructores* coleccionInstructores;
	static ColeccionMediciones* coleccionMediciones;
	static ColeccionEjercicios* coleccionEjercicios;
	static ColeccionRutina* coleccionRutinas;


public: 
	static void menu();
	static void subMenuIngresoDatosGenerales();
	static void subMenuInformeDeClientes();
	static void subMenuInformeDeInstructores();
	static void subMenuHistorialDeMediciones();
	static void subMenuReporteIMC();
	static void subMenuRutinas();
	static void subMenuMatriculaClasesGrupales();

};

