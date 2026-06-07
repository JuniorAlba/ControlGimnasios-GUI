#include "HijaCoachs.h"
#include "string_conv.h"
#include "HijaClientesAgregar.h"
#include "HijaCoachsAgregar.h"
#include "HijaCoachsEditar.h"
#include <wx/wx.h>
#include <wx/msgdlg.h>

/**
* Inicializa la ventana la grilla con los datos de los coachs
* "m_grilla_coachs" y define la cant de filas correspondiente a la
* cantidad de coachs guardados.
*/
HijaCoachs::HijaCoachs(manage *aux,wxWindow *parent) : BaseCoachs(parent), m_manage(aux) {
	wxIcon icon("icono.ico", wxBITMAP_TYPE_ICO);
	SetIcon(icon);
	
	int cant_coachs = m_manage->cantidadcoach();
	m_grilla_coachs->AppendRows(cant_coachs);
	for(int i=0;i<cant_coachs;++i){
		CargarFila(i);
	}
	m_grilla_coachs->SetSelectionMode(wxGrid::wxGridSelectRows);
}

/**
* Toma los datos de una persona desde la instancia de Agenda y los carga en su
* correspondiente fila de la m_grilla.
* La m_grilla ya debe tener lugar, es decir, debe existir el renglon 
* (estara vacio o tendra basura).
* @param pos es el indice de el cliente en el arreglo de la clase Manage (en base 0)
**/
void HijaCoachs::CargarFila(int pos){
	coach ch = m_manage->obtenercoach(pos);
	
	m_grilla_coachs->SetCellValue(pos,0,std_to_wx(ch.ver_apellido()+ ", " + ch.ver_nombre()));
	
	m_grilla_coachs->SetCellValue(pos,1,std_to_wx(ch.ver_DNI()));
	
	m_grilla_coachs->SetCellValue(pos,2,std_to_wx(m_manage->planesResponsables(ch.ver_DNI())));
	
	m_grilla_coachs->SetCellValue(pos,3,std_to_wx(ch.ver_tel()));

}

/// Evento que cierra la ventana de coachs
void HijaCoachs::ClickSalirCoachs( wxCommandEvent& event )  {
	this->Close();
}

/// Abre la ventana para registrar un nuevo cliente
void HijaCoachs::ClickAgregar( wxCommandEvent& event )  {
	HijaCoachsAgregar nueva_ventana(m_manage,this);
	if(nueva_ventana.ShowModal()==1){
		m_grilla_coachs->AppendRows(1); 
		int pos_nuevo = m_manage->cantidadcoach()-1;
		CargarFila(pos_nuevo);
		m_grilla_coachs->SetGridCursor(pos_nuevo,0); 
		m_grilla_coachs->SelectRow(pos_nuevo);
	}
}

/**
* Implementacion del evento de click en el boton eliminar
* Segun donde este posicionado el cursor de la grilla borra el registro tanto
* de la grilla como de la base de datos.
*/
void HijaCoachs::ClickEliminar( wxCommandEvent& event )  {
	int fila_actual = m_grilla_coachs->GetGridCursorRow();
	int res = wxMessageBox(c_to_wx("¿Eliminar el registro?"), m_grilla_coachs->GetCellValue(fila_actual,0),wxYES_NO);
	if(res==wxYES){
		m_grilla_coachs->DeleteRows(fila_actual,1);
		m_manage->borrarcoach(fila_actual);
		m_manage->guardar();
	}
}


/**
* El enter en el cuadro de texto equivale al click en el boton "Buscar".
**/
void HijaCoachs::EnterBuscar( wxCommandEvent& event )  {
	ClickBuscar(event);
}

/**
* Cuando se hace click en buscar, se busca desde el coach que esta seleccionado
* en la tabla, en adelante, algun nombre y apellido que contenga lo que indica
* el cuadro de busqueda (puede contenerlo en cualquier parte, y la busqueda no
* distingue mayusculas y minusculas).
* Si hay mas de uno que coinciden, cada click en buscar nos lleva al siguiente.
**/
void HijaCoachs::ClickBuscar( wxCommandEvent& event )  {
	int fila_pos = m_grilla_coachs->GetGridCursorRow();
	if (m_grilla_coachs->GetSelectedRows().GetCount()==0) fila_pos = -1;
	if(m_grilla_coachs->GetSelectedRows().GetCount()>1){
		wxMessageBox("Usted a seleccionado demasiadas filas, seleccione 1 o menos porfavor.\nTenga en cuenta que se empezara a buscar apartir de esa fila en adelante, en caso de tener seleccionada la ultima fila se comenzara desde el inicio de la grilla.");	
		return;
	}
	std::string nomape = wx_to_std(m_buscar->GetValue());
	int encontrado = m_manage->buscarcoachsNombre( nomape, fila_pos+1 );
	if(encontrado==-1) encontrado = m_manage->buscarcoachsNombre(nomape,0);
	if(encontrado==-1) wxMessageBox("No se encontraron coincidencias");
	else{
		m_grilla_coachs->SetGridCursor(encontrado,1);
		m_grilla_coachs->SelectRow(encontrado);
	}
	
}

/**
* El doble click en la m_grilla equivale al click en el boton "Editar".
**/
void HijaCoachs::DobleClickFila( wxGridEvent& event )  {
	ClickEditar(event);
}

/**
* Si se hace click en la cabecera de alguna columna, la tabla se ordena segun
* ese dato. Para esto, se le pide a la base de datos que ordene, y luego 
* se recargan los datos de todas las filas.
**/
void HijaCoachs::ClickColumna( wxGridEvent& event )  {
	int col = event.GetCol();
	switch(col){
	case 0: m_manage->Ordenarcoachs(ORDEN_APENOMB); break;
	case 1: m_manage->Ordenarcoachs(O_DNI); break;
	case 2: m_manage->Ordenarcoachs(ORDEN_PLANES_RESPONSABLES); break;
	case 3: m_manage->Ordenarcoachs(ORDEN_TELEFONO); break;
	}
	for(int i=0; i<m_manage->cantidadcoach();i++) CargarFila(i);

}

/// Evento que ajusta la grilla segun el tamanio de la ventana y la proporcion que mantenia la grilla
void HijaCoachs::ClickTamanio( wxSizeEvent& event )  {
	Layout();
	int tamanios[4], ancho_total_viejo=0; 
	for (int i=0;i<4;i++) { 
		tamanios[i] = m_grilla_coachs->GetColSize(i);
		ancho_total_viejo += tamanios[i];
	}
	int ancho_total_nuevo=m_grilla_coachs->GetSize().GetWidth(); 
	m_grilla_coachs->BeginBatch(); 
	for (int i=0;i<4;i++) 
		m_grilla_coachs->SetColSize(i,tamanios[i]*ancho_total_nuevo/ancho_total_viejo);
	m_grilla_coachs->EndBatch();
}

/**
* Al hacer click en "Editar", se abre de forma modal la ventana para ver y/o
* modificar los datos. En forma modal significa que esta ventana espera a que 
* termine la otra. Cuando termina, el codigo de retorno me indica si la otra 
* ventana modifico o no los datos (el usuario puede hacer click en Agregar o
* en Cancelar) En caso afirmativo, esta ventana debe actualizar la m_grilla_coachs.
**/
void HijaCoachs::ClickEditar( wxCommandEvent& event )  {
	int pos= m_grilla_coachs->GetGridCursorRow();
	HijaCoachsEditar nueva_ventana(m_manage,pos,this);
	if(nueva_ventana.ShowModal()==1){
		CargarFila(pos);
	}
}




