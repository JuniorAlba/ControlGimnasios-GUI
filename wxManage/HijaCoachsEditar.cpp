 #include "HijaCoachsEditar.h"
#include "string_conv.h"
#include <wx/msgdlg.h>

/**
* Constructor de la clase HijaCoachsEditar
* 
* Recibe la posicion del coach a editar, se crea una copia de este y se cargan
* los datos en las celdas de la ventana
*
*/
HijaCoachsEditar::HijaCoachsEditar(manage *aux, int pos, wxWindow *parent): BaseCoachsAgregar(parent), m_manage(aux){
	this->pos=pos;
	coach ch=m_manage->obtenercoach(pos);
	
	m_nombre_ch->SetValue(std_to_wx(ch.ver_nombre()));
	m_apellido_ch->SetValue(std_to_wx(ch.ver_apellido()));
	m_DNI_ch->SetValue(std_to_wx(ch.ver_DNI()));
	m_sexo_ch->SetValue(std_to_wx(ch.ver_sexo()));
	m_mail_ch->SetValue(std_to_wx(ch.ver_email()));
	m_telefono_ch->SetValue(std_to_wx(ch.ver_tel()));
	m_localidad_ch->SetValue(std_to_wx(ch.ver_loc()));
	m_direccion_ch->SetValue(std_to_wx(ch.ver_dir()));
	
	m_CBU->SetValue(std_to_wx(ch.ver_cbu()));
	m_alias->SetValue(std_to_wx(ch.ver_alias()));
	if(ch.ver_diaN()!=0) m_dia_ch->SetValue(std_to_wx(std::to_string(ch.ver_diaN())));
	if(ch.ver_mesN()!=0)m_mes_ch->SetValue(std_to_wx(std::to_string(ch.ver_mesN())));
	if(ch.ver_anioN()!=0)m_anio_ch->SetValue(std_to_wx(std::to_string(ch.ver_anioN())));
}

/**
* Evento del boton para aceptar el registro
* 
* Al clickear el boton carga los datos de las celdas en un coach, si este fue
* modificado pregunta si quiere guardar los cambios, en caso aceptar copia estos
* nuevos datos en la posicion del coach seleccionado y retorna EndModal(1), 
* caso contrario devuelve EndModal(0)
* 
*
*/
void HijaCoachsEditar::ClickAceptarRegistro(wxCommandEvent& event){
	std::string nombre,apellido,email,sexo,telefono,
		direccion,localidad,DNI,CBU,alias;
	long dia,mes,anio;
	
	nombre=wx_to_std(m_nombre_ch->GetValue());
	apellido=wx_to_std(m_apellido_ch->GetValue());
	email=wx_to_std(m_mail_ch->GetValue());
	sexo=wx_to_std(m_sexo_ch->GetValue());
	telefono=wx_to_std(m_telefono_ch->GetValue());
	direccion=wx_to_std(m_direccion_ch->GetValue());
	localidad=wx_to_std(m_localidad_ch->GetValue());
	DNI=wx_to_std(m_DNI_ch->GetValue());
	
	m_dia_ch->GetValue().ToLong(&dia);
	m_mes_ch->GetValue().ToLong(&mes);
	m_anio_ch->GetValue().ToLong(&anio);
	
	CBU = wx_to_std(m_CBU->GetValue());
	alias= wx_to_std(m_alias->GetValue());
	if(m_dia_ch->GetValue()==""){
		dia=-1;
	}
	if(m_mes_ch->GetValue()==""){
		mes=-1;
	}
	if(m_anio_ch->GetValue()==""){
		anio=-1;
	}
	
	coach ch(nombre,apellido,email,sexo,telefono,direccion,localidad,DNI,dia,mes,anio,CBU,alias);
	std::string errores="";
	errores= ch.validar_datos_ch();
	if(errores.size()){
		wxMessageBox(std_to_wx(errores),"Errores",wxOK|wxICON_ERROR,this);
	}
	else{
		m_manage->obtenercoach(pos)=ch;
		m_manage->guardar();
		EndModal(1);
	}
}

/***
* Evento del boton para cancelar el registro
*
* Devuelve EndModal(0)
*
*/
void HijaCoachsEditar::ClickCancelarRegistro( wxCommandEvent& event ){
	EndModal(0);
}
