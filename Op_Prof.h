#ifndef OP_PROFESOR_
#define OP_PROFESOR_

Alumnos *clase;
int num_alum, num_mat, num_grup;

clase = (Alumnos*)malloc(num_alum*sizeof(Alumnos));

void Modificar_ficha(int index);

#endif // OP_PROFESOR_
