#ifndef HIJACOACHS_H
#define HIJACOACHS_H
#include "wxfb_project.h"
#include "manage.h"
class HijaCoachs : public BaseCoachs {
	
private:
	manage *m_manage;
	void CargarFila(int pos);
protected:
	/// Abre el cuadro para editar los datos de un cliente 
	void ClickEditar( wxCommandEvent& event )  override;
	
	/// Acomoda los tamaños de las columnas de la grilla cuando cambia el tamaño de la ventana
	void ClickTamanio( wxSizeEvent& event )  override;
	
	/// Busca un nombre y apellido en la grilla cuando apretamos enter en el cuadro de busqueda
	void EnterBuscar( wxCommandEvent& event )  override;
	
	/// Busca por nombre y apellido en la grilla cuando hacemos click en el boton "Buscar"
	void ClickBuscar( wxCommandEvent& event )  override;
	
	/// Abre la ventana para editar un cliente cuando se hace doble click sobre el mismo
	void DobleClickFila( wxGridEvent& event )  override;

	/// Elimina el coach que se haya elegido en la grilla
	void ClickEliminar( wxCommandEvent& event )  override;
	
	/// Reordena la grilla cuando se hace click sobre el titulo de una columna
	void ClickColumna( wxGridEvent& event )  override;
	
	/// Abrir ventana de Registro para agregar nuevo coach
	void ClickAgregar( wxCommandEvent& event )  override;
	/// Cerrar ventana actual
	void ClickSalirCoachs( wxCommandEvent& event )  override;
public:
	HijaCoachs(manage *aux,wxWindow *parent=NULL);

	
};

#endif

