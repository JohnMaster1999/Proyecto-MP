#ifndef OP_PROFESOR_
#define OP_PROFESOR_

int Opciones();
// ### FUNCI�N VOLVER_ATR�S ###
Alumnos* Modificar_ficha(int index);
void ficha_alumnos(Alumnos *clase, int i);
void Calificaciones_alum(&clase, i);


#endif // OP_PROFESOR_

/*

INICIO DE SESI�N > PROFESOR > MEN�: LISTA DE TODOS LOS GRUPOS DEL PROFESOR (SELECCIONA UNO) > MEN�:(NOMBRE GRUPO) 1.Lista de Alumnos 2.Cambiar de Grupo >

    1)  MOSTRAR TODOS LOS ALUMNOS DEL GRUPO (SELECCIONA UNO) >
        -> 1.Ficha del Alumno > (MOSTRAR DATOS PERSONALES) 2.Modificar (x)
        -> 2.Calificaciones > (MOSTRAR LISTA DE CALIFICACIONES DE LA MATERIA DEL GRUPO ACTUAL) > MEN�: 1.Modificar 2.Borrarla 3.A�adir nueva
        -> 3.Volver atr�s > (VOLVEMOS AL MEN� INICIAL)
    2) (VOLVEMOS AL MEN� INICIAL) > MEN�: LISTA DE TODOS LOS GRUPOS DEL PROFESOR (SELECCIONA UNO) > ...


##FUNCIONES

*/
