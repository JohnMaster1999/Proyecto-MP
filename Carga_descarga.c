#include "Carga_descarga.h"
#include <stdio.h>

Carga_datos (Alumnos* al, Materias* mate, Usuarios* usu, int* alM, int* matM, int* usM)
{
	FILE *alum, *us, *mat, *calf, *hor;
	int cmax = 59;
	char c[cmax];
	*usM = 1; matM = 1;
	int i, j;


	us = fopen ("usuario.txt", "r");


	if (us == NULL)
	{
		puts("Se ha producido un error en la apertura del fichero: usuarios.txt");
		exit (1);
	}else
	{ //USUARIOS.txt abierto exitosamente
		while(fgets(c, cmax, us)!=NULL)
		{
			usu = (Usuarios*) realloc(usu, *usM * sizeof(Usuarios));
			j=0;
			do
			{
				usu[*usM-1].Nomb[j] = c[i];
				i++; j++;
			}while(c[i]!='-');
			usu[*usM-1].Nomb[j] = '/0';
			i++;

			j=0;
			do
			{
				usu[*usM-1].Perf[j] = c[i];
				i++; j++;
			}while(c[i]!='-');
			usu[*usM-1].Perf[j] = '/0';
			i++;

			j=0;
			do
			{
				usu[*usM-1].NomU[j] = c[i];
				i++; j++;
			}while(c[i]!='-');
			usu[*usM-1].NomU[j] = '/0';
			i++;

			j=0;
			do
			{
				usu[*usM-1].pass[j] = c[i];
				i++; j++;
			}while(c[i]!= '/0');
			usu[*usM-1].pass[j] = '/0';
			i=0;
			*usM++;

		}
		fclose(us);
	}

	mat = fopen ("materias.txt", "r");

	if (mat == NULL)
	{
		puts("Se ha producido un error en la apertura del fichero: materias.txt");
		exit (1);
	}else
	{//MATERIAS.TXT abierto exitosamente
		while(fgets(c, cmax, mat) != NULL)
		{
			mate = (Materias*) realloc(mate, *matM * sizeof(Materias));
			j = 0;
			char id[4]
			do
			{
				id[j] = c[i];
				i++; j++;
			}while(c[i]!='-');
			sscanf(id, "%d", &mate[*matM-1].Id_materia);
			i++;

			j = 0;
			do
			{
				mate[*matM-1].Nombre_Materia[j] = c[i];
				i++; j++;
			}while (c[i] != '-');
			mate[*matM-1].Nombre_Materia[j] = '/0';
			i++;

			j = 0;
			do
			{
				mate[*matM-1].Abrev_materia[j] = c[i];
				i++; j++;
			}while (c[i] != '/0');
			mate[*matM-1].Abrev_materia[j] = '/0';
			i = 0;


		}
	}


}
