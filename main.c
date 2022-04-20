#include <stdio.h>
#include <stdlib.h>
#include "Carga_descarga.h"
#include "Inicio_S.h"
#include "Menus.h"

int main()
{
    printf("______________________________________________________\n\tIniciando el programa...\n______________________________________________________");
    
    Alumnos* al;
    Materias* mate;
    Horarios* hor;
    Usuarios* usu;
    int alM, matM, horM, usM, n;

    Carga_datos(al, mate, hor, usu, &alM, &matM, &horM, &usM);

    n = inicio(usu, usM);

    menu_prin(usu, al, mate, hor, n);

    Guarda_datos(al, mate, hor, usu, &alM, &matM, &horM, &usM);

    return 0;
}
