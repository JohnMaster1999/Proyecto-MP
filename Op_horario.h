#include "Horarios.h"
#ifndef __OP_HORARIO
#define __OP_HORARIO

  void horarios_darDeAlta(Horarios h);
  void horarios_darDeBaja(int pos);
  void horarios_modificar(int pos, Horarios h);
  void horarios_listar(int Id_P, int h, int d, char* g, int m, int n);
  Horarios horarios_crear(int Id_h,int n);
//dependiendo de n, se listará todos los horarios, o los de x día, x hora, x materia, x profesor ó x grupo

  extern Horarios* vhorarios;
  extern int vhorarios_size;

#endif
