/**
* @file Manage.cpp
* @brief Declaraciones de todo lo necesario para trabajar con la clase Manage
**/
#include "Manage.h"
#include <fstream>
#include <algorithm>
/**
* @brief Constructor de la clase Manage
*
* Toma de las variables string los nombres de cada archivo e inicializa las variables
* ifstream para luego leer los archivos binarios y guardarlos en su respectivo vector.
* 
*
* @param std::string nombre_archivo_coachs Cadena que representa el nombre del archivo binario coachs.
*		 std::string nombre_archivo_clientes Cadena que representa el nombre del archivo binario clientes.
*		 std::string nombre_archivo_suscripciones Cadena que representa el nombre del archivo binario suscripciones.
		 std::string nombre_archivo_planes Cadena que representa el nombre del archivo binario planes.
**/ 
manage::manage(std::string nombre_archivo_coachs, std::string nombre_archivo_clientes, std::string nombre_archivo_suscripciones, std::string nombre_archivo_planes){
	
	this->nombre_archivo_coachs = nombre_archivo_coachs;
	std::ifstream archi_coachs(nombre_archivo_coachs.c_str(),std::ios::binary|std::ios::ate);
	if(archi_coachs.is_open()){
		int cantidad_de_coachs = archi_coachs.tellg()/sizeof(registroCoach); 
		vector_de_coachs.resize(cantidad_de_coachs);
		archi_coachs.seekg(0,std::ios::beg);
		for(int i=0;i<cantidad_de_coachs;i++) { 
			vector_de_coachs[i].leer_en_binario(archi_coachs);
		}
		archi_coachs.close();
	}
	
	this->nombre_archivo_clientes = nombre_archivo_clientes;
	std::ifstream archi_clientes(nombre_archivo_clientes.c_str(),std::ios::binary|std::ios::ate);
	if(archi_clientes.is_open()){
		
		int cantidad_de_clientes = archi_clientes.tellg()/sizeof(registroCliente);
		vector_de_clientes.resize(cantidad_de_clientes);
		archi_clientes.seekg(0,std::ios::beg);
		for(int i = 0; i < cantidad_de_clientes; i++) { 
			vector_de_clientes[i].leer_en_binario(archi_clientes);
		}
		archi_clientes.close();
	}
	
	this->nombre_archivo_suscripciones = nombre_archivo_suscripciones;
	std::ifstream archi_suscripciones(nombre_archivo_suscripciones.c_str(), std::ios::binary | std::ios::ate);
	if(archi_suscripciones.is_open()){
		
		int cantidad_de_suscripciones = archi_suscripciones.tellg()/sizeof(registroSuscripcion);
		vector_de_suscripciones.resize(cantidad_de_suscripciones);
		archi_suscripciones.seekg(0,std::ios::beg);
		for(int i = 0; i < cantidad_de_suscripciones; i++) { 
			vector_de_suscripciones[i].leer_en_binario(archi_suscripciones);
		}
		archi_suscripciones.close();
	}
	
	this->nombre_archivo_planes = nombre_archivo_planes;
	std::ifstream archi_planes(nombre_archivo_planes.c_str(),  std::ios::binary | std::ios::ate );
	if(archi_planes.is_open()){
		
		int cantidad_de_planes = archi_planes.tellg()/sizeof(registroPlan);
		vector_de_planes.resize(cantidad_de_planes);
		archi_planes.seekg(0, std::ios::beg);
		for(int i=0; i<cantidad_de_planes; ++i){
			vector_de_planes[i].leer_en_binario(archi_planes);
		}
		archi_planes.close();
	}
}



/**
* @brief Metodo para guardar los datos en los binarios
*
* Toma de las variables string los nombres de cada archivo e inicializa las variables
* ifstream para luego leer los archivos binarios y guardarlos en su respectivo vector.
* 
* @return devuelve una variable booleana "true" si el guardado fue completado con exito.
* 
**/ 
bool manage::guardar() {
	
	std::ofstream archi_coachs(nombre_archivo_coachs.c_str(), std::ios::binary|std::ios::trunc);
	if (!archi_coachs.is_open()) return false;
	for (unsigned i = 0; i < vector_de_coachs.size(); i++){
		vector_de_coachs[i].guardar_en_binario(archi_coachs);
	}
	archi_coachs.close();
	
	std::ofstream archi_clientes(nombre_archivo_clientes.c_str(),std::ios::binary|std::ios::trunc);
	if (!archi_clientes.is_open())return false;
	for (unsigned i = 0; i < vector_de_clientes.size(); i++){
		vector_de_clientes[i].guardar_en_binario(archi_clientes);
	}
	archi_clientes.close();

	std::ofstream archi_suscripciones(nombre_archivo_suscripciones.c_str(), std::ios::binary|std::ios::trunc);
	if(!archi_suscripciones.is_open()) return false;
	for(unsigned i=0; i<vector_de_suscripciones.size(); ++i){
		vector_de_suscripciones[i].guardar_en_binario(archi_suscripciones);
	}
	archi_suscripciones.close();
	
	std::ofstream archi_planes(nombre_archivo_planes.c_str(), std::ios::binary|std::ios::trunc);
	if(!archi_planes.is_open()) return false;
	for(unsigned i=0; i<vector_de_planes.size(); ++i){
		vector_de_planes[i].guardar_en_binario(archi_planes);
	}
	archi_planes.close();
	
	return true;

}



/// @brief Implemetaciones de métodos para ver la cantidad de clientes, coachs, planes y suscripciones.
int manage::cantidadCliente() const{
	return vector_de_clientes.size();
}
int manage::cantidadcoach() const{
	return vector_de_coachs.size();
}
int manage::cantidadPlanes() const{
	return vector_de_planes.size();
}
int manage::cantidadSuscripciones() const{
	return vector_de_suscripciones.size();
}


/** 
* @brief Implemetacion de métodos para agregar clientes, coachs, planes y suscripciones a los vectores.
*/	
void manage::agregarCliente(const cliente &cl) {
	vector_de_clientes.push_back(cl);
}
void manage::agregarcoach (const coach &ch){
	vector_de_coachs.push_back(ch);
}
void manage::agregarPlan(const plan &p){
	vector_de_planes.push_back(p);
}
void manage::agregarSuscripcion(const suscripcion &sub){
	vector_de_suscripciones.push_back(sub);
}


/// @brief Implemetacion de métodos para borrar clientes, coachs, planes y suscripciones de los vectores
void manage::borrarCliente(int pos) {
	vector_de_clientes.erase(vector_de_clientes.begin()+pos);
}
void manage::borrarcoach(int pos) {
	vector_de_coachs.erase(vector_de_coachs.begin()+pos);
}
void manage::borrarPlan(int pos){
	vector_de_planes.erase(vector_de_planes.begin()+pos);
}
void manage::borrarSuscripcion(int pos){
	vector_de_suscripciones.erase(vector_de_suscripciones.begin()+pos);
}

/** @brief Implemetacion de métodos para buscar un coach por su DNI y posicion donde inicia.
* @param -variable std::string DNI que representa el dni del coach a buscar.
* 		 -variable int pos que representa la posicion inicial.
*/
coach manage::buscarcoachsDNI(std::string DNI, int pos) const{
	coach ch;
	for(unsigned i=pos; i<vector_de_coachs.size(); i++){
		if(vector_de_coachs[i].ver_DNI()==DNI) return vector_de_coachs[i];
	}
	return ch;
}

/** @brief Implemetacion de métodos para encontrar la posicion de un coach, por su DNI y posicion donde inicia.
* @param std::string DNI que representa el dni del coach a buscar.
* 		 int pos que representa la posicion inicial.
* @return variable entera con la posicion en donde se encuentra o -1 si no esta
*/
int manage::buscarPoscoachsDNI(std::string DNI, int pos) const{
	coach ch;
	for(unsigned i=pos; i<vector_de_coachs.size(); i++){
		if(vector_de_coachs[i].ver_DNI()==DNI) return i;
	}
	return -1;
}

/** @brief Implemetacion de métodos para encontrar un cliente, por su DNI y posicion donde inicia.
* @param  std::string DNI que representa el dni del cliente a buscar.
* 		  int pos que representa la posicion inicial.
* @return variable cliente representando al cliente encontrado o un cliente vacio de no hallarlo. 
*/
cliente manage::buscarClientesDNI(std::string DNI, int pos) const{
	cliente cl;
	for(unsigned i=pos; i<vector_de_clientes.size(); i++){
		if(vector_de_clientes[i].ver_DNI()==DNI) return vector_de_clientes[i];
	}
	return cl;
}


/** @brief Implemetacion de métodos para encontrar un Plan, por su nombre y posicion donde inicia.
* @param std::string nombre  que representa el dni del plan a buscar.
* 		 int pos que representa la posicion inicial.
* @return -variable plan representando al plan encontrado o vacio de no hallarlo. 
*/
plan manage::buscarPlanNombre(std::string nombre, int pos) const{
	plan pl;
	
	for(unsigned i=pos; i<vector_de_planes.size(); i++){
		if(vector_de_planes[i].ver_nombre_plan()==nombre) return vector_de_planes[i];
	}
	return pl;
}

/** @brief Implemetacion de métodos para encontrar una suscripcion, por el dni del cliente, 
* nombre del plan y la posicion donde inicia.
* @param  std::string cliente_DNI  que representa el dni cliente suscripto.
* 		  std::string nombre_plan pos que representa el nombre del plan.
*		  int pos con la posicion donde empezar a buscar.
* @return suscripcion encontrada o vacia de no hallarlo.
*/
suscripcion manage::buscarSub(std::string cliente_DNI, std::string nombre_plan, int pos) const{
	suscripcion sub;
	for(unsigned i=pos; i<vector_de_suscripciones.size(); i++){
		if(vector_de_suscripciones[i].ver_nombre_plan()==nombre_plan 
		and vector_de_suscripciones[i].ver_DNI_cliente()==cliente_DNI) return vector_de_suscripciones[i];
	}
	return sub;
}

/// @brief Implementaciones de los metodos para retornar los datos almacenados en los distintos vectores.
cliente &manage::ObtenerCliente(int pos){
	return vector_de_clientes[pos];
}

suscripcion &manage::obtenerSuscripcion(int pos) {
	return vector_de_suscripciones[pos];
}

coach &manage::obtenercoach(int pos) {
	return vector_de_coachs[pos];
}

plan &manage::obtenerPlan(int pos) {
	return vector_de_planes[pos];
}

/**
* @brief Implementacion del metodo para buscar los planes en los que se encuentra
* suscripto el cliente.
* 
* @param  variable std::string dni_cliente que representa el dni del mismo.
* @return cadena std::string con el nombre de todos los planes suscriptos.
*/
std::string manage::planesSuscritos(std::string dni_cliente) const{
	
	std::string planes = "";
	
	for(unsigned i = 0;i < vector_de_suscripciones.size();i++) { 
		
		if(vector_de_suscripciones[i].ver_DNI_cliente() == dni_cliente && vector_de_suscripciones[i].estado_suscripcion()){
			planes += vector_de_suscripciones[i].ver_nombre_plan() + " ";
		}
		
	}
	
	return planes;
}
/**
* @brief Implementacion del metodo para buscar los planes en los que se encuentra
* los coachs responsables.
* 
* @param  variable std::string dni_coach que representa el dni del mismo.
* @return cadena std::string con el nombre de todos los planes donde se encuentra registrado.
*/
std::string manage::planesResponsables(std::string dni_coach) const{
	
	std::string planes = "";
	
	for(int i = 0;i < vector_de_planes.size();i++) {
		
		for(int j=0;j<vector_de_planes[i].ver_coachs_plan().size();j++) { 
			
			if(vector_de_planes[i].ver_coach_plan(j) == dni_coach){
				planes += vector_de_planes[i].ver_nombre_plan() + " ";
				break;
			}
			
		}
		
	}
	
	return planes;
}


/**
* @brief Implementacion del metodo para buscar los planes en los que se encuentra
* suscripto el cliente.
* 
* Al recibir la variable nomape la pasa a miniscula para facilitar los calculos, luego
* verifica que no este vacia, y a continuacion busca dentro de vector de clientes si la cadena concatenada
* por apellido+", "+nombre es igual a la variable que recibe, de ser encontrado devuelve la posicion del contador 
* for.
* 
* @param  variable std::string nomape representa el nombre y apellido del cliente.
*         variable int pos representa la posicion de inicio en el vector.
* @return devuelve la posicion donde se encuentra el cliente dentro del vector.
*         devuelve -1 de no ser encontrado.
*/
int manage::buscarClientesNombre(std::string nomape, int pos) const{
	PasarMiniscula(nomape);
	if(nomape==""){
		return -1;
	}
	for(unsigned i=pos; i<vector_de_clientes.size(); i++){
		cliente cl = vector_de_clientes[i];
		std::string aux=cl.ver_apellido() + ", " + cl.ver_nombre();
		PasarMiniscula(aux);
		if(aux.find(nomape,0)!=std::string::npos) return i;
	}
	return -1;
}

/**
* @brief Implementacion del metodo para buscar todos los coachs que estan registrado en cierto plan.
*/
std::vector<coach> manage::coachsInPlan(int pos_plan){
	plan plan_actual = this->obtenerPlan(pos_plan);
	std::vector<std::string> DNI_coachs = plan_actual.ver_coachs_plan();
	std::vector<coach> aux;
	for(int i=0; i<DNI_coachs.size() ; i++){
		coach ch1 = buscarcoachsDNI(DNI_coachs[i]);
		aux.push_back(ch1);
	}
	return aux;
}

/**
* @brief Implementacion del metodo para buscar los coachs que no se encuentran en un plan.
* Este metodo tiene sinergia con el metodo anterior, se hace una copia sobre el vector "v" con los
* coachs que se encuentran dentro del plan y luego en el vector "v2" se hace la copia de todo el vector de coachs.
* Luego por medio de dos for va recorriendo y eliminando los coachs que se encuentran en v del vector v2
*/
std::vector<coach> manage::coachsOutPlan(int pos_plan){
	std::vector<coach>v = this->coachsInPlan(pos_plan);
	std::vector<coach>v2 = vector_de_coachs;
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v2.size();j++){
			if(v[i].ver_DNI()==v2[j].ver_DNI()){
				v2.erase(v2.begin()+j);
			}
		}
	}
	return v2;
}

/**
* @brief Implementacion del metodo para buscar los clientes que se encuentran en una suscripcion.
* Como los clientes y las suscripciones estan en dos vectores distintos, por medio de un for
* va recorriendo el vector de suscripciones y almacena en una variable auxiliar el apellido y nombre 
* concatenados para luego buscarlos con la funcion find, y si se encuentra devuelve su posicion del for.
*/
int manage::buscarClientesEnSub(std::string nomape, int pos){
	PasarMiniscula(nomape);
	if(nomape==""){
		return -1;
	}
	for(unsigned i=pos; i<vector_de_suscripciones.size(); i++){
		
		std::string dni_a_buscar = vector_de_suscripciones[i].ver_DNI_cliente();
		
		cliente cl = buscarClientesDNI(dni_a_buscar);
		
		std::string aux = cl.ver_apellido() + ", " + cl.ver_nombre();
		
		PasarMiniscula(aux);
		
		if(aux.find(nomape,0)!=std::string::npos) return i;
	}
	return -1;
}


/**
* @brief Implementacion del metodo para buscar los coach por su nombre y apellido, y pos inicial.
* 
*/
int manage::buscarcoachsNombre(std::string nomape, int pos) const{
	PasarMiniscula(nomape);
	if(nomape==""){
		return -1;
	}
	for(unsigned i=pos; i<vector_de_coachs.size(); i++){
		coach ch = vector_de_coachs[i];
		std::string aux=ch.ver_apellido() + ", " + ch.ver_nombre();
		PasarMiniscula(aux);
		if(aux.find(nomape,0)!=std::string::npos) return i;
	}
	return -1;
}

/**
* @brief Implementacion del metodo para buscar los coach por su nombre y apellido, pero que se encuentran en un plan.
* Para esto se crea un vector de coach, coachs_plan que almacena los coachs que se encuentran en un plan. Luego se recorre
* un for y en una variable string auxiliar se almacena el apellido y nombre del coach que se encuentra en la posicion correspondiente a 
* la iteracion del for.Para luego verificar en un if que ese nombre+apellido sea igual al parametro recibido.
* 
*/
int manage::buscarcoachsNombre(int pos_plan, std::string nomape, int pos){
	std::vector<coach> coachs_plan = coachsInPlan(pos_plan);
	PasarMiniscula(nomape);
	if(nomape==""){
		return -1;
	}
	for(unsigned i=pos; i<coachs_plan.size(); i++){
		coach ch = coachs_plan[i];
		std::string aux=ch.ver_apellido() + ", " + ch.ver_nombre();
		PasarMiniscula(aux);
		if(aux.find(nomape,0)!=std::string::npos) return i;
	}
	return -1;
}

/**
* @brief Implementacion de metodos para ordenar los distintos tipos de datos.
* Esto nos va servir para ordenar las grillas de las diferentes ventanas.
*
*
*/
void manage::OrdenarClientes(CriterioOrdenClientes criterio){
	auto CriterioClientesPlanesSuscritos = [this](const cliente &a, const cliente &b)->bool{
		std::string aux1=this->planesSuscritos(a.ver_DNI());
		std::string aux2=this->planesSuscritos(b.ver_DNI());
		PasarMiniscula(aux1);
		PasarMiniscula(aux2);
		return aux1< aux2;
	};
	switch(criterio){
	case ORDEN_APELLIDO_Y_NOMBRE:
		sort(vector_de_clientes.begin(), vector_de_clientes.end(), CriterioClientesNombreApellido); break;
	case ORDEN_DNI:
		sort(vector_de_clientes.begin(), vector_de_clientes.end(), CriterioClientesDNI); break;
	case ORDEN_EMAIL:
		sort(vector_de_clientes.begin(), vector_de_clientes.end(), CriterioClientesEmail); break;
	case ORDEN_TELEFONO_EMERGENCIAS:
		sort(vector_de_clientes.begin(), vector_de_clientes.end(), CriterioClientesTelefonoEmergencias); break;
		//lambda 
	case ORDEN_PLANES_SUSCRITOS:
		std::sort(vector_de_clientes.begin(), vector_de_clientes.end(), CriterioClientesPlanesSuscritos);
		break;
	}
	this->guardar();
}


void manage::Ordenarcoachs(CriterioOrdencoachs criterio){

	auto CriteriocoachsPlanesResponsables = [this](const coach &a, const coach &b)->bool{
		std::string aux1=this->planesResponsables(a.ver_DNI());
		std::string aux2=this->planesResponsables(b.ver_DNI());
		PasarMiniscula(aux1);
		PasarMiniscula(aux2);
		return aux1< aux2;
	};
	switch(criterio){
	case ORDEN_APENOMB:
		sort(vector_de_coachs.begin(), vector_de_coachs.end(), CriterioCoachNombreApellido); break;
	case O_DNI:
		sort(vector_de_coachs.begin(), vector_de_coachs.end(), CriterioCoachDNI); break;
	case ORDEN_PLANES_RESPONSABLES:
		std::sort(vector_de_coachs.begin(), vector_de_coachs.end(), CriteriocoachsPlanesResponsables);
		break;
	case ORDEN_TELEFONO:
		sort(vector_de_coachs.begin(), vector_de_coachs.end(), CriterioCoachTelefono); break;
		//lambda 
	
	}

	this->guardar();

}

void manage::OrdenarSuscripciones(CriterioOrdenSuscripcion criterio){
	auto CriterioNombreApellidocoach = [this](const suscripcion &a, const suscripcion &b)->bool{
		coach ch_1=this->buscarcoachsDNI(a.ver_DNI_coach());
		coach ch_2=this->buscarcoachsDNI(b.ver_DNI_coach());
		std::string aux1 = ch_1.ver_apellido() + " " + ch_1.ver_nombre();
		std::string aux2 = ch_2.ver_apellido() + " " + ch_2.ver_nombre();
		PasarMiniscula(aux1);
		PasarMiniscula(aux2);
		return aux1< aux2;
	};
	auto CriterioNombreApellidoCliente = [this](const suscripcion &a, const suscripcion &b)->bool{
		cliente cl_1=this->buscarClientesDNI(a.ver_DNI_cliente());
		cliente cl_2=this->buscarClientesDNI(b.ver_DNI_cliente());
		std::string aux1 = cl_1.ver_apellido() + " " + cl_1.ver_nombre();
		std::string aux2 = cl_2.ver_apellido() + " " + cl_2.ver_nombre();
		PasarMiniscula(aux1);
		PasarMiniscula(aux2);
		return aux1< aux2;
	};
	
	switch(criterio){
	case O_APENOM_CL:
		sort(vector_de_suscripciones.begin(), vector_de_suscripciones.end(), CriterioNombreApellidoCliente); break;
	case O_DNI_CL:
		sort(vector_de_suscripciones.begin(), vector_de_suscripciones.end(), CriterioSuscripcionDNICliente); break;
	case O_APENOM_CH:
		sort(vector_de_suscripciones.begin(), vector_de_suscripciones.end(), CriterioNombreApellidocoach); break;
	case O_DNI_CH:
		sort(vector_de_suscripciones.begin(), vector_de_suscripciones.end(), CriterioSuscripcionDNIcoach); break;
	case O_PLAN:
		sort(vector_de_suscripciones.begin(), vector_de_suscripciones.end(), CriterioSuscripcionPlan); break;
	case O_FECH_PAGO:
		sort(vector_de_suscripciones.begin(), vector_de_suscripciones.end(), CriterioSuscripcionFecha); break;
	case O_FECH_VENC:
		sort(vector_de_suscripciones.begin(), vector_de_suscripciones.end(), CriterioSuscripcionFecha); break;
	}
	
	this->guardar();
	
}




