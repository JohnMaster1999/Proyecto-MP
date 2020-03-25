#ifndef T_DESCUENTOS_H
#define T_DESCUENTOS_H
typedef struct{
	int tipo, estado, importe, aplic;
	char desc[20], id[10];
}T_Descuentos;

#endif

#ifndef T_DESCUENTOS_CLIENTES_H
#define T_DESCUENTOS_CLIENTES_H
typedef struct{
	int idcli, fecha, cad, estado;
	char idcod[10];
}T_Descuentos;

#endif
