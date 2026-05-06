#pragma once
#include <iostream>
#include <string>
#include "ConexionBD.h"
#include "Persona.h"
#include <mysql.h>
using namespace std;
class Estudiante : Persona {
	// atributos
private:
	string codigo;
	int id_estudiante = 0;
	// constructores
public:
	Estudiante() {}
	Estudiante(string nom, string ape, string dir, string fn, int tel, int id_ts, string cod, int id_e)
		: Persona(nom, ape, dir,tel, fn, id_ts) {
		codigo = cod;
		id_estudiante = id_e;
	}
	// metodos gettere y setter
	string getCodigo() {
		return codigo;
	}
	void setCodigo(string cod) {
		codigo = cod;
	}
	int getIdEstudiante() {
		return id_estudiante;
	}
	void setIdEstudiante(int id_e) {
		id_estudiante = id_e;
	}
	string getNombres() {
		return nombres;
	}
	void setNombres(string nom) {
		nombres = nom;
	}
	string getApellidos() {
		return apellidos;
	}
	void setApellidos(string ape) {
		apellidos = ape;
	}
	string getDireccion() {
		return direccion;
	}
	void setDireccion(string dir) {
		direccion = dir;
	}
	int getTelefono() {
		return telefono;
	}
	void setTelefono(int tel) {
		telefono = tel;
	}
	int getIdTipoSangre() {
		return id_tipo_sangre;
	}
	void setIdTipoSangre(int id_ts) {
		id_tipo_sangre = id_ts;
	}
	void setFechaNacimiento(string fn) {
		fecha_nacimiento = fn;
	}
	string getFechaNacimiento() {
		return fecha_nacimiento;
	}
	// metodos CRUD
	// metodos
	void crear() {
		int q_estado = 0;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConector()) {
			string t = to_string(telefono);
			string id_ts = to_string(id_tipo_sangre);
			string consulta = "INSERT INTO db_escuela.estudiantes(codigo, nombres, apellidos, direccion, telefono, fecha_nacimiento, id_tipo_sangre) VALUES ('" + codigo + "', '" + nombres + "', '" + apellidos + "', '" + direccion + "', " + t + ", '" + fecha_nacimiento + "', " + id_ts + ");";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConector(), c);
			if (!q_estado) {
				cout << "Ingreso de datos Exitoso..." << endl;
			}
		}
		else {
			cout << " xxxx Consulta Falllida xxxx " << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		ConexionBD conexion;
		conexion.abrir_conexion();
		MYSQL* conn = conexion.getConector();
		if (conn) {
			cout << "----------- Datos del Estudiante ------------------" << endl;
			string query = "select e.id_estudiante as id, e.codigo, e.nombres, e.apellidos, e.direccion, e.telefono,e.fecha_nacimiento, ts.sangre from estudiantes as e inner join tipo_sangre as ts on e.id_tipo_sangre = ts.id_tipo_sangre;";
			
			const char* q = query.c_str();
			mysql_query(conn, q);
			MYSQL_RES* res = mysql_store_result(conn);
			while (MYSQL_ROW row = mysql_fetch_row(res)) {
				
				cout << "ID: " << row[0] << " Codigo: " << row[1] << "," << " Nombres: " << row[2] << "," << " Apellidos: " << row[3] << "," << " Direccion: " << row[4] << "," << " Telefono: " << row[5] << "," << " Nacimiento: " << row[6] << "," << " Sangre: " << row[7] << endl;
				cout << "-----------------------------" << endl;
			}
				

			mysql_free_result(res);
		}
		else {
			cout << "Error al conectar a la base de datos" << endl;
		}
		conexion.cerrar_conexion();
	}
	void actualizar() {
		int q_estado = 0;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConector()) {

			string t = to_string(telefono);
			string id_ts = to_string(id_tipo_sangre);
			string id_e = to_string(id_estudiante);
			string consulta = "update estudiantes set codigo = '" + codigo + "',nombres = '" + nombres + "',apellidos='" + apellidos + "',direccion='" + direccion + "',telefono=" + t + ",fecha_nacimiento = '" + fecha_nacimiento + "',id_tipo_sangre=" + id_ts + " where id_estudiante = " + id_e + "";			
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConector(), c);
			if (!q_estado) {
				cout << "Modificacion de Datos Exitoso...." << endl;
			}
			else {
				cout << "xxxxx Consulta  Fallida xxxxx" << endl;
			}

		}
		else {
			cout << " xxxx Conexion Falllida xxxx " << endl;
		}
		cn.cerrar_conexion();
	}
	void borrar() {
		int q_estado = 0;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConector()) {

			string t = to_string(telefono);
			string id_ts = to_string(id_tipo_sangre);
			string id_e = to_string(id_estudiante);
			string consulta = "delete from estudiantes  where id_estudiante = " + id_e + "";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConector(), c);
			if (!q_estado) {
				cout << "Eliminacion de Datos Exitoso...." << endl;
			}
			else {
				cout << "xxxxx Consulta  Fallida xxxxx" << endl;
			}

		}
		else {
			cout << " xxxx Conexion Falllida xxxx " << endl;
		}
		cn.cerrar_conexion();
	}
};
