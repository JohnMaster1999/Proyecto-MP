#include "Alumnos.h"
#include "Op_Prof.h"
#include "Op_alum.h"

// ### GRUPOS ###

int Selec_Grupo(Alumnos *clase)
{
    int i = 0, n;
    char cad[11];

    printf("Indique el grupo que desea seleccionar: \n");
    gets(cad);

    do
    {
        if(strcmp(cad, clase[i].Grup) == 0)
        {
            n = i;       // Pasamos por referencia el valor de i a la variable n
            i = num_grup; // Condición de salida
        }
        else i++;

    }while(i < num_grup);

    return n;
}

int Lista_Grupos(Alumnos *clase)
{
    int i = 0, m;

    while(i < num_grup)
    {
        printf("GRUPO %s  MATERIA %s", clase[i].Grup, clase[i].Materias[i].Mat);
        i++;
    }

    return m = Selec_Grupo(clase);
}

// ### ALUMNOS ###

int Opciones()
{
    int option;

    printf("%cQu%c quieres modificar? \n", 168, 130);
    printf("\t1.ID Usuario\n");
    printf("\t2.Nombre\n");
    printf("\t3.Direcci%cn\n", 162);
    printf("\t4.Localidad\n");
    printf("\t5.Curso\n");
    printf("\t6.Grupo\n");
    printf("\t7.Atrás\n\n");

    printf("Indique su opci%cn: ", 162);
    scanf("%d", &option);

    return option;
}

void Modificar_ficha(int index, int n, int *salir)
{
    int op = Opciones();

    switch(op)
    {
        case 1: //IdUs
        {
            do
            {
                printf("Introduzca el ID nuevo: ");
                scanf("%d", clase[index].idUs);

                if(clase[index].idUs != NULL)
                    printf("Cambio realizado con %cxito.\n", 130);
                else
                {
                    printf("Ha ocurrido un error, vuelva a intentarlo.");
                    *salir = 1;
                    //system("cls"); Para usuarios de Windows
                }

            }while(clase[index].idUs == NULL);
        }
        break;

        case 2: //Nombre
        {
            do
            {
                printf("Introduzca el Nombre nuevo: ");
                gets(clase[index].Nomb); //Lee el nombre, REVISAR

                if(clase[index].Nomb != NULL)
                    printf("Cambio realizado con %cxito.\n", 130);
                else
                {
                    printf("Ha ocurrido un error, vuelva a intentarlo.");
                    *salir = 1;
                    //system("cls"); Para usuarios de Windows
                }

            }while(clase[index].Nomb == NULL);
        }
        break;

        case 3: //Dirección
        {
            do
            {
                printf("Introduzca la nueva Direcci%cn: ", 162);
                gets(clase[index].Dir);

                if(clase[index].Dir != NULL)
                    printf("Cambio realizado con %cxito.\n", 130);
                else
                {
                    printf("Ha ocurrido un error, vuelva a intentarlo.");
                    *salir = 1;
                    //system("cls"); Para usuarios de Windows
                }

            }while(clase[index].Dir == NULL);
        }
        break;

        case 4: //Localidad
        {
            do
            {
                printf("Introduzca la nueva Localidad: ");
                gets(clase[index].Loc);

                if(clase[index].Loc != NULL)
                    printf("Cambio realizado con %cxito.\n", 130);
                else
                {
                    printf("Ha ocurrido un error, vuelva a intentarlo.");
                    *salir = 1;
                    //system("cls"); Para usuarios de Windows
                }

            }while(clase[index].Loc == NULL);

        }
        break;

        case 5: //Curso
        {
            do
            {
                printf("Introduzca el Curso nuevo: ");
                gets(clase[index].Curso);

                if(clase[index].Curso != NULL)
                    printf("Cambio realizado con %cxito.\n", 130);
                else
                {
                    printf("Ha ocurrido un error, vuelva a intentarlo.");
                    *salir = 1;
                    //system("cls"); Para usuarios de Windows
                }

            }while(clase[index].Curso == NULL);
        }
        break;

        case 6: //Grupo
        {
            do
            {
                printf("Introduzca el Grupo nuevo: ");
                gets(clase[index].Grup);

                if(clase[index].Grup != NULL)
                    printf("Cambio realizado con %cxito.\n", 130);
                else
                {
                    printf("Ha ocurrido un error, vuelva a intentarlo.");
                    *salir = 1;
                    //system("cls"); Para usuarios de Windows
                }

            }while(clase[index].Grup == NULL);
        }
        break;

        case 7: //Atrás
        {
            int c;

            printf("%cEst%c seguro que desea volver atr%cs?: (s/n)\n", 168, 160, 160);
            scanf("%c", &c);

            if( c == 's')
            {
                //system("cls"); Para usuarios de Windows
                Menu_Alumno(clase, index, n);
                *salir = 1;
            }
            else
            {
                //system("cls"); Para usuarios de Windows
                Modificar_ficha(index, &salir);
            }

        }
        break;

        default: printf("Ha ocurrido un error\n");
    }
}
