#ifndef Menus
#define Menus

#include Op_Admin.h
#include Op_Prof.h
#include Op_alum.h
#include Op_mat.h
#include Op_usuario.h
#include Inicio_S.h

//Cabecera: void menu_prin(Usuarios*, Alumnos*, Materias*, Fecha*, int)
//Precondición: recibe los punteros de las estructuras que necesita y la posicion en el vector estructura del usuario.
//Postcondición: dependiendo de si es un usuario administrador o profesor, lo envia a su respectivo menú.
void menu_prin(Usuarios*, Alumnos*, Materias*, Fecha*, int);
//Cabecera: void menu_prof(Usuarios*, Alumnos*, Fecha*, int)
//Precondición: recibe los punteros de las estructuras que necesita y la posicion en el vector estructura del usuario.
//Postcondición: selecciona un grupo y llama al menu de grupos.
void menu_prof(Usuarios*, Alumnos*, Fecha*, int);
//Cabecera: void menu_grupo(Usuarios*, Alumnos*, Fecha*, int, int);
//Precondición: recibe los punteros de las estructuras que necesita y la posicion en el vector estructura de usuarios y de fecha.
//Postcondición: opera con los grupos a los que imparte clases, devuelve 1 si tiene que continuar o 0 si vuelve al anterior menú,
//selecciona a un alumno y llama al menu de alumnos.
int menu_grupo(Usuarios*, Alumnos*, Fecha*, int, int);
//Cabecera: void menu_alumn(Alumnos*, Fecha*, int, int);
//Precondición:recibe los punteros de las estructuras que necesita y la posicion en el vector estructura de fechas y de alumnos.
//Postcondición:opera con los alumnos.
void menu_alumn(Alumnos*, Fecha*, int, int);
//Cabecera: void Menu_admin(Usuarios*, Alumnos*, Materias*, Fecha*)
//Precondición:recibe los punteros de las estructuras que necesita.
//Postcondición: va llamando a las correspondientes operaciones del administrador.
void Menu_admin(Usuarios*, Alumnos*, Materias*, Fecha*);
#endif // Menus

