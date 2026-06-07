#include "HijaPlanAgregar_Coach.h"
#include "string_conv.h"
#include <vector>
/**
* Implementacion del constructor de la ventana agregar.
* Carga dentro del vector v_coachs los coachs que se encuentran dentro del plan.
* y luego los carga en la grilla.
**/
HijaPlanAgregar_Coach::HijaPlanAgregar_Coach(manage *aux, int pos_plan, wxWindow *parent) : BasePlanAgregar_Coach(parent), m_manage(aux) {
	this->v_coachs = m_manage->coachsOutPlan(pos_plan);
	this->pos_plan = pos_plan;
	m_grilla->AppendRows(v_coachs.size());
	for(int i=0;i<v_coachs.size();++i){
		CargarFila(i);
	}
	m_grilla->SetSelectionMode(wxGrid::wxGridSelectRows);
}
/**
* Toma los datos de una persona desde la instancia de coach y los carga en su
* correspondiente fila de la m_grilla.
* La m_grilla ya debe tener lugar, es decir, debe existir el renglon 
* (estara vacio o tendra basura).
* @param pos es el indice de el cliente en el arreglo de la clase Manage (en base 0)
**/
void HijaPlanAgregar_Coach::CargarFila(int pos){
	m_grilla->SetCellValue(pos,0,std_to_wx(v_coachs[pos].ver_apellido()+ ", " + v_coachs[pos].ver_nombre()));
	m_grilla->SetCellValue(pos,1,std_to_wx(v_coachs[pos].ver_DNI()));
	m_grilla->SetCellValue(pos,2,std_to_wx(m_manage->planesResponsables(v_coachs[pos].ver_DNI())));
	m_grilla->SetCellValue(pos,3,std_to_wx(v_coachs[pos].ver_tel()));

}

/// Al hacer doble click invoca al metodo clickAgregar().
void HijaPlanAgregar_Coach::DobleClickFila( wxGridEvent& event )  {
	ClickAgregar(event);
}

void HijaPlanAgregar_Coach::ClickColumna( wxGridEvent& event )  {
	event.Skip();
}

/** Implementacion del metodo ClickAgregar. Este permite agregar el coach 
* seleccionado en la grilla y agregarlo al plan. Para luego guardarlo en el archivo
* binario con el metodo guardar().
*
*/
void HijaPlanAgregar_Coach::ClickAgregar( wxCommandEvent& event )  {
	int fila_grilla = m_grilla->GetGridCursorRow();
	m_manage->obtenerPlan(pos_plan).agregar_coach(v_coachs[fila_grilla].ver_DNI());
	m_manage->guardar();
	EndModal(1);
}

/// Implementacion de clickcancelar, permite anular el registro del nuevo coach. Es decir
/// no devuelve ninguna modificacion.
void HijaPlanAgregar_Coach::ClickCancelar( wxCommandEvent& event )  {
	EndModal(0);
}

