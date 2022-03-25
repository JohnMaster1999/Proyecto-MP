#ifndef Menus
#define Menus

#include Op_Admin.h
#include Op_Prof.h
#include Op_alum.h
#include Op_mat.h
#include Op_usuario.h
#include Inicio_S.h

//Cabecera: void menu_prin(Usuarios *,int).
//Precondición: recibe la estructura de los profesores y la posicion en el vector estructura del usuario.
//Postcondición: dependiendo de si es un usuario administrador o profesor, lo envia a su respectivo menú.
void menu_prin(Usuarios *,int);
//Cabecera: void menu_prof(Usuarios *,int).
//Precondición: recibe el id de usuario.
//Postcondición: opera con los grupos a los que imparte clases.
void menu_prof(int);
//Cabecera: void menu_grupo(Usuarios *,int).
//Precondición: el id de usuario.
//Postcondición: opera con los grupos a los que imparte clases.
void menu_grupo(int);
//Cabecera: void menu_alumn(Alumnos *).
//Precondición:recibe la estructura de alumnos.
//Postcondición:opera con los alumnos.
void menu_alumn();
//Cabecera: void menu_admin().
//Precondición:
//Postcondición:
void menu_admin();

#endif // Menus
