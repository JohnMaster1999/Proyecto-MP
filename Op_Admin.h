#ifndef OP_ADMIN_
#define OP_ADMIN_

void Dar_alta(&prof, &clase, &mat, &hor, op1);
void Dar_baja(&prof, &clase, &mat, &hor, op1);
void Modificar(&prof, &clase, &mat, &hor, op1);
void Listar(&prof, &clase, &mat, &hor, op1);
int Menu_Admin2();
void Menu_Operaciones(&prof, &clase, &mat, &hor, op1);
int Menu_Admin1();
void Menu_admin(&prof, &clase, &mat, &hor);

#endif // OP_ADMIN_


/*

INICIO DE SESI�N > ADMINISTRADOR > MEN�: 1.Usuarios 2.Alumnos 3.Materias 4.Horarios >

    -> 1.Usuarios > 1.Dar de alta 2.Dar de baja 3.Modificar 4.Listar
    -> 2.Alumnos > 1.Dar de alta 2.Dar de baja 3.Modificar 4.Listar && Adem�s, mostrar la lista de materias en las que se encuentra matriculado, cambios de matr�cula a otras materias, eliminar matr�cula en alguna materia y crear nuevas matr�culas
    -> 3.Materias > 1.Dar de alta 2.Dar de baja 3.Modificar 4.Listar
    -> 4.Horarios > 1.A�adir horas a profesor 2.Quitar horas a profesor 3.Modificar 4.Listar horario de un profesor

*/
