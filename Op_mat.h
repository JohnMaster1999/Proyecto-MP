#include "Materias.h"
#ifndef __OP_MAT_H
#define __OP_MAT_H

void materias_darDeAlta(Materias m);
void materias_darDeBaja(int Id_mat);
void materias_modificar(int Id_mat,Materias m);
char* materias_listar(int n, int Id_mat);
int existe_materia(int Id_mat);
Materias materias_crear(int Id_mat,int n);


extern Materias* vmaterias; //vector dinámico de materias
extern int vmaterias_size; //int que almacena constantemente su tamaño,
//extern permite que pueda ser incluido en los demás archivos de código y al compilarse no detecte las menciones de vmaterias
// y vmaterias_size como definiciones múltiples

#endif
