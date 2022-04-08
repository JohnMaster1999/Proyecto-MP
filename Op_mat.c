#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Materias.h"
#define VMATERIAS_RESIZE vmaterias = (Materias*) realloc(vmaterias,vmaterias_size*sizeof(Materias));

Materias* vmaterias; //vector dinÃ¡mico de materias
int vmaterias_size = 1; //int que almacena constantemente su tamaÃ±o

int existe_materia(int Id_mat)
{
  int n = 0;
  int exists = 1;

  while(vmaterias[n].Id_materia != Id_mat)
  {
    if (n==vmaterias_size) {exists = 0; break;}
    n++;
  }
  if (exists) return n;
  else return -1;
}

void materias_darDeAlta(Materias m)
{
  *(vmaterias+vmaterias_size-1) = m;
  vmaterias_size++;
  VMATERIAS_RESIZE
  //printf("(%s->%s)\n",m.Nombre_Materia,vmaterias[vmaterias_size-2].Nombre_Materia); LÃ­nea de debug
}

void materias_darDeBaja(int Id_mat)
{
  int n = existe_materia(Id_mat);
  if(n>=0)
  {
    for(int i=n;i<vmaterias_size-1;i++) *(vmaterias+i) = *(vmaterias+i+1);
    vmaterias_size--;
    VMATERIAS_RESIZE
  } else printf("Error: Materia de ID:%i no encontrada\n",Id_mat);
}

void materias_modificar(int Id_mat,Materias m)
{
  int n = existe_materia(Id_mat);
  if(n>=0) vmaterias[n] = m;
  else printf("Error: Materia de ID:%i no encontrada\n",Id_mat);
}

char* materias_listar(int n, int Id_mat)
/*n = 0 -> retorna el nombre de la materia del ID; n = 1 -> retorna la abreviaciÃ³n de la materia del ID;
n = 2 -> printea toda la informaciÃ³n de todas las materias; n = 3 -> printea el id y nombre de todas las materias*/
{
  int o = existe_materia(Id_mat);
  if(o < 0 && n <= 1) return "(Error: Materia no existe)";
  if(n==3) printf("ID  | NOMBRE\n");
  for(int i=0;i<vmaterias_size-1;i++)
  {
    if(n<=1)
    {
      switch (n)
      {
        case 0:
          return vmaterias[o].Nombre_Materia;
          break;
        case 1:
          return vmaterias[o].Abrev_materia;
          break;
      }
      break;
    }else {
      switch (n)
      {
        case 2:
          printf("\nId: %i\nNombre: %s\nAbrev: %s\n",vmaterias[i].Id_materia,vmaterias[i].Nombre_Materia,vmaterias[i].Abrev_materia);
          break;
        case 3:
          printf("%i | %s\n",vmaterias[i].Id_materia,vmaterias[i].Nombre_Materia);
          break;
      }
    }
  }
}

Materias materias_crear(int Id_mat,int n)
{

  Materias m;

  int id;
  int loop;
  do
  {
  	loop = 0;
  	printf("Introduzca el ID: ");
  	scanf("%i",&id);
  	switch (n)
  	{
  		case 0:
		case 1:
			if (existe_materia(id)>=0) 
			{
				printf("Error: Materia de id %i (%s) ya existe\n",id,vmaterias[existe_materia(id)].Abrev_materia);
				loop = 1;
			}
			break;
		case 2:
			if(existe_materia(id)>=0 && id != Id_mat)
			{
				printf("Error: No se puede sustituir el id %i por el %i de la materia (%s) ya existente\n",Id_mat,id,vmaterias[existe_materia(id)].Abrev_materia);
				loop = 1;
			}
	}
  }while(loop);
  m.Id_materia = id;

  printf("Introduzca el Nombre: ");
  scanf("%s",&m.Nombre_Materia);

  printf("Introduzca la abreviatura: ");
  scanf("%s",&m.Abrev_materia);

  printf("\n");

  switch(n)
  {
        case 1:
          materias_darDeAlta(m);
          break;
        case 2:
          materias_modificar(Id_mat,m);
          break;
  }
  return m;
}
