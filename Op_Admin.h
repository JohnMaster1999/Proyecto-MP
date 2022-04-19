#ifndef OP_ADMIN_
#define OP_ADMIN_

Alumnos *clase;
Usuarios *prof;
Materias *mat;
Fecha *hor;

int num_prof, num_alum, num_mat, num_hor;

prof = (Usuarios*)malloc(num_prof*sizeof(Usuarios));
clase = (Alumnos*)malloc(num_alum*sizeof(Alumnos));
mat = (Materias*)malloc(num_mat*sizeof(Materias));
clase = (Fecha*)malloc(num_hor*sizeof(Fecha));

#endif // OP_ADMIN_
