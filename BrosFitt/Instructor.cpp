#include "Instructor.h"
#include "Sucursal.h"


Instructor::Instructor()
{
	cedula = "";
	nombre = "";
	telefono = 0;
	fechaNacimiento = "";
	correo = "";


}
Instructor::Instructor(string cedula, string nombre, int telefono, string fechaNacimiento, string correo, string esp[], int tamClientes,int cantEspecialidades)
{
	this->cedula = cedula;
	this->nombre = nombre;
	this->telefono = telefono;
	this->fechaNacimiento = fechaNacimiento;
	this->correo = correo;
	for(int i = 0; i < cantEspecialidades; i++){
		this->especialidades[i] = esp[i];
	}
	clientes = new ColeccionClientes(tamClientes);
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
int Instructor::getTelefono()
{
	return telefono;
}

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

string Instructor::getEspecialidad(){
	string especialidades = "";
	for (int i = 0; i < 8; i++) {
		if (this->especialidades[i] != "") {
			especialidades += this->especialidades[i] + ", ";
		}
	}
	if (especialidades.length() > 2) {
		especialidades = especialidades.substr(0, especialidades.length() - 2); // Quitar la ultima coma y espacio
	}
	return especialidades;
}
void Instructor::setEspecialidad(string especialidad)
{
	for (int i = 0; i < 8; i++) {
		if (this->especialidades[i] == "") {
			this->especialidades[i] = especialidad;
			break;
		}
	}
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

string Instructor::toString()
{
	stringstream s;
	s << "Cedula: " << cedula << endl;
	s << "Nombre: " << nombre << endl;
	s << "Telefono: " << telefono << endl;
	s << "Fecha de Nacimiento: " << fechaNacimiento << endl;
	s << "Correo: " << correo << endl;
	return s.str();
}
Instructor::~Instructor()
{
	delete clientes;
	delete mediciones;
	delete rutinas;
	delete ejercicios;

}



