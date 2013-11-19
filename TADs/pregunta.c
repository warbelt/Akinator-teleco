#include<stdio.h>
#include<stdlib.h>
#include"sListaPregunta.h"

void introDatos_pregunta (PREGUNTA *pregunta)
{
	fflush (stdin);
	printf("\nPregunta: "); 
	gets(pregunta->pregunta);
}

void printDatos_pregunta (PREGUNTA pregunta)
{
	printf ("%s\n", pregunta.pregunta);
}

void modDatos_pregunta (PREGUNTA *pregunta)
{
	system ("cls");
	printf ("===================================AKINATOR===================================\n\n");
	printf ("==============================MODIFICAR PREGUNTAS=============================\n\n");
	fflush (stdin);
	printf ("Nueva pregunta: ");
	gets (pregunta->pregunta);
}