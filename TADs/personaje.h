#pragma once

typedef struct sPersonajes
{
	char nombre[20], apellidos[40], sexo, apodo[20], ocupacion[20];
	int edad;
}PERSONAJE;


void printDatos_personaje (PERSONAJE personaje);
void introDatos_personaje(PERSONAJE *personaje);
void modDatos_personaje (PERSONAJE *personaje, int *p_opcion);