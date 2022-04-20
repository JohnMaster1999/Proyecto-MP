#ifndef OP_ADMIN_
#define OP_ADMIN_

Alumnos *clase; // Vector de la estructura Alumnos.
Usuarios *prof; // Vector de la estructura Usuarios.
Materias *mat; // Vector de la estructura Materias.
Fecha *hor; // Vector de la estructura Fecha.
int num_prof, num_alum, num_mat, num_hor; //Variables que almacenan el tamaño de las distintas estructuras.

prof = (Usuarios*)malloc(num_prof*sizeof(Usuarios));
clase = (Alumnos*)malloc(num_alum*sizeof(Alumnos));
mat = (Materias*)malloc(num_mat*sizeof(Materias));
clase = (Fecha*)malloc(num_hor*sizeof(Fecha));

//Precondición: Recibe como parámetros los vectores de estructuras de los módulos de estructuras.
//Postcondición: Realiza la operación que se indique (Dar de alta, Dar de baja, Modificar, Listar) con las estructuras que se le pasan.
void Menu_admin(Usuarios *prof, Alumnos *clase, Materias *mat, Fechas *hor); // (Menús)

#endif // OP_ADMIN_

