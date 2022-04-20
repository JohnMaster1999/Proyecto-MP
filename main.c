#include <stdio.h>
#include <stdlib.h>
#include "Carga_descarga.h"
#include "Inicio_S.h"
#include "Menus.h"

int main()
{
    printf("______________________________________________________\n\tIniciando el programa...\n______________________________________________________");


    Carga_datos();

    inicio();

    menu_prin();

    Guarda_datos();

    return 0;
}
