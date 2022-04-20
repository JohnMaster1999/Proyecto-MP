#ifndef OP_ALUMNO_
#define OP_ALUMNO_

//Precondición: Recibe como parámetros la estructura de alumnos y una variable por referencia.
//Postcondición: Se modifica el valor de la variable en un paso por referencia.
void Selec_Alumno(Alumnos *clase, int *a);

//Precondición: Recibe como parámetros el vector de la estructura de Alumnos.
//Postcondición: Imprime una lista de los alumnos (elementos del vector de estructura Alumnos).
int Lista_alum(Alumnos *clase);

//Precondición: Recibe como parámetros la estructura de alumnos y dos variables.
//Postcondición: Imprime los datos del alumno y permite modificarlos.
void ficha_alumnos(Alumnos *clase, int  a, int n);

//Precondición: Recibe como parámetros la estructura de alumnos y dos variables.
//Postcondición: Imprime una lista de los alumnos (y una vez seleccionado) modifica, borra o crea las calificaciones del alumno.
void Calificaciones_alum(Alumnos *clase, int  a, int n);

#endif // OP_ALUMNO_
