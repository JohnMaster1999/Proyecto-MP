#include "Carga_descarga.h"
#include <stdio.h>

Carga_datos (Alumnos* al, Materias* mat, Usuarios* us, int* alM, int* matM, int* usM)
{
	FILE *alum, *us, *mat, *mat, *calf, *hor;
	char c[51];

	mat=fopen("materias.txt", "r");
	if (mat==NULL)
	{
		printf("\n ERROR EN LA APERTURA DE 'materias.txt' \n");
		exit(1);
	}else
	{
		fgets (mat);

		int atributo;
		while (c!=EOF)
		{
			switch (atributo)
			{
				case 1:
					if ((int)c!=0)

					break;
				case 2:
					break;
				case 3:
					break;
				default:
					printf("Error inesperado en carga de mat");

			}

		}
	}

}
