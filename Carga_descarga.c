#include "Carga_descarga.h"
#include <stdio.h>

Carga_datos (Alumnos* al, Materias* mat, Usuarios* us, int* alM, int* matM, int* usM)
{
	FILE *alum, *us, *mat, *calf, *hor;
	int cmax = 51;
	char c[cmax];

	us = fopen ("usuario.txt", "r");

	if (us == NULL)
	{
		printf("\nSe ha producido un error en la apertura del fichero: usuarios.txt\n");
		exit (1);
	}else{ //USUARIOS.txt abierto exitosamente
		fgets
	}


}
