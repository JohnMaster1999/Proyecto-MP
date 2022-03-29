#include "Materias.h"
#ifndef __OP_MAT_H
#define __OP_MAT_H

void materias_darDeAlta(Materias m);
void materias_darDeBaja(int Id_mat);
void materias_modificar(int Id_mat,Materias m);
char* materias_listar(int n, int Id_mat);
int existe_materia(int Id_mat);

extern Materias* vmaterias; //vector dinÃ¡mico de materias
extern int vmaterias_size; //int que almacena constantemente su tamaÃ±o,
//extern permite que pueda ser incluido en los demÃ¡s archivos de cÃ³digo y al compilarse no detecte las menciones de vmaterias
// y vmaterias_size como definiciones mÃºltiples

#endif
