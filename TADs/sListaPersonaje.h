#pragma once
#include"personaje.h"

typedef struct sListaPersonaje
{
	PERSONAJE *pPersonajes;
	int num;
}LISTA_P;

void introducir_personaje ();
void mostrar_personaje ();
void modificar_personaje ();
void borrar_personaje ();
void cargarDatosPersonajes (LISTA_P *lista);
void guardaDatosPersonajes(LISTA_P lista);