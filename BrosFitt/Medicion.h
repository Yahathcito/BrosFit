#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Medicion
{
private:
	string nombreCliente;
	string idCliente;
	string fechaMedicion;
	string nombreInstructor;
	float peso;
	float estatura;
	float porcentajeGrasa;
	float porcentajeMusculo;
	int edadMetabolica;
	float porcentajeGrasaVisceral;
	float medidaCintura;
	float medidaCadera;
	float medidaPecho;
	float medidaMuslo;
	float imc;
	void calcularIMC() {
		if (estatura > 0) {
			imc = peso / (estatura * estatura);
		}
		else {
			imc = 0;
		}
	}
public:
	Medicion();
	Medicion( string, string, string, float, float, float, float, int, float, float, float, float, float);
	string getNombreCliente();
	void setNombreCliente(string);
	string getIdCliente();
	void setIdCliente(string);
	string getFechaMedicion();
	void setFechaMedicion(string);
	string getNombreInstructor();
	void setNombreInstructor(string);
	float getPeso();
	void setPeso(float);
	float getEstatura();
	void setEstatura(float);
	float getPorcentajeGrasa();
	void setPorcentajeGrasa(float);
	float getPorcentajeMusculo();
	void setPorcentajeMusculo(float);
	int getEdadMetabolica();
	void setEdadMetabolica(int);
	float getPorcentajeGrasaVisceral();
	void setPorcentajeGrasaVisceral(float);
	float getMedidaCintura();
	void setMedidaCintura(float);
	float getMedidaCadera();
	void setMedidaCadera(float);
	float getMedidaPecho();
	void setMedidaPecho(float);
	float getMedidaMuslo();
	void setMedidaMuslo(float);
	float getIMC();
	string toString();
	~Medicion();

};
