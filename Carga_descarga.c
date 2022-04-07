#include "Carga_descarga.h"
#include <stdio.h>

Carga_datos (Alumnos* al, Materias* mate, Usuarios* usu, int* alM, int* matM, int* usM)
{
	FILE *alum, *us, *mat, *calf, *hor;
	int cmax = 51;
	char c[cmax];
	*usM = 1;
	int i;


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
			int j=0;
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
			}while(c[i]!= EOF);
			usu[*usM-1].pass[j] = '/0';
			i=0;
			*usM++;

		}
		fclose(us);
	}

	mat = fopen ("materias.txt", "r");

	if (mat == NULL)
	{
		puts("Se ha producido un error en la apertura del fichero: usuarios.txt");
		exit (1);
	}else
	{//MATERIAS.TXT abierto exitosamente

	}


}
