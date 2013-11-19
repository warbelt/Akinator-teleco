#include<stdio.h>
#include<stdlib.h>
#include"sListaUsuario.h"

void introDatos_usuario (USUARIO *usuario)
{
	fflush (stdin);
	printf("Nombre: "); 
	gets(usuario->nombre);
	fflush (stdin);
	printf("Apellidos: "); 
	gets(usuario->apellidos);
	fflush (stdin);
	printf("Alias: "); 
	gets(usuario->alias);
	fflush (stdin);
	printf("Sexo (M o F): "); 
	scanf("%c", &usuario->sexo);
	printf("Edad: "); 
	scanf("%d", &usuario->edad);
	usuario->acertados=0;
	usuario->fallados=0;
}

void printDatos_usuario (USUARIO usuario)
{
	printf ("\n\n\tNombre y apellidos: %s %s", usuario.nombre, usuario.apellidos);
	printf ("\n\tAlias: %s\n", usuario.alias);
	printf ("\tSexo: %c", usuario.sexo);
	printf ("\n\tEdad: %d", usuario.edad);
	printf ("\n\tPersonajes acertados: %d", usuario.acertados);
	printf ("\n\tPersonajes fallados: %d", usuario.fallados);
}

void modDatos_usuario (USUARIO *usuario, int *p_opcion)
{
	switch (*p_opcion)
	{	
		case 1:
			fflush (stdin);
			printf ("\nNuevo alias: ");
			gets(usuario->alias);
			break;
		
		case 2:
			fflush (stdin);
			printf ("Nuevo Sexo (M o F): ");
			scanf ("%c", &usuario->sexo);
			break;

		case 3:
			printf ("Nueva edad: ");
			scanf ("%d", &usuario->edad);
			break;

		case 4:
			printf ("Nuevo nombre: ");
			scanf ("%d", &usuario->nombre);
			break;

		case 5:
			printf ("Nuevos apellidos: ");
			scanf ("%d", &usuario->apellidos);
			break;

		case 0:
			return;
	}
}