#ifndef HIJAPLANAGREGAR_COACH_H
#define HIJAPLANAGREGAR_COACH_H
#include "wxfb_project.h"
#include "manage.h"
#include <vector>

class HijaPlanAgregar_Coach : public BasePlanAgregar_Coach {
	
private:
	manage *m_manage;
	int pos_plan;
	std::vector<coach> v_coachs;
	
	
	void CargarFila(int pos);
protected:
	/// Evento para el click en el boton de cancelar
	void ClickCancelar( wxCommandEvent& event )  override;
	/// Evento que permite hacer dobleClick en la fila para agregar 
	void DobleClickFila( wxGridEvent& event )  override;
	/// Evento que permite elegir el coach haciendo click en la columna
	void ClickColumna( wxGridEvent& event )  override;
	/// Evento que permite hacer click en agregar
	void ClickAgregar( wxCommandEvent& event )  override;
	
public:
	HijaPlanAgregar_Coach(manage *aux, int pos_plan, wxWindow *parent=NULL);

};

#endif

