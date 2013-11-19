#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "akinator.h"
#include "sListaPersonaje.h"
#include "sListaUsuario.h"
#include "sListaPregunta.h"


//PREGUNTA
	//INTRODUCIR
void introducir_pregunta (LISTA_Q *lista)
{
	lista->pPreguntas = realloc(lista->pPreguntas, (lista->num+1)*sizeof(PREGUNTA));
	introDatos_pregunta(&lista->pPreguntas[lista->num]);
	(lista->num)++;
	if (lista->num==1)
		lista->pPreguntas[0].ID=1;
	else 
		lista->pPreguntas[(lista->num)-1].ID=(lista->pPreguntas[(lista->num)-2].ID)+1;
}
void introDatos_pregunta (PREGUNTA *pregunta)
{
	fflush (stdin);
	printf("\nPregunta: "); gets(pregunta->pregunta);
}
	
	//MOSTRAR
void mostrar_pregunta (LISTA_Q p_lista)
{
	int i;
	if(p_lista.num==0)
		printf("No hay preguntas introducidas\n");
	else
	{
		for(i=0;i<p_lista.num;i++)
		{
			printf ("\nPregunta %d (ID %d): ", i+1, p_lista.pPreguntas[i].ID);
			printDatos_pregunta(p_lista.pPreguntas[i]);
		}
	}
}
void printDatos_pregunta (PREGUNTA pregunta)
{
	printf ("%s\n", pregunta.pregunta);
}
	
	//BORRAR
void borrar_pregunta (LISTA_Q *p_lista)
{
	int i=0, encontrado=-1, ID;

	mostrar_pregunta (*p_lista);
	fflush(stdin);
	printf("\n\nID de la pregunta a eliminar: "); scanf ("%d", &ID);

	while(i<p_lista->num && encontrado==-1)
	{
		if (ID == p_lista->pPreguntas[i].ID)
			{
			encontrado = i; 
			}
		else i++;
	}
	
	if(encontrado!=-1) 
	{
		for(i=encontrado;i<p_lista->num-1;i++)
			p_lista->pPreguntas[i]=p_lista->pPreguntas[i+1];
		p_lista->num--;
		printf("\nLa pregunta con ID %d ha sido borrada\n", ID);
		
		p_lista->pPreguntas = realloc(p_lista->pPreguntas, (p_lista->num)*sizeof(PREGUNTA));
	}
	
	else 
		printf("No hay ninguna pregunta con el identificador %d.\n", ID);
}

//USUARIO
		//INTRODUCIR
	void introducir_usuario (LISTA_U *lista)
	{
		lista->pUsuarios = realloc(lista->pUsuarios, (lista->num+1)*sizeof(USUARIO));
		introDatos_usuario(&lista->pUsuarios[lista->num]);
		lista->num ++;
	}
	void introDatos_usuario (USUARIO *usuario)
	{
		fflush (stdin);
		printf("Alias: "); gets(usuario->alias);
		fflush (stdin);
		printf("Sexo (M o F): "); scanf("%c", &usuario->sexo);
		printf("Edad: "); scanf("%d", &usuario->edad);
	}

		
		//MOSTRAR
void mostrar_usuario (LISTA_U p_lista)
	{
		int i;
		if(p_lista.num==0)
			printf("No hay usuarios registrados\n");
		else
		{
			for(i=0;i<p_lista.num;i++)
			{	
				printf ("\nUsuario %d: ", i+1);
				printDatos_usuario(p_lista.pUsuarios[i]);
			}											
		}
}
void printDatos_usuario (USUARIO usuario)
{
	printf ("\n\n\tAlias: %s\n", usuario.alias);
	printf ("\tSexo: %c", usuario.sexo);
	printf ("\n\tEdad: %d", usuario.edad);
}
	
	//BORRAR
void borrar_usuario (LISTA_U *p_lista)
{
	char alias[40];
	int i, encontrado;

	mostrar_usuario (*p_lista);
	fflush(stdin);
	printf("\n\nAlias del usuario a eliminar: "); gets(alias);
	i=0;
	encontrado = -1;
	while(i<p_lista->num && encontrado==-1)
	{
		if(strcmp(p_lista->pUsuarios[i].alias, alias)==0) // mismo nombre
			{
			encontrado = i; // guardo el indice en encontrado
			}
		else i++;
	}
		if(encontrado!=-1) // hay un usuario con ese nombre
		{
			for(i=encontrado;i<p_lista->num-1;i++)
				p_lista->pUsuarios[i]=p_lista->pUsuarios[i+1];
			p_lista->num--;
			printf("\nEl usuario llamado %s ha sido borrado\n", alias);
			// Decremento en un usuario el nº de usuarios de la lista
			p_lista->pUsuarios = realloc(p_lista->pUsuarios, (p_lista->num)*sizeof(USUARIO));
		}
		else // no hay ningun usuario
			printf("No hay ningún usuario llamado %s.\n", alias);
}



