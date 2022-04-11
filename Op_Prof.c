#include "Alumnos.h"
#include "Op_Prof.h"

Alumnos *clase;
int num_alum, num_mat;

clase = (Alumnos*)malloc(num_alum*sizeof(Alumnos));

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

// ### FUNCIÓN VOLVER_ATRÁS ###

Alumnos* Modificar_ficha(int index)
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
                    printf("Ha ocurrido un error, vuelva a intentarlo.");

            }while(clase[index].idUs == NULL);
        }
        break;

        case 2: //Nombre
        {
            do
            {
                printf("Introduzca el Nombre nuevo: ");
                clase[index].Nomb = gets(); //Lee el nombre, REVISAR

                if(clase[index].Nomb != NULL)
                    printf("Cambio realizado con %cxito.\n", 130);
                else
                    printf("Ha ocurrido un error, vuelva a intentarlo.");
            }while(clase[index].Nomb == NULL);
        }
        break;

        case 3: //Dirección
        {
            do
            {
                printf("Introduzca la nueva Direcci%cn: ", 162);
                clase[index].Dir = gets();

                if(clase[index].Dir != NULL)
                    printf("Cambio realizado con %cxito.\n", 130);
                else
                    printf("Ha ocurrido un error, vuelva a intentarlo.");
            }while(clase[index].Dir == NULL);
        }
        break;

        case 4: //Localidad
        {
            do
            {
                printf("Introduzca la nueva Localidad: ");
                clase[index].Loc = gets();

                if(clase[index].Loc != NULL)
                    printf("Cambio realizado con %cxito.\n", 130);
                else
                    printf("Ha ocurrido un error, vuelva a intentarlo.");
            }while(clase[index].Loc == NULL);

        }
        break;

        case 5: //Curso
        {
            do
            {
                printf("Introduzca el Curso nuevo: ");
                clase[index].Curso = gets(); //Lee el nombre, REVISAR

                if(clase[index].Curso != NULL)
                    printf("Cambio realizado con %cxito.\n", 130);
                else
                    printf("Ha ocurrido un error, vuelva a intentarlo.");
            }while(clase[index].Curso == NULL);
        }
        break;

        case 6: //Grupo
        {
            do
            {
                printf("Introduzca el Grupo nuevo: ");
                clase[index].Grup = gets(); //Lee el nombre, REVISAR

                if(clase[index].Grup != NULL)
                    printf("Cambio realizado con %cxito.\n", 130);
                else
                    printf("Ha ocurrido un error, vuelva a intentarlo.");
            }while(clase[index].Grup == NULL);
        }
        break;

        case 7: //Volver atrás
        {
            // ### Función importante ###
        }
        break;

        default:
        {
            printf("Ha ocurrido un error, vuelva a intentarlo.");

        }
    }
}

void ficha_alumnos(Alumnos *clase, int  i) //para el módulo de OP.ALUM
{
    printf("%d", clase[i].idUs);
    puts(clase[i].Nomb);
    puts(clase[i].Dir);
    puts(clase[i].Loc);
    puts(clase[i].Curso);
    puts(clase[i].Grup);

    clase = Modificar_ficha(i);
}

void Calificaciones_alum(Alumnos *clase, int  i)  //para el módulo de OP.ALUM
{

}

int Opciones_Usuario()
{
    int opcion;

    printf("\t1.Lista de Alumnos\n");
    printf("\t2.Cambiar de grupo\n\n");

    printf("Indique una opci%cn: ", 162);
    scanf("%d", &opcion);

    return opcion;
}

//void Lista_alum(Alumnos *clase);

void Menu_Grupo(Alumnos *clase)
{
    int op = Opciones_Usuario();

    printf("GRUPO %d %s  MATERIA %s"); // CURSO NOMBRE_GRUPO ABREVIATURA

    switch(op)
    {
        case 1: Lista_alum(clase);
        break;

        case 2: Lista_Grupos(clase);
        break;
    }

}

1º)//void Lista_Grupos(Alumnos *clase) > Seleccionar grupo >
