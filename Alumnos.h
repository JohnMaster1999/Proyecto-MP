#ifndef ALUMNOS_H
#define ALUMNOS_H

#include "Fecha.h"

typedef struct Calif
{
	Fecha Fech_calif;
	char Desc_calif [31];
	int Id_materia;
	int Id_amun;
	int Valor_calif;
} Calif;

typedef struct Mat_Alum
{
	char Mat[51];
	Calif* Calf_;
	int nCal;

}Mat_Alum;

typedef struct Alumnos
{
	int idUs;
	char Nomb[21];
	char Dir[31];
	char Loc[31];
	char Curso[31];
	char Grup[11];
	Mat_Alum* Materias;
	int nMat;

}Alumnos;


#endif
