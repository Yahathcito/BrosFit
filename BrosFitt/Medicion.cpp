#include "Medicion.h"

Medicion::Medicion()
{
	nombreCliente = "";
	idCliente = "";
	fechaMedicion = "";
	nombreInstructor = "";
	peso = 0.0;
	estatura = 0.0;
	porcentajeGrasa = 0.0;
	porcentajeMusculo = 0.0;
	edadMetabolica = 0;
	porcentajeGrasaVisceral = 0.0;
	medidaCintura = 0.0;
	medidaCadera = 0.0;
	medidaPecho = 0.0;
	medidaMuslo = 0.0;
	imc = 0.0;
}
Medicion::Medicion(string nombreCliente, string idCliente, string fechaMedicion, string nombreInstructor, float peso, float estatura, float porcentajeGrasa, float porcentajeMusculo, int edadMetabolica, float porcentajeGrasaVisceral, float medidaCintura, float medidaCadera, float medidaPecho, float medidaMuslo)
{
	this->nombreCliente = nombreCliente;
	this->idCliente = idCliente;
	this->fechaMedicion = fechaMedicion;
	this->nombreInstructor = nombreInstructor;
	this->peso = peso;
	this->estatura = estatura;
	this->porcentajeGrasa = porcentajeGrasa;
	this->porcentajeMusculo = porcentajeMusculo;
	this->edadMetabolica = edadMetabolica;
	this->porcentajeGrasaVisceral = porcentajeGrasaVisceral;
	this->medidaCintura = medidaCintura;
	this->medidaCadera = medidaCadera;
	this->medidaPecho = medidaPecho;
	this->medidaMuslo = medidaMuslo;
	calcularIMC();
}
string Medicion::getNombreCliente()
{
	return nombreCliente;
}
void Medicion::setNombreCliente(string nombreCliente)
{
	this->nombreCliente = nombreCliente;
}
string Medicion::getIdCliente()
{
	return idCliente;
}
void Medicion::setIdCliente(string idCliente)
{
	this->idCliente = idCliente;
}
string Medicion::getFechaMedicion()
{
	return fechaMedicion;
}
void Medicion::setFechaMedicion(string fechaMedicion)
{
	this->fechaMedicion = fechaMedicion;
}
string Medicion::getNombreInstructor()
{
	return nombreInstructor;
}
void Medicion::setNombreInstructor(string nombreInstructor)
{
	this->nombreInstructor = nombreInstructor;
}
float Medicion::getPeso()
{
	return peso;
}

void Medicion::setPeso(float peso)
{
	this->peso = peso;
	calcularIMC();
}
float Medicion::getEstatura()
{
	return estatura;
}
void Medicion::setEstatura(float estatura)
{
	this->estatura = estatura;
	calcularIMC();
}
float Medicion::getPorcentajeGrasa()
{
	return porcentajeGrasa;
}
void Medicion::setPorcentajeGrasa(float porcentajeGrasa)
{
	this->porcentajeGrasa = porcentajeGrasa;
}
float Medicion::getPorcentajeMusculo()
{
	return porcentajeMusculo;
}
void Medicion::setPorcentajeMusculo(float porcentajeMusculo)
{
	this->porcentajeMusculo = porcentajeMusculo;
}
int Medicion::getEdadMetabolica()
{
	return edadMetabolica;
}
void Medicion::setEdadMetabolica(int edadMetabolica)
{
	this->edadMetabolica = edadMetabolica;
}
float Medicion::getPorcentajeGrasaVisceral()
{
	return porcentajeGrasaVisceral;
}
void Medicion::setPorcentajeGrasaVisceral(float porcentajeGrasaVisceral)
{
	this->porcentajeGrasaVisceral = porcentajeGrasaVisceral;
}
float Medicion::getMedidaCintura()
{
	return medidaCintura;
}
void Medicion::setMedidaCintura(float medidaCintura)
{
	this->medidaCintura = medidaCintura;
}
float Medicion::getMedidaCadera()
{
	return medidaCadera;
}
void Medicion::setMedidaCadera(float medidaCadera)
{
	this->medidaCadera = medidaCadera;
}
float Medicion::getMedidaPecho()
{
	return medidaPecho;
}
void Medicion::setMedidaPecho(float medidaPecho)
{
	this->medidaPecho = medidaPecho;
}
float Medicion::getMedidaMuslo()
{
	return medidaMuslo;
}
void Medicion::setMedidaMuslo(float medidaMuslo)
{
	this->medidaMuslo = medidaMuslo;
}
float Medicion::getIMC()
{
	return imc;
}

string Medicion::toString()
{
	stringstream s;
	s << "Nombre del Cliente: " << nombreCliente << endl;
	s << "ID del Cliente: " << idCliente << endl;
	s << "Fecha de Medicion: " << fechaMedicion << endl;
	s << "Nombre del Instructor: " << nombreInstructor << endl;
	s << "Peso: " << peso << " kg" << endl;
	s << "Estatura: " << estatura << " m" << endl;
	s << "Porcentaje de Grasa: " << porcentajeGrasa << " %" << endl;
	s << "Porcentaje de Musculo: " << porcentajeMusculo << " %" << endl;
	s << "Edad Metabolica: " << edadMetabolica << " años" << endl;
	s << "Porcentaje de Grasa Visceral: " << porcentajeGrasaVisceral << " %" << endl;
	s << "Medida de Cintura: " << medidaCintura << " cm" << endl;
	s << "Medida de Cadera: " << medidaCadera << " cm" << endl;
	s << "Medida de Pecho: " << medidaPecho << " cm" << endl;
	s << "Medida de Muslo: " << medidaMuslo << " cm" << endl;
	s << "IMC: " << imc << endl;
	return s.str();
}
Medicion::~Medicion()
{
}
