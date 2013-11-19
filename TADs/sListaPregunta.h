#pragma once
#include"pregunta.h"

typedef struct sListaPregunta
{
	int num;
	PREGUNTA *pPreguntas;
}LISTA_Q;

void introducir_pregunta ();
void mostrar_pregunta ();
void modificar_pregunta ();
void borrar_pregunta ();
void cargarDatosPreguntas (LISTA_Q *lista);
void guardaDatosPreguntas (LISTA_Q lista);