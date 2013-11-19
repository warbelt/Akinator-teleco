#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menú.h"
#include "..\\TADs\\respuestas.h"
#include "..\\TADs\\sListaPersonaje.h"
#include "..\\TADs\\sListaPregunta.h"
#include "..\\TADs\\sListaUsuario.h"

void menus()
{
	int opcion1, opcion2, accion;
	
	do
	{
		system ("cls");
		printf ("===================================AKINATOR===================================\n\n");
		printf ("================================MENU PRINCIPAL================================\n\n");
		printf("1. Mantenimiento\n");
		printf("2. Jugar\n");
		printf("0. Salir\n");
		printf ("\nSeleccione la accion que desee realizar y teclee Intro: ");
		scanf("%d", &opcion1); 

		switch (opcion1)
		{
		case 0: 
			break;

		case 1:

			do
			{
				system ("cls");
				printf ("===================================AKINATOR===================================\n\n");
				printf ("================================MANTENIMIENTO================================\n\n");
				printf("\t1. Mantenimiento de personajes\n");
				printf("\t2. Mantenimiento de preguntas\n");
				printf("\t3. Mantenimiento de usuarios\n");
				printf("\t0. Volver al menu principal\n");
						
				printf ("\nSeleccione la accion que desee realizar y teclee Intro: ");
				scanf("%d", &opcion2); 

				switch (opcion2)
				{
				case 0:
					printf ("\n");
					break;

				//MANTENIMIENTO PERSONAJE
				//
				//
				case 1:

					do
					{
						system ("cls");
						printf ("===================================AKINATOR===================================\n\n");
						printf ("==========================MANTENIMIENTO DE PERSONAJES==========================\n\n");
						printf ("\t\t1. Insertar personaje\n");
						printf ("\t\t2. Ver todos los personajes\n");
						printf ("\t\t3. Modificar personaje\n");
						printf ("\t\t4. Borrar personaje\n");
						printf ("\t\t0. Volver al menu de mantenimiento\n\n");

						printf ("Seleccione la accion que desee realizar y teclee Intro: ");
						scanf ("%d", &accion);

						switch (accion)
						{
							case 0:
								printf ("\n");
								break;

							case 1:
								system ("cls");
								printf ("===================================AKINATOR===================================\n\n");
								printf ("==============================INSERTAR PERSONAJE==============================\n\n");
								introducir_personaje ();
								break;

							case 2:
								system ("cls");
								printf ("===================================AKINATOR===================================\n\n");
								printf ("==============================MOSTRAR PERSONAJES==============================\n\n");
								mostrar_personaje ();
								printf ("\n");
								system ("pause");
								break;

							case 3:
								system ("cls");
								printf ("===================================AKINATOR===================================\n\n");
								printf ("=============================MODIFICAR PERSONAJES=============================\n\n");
								modificar_personaje ();
								break;

							case 4: 
								system ("cls");
								printf ("===================================AKINATOR===================================\n\n");
								printf ("===============================BORRAR PERSONAJES==============================\n\n");
								borrar_personaje ();
								break;
						
							default: 
								printf("\nAccion imposible de realizar\n\n");
								system ("pause");
						}								
					}while (accion !=0);
					break;

				//MANTENIMIENTO PREGUNTA
				//
				//
				case 2:	
					do
					{	
						system ("cls");
						printf ("===================================AKINATOR===================================\n\n");
						printf ("==========================MANTENIMIENTO DE PREGUNTAS==========================\n\n");
						printf ("\t\t1. Insertar pregunta\n");
						printf ("\t\t2. Ver todas las preguntas\n");
						printf ("\t\t3. Modificar pregunta\n");
						printf ("\t\t4. Borrar pregunta\n");
						printf ("\t\t0. Volver al menu de mantenimiento\n\n");

						printf ("Seleccione la accion que desee realizar y teclee Intro: ");
						scanf ("%d", &accion);

						switch (accion)
						{
							case 0:
								printf ("\n");
								break;
							
							case 1:
								system ("cls");
								printf ("===================================AKINATOR===================================\n\n");
								printf ("==============================INSERTAR PREGUNTA===============================\n\n");
								introducir_pregunta ();
								break;

							case 2:
								system ("cls");
								printf ("===================================AKINATOR===================================\n\n");
								printf ("===============================MOSTRAR PREGUNTAS==============================\n\n");
								mostrar_pregunta ();
								printf ("\n");
								system ("pause");
								break;

							case 3:
								system ("cls");
								printf ("===================================AKINATOR===================================\n\n");
								printf ("==============================MODIFICAR PREGUNTAS=============================\n\n");
								modificar_pregunta ();
								break;

							case 4: 
								system ("cls");
								printf ("===================================AKINATOR===================================\n\n");
								printf ("===============================BORRAR PREGUNTAS===============================\n\n");
								borrar_pregunta();
								break;
						
							default: 
								printf("\nAccion imposible de realizar\n\n");
								system ("pause");
						}
					}while (accion !=0);
					break;

				//MANTENIMIENTO USUARIO
				//
				//
				case 3:
					do
					{
						system ("cls");
						printf ("===================================AKINATOR===================================\n\n");
						printf ("===========================MANTENIMIENTO DE USUARIOS==========================\n\n");
						printf ("\t\t1. A%cadir jugador\n", 164);
						printf ("\t\t2. Ver todos los jugadores\n");
						printf ("\t\t3. Modificar jugador\n");
						printf ("\t\t4. Borrar jugador\n");
						printf ("\t\t0. Volver al menu de mantenimiento\n\n");

						printf ("Seleccione la accion que desee realizar y teclee Intro: ");
						scanf ("%d", &accion);

						switch (accion)
						{
							case 0:
								printf ("\n");
								break;

							case 1:
								system ("cls");
								printf ("===================================AKINATOR===================================\n\n");
								printf ("================================A%cADIR USUARIO===============================\n\n", 165);
								introducir_usuario ();
								break;

							case 2:
								system ("cls");
								printf ("===================================AKINATOR===================================\n\n");
								printf ("===============================MOSTRAR USUARIOS===============================\n\n");
								mostrar_usuario ();
								printf ("\n\n");
								system ("pause");
								break;

							case 3:
								system ("cls");
								printf ("===================================AKINATOR===================================\n\n");
								printf ("==============================MODIFICAR USUARIOS==============================\n\n");
								modificar_usuario ();
								break;

							case 4: 
								system ("cls");
								printf ("===================================AKINATOR===================================\n\n");
								printf ("================================BORRAR USUARIOS===============================\n\n");
								borrar_usuario ();
								break;
							
							default: 
								printf("\nAccion imposible de realizar\n\n");
								system ("pause");
						}							
					}while (accion !=0);
						break;

				default:
					printf("\nHa introducido una opcion no valida.\n\n");
					system ("pause");
				}
			} while (opcion2 != 0);
			break;

		case 2:
			system ("cls");
			printf ("===================================AKINATOR===================================\n\n");
			printf ("====================================JUGAR=====================================\n\n");
			jugar();
			system ("pause");
			break;

		default:
			printf("\nAccion imposible de realizar\n\n");
			system ("pause");

		}
	}
	while (opcion1 != 0);
}

int numero_registros(char *archivo, int tam)
{
	FILE *ptr;
	int nbytes, nreg;

	ptr = fopen(archivo, "r");
	if(ptr == NULL) return 0; 
	fseek(ptr, 0, SEEK_END);
	nbytes = ftell(ptr);
	fclose(ptr);
	nreg = nbytes/tam;
	return nreg;
}


void jugar ()
{
	int *resp_usuario=NULL;
	int i=0, coincidencias, posicion_personaje, encontrado;
	char alias[20];
	LISTA_Q lista_preguntas;
	USUARIO usuario;
	int opcion;
	printf("\n\t1.Nuevo usuario.");
	printf("\n\t2.Iniciar sesion.");
	printf ("\n\t0. Volver al menu de mantenimiento\n\n");

	scanf("%d", &opcion);
	switch(opcion)
	{
	case 1:
		introducir_usuario();
		break;
	case 2:
		mostrar_usuario();
		printf("Introduzca su alias: ");
		gets(alias);
		break;
	case 0:
		printf ("\n");
		return;
	default:
		printf("\nHa introducido una opcion no valida.\n\n");
		system("pause");
		return;
	}

	cargarDatosPreguntas (&lista_preguntas);

	while(i<lista_preguntas.num && encontrado!=1)
	{
		resp_usuario = realloc (resp_usuario, sizeof (int)*(i+1));
		
		resp_usuario[i]= preguntar(lista_preguntas.pPreguntas[i]);

		coincidencias = comparar (resp_usuario, &posicion_personaje);
		
		adivinar (coincidencias, posicion_personaje, i, &encontrado);
		i++;

	}
	system ("pause");
	return;
}

