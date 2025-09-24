#include "Instructor.h"
#include "Sucursal.h"



Instructor::Instructor()
{
	cedula = "";
	nombre = "";
	telefono = 0;
	fechaNacimiento = "";
	correo = "";
	for (int i = 0; i < 8; i++) {
		especialidades[i] = "";
	}
	
}

Instructor::Instructor(string cedula, string nombre, int telefono, string fechaNacimiento, string correo, string especialidades[], int cantidadEspecialidades, int tamClientes)
{
	this->cedula = cedula;
	this->nombre = nombre;
	this->telefono = telefono;
	this->fechaNacimiento = fechaNacimiento;
	this->correo = correo;
	for (int i = 0; i < 8; i++) {
		if (i < cantidadEspecialidades) {
			this->especialidades[i] = especialidades[i];
		}
		else {
			this->especialidades[i] = "";
		}
	}
	clientes = new ColeccionClientes(tamClientes);
	mediciones = new ColeccionMediciones(20);
	rutinas = new ColeccionRutina(20);
	ejercicios = new ColeccionEjercicios(20);
	clasesAsociadas = new ColeccionClaseGrupal();
}

string Instructor::getCedula()
{
	return cedula;
}

void Instructor::setCedula(string cedula)
{
	this->cedula = cedula;
}

string Instructor::getNombre()
{
	return nombre;
}
void Instructor::setNombre(string nombre)
{
	this->nombre = nombre;
}
/*int Instructor::getTelefono()
{
	return telefono;
}*/

void Instructor::setTelefono(int telefono)
{
	this->telefono = telefono;
}
string Instructor::getFechaNacimiento()
{
	return fechaNacimiento;
}
void Instructor::setFechaNacimiento(string fechaNacimiento)
{
	this->fechaNacimiento = fechaNacimiento;
}
string Instructor::getCorreo()
{
	return correo;
}
void Instructor::setCorreo(string correo)
{
	this->correo = correo;
}
bool Instructor::tieneEspecialidad( string n) {
	for (int i = 0; i < 8; ++i) {
		if (especialidades[i] == n) return true;
    	}
	return false;
}
string* Instructor::getEspecialidades()
{
	return especialidades;
}

string Instructor::getEspecialidad()
{
	string resultado = "";
	for (int i = 0; i < 8; i++) {
		if (especialidades[i] != "") {
			resultado += especialidades[i];
			if (i < 7 && especialidades[i + 1] != "") {
				resultado += ", ";
			}
		}
	}
	return resultado;
}
void Instructor::setEspecialidad(string especialidad){
	for (int i = 0; i < 8; i++) {
		if (this->especialidades[i] == "") {
			this->especialidades[i] = especialidad;
			break;
		}
	}
}
int Instructor::getCantEspecialidades(){
	int count = 0;
	for (int i = 0; i < 8; i++) {
		if (especialidades[i] != "") {
			count++;
		}
	}
	return count;
}
ColeccionClientes* Instructor::getClientes()
{
	return clientes;
}








void Instructor::setClientes(ColeccionClientes* clientes)
{
	this->clientes = clientes;
}



ColeccionMediciones* Instructor::getMediciones()
{
	return mediciones;
}
void Instructor::setMediciones(ColeccionMediciones* mediciones)
{
	this->mediciones = mediciones;
}

ColeccionRutina* Instructor::getRutinas()
{
	return rutinas;
}

void Instructor::setRutinas(ColeccionRutina* rutinas)
{
	this->rutinas = rutinas;
}
ColeccionEjercicios* Instructor::getEjercicios()
{
	return ejercicios;
}
void Instructor::setEjercicios(ColeccionEjercicios* ejercicios)
{
	this->ejercicios = ejercicios;
}
ColeccionClaseGrupal* Instructor::getClasesAsociadas(){
	return clasesAsociadas;
}
// muestra las especialidades, si son 8 las 8 y si son menos las que tenga, hazlo bien y ordenando en pantalla, muestrame el nombre de esas especialidades

string Instructor::toString()
{
	stringstream ss;
	ss << "Cedula: " << cedula << "\n";
	ss << "Nombre: " << nombre << "\n";
	ss << "Telefono: " << telefono << "\n";
	ss << "Fecha de Nacimiento: " << fechaNacimiento << "\n";
	ss << "Correo: " << correo << "\n";
	ss << "Especialidades: " << getEspecialidad() << "\n";
	ss << "Cantidad de Clientes a Cargo: " << clientes->getCantidad() << "\n";
	return ss.str();
}





Instructor::~Instructor()
{
	delete clientes;
	delete mediciones;
	delete rutinas;
	delete ejercicios;
	delete clasesAsociadas;
}



