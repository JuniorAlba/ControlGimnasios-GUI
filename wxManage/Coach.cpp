/**
*@file Coach.cpp
*@brief Implementacion de los metodos de la clase Coach.
**/
#include "Coach.h"
#include <cstring>
#include <fstream>
#include "Utils.h"


/// Implementacion del constructor de la clase coach
coach::coach(std::string nom, std::string ape, std::string mail, std::string sex,
			 std::string tel, std::string dir, std::string loc, std::string dni,
			 int dia, int mes, int anio, std::string _cbu, std::string _alias):
	persona(nom, ape, mail, sex, tel, dir, loc, dni, dia, mes, anio){
	cbu = _cbu;
	alias = _alias;
}

/// Implementacion de los metodos para obtener los atributos de coach
std::string coach::ver_cbu() const{
	return cbu;
}
std::string coach::ver_alias() const{
	return alias;
}


///Implementacion de los metodos para modificar los atributos de coach
void coach::modificar_cbu(std::string cbu){
	this->cbu = cbu;
}
void coach::modificar_alias(std::string alias){
	this->alias = alias;
}

/// Implementacion del metodo para guardar un coach en un archivo binario
void coach::guardar_en_binario(std::ofstream &archivo){
	registroCoach registro;
	strcpy(registro.nombre,nombre.c_str());
	strcpy(registro.apellido,apellido.c_str());
	strcpy(registro.email,email.c_str());
	strcpy(registro.telefono,telefono.c_str());
	strcpy(registro.direccion,direccion.c_str());
	strcpy(registro.localidad,localidad.c_str());
	
	strcpy(registro.sexo,sexo.c_str());
	
	strcpy(registro.dni,dni.c_str());
	strcpy(registro.cbu,cbu.c_str());
	strcpy(registro.alias,alias.c_str());
	registro.fecha_nac = fecha_nacimiento;
	archivo.write(reinterpret_cast<char*>(&registro),sizeof(registro));
}

/// Implementacion del metodo para leer un coach en un archivo binario
void coach::leer_en_binario(std::ifstream &archivo){
	registroCoach registro;
	archivo.read(reinterpret_cast<char*>(&registro), sizeof(registro));
	nombre = registro.nombre;
	apellido = registro.apellido;
	email = registro.email;
	telefono = registro.telefono;
	direccion = registro.direccion;
	localidad = registro.localidad;
	
	sexo = registro.sexo;
	
	dni = registro.dni;
	cbu = registro.cbu;
	alias = registro.alias;
	fecha_nacimiento = registro.fecha_nac;
}

/// Implementacion del metodo que valida los atributos del coach
std::string coach::validar_datos_ch() const{
	std::string errores=validar_datos();
	if(contieneLetra(cbu)) errores+="El CBU no debe contener letras \n";
	if(cbu.size()>22){
		errores+="El cbu es demasiado largo \n";
	}
	if(alias.size()>20){
		errores+="El alias es demasiado largo \n";
	}
	if(alias.size()<6){
		errores+="El alias es demasiado corto \n";
	}
	return errores;
}



/**
* Devuelve true si la combinacion "apellido, nombre" de el primer coach esta
* antes segun el orden alfabetico que el apellido y nombre de el segundo coach.
* Se usa como argumento para la funcion sort para ordenar toda la lista.
**/
bool CriterioCoachNombreApellido(coach c1, coach c2){
	std::string txt1 = c1.ver_apellido() + " " + c1.ver_nombre();
	std::string txt2 = c2.ver_apellido() + " " + c2.ver_nombre();
	PasarMiniscula(txt1);
	PasarMiniscula(txt2);
	return txt1 < txt2;
}	
	
	
/**
* Devuelve true si la localidad de el primer coach esta antes segun el 
* orden alfabetico que la localidad de el segundo coach.
* Se usa como argumento para la funcion sort para ordenar toda la lista.
**/
bool CriterioCoachLocalidad(coach c1, coach c2){
	std::string txt1 = c1.ver_loc();
	std::string txt2 = c2.ver_loc();
	PasarMiniscula(txt1);
	PasarMiniscula(txt2);
	return txt1 < txt2;
}
	
	
/**
* Devuelve true si la edad de el primer coach es mas pequena que la edad de
* el segundo coach.
* Se usa como argumento para la funcion sort para ordenar toda la lista.
**/
bool CriterioCoachEdad(coach c1, coach c2){
	return c1.ver_edad() < c2.ver_edad();
}

/**
* Devuelve true si el email de el primer coach esta antes segun el 
* orden alfabetico que el email de el segundo coach.
* Se usa como argumento para la funcion sort para ordenar toda la lista.
**/
bool CriterioCoachEmail(coach c1, coach c2){
	std::string txt1 = c1.ver_email();
	std::string txt2 = c2.ver_email();
	PasarMiniscula(txt1);
	PasarMiniscula(txt2);
	return txt1 < txt2;
}
	
	
/**
* Devuelve true si el telefono de el primer coach esta antes segun el 
* orden alfabetico que el telefono de el segundo coach.
* Se usa como argumento para la funcion sort para ordenar toda la lista.
**/
bool CriterioCoachTelefono(coach c1, coach c2){
	return c1.ver_tel()<c2.ver_tel();
}
	
/**
* Devuelve true si el DNI de el primer coach esta antes segun el 
* orden alfabetico que el DNI de el segundo coach.
* Se usa como argumento para la funcion sort para ordenar toda la lista.
**/
bool CriterioCoachDNI(coach c1, coach c2){
	return c1.ver_DNI()<c2.ver_DNI();
}
