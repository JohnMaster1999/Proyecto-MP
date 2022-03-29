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
    printf("\tMenu: Grupo\n%s\n---------------------------\n", grupo[k].Nom);
    printf("Selecciona una opcion:\n\t1.Lista de alumnos\n\t2.Cambiar de grupo\n");
    scanf("%d", &n);
    switch(n){
        case 1:
            printf("Lista de alumnos:\n");
            lista_alumnos();
            selec_alumn();
        case 2:
            printf("¿Seguro que deseas volver?\n\t1.Si\n\t2.No");
            scanf("%d", n2);
            switch(n2){
                case 1:
                    menu_prin();
                case 2:
                    menu_grupo();
                default:
		        {
		            printf("La opción introducida es errónea, por favor introduzca nuevamente una opción.\n");
		            // ### Función para volver ###
		        }
		default:
        {
            printf("La opción introducida es errónea, por favor introduzca nuevamente una opción.\n");
            // ### Función para volver ###
        }
            }
    }
}

void menu_alum(Alumnos *alum)
{
    int n;
    printf("\tMenu: Alumno\n%s\n---------------------------\n", alum[i].Nomb);
    printf("\n\t1.Ficha del alumno\n\t2.Calificaciones del alumno\n\t3.Volver\n");
    scanf("%d", &n);
    switch(n){
        case 1:
            ficha_alumnos();
        case 2:
            Calificaciones_alum();
        case 3:
            Volver_atras();
        default:
        {
            printf("La opción introducida es errónea, por favor introduzca nuevamente una opción.\n");
            // ### Función para volver ###
        }
    }
}


void Menu_admin(&prof, &clase, &mat, &hor)
{
	int op;
	
    printf("\tMenu: Administrador\n---------------------------\n\n");
	printf("\t1.-Usuarios.\n");
    printf("\t2.-Alumnos.\n");
    printf("\t3.-Materias.\n");
    printf("\t4.-Horarios.\n\n");

    printf("Indique su opci%cn: ", 162);
    scanf("%d", &op);
    
    switch(op)
    {
    	
    	case 1:
        case 2:
        {
            Menu_Operaciones(prof, clase, mat, hor, op);
            Matrículas(prof, clase, mat, hor, op)
        }
        break;

        
        case 3:
        case 4: Menu_Operaciones(prof, clase, mat, hor, op);
                break;
        default:
        {
            printf("La opción introducida es errónea, por favor introduzca nuevamente una opción.\n");
            // ### Función para volver ###
        }
    }
}
