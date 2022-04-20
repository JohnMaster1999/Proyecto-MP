#ifndef Menus
#define Menus

#include "Op_Admin.h"
#include "Op_Prof.h"
#include "Op_alum.h"
#include "Op_mat.h"
#include "Op_usuario.h"
#include "Inicio_S.h"

//Cabecera: void menu_prin(Usuarios*, Alumnos*, Materias*, Fecha*, int)
//Precondición: recibe los punteros de las estructuras que necesita y la posicion en el vector estructura del usuario.
//Postcondición: dependiendo de si es un usuario administrador o profesor, lo envia a su respectivo menú.
void menu_prin(Usuarios*, Alumnos*, Materias*, Fecha*, int);
#endif // Menus

