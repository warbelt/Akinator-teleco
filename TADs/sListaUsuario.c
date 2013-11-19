#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sListaUsuario.h"



//USUARIO
	//INTRODUCIR
void introducir_usuario ()
{
	LISTA_U lista;
	lista.pUsuarios=NULL;

	lista.num = numero_registros ("..\\Base de Datos\\usuarios.dat", sizeof(USUARIO));
	if (lista.num>0)
	{
		cargarDatosUsuarios(&lista);
	}

	lista.pUsuarios = realloc(lista.pUsuarios, (1+lista.num)*sizeof(USUARIO));
	introDatos_usuario (&lista.pUsuarios[lista.num]);
	lista.num ++;
	guardaDatosUsuarios(lista);
}


		
	//MOSTRAR
void mostrar_usuario ()
{
	int i;
	LISTA_U lista;

	lista.num = numero_registros ("..\\Base de Datos\\usuarios.dat", sizeof(USUARIO));
	if (lista.num>0)
	{
		cargarDatosUsuarios(&lista);
	}

	if(lista.num==0)
		printf("No hay usuarios registrados\n");
	else
	{
		for(i=0;i<lista.num;i++)
		{	
			printf ("\nUsuario %d: ", i+1);
			printDatos_usuario(lista.pUsuarios[i]);
		}											
	}
}

	
	//MODIFICAR
void modificar_usuario ()
{
	char alias[40];
	int opcion, i=0, encontrado=-1;
	LISTA_U lista;

	lista.num = numero_registros ("..\\Base de Datos\\usuarios.dat", sizeof(USUARIO));
	if (lista.num>0)
	{
		cargarDatosUsuarios(&lista);
	}

	if (lista.num==0)
	{
		system ("cls");
		printf ("===================================AKINATOR===================================\n\n");
		printf ("==============================MODIFICAR USUARIOS==============================\n\n");
		printf("No se ha introducida ningun usuario\n\n");
		system ("pause");
		return;
	}
	mostrar_usuario ();
	fflush (stdin);
	printf("\n\nAlias del usuario a eliminar: "); 
	gets(alias);

	while(i<lista.num && encontrado==-1)
	{
		if (strcmp(lista.pUsuarios[i].alias, alias)==0)
			{
			encontrado = i;
			}
		else i++;
	}

	if (encontrado==-1)
	{
		system ("cls");
		printf ("===================================AKINATOR===================================\n\n");
		printf ("==============================MODIFICAR USUARIOS==============================\n\n");
		printf ("No hay ningun personaje llamado %s\n\n", alias);
		system ("pause");
	}
	
	else
	{
		do
		{
			system ("cls");
			printf ("===================================AKINATOR===================================\n\n");
			printf ("==============================MODIFICAR USUARIOS==============================\n\n");
			printf ("\n\t1. Alias\n");
			printf ("\t2. Sexo\n");
			printf ("\t3. Edad\n");
			printf ("\t4. Nombre\n");
			printf ("\t5. Apellidos\n");
			printf ("\t0. Volver");

			printf ("\n\nIndique que atributo desea modificar: ");
			scanf ("%d", &opcion);

			modDatos_usuario (&lista.pUsuarios[i], &opcion);

		}while (opcion!=0);
	}
	guardaDatosUsuarios(lista);
}

	//BORRAR
void borrar_usuario ()
{
	char alias[40];
	int i=0, encontrado=-1;
	LISTA_U lista;

	lista.num = numero_registros ("..\\Base de Datos\\usuarios.dat", sizeof(USUARIO));
	if (lista.num>0)
	{
		cargarDatosUsuarios(&lista);
	}

	if (lista.num==0)
	{
		system ("cls");
		printf ("===================================AKINATOR===================================\n\n");
		printf ("================================BORRAR USUARIOS===============================\n\n");
		printf("No se ha introducida ningun usuario\n\n");
		system ("pause");
		return;
	}
	
	system ("cls");
	printf ("===================================AKINATOR===================================\n\n");
	printf ("================================BORRAR USUARIOS===============================\n\n");
	mostrar_usuario ();
	fflush(stdin);
	printf("\n\nAlias del usuario a eliminar: "); gets(alias);

	while(i<lista.num && encontrado==-1)
	{
		if(strcmp(lista.pUsuarios[i].alias, alias)==0) 
			{
			encontrado = i; 
			}
		else i++;
	}

	if(encontrado!=-1) 
	{
		for(i=encontrado;i<lista.num-1;i++)
			lista.pUsuarios[i]=lista.pUsuarios[i+1];
		lista.num--;
		system ("cls");
		printf ("===================================AKINATOR===================================\n\n");
		printf ("================================BORRAR USUARIOS===============================\n\n");
		printf("\nEl usuario llamado %s ha sido borrado\n\n", alias);
		system("pause");

		lista.pUsuarios = realloc(lista.pUsuarios, (lista.num)*sizeof(USUARIO));
	}
	else 
	{
		system ("cls");
		printf ("===================================AKINATOR===================================\n\n");
		printf ("================================BORRAR USUARIOS===============================\n\n");
		printf("\nNo hay ningún usuario llamado %s\n\n", alias);
		system ("pause");	
	}
	guardaDatosUsuarios(lista);
}

void guardaDatosUsuarios(LISTA_U lista)
{
	FILE *ptr;
	// Compruebo existencia de registros
	ptr = fopen("..\\Base de Datos\\usuarios.dat", "wb");
	if(ptr == NULL)
	{
		printf("Error al abrir archivo %s\n", "usuarios.dat");
		exit(0);
	}
	fwrite((USUARIO*)lista.pUsuarios, sizeof(USUARIO), lista.num, ptr);
	fclose(ptr);
}

void cargarDatosUsuarios(LISTA_U *lista)
{
	FILE *ptr;

	lista->num = numero_registros("..\\Base de Datos\\usuarios.dat", sizeof(USUARIO));
	if(lista->num)
	{
		
		printf("Numero de usuarios: %d\n", lista->num);

		lista->pUsuarios = (USUARIO *)calloc(sizeof(USUARIO), lista->num);
		if(lista->pUsuarios == NULL)
		{
			printf("No hay memoria suficiente para la lista de usuarios.\n");
			exit(0);
		}
		ptr = fopen("..\\Base de Datos\\usuarios.dat", "rb");
		fread((USUARIO*)lista->pUsuarios, sizeof(USUARIO), lista->num, ptr);

		fclose(ptr);
	} 
}