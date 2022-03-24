#ifndef OP_PROFESOR_
#define OP_PROFESOR_

int Opciones();
// ### FUNCIÓN VOLVER_ATRÁS ###
Alumnos* Modificar_ficha(int index);
void ficha_alumnos(Alumnos *clase, int i);
void Calificaciones_alum(&clase, i);


#endif // OP_PROFESOR_

/*

INICIO DE SESIÓN > PROFESOR > MENÚ: LISTA DE TODOS LOS GRUPOS DEL PROFESOR (SELECCIONA UNO) > MENÚ:(NOMBRE GRUPO) 1.Lista de Alumnos 2.Cambiar de Grupo >

    1)  MOSTRAR TODOS LOS ALUMNOS DEL GRUPO (SELECCIONA UNO) >
        -> 1.Ficha del Alumno > (MOSTRAR DATOS PERSONALES) 2.Modificar (x)
        -> 2.Calificaciones > (MOSTRAR LISTA DE CALIFICACIONES DE LA MATERIA DEL GRUPO ACTUAL) > MENÚ: 1.Modificar 2.Borrarla 3.Añadir nueva
        -> 3.Volver atrás > (VOLVEMOS AL MENÚ INICIAL)
    2) (VOLVEMOS AL MENÚ INICIAL) > MENÚ: LISTA DE TODOS LOS GRUPOS DEL PROFESOR (SELECCIONA UNO) > ...


##FUNCIONES

*/
