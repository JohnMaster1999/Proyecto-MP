#include "Menus.h"

#include <stdio.h>
#include <stdlib.h>

void menu_prin(Usuarios *user, Alumnos *alum, Materias *mat, Horarios *fech, int i, int* alM, int* matM, int* horM, int* usM, int* salir)
{
    if(strcmp(user[i].Perf,"profesor")==0)//Si nuestro usuario es profesor abre el menu de profesor.
        menu_prof(user, alum, fech, i);
    if(strcmp(user[i].Perf,"administrador")==0)//Si nuestro usuario es admin abre el menú de administrador.
        do{
	    Menu_admin(user, alum, fech, mat, &alM, &matM, &horM, &usM, &salir);
	}while(salir == 1);
}

void menu_prof(Usuarios *user, Alumnos *alum, int i)
{
    int j;
    printf("BIENVENIDO %s\n\n", user[i].Nomb);
    printf("Listado de grupos y materias\n______________________________________________________");
    j = Lista_Grupos(alum); //Devuelve la posición en el vector de alumnos.
    menu_grupo(alum, j); //Abre el menú de grupos.
}

int menu_grupo(Alumnos *alum, int i)
{
    int n, op;

    printf("\t1.Lista de Alumnos\n");
    printf("\t2.Cambiar de grupo\n\n");

    printf("Indique una opci%cn: ", 162);
    scanf("%d", &op);

    switch(op)
    {
        case 1:           //Muestra la lista de los alumnos, selecciona uno y se abre el menú de alumnos.
        {
            Lista_alum(alum);
            Selec_Alumno(alum, &n);
            menu_alum(alum, n, i);
        }
        break;

        case 2:           //Cambia de grupo
        {
            int c;

            printf("%cEst%c seguro que desea cambiar de grupo?: (s/n)\n", 168, 160);
            scanf("%c", &c);

            if( c == 's')
                Lista_Grupos(alum);
            else
                Menu_Grupo(alum, i);
        }
        break;
    }
}

void menu_alum(Alumnos *alum, int n, int i)
{
    int p;
    printf("\tMenu: Alumno\n%s\n______________________________________________________\n", alum[n].Nomb);
    printf("\n\t1.Ficha del alumno\n\t2.Calificaciones del alumno\n\t3.Volver\n");
    scanf("%d", &p);
    switch(p){
        case 1:
            ficha_alumnos(alum, n, i);  //Muestra los datos del alumno
            break;
        case 2:
            Calificaciones_alum(alum, n, i); //Muestra las calificaciones del alumno
            break;
        case 3:
            {
            int c;

            printf("%cEst%c seguro que desea volver atr%cs?: (s/n)\n", 168, 160, 160);
            scanf("%c", &c);

            if( c == 's')
                menu_grupo(alum, i);  //Vuelve al menú de grupo.
            else
                menu_alum(alum, n, i); //Se reinicia el menu de alumno.
        }
        break;
    }
}


void Menu_admin(Usuarios *user, Alumnos *alum, Horarios *fech, Materias *mat, int* alM, int* matM, int* horM, int* usM, int* salir)
{
	int op;

    printf("\tMenu: Administrador\n______________________________________________________\n\n");
    printf("\t1.-Usuarios.\n");
    printf("\t2.-Alumnos.\n");
    printf("\t3.-Materias.\n");
    printf("\t4.-Horarios.\n\n");

    printf("Indique su opci%cn: ", 162);
    scanf("%d", &op);

    switch(op)
    {
        case 2: //Entra en el menú de edición de alumnos del administrador.
        {
            do
            {
                Menu_Operaciones(user, alum, mat, fech, op, &salir);

            }while(salir == 0);

            Matriculas_alumno(alum);
        }
        break;

        case 1:
        case 3:
        case 4: //Entra en el menú de edición de horarios del administrador.
        {
            do
            {
                Menu_Operaciones(user, alum, mat, fech, op, &salir);

            }while(salir == 0);

            Menu_admin(user, alum, fech, mat, &alM, &matM, &horM, &usM, &salir);
        }
        break;

        default:
        {
            printf("La opci%cn introducida es err%cnea, por favor introduzca nuevamente una opci%cn.\n", 162, 162, 162);
            salir = 1;
        }
    }
}
