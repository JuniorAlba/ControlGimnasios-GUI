#ifndef HIJACOACHSAGREGAR_H
#define HIJACOACHSAGREGAR_H
#include "wxfb_project.h"
#include "manage.h"
class HijaCoachsAgregar : public BaseCoachsAgregar {
	
private:
	manage *m_manage;
protected:
	/// Evento para cancelar el registro de un nuevo coach
	void ClickCancelarRegistro( wxCommandEvent& event )  override;
	/// Evento para aceptar el registro de un nuevo coach
	void ClickAceptarRegistro( wxCommandEvent& event )  override;
	
public:
	HijaCoachsAgregar(manage *aux, wxWindow *parent=NULL);
};

#endif

