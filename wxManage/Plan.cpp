/**
* @file Plan.cpp
* @brief Implementaciones de todo lo necesario para trabajar con la clase Plan.
**/
#include "Plan.h"
#include <cstring>

/// Implementación del constructor de la clase Plan
plan::plan(std::string nombre, int precio){
	this->nombre = nombre;
	this->precio = precio;
	nombre_rutina_base = "rutina"+nombre+".txt";
	std::ofstream rutina_base("RutinasBases/"+nombre_rutina_base);
}

/**
* Implementacion del metodo que valida los datos ingresados.
* El vector de coachs no es necesario pq ya posee un metodo propio
* la clase cliente.
**/
std::string plan::validar_datos() const{
	std::string errores = "";
	
	if(nombre.size()==0){
		errores+="El nombre no puede estar vacio \n";
	}
	if(nombre_rutina_base.size()==0){
		errores+="La rutina no puede estar vacia \n";
	}
	if(precio<0){
		errores+="El precio no puede ser negativo \n";
	}
	if(p_coachs.size()==0){
		errores+="Falta un coach responsable del plan \n";
	}
	return errores;
}

/// Implementación del metodo para modificar el precio del plan.
void plan::modificar_precio(int nuevo_precio) {
	precio = nuevo_precio;
}

///Implementaciónes de los métodos para obtener los atributos.
int plan::ver_precio_plan() const{
	return precio;
}

std::string plan::ver_coach_plan(int pos) const{ 
	return p_coachs[pos];
}

std::vector<std::string> plan::ver_coachs_plan() const{
	return p_coachs;
}

std::string plan::ver_nombre_plan() const{
	return nombre;
}

std::string plan::ver_nombre_rutina() const{
	return nombre_rutina_base;
}


///Implementación del metódo que leer el registro en un archivo binario.
void plan::leer_en_binario(std::ifstream &archivo){
	registroPlan registro;
	archivo.read(reinterpret_cast<char*>(&registro), sizeof(registroPlan));
	this->nombre = registro.nombre;
	this->nombre_rutina_base = registro.rutina_base;
	this->precio = registro.precio;
	
	p_coachs.erase(p_coachs.begin(), p_coachs.end()); // asegurarse de que el vector esté vacío antes de
	//agregar elementos
	
	for (int i = 0; i < registro.num_coachs; ++i) {
		std::string id_coach(registro.coachs[i],8);
		p_coachs.push_back(id_coach);
	}
	
}

///Implementación del metódo que guarda el registro en un archivo binario.
void plan::guardar_en_binario(std::ofstream &archivo){
	registroPlan registro;
	strcpy(registro.nombre, this->nombre.c_str());
	strcpy(registro.rutina_base, this->nombre_rutina_base.c_str());
	registro.precio = this->precio;
	
	registro.num_coachs = p_coachs.size();
	
	
	for (int i = 0; i < p_coachs.size(); ++i) {
		std::strcpy(registro.coachs[i], p_coachs[i].c_str());
	}
	
	archivo.write(reinterpret_cast<char*>(&registro), sizeof(registroPlan));
}

///Implementacion del metodo que agrega un coach al arreglo que tiene el plan
void plan::agregar_coach(std::string id_coach){
	p_coachs.push_back(id_coach);
}

///Implementacion del metodo para eliminar un ouch del arreglo
void plan::eliminar_coach(std::string id_coach){
	for(int i=0;i<p_coachs.size();i++){ 
		if(id_coach == p_coachs[i]){
			p_coachs.erase(p_coachs.begin()+i);
		}
	}
}

///Implementacion dle metodo para ver la cantidad de coachs del arreglo
int plan::ver_cant_coachs() const{
	return p_coachs.size();
}



///Implementacion de funciones para enviar como puntero a funcion a sort
bool CriterioPrecioPlan(plan p1, plan p2){
	return p1.ver_precio_plan()<p2.ver_precio_plan();
}
bool CriterioNombre(plan p1, plan p2){
	return p1.ver_nombre_plan()<p2.ver_nombre_plan();
}
	
///Implementacion de metodo para sobrecargar el operador = para la clase plan
void plan::operator=(plan pl){
	this->nombre = pl.ver_nombre_plan();
	this->nombre_rutina_base = pl.ver_nombre_rutina();
	this->precio = pl.ver_precio_plan();
	this->p_coachs.erase((this->p_coachs).begin(),(this->p_coachs).end());
	for(int i=0; i<pl.ver_coachs_plan().size() ;i++){
		(this->p_coachs).push_back(pl.ver_coach_plan(i));
	}
}

