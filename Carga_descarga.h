#ifndef SAVE_LOAD_H
#define SAVE_LOAD_H

#include "Alumnos.h"
#include "Materias.h"
#include "Usuarios.h"
#include "Horarios.h"

//void Carga_datos (Alumnos*, Materias*, Usuarios*);
//Precondicion: Recive punteros a las estrucuturas
//Postcondición: Inicializa los vectores y sus tamaños máximos
void Carga_datos (Alumnos*, Materias*, Horarios*, Usuarios*, int*, int*, int*, int*);


//void Descarga_datos (Alumnos*, Materias*, Usuarios*, int, int, int);
//Precondicion: Recive vectores de estrucuturas inicializados y escribe en los ficheros
void Descarga_datos (Alumnos*, Materias*, Horarios*, Usuarios*, int*, int*, int*,int*);

#endif
