#pragma once

typedef struct sPregunta
{
	char pregunta[200];
	int ID;
}PREGUNTA;

void printDatos_pregunta (PREGUNTA pregunta);
void modDatos_pregunta (PREGUNTA *pregunta);
void introDatos_pregunta (PREGUNTA *pregunta);