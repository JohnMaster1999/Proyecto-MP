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
}

// ### FUNCIÓN VOLVER_ATRÁS ###

Alumnos* Modificar_ficha(int index)
{
    int op = Opciones();

    //printf("\nIndique el %cndice del alumno: ", 161);
    //scanf("%d", &index);

    switch(op)
    {
        case 1: //IdUs
        {
            printf("Introduzca el ID nuevo: ");
            scanf("%d", clase[index].idUs);

            if(clase[index].idUs != NULL)
                printf("Cambio realizado con %cxito.\n", 130);
            else
            {
                printf("Ha ocurrido un error, vuelva a intentarlo.");
                exit(1); //Vuelve a introducir el nombre
            }

        }
        break;

        case 2: //Nombre
        {
            printf("Introduzca el Nombre nuevo: ");
            clase[index].Nomb = gets(); //Lee el nombre, REVISAR

            if(clase[index].Nomb != NULL)
                printf("Cambio realizado con %cxito.\n", 130);
            else
            {
                printf("Ha ocurrido un error, vuelva a intentarlo.");
                exit(1); //Vuelve a introducir el nombre
            }
        }
        break;

        case 3: //Dirección
        {
            printf("Introduzca la nueva Direcci%cn: ", 162);
            clase[index].Dir = gets(); //Lee Dir, REVISAR

            if(clase[index].Dir != NULL)
                printf("Cambio realizado con %cxito.\n", 130);
            else
            {
                printf("Ha ocurrido un error, vuelva a intentarlo.");
                exit(1); //Vuelve a introducirlo
            }
        }
        break;

        case 4: //Localidad
        {
            printf("Introduzca la nueva Localidad: ");
            clase[index].Loc = gets(); //Lee el nombre, REVISAR

            if(clase[index].Loc != NULL)
                printf("Cambio realizado con %cxito.\n", 130);
            else
            {
                printf("Ha ocurrido un error, vuelva a intentarlo.");
                exit(1); //Vuelve a introducir el nombre
            }
        }
        break;

        case 5: //Curso
        {
            printf("Introduzca el Curso nuevo: ");
            clase[index].Curso = gets(); //Lee el nombre, REVISAR

            if(clase[index].Curso != NULL)
                printf("Cambio realizado con %cxito.\n", 130);
            else
            {
                printf("Ha ocurrido un error, vuelva a intentarlo.");
                exit(1); //Vuelve a introducir el nombre
            }
        }
        break;

        case 6: //Grupo
        {
            printf("Introduzca el Grupo nuevo: ");
            clase[index].Grup = gets(); //Lee el nombre, REVISAR

            if(clase[index].Grup != NULL)
                printf("Cambio realizado con %cxito.\n", 130);
            else
            {
                printf("Ha ocurrido un error, vuelva a intentarlo.");
                exit(1); //Vuelve a introducir el nombre
            }
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
            exit(1);
        }
    }
}

void ficha_alumnos(&clase, i)
{
    printf("%d", clase[i].idUs);
    puts(clase[i].Nomb);
    puts(clase[i].Dir);
    puts(clase[i].Loc);
    puts(clase[i].Curso);
    puts(clase[i].Grup);

    clase = Modificar_ficha(i);
}

void Calificaciones_alum(&clase, i)
{

}


/*Listado de Grupos:

void Menu_Grupos(&clase) ### preguntar al grupo ###
{
}

*/

