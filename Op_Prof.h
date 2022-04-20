#ifndef OP_PROFESOR_
#define OP_PROFESOR_

// Precondición: Recibe un entero que sirve como índice para un alumno seleccionado.
// Postcondición: Permite modificar los distintos campos de la Estructura Alumno.
void Modificar_ficha(int index);

// Precondición: Recibe como parámetros el vector de la estructura de alumnos y un entero que indica el numero de grupos
// Postcondición: Permite listar alumnos o cambiar de grupo.
void Menu_Grupo(Alumnos *clase, int n);

#endif // OP_PROFESOR_
