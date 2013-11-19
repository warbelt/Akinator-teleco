#pragma once
#include"usuario.h"

typedef struct sListaUsuario
{
	int num;
	USUARIO *pUsuarios;
}LISTA_U;

void introducir_usuario ();
void mostrar_usuario ();
void modificar_usuario ();
void borrar_usuario ();
void cargarDatosUsuarios(LISTA_U *lista);
void guardaDatosUsuarios(LISTA_U lista);