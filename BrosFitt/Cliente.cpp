#include "Cliente.h"

//Constructores y desctructor 
Cliente::Cliente() {
	cedulaIdentidad = "";
	nombre = "";
	correoElectronico = "";
	fechaNacimiento = "";
	fechaInscripcion = "";
	numeroCelular = 0;
	sexo = ' ';



}
Cliente::Cliente(string cedula, string nombre, string correo, string fechaInscripcion, string fechaNacimiento, int celular, char sexo) {
	this->cedulaIdentidad = cedula;
	this->nombre = nombre;
	this->correoElectronico = correo;
	this->fechaNacimiento = fechaNacimiento;
	this->fechaInscripcion = fechaInscripcion;
	this->numeroCelular = celular;
	this->sexo = sexo;


}

Cliente::~Cliente()
{
}

//setters y getters 
string Cliente::getCedula() {
	return cedulaIdentidad;
}
void Cliente::setCedula(string cedula) {
	cedulaIdentidad = cedula;
}

string Cliente::getNombre() {
	return nombre;
}
void Cliente::setNombre(string nombre) {
	this->nombre = nombre;
}

string Cliente::getCorreo() {
	return correoElectronico;
}
void Cliente::setCorreo(string correo)
{
	correoElectronico = correo;
}

string Cliente::getFechaNacimiento() {
	return fechaNacimiento;
}
void Cliente::setFechaNacimiento(string fecha) {
	fechaNacimiento = fecha;
}

string Cliente::getFechaInscripcion() {
	return fechaInscripcion;
}
void Cliente::setFechaInscripcion(string fecha) {
	fechaInscripcion = fecha;
}

int Cliente::getCelular() {
	return numeroCelular;
}

void Cliente::setCelular(int celular) {
	numeroCelular = celular;
}

char Cliente::getSexo() {
	return sexo;
}

void Cliente::setSexo(char sexo) {
	this->sexo = sexo;
}
string Cliente::toString() {
	stringstream ss;
	ss << "Cliente: " << nombre << " (" << cedulaIdentidad << ")\n";
	ss << "Correo: " << correoElectronico << "\n";
	ss << "Celular: " << numeroCelular << "\n";
	ss << "Sexo: " << sexo << "\n";
	ss << "Fecha Nacimiento: " << fechaNacimiento << "\n";
	ss << "Fecha Inscripcion: " << fechaInscripcion << "\n";
	return ss.str();
}



//metodos de las clases funcionales 









