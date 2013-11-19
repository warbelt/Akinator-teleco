#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#include "..\\Codigo\\menú.h"
#include "..\\TADs\\respuestas.h"
#include "..\\TADs\\sListaPersonaje.h"
#include "..\\TADs\\sListaPregunta.h"
#include "..\\TADs\\sListaUsuario.h"


//PERSONAJE
	//INTRODUCIR
void introducir_personaje ()
{
	LISTA_P lista;
	int * respuestas=NULL;
	int num_preguntas;

	lista.pPersonajes=NULL;

	lista.num = numero_registros ("..\\Base de Datos\\personajes.dat", sizeof(PERSONAJE));
	if (lista.num>0)
	{
		cargarDatosPersonajes(&lista);
	}

	lista.pPersonajes = realloc(lista.pPersonajes, (1+lista.num)*sizeof(PERSONAJE));
	introDatos_personaje (&lista.pPersonajes[lista.num]);
	lista.num ++;
	guardaDatosPersonajes(lista);
	
	num_preguntas = numero_registros ("..\\Base de Datos\\preguntas.dat", sizeof(PREGUNTA));
	cargar_respuestas (respuestas);
	respuestas = realloc (respuestas, num_preguntas*lista.num);
	guardar_respuestas (respuestas);

}

	
	//MOSTRAR
void mostrar_personaje ()
{
	int i;
	LISTA_P lista;

	lista.num = numero_registros ("..\\Base de Datos\\personajes.dat", sizeof(PERSONAJE));
	if (lista.num>0)
	{
		cargarDatosPersonajes(&lista);
	}

	if(lista.num==0)
		printf("No se ha introducida ningun personaje\n");
	else
	{
		for(i=0;i<lista.num;i++)
		{
			printf ("\nPersonaje %d: ", i+1);
			printDatos_personaje(lista.pPersonajes[i]);
		}
	}
}


	//MODIFICAR
void modificar_personaje ()
{
	char nombre[20], apellidos[40];
	int opcion, i=0, encontrado=-1;
	LISTA_P lista;

	lista.num = numero_registros ("..\\Base de Datos\\personajes.dat", sizeof(PERSONAJE));
	if (lista.num>0)
	{
		cargarDatosPersonajes(&lista);
	}

	if (lista.num==0)
	{
		system ("cls");
		printf ("===================================AKINATOR===================================\n\n");
		printf ("=============================MODIFICAR PERSONAJES=============================\n\n");
		printf("No se ha introducida ningun personaje\n\n");
		system ("pause");
		return;
	}

	system ("cls");
	printf ("===================================AKINATOR===================================\n\n");
	printf ("==============================MODIFICAR PERSONAJES============================\n\n");
	mostrar_personaje ();
	fflush (stdin);
	printf("\n\nNombre del personaje que desea modificar: "); 
	gets(nombre);
	printf("Apellidos del personaje que desea modificar: "); 
	gets(apellidos);

	while(i<lista.num && encontrado==-1)
	{
		if ((strcmp(lista.pPersonajes[i].nombre, nombre)==0) && (strcmp(lista.pPersonajes[i].apellidos, apellidos)==0)) 
			{
			encontrado = i;
			}
		else i++;
	}

	if (encontrado==-1)
	{
		system ("cls");
		printf ("===================================AKINATOR===================================\n\n");
		printf ("=============================MODIFICAR PERSONAJES=============================\n\n");
		printf ("No hay ningun personaje llamado %s %s\n\n", nombre, apellidos);
		system ("pause");
	}
	
	else
	{
		do
		{
			system ("cls");
			printf ("===================================AKINATOR===================================\n\n");
			printf ("=============================MODIFICAR PERSONAJES=============================\n\n");
			printf ("\n\t1. Nombre\n");
			printf ("\t2. Apellidos\n");
			printf ("\t3. Apodo\n");
			printf ("\t4. Edad\n");
			printf ("\t5. Sexo\n");
			printf ("\t6. Ocupacion\n");
			printf ("\t0. Volver");

			printf ("\n\nIndique que atributo desea modificar: ");
			scanf ("%d", &opcion);

			modDatos_personaje (&lista.pPersonajes[i], &opcion);

		}while (opcion!=0);
	}
	guardaDatosPersonajes(lista);
}


	
	//BORRAR
void borrar_personaje ()
{
	char nombre[20], apellidos[40];
	int i=0, encontrado=-1, num_preguntas;
	int * respuestas;
	LISTA_P lista;

	lista.num = numero_registros ("..\\Base de Datos\\personajes.dat", sizeof(PERSONAJE));
	if (lista.num>0)
	{
		cargarDatosPersonajes(&lista);
	}

	if (lista.num==0)
	{
		system ("cls");
		printf ("===================================AKINATOR===================================\n\n");
		printf ("===============================BORRAR PERSONAJES==============================\n\n");
		printf("No se ha introducida ningun personaje\n\n");
		system ("pause");
		return;
	}

	system ("cls");
	printf ("===================================AKINATOR===================================\n\n");
	printf ("===============================BORRAR PERSONAJES==============================\n\n");
	mostrar_personaje ();
	fflush(stdin);
	printf("\n\nNombre del personaje a eliminar: "); gets(nombre);
	printf("Apellidos del personaje a eliminar: "); gets(apellidos);
	
	while(i<lista.num && encontrado==-1)
	{
		if ((strcmp(lista.pPersonajes[i].nombre, nombre)==0) && (strcmp(lista.pPersonajes[i].apellidos, apellidos)==0)) 
			{
			encontrado = i;
			}
		else i++;
	}
	
	if(encontrado!=-1)
	{
		for(i=encontrado;i<lista.num-1;i++)
			lista.pPersonajes[i]=lista.pPersonajes[i+1];
		lista.num--;
		system ("cls");
		printf ("===================================AKINATOR===================================\n\n");
		printf ("===============================BORRAR PERSONAJES==============================\n\n");
		printf("\nEl personaje llamado %s %s ha sido borrado\n\n", nombre, apellidos);
		system ("pause");
		
		lista.pPersonajes = realloc(lista.pPersonajes, (lista.num)*sizeof(PERSONAJE));
	}
		
	else
	{
		system ("cls");
		printf ("===================================AKINATOR===================================\n\n");
		printf ("===============================BORRAR PERSONAJES==============================\n\n");
		printf("\nNo hay ningun personaje llamado %s %s\n\n", nombre, apellidos);
		system ("pause");
	}
	guardaDatosPersonajes(lista);

	num_preguntas = numero_registros ("..\\Base de Datos\\preguntas.dat", sizeof(PREGUNTA));
	cargar_respuestas (respuestas);
	respuestas = realloc (respuestas, (num_preguntas*lista.num));
	guardar_respuestas (respuestas);
}

void guardaDatosPersonajes(LISTA_P lista)
{
	FILE *ptr;
	// Compruebo existencia de registros
	ptr = fopen("..\\Base de Datos\\personajes.dat", "wb");
	if(ptr == NULL)
	{
		printf("Error al abrir archivo %s\n", "personajes.dat");
		exit(0);
	}
	fwrite((PERSONAJE*)lista.pPersonajes, sizeof(PERSONAJE), lista.num, ptr);
	fclose(ptr);
}

void cargarDatosPersonajes (LISTA_P *lista)
{
	FILE *ptr;

	lista->num = numero_registros("..\\Base de Datos\\personajes.dat", sizeof(PERSONAJE));
	if(lista->num)
	{
		printf("Numero de personajes: %d\n", lista->num);

		lista->pPersonajes = (PERSONAJE *)calloc(sizeof(PERSONAJE), lista->num);
		if(lista->pPersonajes == NULL)
		{
			printf("No hay memoria suficiente para la lista de personajes.\n");
			exit(0);
		}
		ptr = fopen("..\\Base de Datos\\personajes.dat", "rb");
		fread((PERSONAJE*)lista->pPersonajes, sizeof(PERSONAJE), lista->num, ptr);

		fclose(ptr);
	} 
}