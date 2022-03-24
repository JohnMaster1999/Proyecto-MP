#include "Op_Admin.h"
#include "Usuarios.h"
#include "Alumnos.h"
#include "Materias.h"
#include "Fecha.h"

Alumnos *clase;
Usuarios *prof;
Materias *mat;
Fecha *hor; //### Preguntar sobre su tratamiento ###

int num_prof, num_alum, num_mat, num_hor;

prof = (Usuarios*)malloc(num_prof*sizeof(Usuarios))
clase = (Alumnos*)malloc(num_alum*sizeof(Alumnos));
mat = (Materias*)malloc(num_mat*sizeof(Materias));
clase = (Fecha*)malloc(num_hor*sizeof(Fecha));


void Dar_alta(&prof, &clase, &mat, &hor, op1)
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
            prof[num_prof].Nomb = gets(); //Lee el nombre, REVISAR
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

        case 3:
        {
            mat = (Materias*)realloc(mat, (num_mat + 1)*sizeof(Materias));

            printf("Introduzca el ID de Materia: ");
            scanf("%d", mat[num_mat].Id_materia);
            printf("Introduzca el Nombre de la Materia: ");
            mat[num_mat].Nombre_Materia = gets();
            printf("Introduzca la Abreviatura de la Materia: ");
            mat[num_mat].Abrev_Materia = gets();

        }
        break;

        case 4:
        {
            hor = (Fecha*)realloc(hor, (num_hor + 1)*sizeof(Fecha));
        }
        break;

        default: printf("Ha ocurrido un error.\n");
                 exit(1);
    }
}

void Dar_baja(&prof, &clase, &mat, &hor, op1)
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

        case 3:
        {

        }
        break;

        case 4:
        {

        }
        break;

        default: printf("Ha ocurrido un error.\n");
                 exit(1);
    }
}

void Modificar(&prof, &clase, &mat, &hor, op1)
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

        case 3:
        {

        }
        break;

        case 4:
        {

        }
        break;

        default: printf("Ha ocurrido un error.\n");
                 exit(1);
    }
}

void Listar(&prof, &clase, &mat, &hor, op1)
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

        case 3:
        {

        }
        break;

        case 4:
        {

        }
        break;

        default: printf("Ha ocurrido un error.\n");
                 exit(1);
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
}

void Menu_Operaciones(&prof, &clase, &mat, &hor, op1)
{
    int op2 = Menu_Admin2();

    if(prof == NULL || clase == NULL || mat == NULL ||| hor == NULL)
    {
        printf("Ha ocurrido un error, se va a cerrar este men%c.\n", 163);
        exit(1);
    }
    else
    {
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
            default: printf("La opción introducida es errónea, por favor introduzca nuevamente una opción.\n");
                    // ### Función para volver ###
        }
    }
}

int Menu_Admin1()
{
    int op;

    printf("\t1.-Usuarios.\n");
    printf("\t2.-Alumnos.\n");
    printf("\t3.-Materias.\n");
    printf("\t4.-Horarios.\n\n");

    printf("Indique su opci%cn: ", 162);
    scanf("%d", &op);
}

void Menu_admin(&prof, &clase, &mat, &hor)
{
    int op1 = Menu_Admin1();

    switch(op1)
    {
        case 2:
        {
            Menu_Operaciones(prof, clase, mat, hor, op1);
             /* ### Función para mostrar las matrículas del alumno y poder realizar:
                        1)cambios de matrícula a otras materias
                        2)eliminar matrícula en alguna materia
                        3) crear nuevas matrículas.
                ###
            */
        }
        break;

        case 1:
        case 3:
        case 4: Menu_Operaciones(prof, clase, mat, hor, op1);
                break;
        default:
        {
            printf("La opción introducida es errónea, por favor introduzca nuevamente una opción.\n");
            // ### Función para volver ###
        }
    }
}

