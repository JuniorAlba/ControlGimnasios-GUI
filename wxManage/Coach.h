/**
* @file Coach.h
* @brief Implementaciones de todo lo necesario para trabajar con la clase 
* clase coach.
*
* 
* Este archivo define la clase cliente y la clase coach, las funciones
* auxiliares para compararlas y el struct de registro para poder guardar
* y leer en archivo binarios
**/
#ifndef COACH_H
#define COACH_H

#include "Persona.h"
#include <string>

/**
* @brief Estructura auxiliar para usar con archivos binarios en la clase coach
*
* En los binarios no se debe guardar ni escribir objetos string porque al ser
* dinamicos contienen punteros y lo que en realidad se guardaria seria el
* puntero y no la informacion a la que apunta. Esta estructura sirve de 
* intermediaria para guardar y escribir los datos de una persona.
**/

struct registroCoach{
	char nombre[100];
	char apellido[100];
	char email[260];
	char telefono[25];
	char direccion[100];
	char localidad[100];
	char sexo[2];
	char dni[20];
	char cbu[22];
	char alias[20];
	fecha fecha_nac;
};

/**
* @brief Clase que representara a un coach, clase que hereda de persona
*
* Contiene el cbu del coach y su alias, ya que son datos que el usuario
* necesitara almacenar para realizar los pagos
**/

class coach : public persona{
private:
	/// @brief Cbu del coach
	std::string cbu;
	/// @brief Alias del coach
	std::string alias;
	
public:
	
	/// @brief Constructor de la clase coach con sus paramentros por defecto
	coach(std::string nombre = "", std::string apellido = "",
	std::string email = "", std::string sexo = "", std::string telefono = "",
	std::string direccion = "", std::string localidad = "", std::string dni = "",
	int dia = 0, int mes = 0, int anio = 0, std::string _cbu = "",
	std::string _alias = "");
	
	/// @brief  Metodos para obtener los atributos de coach
	std::string ver_cbu() const;
	std::string ver_alias() const;
	
	/// @brief Metodos para editar cbu y alias del coach
	void modificar_cbu(std::string cbu);
	void modificar_alias(std::string alias);
	
	/// @brief Metodo que guarda su registro en un archivo binario
	void guardar_en_binario(std::ofstream &archivo) override;
	
	/// @brief Metodo que lee un registro de un archivo binario
	void leer_en_binario(std::ifstream &archivo) override;
	
	/// @brief Metodo que validar que cbu y alias esten ingresados correctamente
	std::string validar_datos_ch() const;
	
};

///@brief Funcion que compara dos coach por su nombre y apellido
bool CriterioCoachNombreApellido(coach c1, coach c2);
///@brief Funcion que compara dos coachs por su localidad
bool CriterioCoachLocalidad(coach c1, coach c2);
///@brief Funcion que compara dos coach por su edad
bool CriterioCoachEdad(coach c1, coach c2);
///@brief Funcion que compara dos coach por su email
bool CriterioCoachEmail(coach c1, coach c2);
///@brief Funcion que compara dos coach por su telefono
bool CriterioCoachTelefono(coach c1, coach c2);
///@brief Funcion que compara dos coach por su DNI
bool CriterioCoachDNI(coach c1, coach c2);
#endif

