#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Op_mat.h"
#include "Horarios.h"
#define VHORARIOS_RESIZE vhorarios = (Horarios*) realloc(vhorarios,vhorarios_size*sizeof(Horarios));

Horarios* vhorarios;
int vhorarios_size = 1;

const char* dias[5] = {
"Lunes",
"Martes",
"Miercoles",
"Jueves",
"Viernes"
};

void horarios_darDeAlta(Horarios h)
{
  *(vhorarios+vhorarios_size-1) = h;
  vhorarios_size++;
  VHORARIOS_RESIZE
}

void horarios_darDeBaja(int pos)
{
  for(int i=pos;i<vhorarios_size-1;i++) *(vhorarios+i) = *(vhorarios+i+1);
  vhorarios_size--;
  VHORARIOS_RESIZE
}

void horarios_modificar(int pos, Horarios h)
{
  if(pos<0 || pos >= vhorarios_size) printf("Error: Id fuera de límites\n");
  else vhorarios[pos] = h;
}

void horarios_listar(int Id_P, int h, int d, char g[51], int m, int n)
/* esta función printea todos los horarios de mismo: n=2 (profesor), n=3 (materia), n=4 (grupo), n=5 (día), n=6 (hora)
n=0 (todos los horarios (simple)); n=1 (todos los horarios (verbose))
*/
{
  for(int i=0;i<vhorarios_size-1;i++)
  {
    int doprint = 0;
    switch(n)
    {
      case 2:
        if (vhorarios[i].Id_Profesor == Id_P) doprint = 1;
        break;
      case 3:
        if (vhorarios[i].Id_materia == m) doprint = 1;
        break;
      case 4:
        if (strcmp(vhorarios[i].Grupo,g)==0) doprint = 1;
        break;
      case 5:
        if (vhorarios[i].Dia_Clase == d) doprint = 1;
        break;
      case 6:
        if (vhorarios[i].Hora_Clase == h) doprint = 1;
        break;
      default:
        doprint = 1;
        break;
    }
    if (doprint)
    {
      printf("%i-%i-%i-%i-%s ID:%i\n",vhorarios[i].Id_Profesor,vhorarios[i].Dia_Clase,vhorarios[i].Hora_Clase,vhorarios[i].Id_materia,vhorarios[i].Grupo,i);
      if(n!=0)printf("(El profesor %i imparte clase de %s al grupo %s los %s la hora %i\n)",vhorarios[i].Id_Profesor,
                                                                                    materias_listar(0,vhorarios[i].Id_materia),
                                                                                    vhorarios[i].Grupo,dias[vhorarios[i].Dia_Clase-1],vhorarios[i].Hora_Clase);
    }
  }
}


Horarios horarios_crear(int Id_h,int n)
{

  Horarios h;

  printf("Introduzca el ID del profesor: ");
  scanf("%i",&h.Id_Profesor);

  printf("Introduzca el Nombre del Grupo: ");
  scanf("%s",&h.Grupo);

  int i;
  do{
    printf("Introduzca el ID de la materia (escriba -1 para listar): ");
    scanf("%i",&i);
    if (i==-1) materias_listar(3,0);
    else if (existe_materia(i) <  0)
    {
      printf("Error: Materia ID:%i no existe\n", i);
      i = -1;
    }
  }while(i == -1);
  h.Id_materia = i;

  printf("Introduzca el Dia (1 a 5) y la hora:\n ");
  scanf("%i%i",&h.Dia_Clase,&h.Hora_Clase);

  switch(n)
  {
        case 1:
          horarios_darDeAlta(h);
          break;
        case 2:
          horarios_modificar(Id_h,h);
          break;
  }
  return h;
}
