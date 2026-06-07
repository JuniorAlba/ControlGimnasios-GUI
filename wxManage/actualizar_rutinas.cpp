#include "Manage.h"
#include <iostream>
#include <fstream>
#include "Utils.h"
using namespace std;

int main() {
    manage m("coachs.dat", "clientes.dat", "suscripciones.dat", "planes.dat");
    int cant = m.cantidadSuscripciones();
    for (int i = 0; i < cant; i++) {
        suscripcion s = m.obtenerSuscripcion(i);
        string plan = s.ver_nombre_plan();
        string rut_base = "RutinasBases/rutina" + plan + ".txt";
        PasarMiniscula(rut_base);
        string rut_cliente = "RutinasClientes/" + FechaArchivo(s.ver_fecha_pago()) + "_" + s.ver_DNI_cliente() + "_" + plan + ".txt";
        
        ifstream base(rut_base.c_str());
        ofstream cliente_archivo(rut_cliente.c_str());
        if (base.is_open() && cliente_archivo.is_open()) {
            string linea;
            while(getline(base, linea)) {
                cliente_archivo << linea << "\n";
            }
            cout << "Rutina actualizada para " << s.ver_DNI_cliente() << " con plan " << plan << endl;
        } else {
            cout << "Error abriendo archivos para " << s.ver_DNI_cliente() << " (" << rut_base << ")" << endl;
        }
        if (base.is_open()) base.close();
        if (cliente_archivo.is_open()) cliente_archivo.close();
    }
    return 0;
}
