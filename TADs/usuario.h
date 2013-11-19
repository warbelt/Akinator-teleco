#pragma once

typedef struct sUsuario
{
	char nombre[20], apellidos[40], alias[20], sexo;
	int edad, acertados, fallados;
}USUARIO;

void printDatos_usuario (USUARIO usuario);
void modDatos_usuario (USUARIO *usuario, int *p_opcion);
void introDatos_usuario (USUARIO *usuario);