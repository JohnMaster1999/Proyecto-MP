#ifndef OP_ADMIN_
#define OP_ADMIN_

//Precondición: Recibe como parámetros los vectores de estructuras de los módulos de estructuras.
//Postcondición: Realiza la operación que se indique (Dar de alta, Dar de baja, Modificar, Listar) con las estructuras que se le pasan.
void Menu_admin(Usuarios *prof, Alumnos *clase, Materias *mat, Horarios *hor,  int *num_alum, int *num_mat, int *num_prof, int *num_hor);
//### Cuando se llame a esta función hay que meterla en un do-while ###

#endif // OP_ADMIN_

