#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sListaPregunta.h"


//PREGUNTA
	//INTRODUCIR
void introducir_pregunta ()
{
	LISTA_Q lista;
	lista.pPreguntas=NULL;

	lista.num = numero_registros ("..\\Base de Datos\\preguntas.dat", sizeof(PREGUNTA));
	if (lista.num>0)
	{
		cargarDatosPreguntas(&lista);
	}
	
	lista.pPreguntas = realloc(lista.pPreguntas, (lista.num+1)*sizeof(PREGUNTA));
	introDatos_pregunta(&lista.pPreguntas[lista.num]);
	
	if (lista.num==0)
		lista.pPreguntas[lista.num].ID=1;
	else
		lista.pPreguntas[lista.num].ID=lista.pPreguntas[lista.num-1].ID+1;
	(lista.num)++;
	guardaDatosPreguntas(lista);
	añadirColumnaRespuestas();
}

	
	//MOSTRAR
void mostrar_pregunta ()
{
	int i;
	LISTA_Q lista;

	lista.num = numero_registros ("..\\Base de Datos\\preguntas.dat", sizeof(PREGUNTA));
	if (lista.num>0)
	{
		cargarDatosPreguntas(&lista);
	}

	if(lista.num==0)
		printf("No se ha introducido ninguna pregunta\n");
	else
	{
		for(i=0;i<lista.num;i++)
		{
			printf ("\nPregunta %d (ID %d): ", i+1, lista.pPreguntas[i].ID);
			printDatos_pregunta(lista.pPreguntas[i]);
		}
	}
}

	
	//MODIFICAR
void modificar_pregunta ()
{
	int i=0, encontrado=-1, ID;
	LISTA_Q lista;

	lista.num = numero_registros ("..\\Base de Datos\\preguntas.dat", sizeof(PREGUNTA));
	if (lista.num>0)
	{
		cargarDatosPreguntas(&lista);
	}

	if (lista.num==0)
	{
		system ("cls");
		printf ("===================================AKINATOR===================================\n\n");
		printf ("==============================MODIFICAR PREGUNTAS=============================\n\n");
		printf("No se ha introducida ninguna pregunta\n\n");
		system ("pause");
		return;
	}

	mostrar_pregunta ();
	printf("\n\nID de la pregunta a eliminar: "); scanf ("%d", &ID);
	
	while(i<lista.num && encontrado==-1)
	{
		if (ID == lista.pPreguntas[i].ID)
			{
				encontrado = i; 
			}
		else i++;
	}

	if (encontrado==-1)
	{
		system ("cls");
		printf ("===================================AKINATOR===================================\n\n");
		printf ("==============================MODIFICAR PREGUNTAS=============================\n\n");
		printf ("No hay ninguna pregunta con ID %d\n\n", ID);
		system ("pause");
	}
	
	else
			modDatos_pregunta (&lista.pPreguntas[i]);
	guardaDatosPreguntas(lista);
}

	//BORRAR
void borrar_pregunta ()
{
	int i=0, encontrado=-1, ID;
	LISTA_Q lista;

	lista.num = numero_registros ("..\\Base de Datos\\preguntas.dat", sizeof(PREGUNTA));
	if (lista.num>0)
	{
		cargarDatosPreguntas(&lista);
	}

	if (lista.num==0)
	{
		system ("cls");
		printf ("===================================AKINATOR===================================\n\n");
		printf ("===============================BORRAR PREGUNTAS===============================\n\n");
		printf("No se ha introducida ninguna pregunta\n\n");
		system ("pause");
		return;
	}

	mostrar_pregunta ();
	printf("\n\nID de la pregunta a eliminar: "); scanf ("%d", &ID);

	while(i<lista.num && encontrado==-1)
	{
		if (ID == lista.pPreguntas[i].ID)
			{
				encontrado = i; 
			}
		else i++;
	}
	
	if(encontrado!=-1) 
	{
		for(i=encontrado;i<lista.num-1;i++)
			lista.pPreguntas[i]=lista.pPreguntas[i+1];
		lista.num--;
		system ("cls");
		printf ("===================================AKINATOR===================================\n\n");
		printf ("===============================BORRAR PREGUNTAS===============================\n\n");
		printf("\nLa pregunta con ID %d ha sido borrada\n\n", ID);
				
		lista.pPreguntas = realloc(lista.pPreguntas, (lista.num)*sizeof(PREGUNTA));
	}
	
	else 
	{
		system ("cls");
		printf ("===================================AKINATOR===================================\n\n");
		printf ("===============================BORRAR PREGUNTAS===============================\n\n");
		printf("\nNo hay ninguna pregunta con el identificador %d\n\n", ID);
		system ("pause");
	}
	guardaDatosPreguntas(lista);
}

void guardaDatosPreguntas(LISTA_Q lista)
{
	FILE *ptr;
	// Compruebo existencia de registros
	ptr = fopen("..\\Base de Datos\\preguntas.dat", "wb");
	if(ptr == NULL)
	{
		printf("Error al abrir archivo %s\n", "preguntas.dat");
		exit(0);
	}
	fwrite((PREGUNTA*)lista.pPreguntas, sizeof(PREGUNTA), lista.num, ptr);
	fclose(ptr);
}

void cargarDatosPreguntas (LISTA_Q *lista)
{
	FILE *ptr;

	lista->num = numero_registros("..\\Base de Datos\\preguntas.dat", sizeof(PREGUNTA));
	if(lista->num)
	{
		printf("Numero de preguntas: %d\n", lista->num);

		lista->pPreguntas = (PREGUNTA *)calloc(sizeof(PREGUNTA), lista->num);
		if(lista->pPreguntas == NULL)
		{
			printf("No hay memoria suficiente para la lista de preguntas.\n");
			exit(0);
		}
		ptr = fopen("..\\Base de Datos\\preguntas.dat", "rb");
		fread((PREGUNTA*)lista->pPreguntas, sizeof(PREGUNTA), lista->num, ptr);

		fclose(ptr);
	} 
}