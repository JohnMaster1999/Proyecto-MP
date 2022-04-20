#include "Carga_descarga.h"
#include <stdio.h>

void carga_usu(Usuarios* usu, int* max)
{
	FILE * us;
	//int cmax = 59;
	char c[59];
	*max = 1;
	int i, j;


	us = fopen ("usuario.txt", "r");


	if (us == NULL)
	{
		puts("Se ha producido un error en la apertura del fichero: usuarios.txt");
		exit (1);
	}else
	{ //USUARIOS.txt abierto exitosamente
		while(fgets(c, 59, us)!=NULL)
		{
			usu = (Usuarios*) realloc(usu, *max * sizeof(Usuarios));
			j=0;
			do
			{
				usu[*max-1].Nomb[j] = c[i];
				i++; j++;
			}while(c[i]!='-');
			usu[*max-1].Nomb[j] = '/0';
			i++;

			j=0;
			do
			{
				usu[*max-1].Perf[j] = c[i];
				i++; j++;
			}while(c[i]!='-');
			usu[*max-1].Perf[j] = '/0';
			i++;

			j=0;
			do
			{
				usu[*max-1].NomU[j] = c[i];
				i++; j++;
			}while(c[i]!='-');
			usu[*max-1].NomU[j] = '/0';
			i++;

			j=0;
			do
			{
				usu[*max-1].pass[j] = c[i];
				i++; j++;
			}while(c[i]!= '/0');
			usu[*max-1].pass[j] = '/0';
			i=0;
			*max++;

		}
		fclose(us);
	}

}

void carga_mat(Materias* mate, int* max)
{
	FILE * mat;
	//int cmax = 59;
	char c[59];
	*max = 1;
	int i, j;

	mat = fopen ("materias.txt", "r");

	if (mat == NULL)
	{
		puts("Se ha producido un error en la apertura del fichero: materias.txt");
		exit (1);
	}else
	{//MATERIAS.TXT abierto exitosamente
		while(fgets(c, 59, mat) != NULL)
		{
			mate = (Materias*) realloc(mate, *max * sizeof(Materias));
			j = 0;
			char id[4];
			do
			{
				id[j] = c[i];
				i++; j++;
			}while(c[i]!='-');
			sscanf(id, "%d", &mate[*max-1].Id_materia);
			i++;

			j = 0;
			do
			{
				mate[*max-1].Nombre_Materia[j] = c[i];
				i++; j++;
			}while (c[i] != '-');
			mate[*max-1].Nombre_Materia[j] = '/0';
			i++;

			j = 0;
			do
			{
				mate[*max-1].Abrev_materia[j] = c[i];
				i++; j++;
			}while (c[i] != '/0');
			mate[*max-1].Abrev_materia[j] = '/0';
			i = 0;


		}
	}
}

void carga_hor(Horarios* h, int* max);

void carga_al(Alumnos* al, int* max);


void Carga_datos (Alumnos* al, Materias* mate, Horarios* hor, Usuarios* usu, int* alM, int* matM, int* horM, int* usM)
{
	carga_al(al, alM);
	carga_usu(usu, usM);
	carga_mat(mate, matM);
}
