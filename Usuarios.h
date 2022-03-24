#ifndef USUARIOS_H
#define USUARIOS_H

typedef struct Usuarios
{
	int idUs; //3 digitos
	char Nomb[21]; // 20 caracteres
	char Perf[14]; // 13 caracteres
	char NomU[6];  //  5 caracteres
	char pass[9];  //  8 caracteres
				   //  4 caracteres (guiones)
				   //  1 caractere (/0)
				   // 51 caracteres totales
}Usuarios ;

#endif
