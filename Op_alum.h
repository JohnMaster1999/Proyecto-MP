#ifndef OP_ALUMNO_
#define OP_ALUMNO_

Alumnos *clase;
int num_alum, num_mat, num_grup, num_calif;

clase = (Alumnos*)malloc(num_alum*sizeof(Alumnos));

void Selec_Alumno(Alumnos *clase, int *a);
int Lista_alum(Alumnos *clase);
void ficha_alumnos(Alumnos *clase, int  a);
void Calificaciones_alum(Alumnos *clase, int  a, int n);

#endif // OP_ALUMNO_
