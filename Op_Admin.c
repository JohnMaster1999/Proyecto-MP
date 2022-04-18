#include "Usuarios.h"
#include "Alumnos.h"
#include "Materias.h"
#include "Fecha.h"
#include "Op_Admin.h"
#include "Op_Prof.h"
#include "Op_alum.h"
#include "Op_mat.h"
#include "Op_fecha.h"

/*Alumnos *clase;                                   En fichero Op_Admin.h
Usuarios *prof;
Materias *mat;
Fecha *hor;

int num_prof, num_alum, num_mat, num_hor;

prof = (Usuarios*)malloc(num_prof*sizeof(Usuarios));
clase = (Alumnos*)malloc(num_alum*sizeof(Alumnos));
mat = (Materias*)malloc(num_mat*sizeof(Materias));
clase = (Fecha*)malloc(num_hor*sizeof(Fecha));*/

int salir = 0;

void Dar_alta(Usuarios *prof, Alumnos *clase, Materias *mat, Fechas *hor, int op1) // TODAVÍA NO ESTÁ TERMINADO
{
    switch(op1)
    {
        case 1: //Usuarios
        {
            prof = (Usuarios*)realloc(prof, (num_prof + 1)*sizeof(Usuarios));

            printf("Introduce los datos del nuevo Usuario: \n\n");

            printf("Introduzca el ID: ");
            scanf("%d", prof[num_prof].idUs);
            printf("Introduzca el Nombre: ");
            gets(prof[num_prof].Nomb);
            printf("Introduzca el tipo de Perfil: ");
            gets(prof[num_prof].Perf);
            printf("Introduzca el Nombre de Usuario: ");
            gets(prof[num_prof].NomU);
            printf("Introduzca una Contrase%ca: ", 164);
            gets(prof[num_prof].pass);
        }
        break;

        case 2: //Alumnos
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

        case 3: //### (REPASAR) Funciones del módulo de Manuel ###
        {
            materias_darDeAlta(mat[num_mat]);
            //mat[num_mat] = materias_crear(mat[num_mat].Id_materia, );

        }
        break;

        case 4: //### Funciones del módulo de Manuel ###
        {

        }
        break;

        default:
        {
            printf("Ha ocurrido un error.\n");
            system("cls");
            Menu_Operaciones(prof, clase, mat, hor, op1, &salir);
        }

    }
}

void Dar_baja(Usuarios *prof, Alumnos *clase, Materias *mat, Fechas *hor, int op1) // TODAVÍA NO ESTÁ TERMINADO
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

        case 3: //### (REPASAR) Funciones del módulo de Manuel ###
        {
            materias_darDeBaja(Id_mat);
        }
        break;

        case 4: //### Funciones del módulo de Manuel ###
        {

        }
        break;

        default:
        {
            printf("Ha ocurrido un error.\n");
            system("cls");
            Menu_Operaciones(prof, clase, mat, hor, op1, &salir);
        }

    }
}

void Selec_Usuario(Usuarios *prof, int *p)
{
    int i = 0;
    char s[21];

    printf("Indique el usuario que desea seleccionar: \n");
    gets(s);

    do
    {
        if(strcmp(s, prof[i].Nomb) == 0)
        {
            *p = i;       // Pasamos por referencia el valor de i a la variable a
            i = num_prof; // Condición de salida
        }
        else i++;

    }while(i < num_prof);
}

int Opciones_Usuario()
{
    int option;

    printf("%cQu%c quieres modificar? \n", 168, 130);
    printf("\t1.ID Usuario\n");
    printf("\t2.Nombre\n");
    printf("\t3.Perfil\n");
    printf("\t4.Nombre de Usuario\n");
    printf("\t5.Contrase%ca\n", 164);
    printf("\t6.Atrás\n\n");

    printf("Indique su opci%cn: ", 162);
    scanf("%d", &option);

    return option;
}

void Modificar_usuario(int p, int *salir)
{
    int op = Opciones_Usuario();

    switch(op)
    {
        case 1: //Id Usuario
        {
            do
            {
                printf("Introduzca el ID nuevo: ");
                scanf("%d", prof[p].idUs);

                if(prof[p].idUs != NULL)
                    printf("Cambio realizado con %cxito.\n", 130);
                else
                {
                    printf("Ha ocurrido un error, vuelva a intentarlo.");
                    *salir = 1;
                    system("cls");
                }

            }while(prof[p].idUs == NULL);
        }
        break;

        case 2: //Nombre
        {
            do
            {
                printf("Introduzca el Nombre nuevo: ");
                gets(prof[p].Nomb); //Lee el nombre, REVISAR

                if(prof[p].Nomb != NULL)
                    printf("Cambio realizado con %cxito.\n", 130);
                else
                {
                    printf("Ha ocurrido un error, vuelva a intentarlo.");
                    *salir = 1;
                    system("cls");
                }

            }while(prof[p].Nomb == NULL);
        }
        break;

        case 3: //Perfil
        {
            do
            {
                printf("Introduzca la nueva Direcci%cn: ", 162);
                gets(prof[p].Perf);

                if(prof[p].Perf != NULL)
                    printf("Cambio realizado con %cxito.\n", 130);
                else
                {
                    printf("Ha ocurrido un error, vuelva a intentarlo.");
                    *salir = 1;
                    system("cls");
                }

            }while(prof[p].Perf == NULL);
        }
        break;

        case 4: //Nombre de Usuario
        {
            do
            {
                printf("Introduzca el nuevo Nombre de Usuario: ");
                gets(prof[p].NomU);

                if(prof[p].NomU != NULL)
                    printf("Cambio realizado con %cxito.\n", 130);
                else
                {
                    printf("Ha ocurrido un error, vuelva a intentarlo.");
                    *salir = 1;
                    system("cls");
                }

            }while(prof[p].NomU == NULL);

        }
        break;

        case 5: //Contraseña
        {
            do
            {
                printf("Introduzca el Curso nuevo: ");
                gets(prof[p].pass); //Lee el nombre, REVISAR

                if(prof[p].pass != NULL)
                    printf("Cambio realizado con %cxito.\n", 130);
                else
                {
                    printf("Ha ocurrido un error, vuelva a intentarlo.");
                    *salir = 1;
                    system("cls");
                }

            }while(prof[p].pass == NULL);
        }
        break;

        case 6: //Atrás
        {
            int c;

            printf("%cEst%c seguro que desea volver atr%cs?: (s/n)\n", 168, 160, 160);
            scanf("%c", &c);

            if( c == 's')
            {
                system("cls");
                Menu_Operaciones(prof, clase, mat, hor, op1, salir);
                *salir = 1;
            }
            else
            {
                system("cls");
                Modificar_usuario(p);
            }

        }
        break;

        default:
        {
            printf("La opci%cn introducida no es correcta, por favor, introd%czcala nuevamente.\n", 163);
            *salir = 1;
            Modificar_usuario(p, &salir);
        }
    }
}

void Modificar(Usuarios *prof, Alumnos *clase, Materias *mat, Fechas *hor, int op1) // TODAVÍA NO ESTÁ TERMINADO
{
    int p, a;
    switch(op1)
    {
        case 1:
        {
            Selec_Usuario(prof, &p);

            do
            {
                Modificar_usuario(p, &salir);

            }while(salir == 0);

        }
        break;

        case 2:
        {
            Selec_Alumno(clase, &a);
            Modificar_ficha(a);
        }
        break;

        case 3: //### (REPASAR) Funciones del módulo de Manuel ###
        {
            materias_modificar(Id_mat, mat);
        }
        break;

        case 4: //### Funciones del módulo de Manuel ###
        {

        }
        break;

        default:
        {
            printf("Ha ocurrido un error.\n");
            system("cls");
            Menu_Operaciones(prof, clase, mat, hor, op1, &salir);
        }
    }
}

void Listar(Usuarios *prof, Alumnos *clase, Materias *mat, Fecha *hor, int op1) // TODAVÍA NO ESTÁ TERMINADO
{
    int i = 0;

    switch(op1)
    {
        case 1:
        {
            printf("ID  |   NOMBRE  |   NICKNAME    |   PERFIL\n");

            while(i < num_prof)
            {
                printf("%d  |   %s  |   %s  |   %s\n", prof[i].idUs, prof[i].Nomb, prof[i].NomU, prof[i].Perf);
                i++;
            }
        }
        break;

        case 2:
        {
            Lista_alum(clase);
        }
        break;

        case 3: //### (REPASAR) Funciones del módulo de Manuel ###
        {
            materias_listar(n, Id_mat);
        }
        break;

        case 4: //### Funciones del módulo de Manuel ###
        {

        }
        break;

        default:
        {
            printf("Ha ocurrido un error.\n");
            system("cls");
            Menu_Operaciones(prof, clase, mat, hor, op1, &salir);
        }
    }
}

int Menu_Admin2()
{
    int option;

    printf("%cQu%c quieres hacer? \n\n", 168, 130);

    printf("\t1.-Dar de Alta.\n");
    printf("\t2.-Dar de Baja.\n");
    printf("\t3.-Modificar.\n");
    printf("\t4.-Listar.\n");
    printf("\t5.-Salir\n\n");

    printf("Indique su opci%cn: ", 162);
    scanf("%d", &option);

    return option;
}

void Menu_Operaciones(Usuarios *prof, Alumnos *clase, Materias *mat, Fecha *hor, int op1, int *salir)
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
            case 5:
            {
                *salir = 1;
                printf("Volviendo al men%c anterior.\n", 163);
                system("cls");
            }
            break;
            default:
            {
                printf("La opci%cn introducida es errónea, por favor introduzca nuevamente una opci%cn.\n", 162, 162);
                *salir = 1;
                system("cls");
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

void Menu_admin(Usuarios *prof, Alumnos *clase, Materias *mat, Fechas *hor) // TODAVÍA NO ESTÁ TERMINADO ### Cuando se llame a esta función hay que meterla en un do-while ###
{
    int op1 = Menu_Admin1();

    switch(op1)
    {
        case 2:
        {
            do
            {
                Menu_Operaciones(prof, clase, mat, hor, op1, &salir);

            }while(salir == 0);

            Menu_admin(prof, clase, mat, hor);

            /* ### Función para mostrar las matrículas del alumno y poder realizar:
                        1)cambios de matrícula a otras materias.
                        2)eliminar matrícula en alguna materia.
                        3)crear nuevas matrículas.
               ###
            */
        }
        break;

        case 1:
        case 3:
        case 4:
        {
            do
            {
                Menu_Operaciones(prof, clase, mat, hor, op1, &salir);

            }while(salir == 0);

            Menu_admin(prof, clase, mat, hor);
        }
        break;

        default:
        {
            printf("La opci%cn introducida es err%cnea, por favor introduzca nuevamente una opci%cn.\n", 162, 162, 162);
            salir = 1;
            system("cls");
        }
    }
}
