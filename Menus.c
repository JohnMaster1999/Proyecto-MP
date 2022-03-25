#include "Menus.h"
#include <stdio.h>
#include <stdlib.h>

void menu_prin(Usuarios *user, int i)
{
    if(strcmp(user[i].Perf,"profesor")==0)
        menu_prof(user[i].idUs);
    if(strcmp(user[i].Perf,"administrador")==0)
        menu_admin(user[i].idUs);
}

void menu_prof(Usuarios *user, int i)
{
    printf("BIENVENIDO %s\n\n", user[i].Nomb);
    printf("Listado de grupos y materias\n------------------------------------");
    printf("Escriba el nombre de uno de los siguientes\ngrupos para seleccionarlo:\n");
    mostrar_grupos();
    seleccionar_grupo();
    menu_grupo();
}

void menu_grupo(Usuarios *, )
{
    int n, n2;
    printf("   Menu: Grupo\n%s\n---------------------------\n", grupo[k].Nom);
    printf("Selecciona una opcion:\n1.Lista de alumnos\n2.Cambiar de grupo\n");
    scanf("%d", &n);
    switch(n){
        case 1:
            printf("Lista de alumnos:\n");
            lista_alumnos();
            selec_alumn();
        case 2:
            printf("¿Seguro que deseas volver?\n1.Si  2.No");
            scanf("%d", n2);
            switch(n2){
                case 1:
                    menu_prin();
                case 2:
                    menu_grupo();

            }
    }
}

void menu_alum(Alumnos *alum)
{
    int n;
    printf("   Menu: Alumno\n%s\n---------------------------\n", alum[i].Nomb);
    printf("\n1.Ficha del alumno\n2.Calificaciones del alumno\n3.Volver\n");
    scanf("%d", &n);
    switch(n){
        case 1:
            ficha_alumnos();
        case 2:
            Calificaciones_alum();
        case 3:
            Volver_atras();
    }
}
