#include <iostream>
#include "Estudiante.h"
using namespace std;
int main() {
	string codigo, nombres, apellidos, direccion, fecha_nacimiento;
	int telefono = 0, id_tipo_sangre = 0, id_estudiante = 0;

	cout << "Ingrese Codigo:";
	cin >> codigo;
	cin.ignore();

	cout << "Ingres Nombres:";
	getline(cin, nombres);
	cout << "Ingres Apellidos:";
	getline(cin, apellidos);
	cout << "Ingres Direccion:";
	getline(cin, direccion);
	cout << "Ingrese Telefono:";
	cin >> telefono;
	cin.ignore();

	cout << "Ingres Fecha Nacimiento:";
	getline(cin, fecha_nacimiento);

	cout << "Ingrese Tipo Sangre:";
	cin >> id_tipo_sangre;
	cin.ignore();

	Estudiante e = Estudiante(nombres, apellidos, direccion, fecha_nacimiento, telefono, id_tipo_sangre, codigo, id_estudiante);
	e.crear();
	e.leer();

	// Actualizacion
	cout << "\nIngrese el ID a modificar:";
	cin >> id_estudiante;
	cin.ignore(); 

	cout << "Ingrese Codigo:";
	cin >> codigo;
	cin.ignore(); 

	cout << "Ingresa Nombres:";
	getline(cin, nombres);

	cout << "Ingres Apellidos:";
	getline(cin, apellidos);

	cout << "Ingres Direccion:";
	getline(cin, direccion);

	cout << "Ingrese Telefono:";
	cin >> telefono;
	cin.ignore(); 
	cout << "Ingres Fecha Nacimiento:";
	getline(cin, fecha_nacimiento);

	cout << "Ingrese Tipo Sangre:";
	cin >> id_tipo_sangre;
	cin.ignore(); 
	e.setIdEstudiante(id_estudiante);
	e.setNombres(nombres);
	e.setApellidos(apellidos);
	e.setDireccion(direccion);
	e.setTelefono(telefono);
	e.setCodigo(codigo);
	e.setFechaNacimiento(fecha_nacimiento);
	e.setIdTipoSangre(id_tipo_sangre);
	e.actualizar();
	e.leer();
	cout << "Ingrese el ID a Eliminar:";
	cin >> id_estudiante;
	e.setIdEstudiante(id_estudiante);
	e.borrar();
	e.leer();


}