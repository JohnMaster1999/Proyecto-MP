#ifndef T_CLIENTES_H
#define T_CLIENTES_H
typedef struct{
	int id, cartera;
	char nombre[10], apellido[10], direc[50], loc[10], prov[10], email[50], passw[15];
}T_Clientes;

#endif

#ifndef T_ADMINPROV_H
#define T_ADMINPROV_H
typedef struct{
}T_Adminprov;

#endif

#ifndef T_TRANSP_H
#define T_TRANSP_H
typedef struct{
}T_Transportistas;

#endif
