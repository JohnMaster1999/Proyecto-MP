#include "Usuarios.h"
#include "Alumnos.h"
#include "Materias.h"
#include "Horarios.h"
#include "Op_Admin.h"
#include "Op_Prof.h"
#include "Op_alum.h"
#include "Op_mat.h"
#include "Op_horario.h"

// ### OPERACIONES ###

void Dar_alta(Usuarios *prof, Alumnos *clase, Materias *mat, Horarios *hor, int op1, int *num_alum, int *num_mat, int *num_prof, int *num_hor) // Faltan funciones Horarios
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

            *num_prof++;
        }
        break;

        case 2: //Alumnos
        {
            clase = (Alumnos*)realloc(clase, (num_alum + 1)*sizeof(Alumnos));

            printf("Introduce los datos del nuevo Alumno: \n\n");

            printf("Introduzca el ID: ");
            scanf("%d", clase[num_alum].idUs);
            printf("Introduzca el Nombre: ");
            gets(clase[num_alum].Nomb);
            printf("Introduzca la Direcci%cn: ", 162);
            gets(clase[num_alum].Dir);
            printf("Introduzca la Localidad: ");
            gets(clase[num_alum].Loc);
            printf("Introduzca el Curso: ");
            gets(clase[num_alum].Curso);
            printf("Introduzca el Grupo: ");
            gets(clase[num_alum].Grup);

            *num_alum++;
        }
        break;

        case 3:
        {
            materias_darDeAlta(mat[num_mat]);
            mat[num_mat] = materias_crear(mat[num_mat].Id_materia, );
        }
        break;

        case 4: horarios_darDeAlta(hor);
        break;

        default:
        {
            printf("Ha ocurrido un error.\n");
            //system("cls"); Para usuarios de Windows
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
            *p = i;       // Pasamos por referencia el valor de i a la variable p
            i = num_prof; // Condición de salida
        }
        else i++;

    }while(i < num_prof);
}

void Dar_baja(Usuarios *prof, Alumnos *clase, Materias *mat, Horarios *hor, int op1, int *num_alum, int *num_mat, int *num_prof, int *num_hor) // Faltan funciones Horarios
{
    int p, a, m, h, i;

    switch(op1)
    {
        case 1:
        {
            Selec_Usuario(prof, &p);

            for(i = p; i < num_prof; i++)
                *(prof+i) = *(prof+i+1);

            *num_prof--;

            prof = (Usuarios*)realloc(prof,num_prof*sizeof(Usuarios));


            if(prof != NULL)
            {
                printf("Proceso terminado con %cxito.\n", 130);
            }
            else
            {
                printf("Ha ocurrido un error.\n");
                //system("cls"); Para usuarios de Windows
                Menu_Operaciones(prof, clase, mat, hor, op1, &salir);
            }
        }
        break;

        case 2:
        {
            Selec_Alumno(clase, &a);

            for(i = a; i < num_alum; i++)
                *(clase+i) = *(clase+i+1);

            *num_alum--;

            clase = (Alumnos*)realloc(clase,num_alum*sizeof(Alumnos));


            if(clase != NULL && num_alum > 0)
            {
                printf("Proceso terminado con %cxito.\n", 130);
            }
            else
            {
                printf("Ha ocurrido un error.\n");
                //system("cls"); Para usuarios de Windows
                Menu_Operaciones(prof, clase, mat, hor, op1, &salir);
            }
        }
        break;

        case 3: materias_darDeBaja(m);
        break;

        case 4: horarios_darDeBaja(h);
        break;

        default:
        {
            printf("Ha ocurrido un error.\n");
            //system("cls"); Para usuarios de Windows
            Menu_Operaciones(prof, clase, mat, hor, op1, &salir);
        }

    }
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
                    //system("cls"); Para usuarios de Windows
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
                    //system("cls"); Para usuarios de Windows
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
                    //system("cls"); Para usuarios de Windows
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
                    //system("cls"); Para usuarios de Windows
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
                   //system("cls"); Para usuarios de Windows
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
                //system("cls"); Para usuarios de Windows
                Menu_Operaciones(prof, clase, mat, hor, op1, salir);
                *salir = 1;
            }
            else
            {
                //system("cls"); Para usuarios de Windows
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

void Modificar(Usuarios *prof, Alumnos *clase, Materias *mat, Horarios *hor, int op1) // Faltan funciones Horarios
{
    int p, a, m, h;
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

        case 3: materias_modificar(m, mat);
        break;

        case 4: horarios_modificar(h, hor);
        break;

        default:
        {
            printf("Ha ocurrido un error.\n");
           //system("cls"); Para usuarios de Windows
            Menu_Operaciones(prof, clase, mat, hor, op1, &salir);
        }
    }
}

void Listar(Usuarios *prof, Alumnos *clase, Materias *mat, Horarios *hor, int op1) // Faltan funciones Horarios
{
    int i = 0, dia, hora;

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

        case 2: Lista_alum(clase);
        break;

        case 3: materias_listar(n, Id_mat);
        break;

        case 4: horarios_listar(prof[i].idUs, hora, dia, clase[i].Grup, hor[i].Id_materia, 1);
        break;

        default:
        {
            printf("Ha ocurrido un error.\n");
            //system("cls"); Para usuarios de Windows
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

void Menu_Operaciones(Usuarios *prof, Alumnos *clase, Materias *mat, Horarios *hor, int op1, int *salir, int *num_alum, int *num_mat, int *num_prof, int *num_hor)
{
    int op2 = Menu_Admin2();

        switch(op2)
        {
            case 1: Dar_alta(prof, clase, mat, hor, op1, &num_alum, &num_mat, &num_prof, &num_hor);
                    break;
            case 2: Dar_baja(prof, clase, mat, hor, op1, &num_alum, &num_mat, &num_prof, &num_hor);
                    break;
            case 3: Modificar(prof, clase, mat, hor, op1);
                    break;
            case 4: Listar(prof, clase, mat, hor, op1);
                    break;
            case 5:
            {
                printf("Volviendo al men%c anterior.\n", 163);
                //system("cls"); Para usuarios de Windows
                *salir = 1;
            }
            break;
            default:
            {
                printf("La opci%cn introducida es errónea, por favor introduzca nuevamente una opci%cn.\n", 162, 162);
                //system("cls"); Para usuarios de Windows
                *salir = 1;
            }
        }
}

// ### OPERACIONES DE MATRÍCULAS DE ALUMNO ###

int Menu_Matriculas()
{
    int option;

    printf("%cQu%c quieres hacer? \n\n", 168, 130);

    printf("\t1.-Cambiar Matr%ccula.\n", 161);
    printf("\t2.-Eliminar Matr%ccula.\n", 161);
    printf("\t3.-Crear Matr%ccula.\n", 161);
    printf("\t4.-Salir\n\n");

    printf("Indique su opci%cn: ", 162);
    scanf("%d", &option);

    return option;
}

void Selec_Materia(Alumnos *clase, int *a, int *m)
{
    int i = 0, id;

    printf("Indique el ID de la materia que desea seleccionar: \n");
    scanf("%d", &id);

    do
    {
        if(id == clase[a].materias[i].Calf_.Id_materia)
        {
            *m = i;       // Pasamos por referencia el valor de i a la variable m
            i = num_mat; // Condición de salida
        }
        else i++;

    }while(i < num_mat);
}

void Cambiar_Matricula(int a, int m)
{
    int op;

    printf("%cQu%c quieres hacer? \n\n", 168, 130);

    printf("\t1.Cambiar el ID de Alumno.\n");
    printf("\t2.Cambiar el ID de Materia.\n\n");

    printf("Introduzca su opci%cn: ", 162);
    scanf("%d", &op);

    switch(op)
    {
        case 1:
        {
            printf("Introduzca el nuevo ID de Alumno: ");
            scanf("%d", clase[a].idUs);

            printf("\nCambio realizado con %cxito.\n", 130);
        }
        break;

        case 2:
        {
            printf("Introduzca el nuevo ID de Alumno: ");
            scanf("%d", clase[a].materias[m].Calf_.Id_materia);

            printf("\nCambio realizado con %cxito.\n", 130);
        }

        default:
        {
            printf("La opci%cn introducida no es correcta, vuelva a intentarlo.\n", 162);
            //system("cls"); Para usuarios de Windows
            Cambiar_Matricula(a, m);
        }
    }
}

void Borrar_Matricula(Alumnos *clase, int a, int m, int *num_calif)
{
    int i;

    Selec_Materia(clase, &a, &m);

    for(i = m; i < num_mat; i++)
    {
        *(clase[a].materias[m].Calf+i) = *(clase[a].materias[m].Calf+i+1);
    }

    num_mat--;

    clase[a].materias[m].Calf = (Alumnos*)realloc(clase[a].materias[m].Calf, num_calif-1*sizeof(Alumnos));

    if(clase[a].materias[m].Calf_ != NULL)
    {
        printf("Proceso terminado con %cxito.\n", 130);
    }
    else
    {
        printf("Ha ocurrido un error.\n");
        //system("cls"); Para usuarios de Windows
        Matriculas_alumno(clase);
    }

    *num_calif--;
}

void Crear_Matricula(int a, int m))
{
    clase[a].materias[m].Calf_ = (Calif*)realloc(clase[a].materias[m].Calf_, (num_calif+1)*sizeof(Calif));

    printf("Introduzca el ID de Alumno: ");
    scanf("%d", clase[a].idUs);

    if(clase[a].idUs != NULL)
        printf("\nCambio realizado con %cxito.\n", 130);
    else
    {
        printf("Ha ocurrido un error, vuelva a intentarlo.\n");
        //system("cls"); Para usuarios de Windows
        Crear_Matricula(a, m);
    }

    printf("Introduzca el nuevo ID de Alumno: ");
    scanf("%d", clase[a].materias[m].Calf_.Id_materia);

    if(clase[a].materias[m].Calf_.Id_materia != NULL)
        printf("\nCambio realizado con %cxito.\n", 130);
    else
    {
        printf("Ha ocurrido un error, vuelva a intentarlo.\n");
        //system("cls"); Para usuarios de Windows
        Crear_Matricula(a, m);
    }
}

void Matriculas_alumno(Alumnos *clase)
{
    int a, m, i = 0, op = Menu_Matriculas();

    Selec_Alumno(clase, &a);

    printf("ID ALUMNO   ||  ID MATERIA\n");

    while(i < num_mat)
    {
        printf("%d  ||  %d\n", clase[a].idUs, clase[a].materias[i].Calf_.Id_materia);
        i++;
    }

    Selec_Materia(clase, &a, &m);

    switch(op)
    {
        case 1: Cambiar_Matricula(a, m);
        break;

        case 2: Borrar_Matricula(a, m);
        break;

        case 3: Crear_Matricula(a, m);
        break;

        case 4:
        {
            //system("cls"); Para usuarios de Windows
            Menu_admin(prof, clase, mat, hor);
        }
        break;

        default:
        {
            printf("La opci%cn introducida no es correcta, vuelva a intentarlo.\n");
            //system("cls"); Para usuarios de Windows
            Matriculas_alumno(clase);
        }

    }
}

// ### MENÚ PRINCIPAL ###

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

void Menu_admin(Usuarios *prof, Alumnos *clase, Materias *mat, Horarios *hor,  int *num_alum, int *num_mat, int *num_prof, int *num_hor, int salir)
{
    int op1 = Menu_Admin1();

    switch(op1)
    {
        case 2:
        {
            do
            {
                Menu_Operaciones(prof, clase, mat, hor, op1, &salir, &num_alum, &num_mat, &num_prof, &num_hor);

            }while(salir == 0);

            Matriculas_alumno(clase);
        }
        break;

        case 1:
        case 3:
        case 4:
        {
            do
            {
                Menu_Operaciones(prof, clase, mat, hor, op1, &salir, &num_alum, &num_mat, &num_prof, &num_hor);

            }while(salir == 0);

            Menu_admin(prof, clase, mat, hor);
        }
        break;

        default:
        {
            printf("La opci%cn introducida es err%cnea, por favor introduzca nuevamente una opci%cn.\n", 162, 162, 162);
            salir = 1;
            //system("cls"); Para usuarios de Windows
        }
    }
}
