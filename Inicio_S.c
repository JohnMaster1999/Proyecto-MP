#include <stdio.h>
#include <stdlib.h>
#include "Inicio_S.h"

//Cabecera: int inicio(Usuarios*, int).
//Precondición: recibe la estructura usuarios y el número de usuarios.
//Postcondición: devuelve la posición del usuario en el vector de estructura.

int inicio(Usuarios *user, int n_usuarios)
{
    char *usu;
    char *pass;
    int id=0, i=0;
    int n=0;

    printf("______________________________________________________\n\t\tInicio de Sesi%cn\n______________________________________________________\n\nUsuario:", 162);

    usu = (char*)malloc(6*sizeof(char));
    pass = (char*)malloc(9*sizeof(char));

    do{
    fgets(usu, 6, stdin); //Lee un usuario
    fflush(stdin);
    usu[6]='\0';
        do{
            if(strcmp(usu, user[i].NomU)==0 && strlen(usu)==strlen(user[i].NomU)) //Busca el usuario para ver si existe en nuestra estructura de usuarios
            {
                printf("\tUsuario encontrado, introduzca la contrase%ca.\n", 164); //Si el usuario coincide pide la contraseña.
                n=1;
            }
            else  //Si el usuario no coincide, lo compara con el siguiente de la lista.
                i++;
        }while(i < n_usuarios && n==0);

        if(i == n_usuarios)
                printf("\tUsuario no encontrado, vuelva a introducir el usuario.\nUsuario:"); //Si el usuario no existe, vuelve a padir uno nuevo.

    }while(n==0);

    while(n==1)
    {
        printf("\nContraseña:");

        fgets(pass, 9, stdin); //Lee una contraseña.
        fflush(stdin);
        usu[9]='\0';

        if(strcmp(pass, user[i].pass)==0 && strlen(pass)==strlen(user[i].pass)) //Comprueba si la contraseña del usuario actual es correcta.
            {
            printf("\t\tContraseña correcta.\n\n\nIniciando sesión..."); //Si es correcta inicia sesión.
            n=0;
            }
        else
            printf("\t\tContraseña incorrecta, vuelve a introducirla."); //Si es incorrecta vuelve a pedir la contraseña.
    }
    return i; //Devuelve la posición del usuario en el vector de usuarios.
}
