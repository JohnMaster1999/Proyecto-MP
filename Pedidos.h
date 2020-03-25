#ifndef T_PEDIDOS_H
#define T_PEDIDOS_H

typedef struct {
    int id, Fecha, idCli;
    char Lugar[7], idLok[10], regalo[10], promo[10];
} T_Pedidos;

#endif

#ifndef T_PROD_PED_H
#define T_PROD_PED_H

typedef struct {
    int idPed, idProd, nUni, fecha;
    float import, 
    char 
} T_Pedidos;

#endif