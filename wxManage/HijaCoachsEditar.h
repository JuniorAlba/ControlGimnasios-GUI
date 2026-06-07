#ifndef HIJACOACHSEDITAR_H
#define HIJACOACHSEDITAR_H

#include "wxfb_project.h"
#include "manage.h"

class HijaCoachsEditar : public BaseCoachsAgregar{
private:
	manage *m_manage;
	int pos;
protected:
	/// Evento para cancelar el registro de editar un coach
	void ClickCancelarRegistro( wxCommandEvent& event )  override;
	/// Evento para aceptar el registro de editar un coach
	void ClickAceptarRegistro( wxCommandEvent& event )  override;
public:
	HijaCoachsEditar(manage *aux, int pos, wxWindow *parent=NULL);
};

#endif
