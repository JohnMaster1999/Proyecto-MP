#include "Op_alum.h"
#include "Alumnos.h"

Alumnos *clase;
int num_alum, num_mat, num_grup, num_calif;

clase = (Alumnos*)malloc(num_alum*sizeof(Alumnos));

/* OPERACIONES DEL PROFESOR CON RESPECTO A UN ALUMNO SELECCIONADO */

void ficha_alumnos(Alumnos *clase, int  a)
{
    printf("%d", clase[a].idUs);
    puts(clase[a].Nomb);
    puts(clase[a].Dir);
    puts(clase[a].Loc);
    puts(clase[a].Curso);
    puts(clase[a].Grup);

    Modificar_ficha(a);
}

int Menu_Calif()
{
    int op;

    printf("%cQu%c quieres hacer? \n", 168, 130);
    printf("\t1.Modificar calificaci%cn\n", 162);
    printf("\t2.Borrar calificaci%cn\n", 162);
    printf("\t3.A%cadir calificaci%cn\n\n", 164, 162);

    printf("Indique su opci%cn", 162);
    scanf("%d", &op);

    return op;
}

int Lista_Cal(Alumnos *clase, int  a, int n)
{
    int i = 0, cal;

    printf("%s: \n", clase[a]->Materias[n].mat);

    do
    {
        printf("\t%d. %d\n", i+1, clase[a]->Materias[n]->Calf[i].Valor_calif);
        i++;
    }while(i < num_calif);

    printf("Indica la calificaci%cn que desea modificar/borrar/a%cadir: \n", 162, 164);
    scanf("%d", &cal);

    return cal;
}

void Modificar_Calif(Alumnos *clase, int  a, int n, int cal)
{
    printf("Introduzca la nueva calificaci%cn: \n");
    scanf("%d", clase[a]->Materias[n]->Calf[cal].Valor_calif);

    if(clase[a]->Materias[n]->Calf[cal].Valor_calif == NULL)
        printf("Calificaci%cn modificada con %cxito.\n", 162, 130);
    else
    {
        printf("Ha ocurrido un error, vuelva a seleccinar una calificaci%cn.\n", 162);
        Calificaciones_alum(clase, a, n);
    }
}

void Borrar_Calif(Alumnos *clase, int  a, int n, int cal)
{
    clase[a]->Materias[n]->Calf[cal].Valor_calif = 0;
    clase[a]->Materias[n]->Calf[cal].Valor_calif = (Calif*)realloc(clase[a]->Materias[n]->Calf[cal].Valor_calif, (num_calif-1)*sizeof(Calif));

    printf("Calificaci%cn borrada con %cxito.\n", 162, 130);
}

void Meter_Calif(Alumnos *clase, int  a, int n, int cal)
{
    clase[a]->Materias[n]->Calf[cal].Valor_calif = (Calif*)realloc(clase[a]->Materias[n]->Calf[cal].Valor_calif, (num_calif+1)*sizeof(Calif));

    printf("Introduzca la nueva calificaci%cn: \n");
    scanf("%d", clase[a]->Materias[n]->Calf[num_calif].Valor_calif);

    printf("Calificaci%cn a%cadida con %cxito.\n", 162, 164, 130);
}

void Calificaciones_alum(Alumnos *clase, int  a, int n)
{
    int op, cal;

    cal = Lista_Cal(clase, a, n);

    op = Menu_Calif();

    switch(op)
    {
        case 1: Modificar_Calif(clase, cal);
        break;

        case 2: Borrar_Calif(clase);
        break;

        case 3: Meter_Calif(clase);
        break;

        default:
        {
            printf("Ha ocurrido un error.\n");
            Calificaciones_alum(clase, a, n);
        }
    }
}
