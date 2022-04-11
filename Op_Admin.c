#include "Op_Admin.h"
#include "Usuarios.h"
#include "Alumnos.h"
#include "Materias.h"
#include "Op_mat.h"
#include "Fecha.h"
#include "Op_fecha.h"

Alumnos *clase;
Usuarios *prof;
Materias *mat;
Fecha *hor;

int num_prof, num_alum, num_mat, num_hor;

prof = (Usuarios*)malloc(num_prof*sizeof(Usuarios));
clase = (Alumnos*)malloc(num_alum*sizeof(Alumnos));
mat = (Materias*)malloc(num_mat*sizeof(Materias));
clase = (Fecha*)malloc(num_hor*sizeof(Fecha));


void Dar_alta(Usuarios *prof, Alumnos *clase, Materias *mat, Fechas *hor, op1)
{
    switch(op1)
    {
        case 1:
        {
            prof = (Usuarios*)realloc(prof, (num_prof + 1)*sizeof(Usuarios));

            printf("Introduce los datos del nuevo Usuario: \n\n");

            printf("Introduzca el ID: ");
            scanf("%d", prof[num_prof].idUs);
            printf("Introduzca el Nombre: ");
            prof[num_prof].Nomb = gets();
            printf("Introduzca el tipo de Perfil: ");
            prof[num_prof].Perf = gets();
            printf("Introduzca el Nombre de Usuario: ");
            prof[num_prof].NomU = gets();
            printf("Introduzca una Contrase%ca: ", 164);
            prof[num_prof].pass = gets();
        }
        break;

        case 2:
        {
            clase = (Alumnos*)realloc(clase, (num_alum + 1)*sizeof(Alumnos));

            printf("Introduce los datos del nuevo Alumno: \n\n");

            printf("Introduzca el ID: ");
            scanf("%d", clase[num_alum].idUs);
            printf("Introduzca el Nombre: ");
            clase[num_alum].Nomb = gets();
            printf("Introduzca la Direcci%cn: ", 162);
            clase[num_alum].Dir = gets();
            printf("Introduzca la Localidad: ");
            clase[num_alum].Loc = gets();
            printf("Introduzca el Curso: ");
            clase[num_alum].Curso = gets();
            printf("Introduzca el Grupo: ");
            clase[num_alum].Grup = gets();

        }
        break;

        case 3: //### Funciones del módulo de Manuel ###
        {
            /*mat = (Materias*)realloc(mat, (num_mat + 1)*sizeof(Materias));


            printf("Introduzca el ID de Materia: ");
            scanf("%d", mat[num_mat].Id_materia);
            printf("Introduzca el Nombre de la Materia: ");
            mat[num_mat].Nombre_Materia = gets();
            printf("Introduzca la Abreviatura de la Materia: ");
            mat[num_mat].Abrev_Materia = gets();*/
        }
        break;

        case 4: //### Funciones del módulo de Manuel ###
        {
           // hor = (Fecha*)realloc(hor, (num_hor + 1)*sizeof(Fecha));
        }
        break;

        default:
        {
            printf("Ha ocurrido un error.\n");
        }

    }
}

void Dar_baja(Usuarios *prof, Alumnos *clase, Materias *mat, Fechas *hor, op1)
{
    switch(op1)
    {
        case 1:
        {

        }
        break;

        case 2:
        {

        }
        break;

        case 3: //### Funciones del módulo de Manuel ###
        {

        }
        break;

        case 4: //### Funciones del módulo de Manuel ###
        {

        }
        break;

        default:
        {
            printf("Ha ocurrido un error.\n");
        }

    }
}

void Modificar(Usuarios *prof, Alumnos *clase, Materias *mat, Fechas *hor, op1)
{
    switch(op1)
    {
        case 1:
        {

        }
        break;

        case 2:
        {

        }
        break;

        case 3: //### Funciones del módulo de Manuel ###
        {

        }
        break;

        case 4: //### Funciones del módulo de Manuel ###
        {

        }
        break;

        default:
        {
            printf("Ha ocurrido un error.\n");
        }
    }
}

void Listar(Usuarios *prof, Alumnos *clase, Materias *mat, Fecha *hor, op1)
{
    switch(op1)
    {
        case 1:
        {
            printf("ID  |   NOMBRE  |   NICKNAME    |   PERFIL\n");

            while(num_prof > 0)
            {
                printf("%d  |   %s  |   %s  |   %s\n", prof[num_prof].idUs, prof[num_prof].Nomb, prof[num_prof].NomU, prof[num_prof].Perf);
                num_prof--;
            }
        }
        break;

        case 2:
        {
            printf("ID  |   NOMBRE  |   DIRECCI%cN   |   LOCALIDAD  |   CURSO   |   GRUPO\n", 162);

            while(num_alum > 0)
            {
                printf("%d  |   %s  |   %s  |   %s  |   %s  |   %s\n", clase[num_alum].idUs, clase[num_alum].Nomb, clase[num_alum].Dir, clase[num_alum].Loc, clase[num_alum].Curso, clase[num_alum].Grup);
                num_alum--;
            }
        }
        break;

        case 3: //### Funciones del módulo de Manuel ###
        {

        }
        break;

        case 4: //### Funciones del módulo de Manuel ###
        {

        }
        break;

        default:
        {
            printf("Ha ocurrido un error.\n");
        }
    }
}

int Menu_Admin2()
{
    int option;

    printf("%cQu%c quieres hacer? \n", 168, 130);
    printf("\t1.-Dar de Alta.\n");
    printf("\t2.-Dar de Baja.\n");
    printf("\t3.-Modificar.\n");
    printf("\t4.-Listar.\n\n");

    printf("Indique su opci%cn: ", 162);
    scanf("%d", &option);

    return option;
}

void Menu_Operaciones(Usuarios *prof, Alumnos *clase, Materias *mat, Fecha *hor, op1, salir)
{
    int op2 = Menu_Admin2();

        switch(op2)
        {
            case 1: Dar_alta(prof, clase, mat, hor, op1);
                    break;
            case 2: Dar_baja(prof, clase, mat, hor, op1);
                    break;
            case 3: Modificar(prof, clase, mat, hor, op1);
                    break;
            case 4: Listar(prof, clase, mat, hor, op1);
                    break;
            default:
            {
                printf("La opci%cn introducida es errónea, por favor introduzca nuevamente una opci%cn.\n", 162, 162);
                salir = 1;
            }
        }
}

int Menu_Admin1()
{
    int op;
    printf("Men%c: Administrador\n\n", 163);

    printf("\t1.-Usuarios.\n");
    printf("\t2.-Alumnos.\n");
    printf("\t3.-Materias.\n");
    printf("\t4.-Horarios.\n\n");

    printf("Indique una opci%cn: ", 162);
    scanf("%d", &op);

    return op;
}

void Menu_admin(Usuarios *prof, Alumnos *clase, Materias *mat, Fechas *hor) // ### Cuando se llame a esta función hay que meterla en un do-while ###
{
    int op1 = Menu_Admin1();
    int salida = 0; //###
    switch(op1)
    {
        case 2:
        {
            int salir = 0;

            do
            {
                Menu_Operaciones(prof, clase, mat, hor, op1, salir);

            }while(salir != 0);

            /* ### Función para mostrar las matrículas del alumno y poder realizar:
                        1)cambios de matrícula a otras materias
                        2)eliminar matrícula en alguna materia
                        3)crear nuevas matrículas.
                ###
            */
        }
        break;

        case 1:
        case 3:
        case 4:
        {
            salir = 0;

            do
            {
                Menu_Operaciones(prof, clase, mat, hor, op1, salir);

            }while(salir != 0);
        }
        break;

        default:
        {
            printf("La opción introducida es errónea, por favor introduzca nuevamente una opción.\n");
            salida = 1;
        }
    }
}
