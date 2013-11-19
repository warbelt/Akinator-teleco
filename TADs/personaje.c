#include<stdio.h>
#include<stdlib.h>
#include"sListaPersonaje.h"

void introDatos_personaje(PERSONAJE *personaje)
{
	fflush (stdin);
	printf("Nombre: "); 
	gets(personaje->nombre);
	fflush (stdin);
	printf("Apellidos: "); 
	gets(personaje->apellidos);
	fflush (stdin);
	printf("Apodo: "); 
	gets(personaje->apodo);
	printf("Edad: "); 
	scanf("%d", &personaje->edad);
	fflush (stdin);
	printf ("Sexo (M o F): ");
	scanf("%c", &personaje->sexo);
	fflush (stdin);
	printf ("Ocupacion: ");
	gets (personaje->ocupacion);
}

void printDatos_personaje (PERSONAJE personaje)
{
	printf ("\n\n\tNombre: %s\n\tApellidos: %s\n\tApodo: %s", personaje.nombre, personaje.apellidos, personaje.apodo);
	printf ("\n\tEdad: %d\n\tSexo: %c\n\tOcupacion: %s\n\t", personaje.edad, personaje.sexo, personaje.ocupacion);
}

void modDatos_personaje (PERSONAJE *personaje, int *p_opcion)
{
	switch (*p_opcion)
	{	
		case 1:
			fflush (stdin);
			printf ("\nNuevo nombre: ");
			gets(personaje->nombre);
			break;
		
		case 2:
			fflush (stdin);
			printf ("Nuevos apellidos: ");
			gets(personaje->apellidos);
			break;

		case 3:
			fflush (stdin);
			printf ("Nuevo apodo: ");
			gets(personaje->apodo);
			break;

		case 4:
			printf ("Nueva edad: ");
			scanf ("%d", &personaje->edad);
			break;

		case 5:
			fflush (stdin);
			printf ("Nuevo sexo (M o F): ");
			scanf ("%c", &personaje->sexo);
			break;

		case 6:
			fflush (stdin);
			printf ("Nueva ocupacion: ");
			gets(personaje->ocupacion);
			break;

		case 0:
			return;
	}
}