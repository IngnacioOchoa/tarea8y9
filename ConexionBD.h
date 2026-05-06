#pragma once
#include <mysql.h>
#include <iostream>
using namespace std;
class ConexionBD{
	// privado, publico y protegido
private: MYSQL* conector; //controla el estado de la conexion a la BD
public : 
	void abrir_conexion() {
		conector = mysql_init(0);
		conector = mysql_real_connect(conector, "localhost", "root", "40684566", "db_escuela", 3306, NULL, 0);

	}
	MYSQL* getConector() {
		return conector;
	}
	void cerrar_conexion() {
		mysql_close(conector);
	}

};

