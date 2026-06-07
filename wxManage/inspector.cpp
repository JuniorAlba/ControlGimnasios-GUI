#include "Manage.h"
#include <iostream>
using namespace std;

int main() {
    manage m("coachs.dat", "clientes.dat", "suscripciones.dat", "planes.dat");
    cout << "--- PLANES (" << m.cantidadPlanes() << ") ---" << endl;
    for (int i = 0; i < m.cantidadPlanes(); i++) {
        plan p = m.obtenerPlan(i);
        cout << "Plan: " << p.ver_nombre_plan() << " | Precio: " << p.ver_precio_plan() << endl;
    }
    
    cout << "\n--- SUSCRIPCIONES (" << m.cantidadSuscripciones() << ") ---" << endl;
    for (int i = 0; i < m.cantidadSuscripciones(); i++) {
        suscripcion s = m.obtenerSuscripcion(i);
        cout << "DNI Cliente: " << s.ver_DNI_cliente() << " | Plan: " << s.ver_nombre_plan() << endl;
    }
    
    cout << "\n--- CLIENTES (" << m.cantidadCliente() << ") ---" << endl;
    for (int i = 0; i < m.cantidadCliente(); i++) {
        cliente c = m.ObtenerCliente(i);
        cout << "DNI: " << c.ver_DNI() << " | Nombre: " << c.ver_nombre() << " " << c.ver_apellido() << endl;
    }

    return 0;
}
