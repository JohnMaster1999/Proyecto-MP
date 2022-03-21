//Cabecera: int inicio(Usuarios*, int).
//Precondición: recibe la estructura usuarios y el número de usuarios.
//Postcondición: devuelve el ID del usuario.

int inicio(Usuarios *user, int n_usuarios)
{
    char usu[];
    char pass[];
    int id=0, i=0;
    bool n=0;

    printf("            Inicio de Sesion\n-----------------------------------------\n\nUsuario:")

    usu = (char*)malloc(6*sizeof(char));
    pass = (char*)malloc(9*sizeof(char));
    
    do{
    fgets(usu, 6, stdin);
    fflush(stdin);
    usu[6]='\0'
        do{
            if(strcmp(usu, user[i].NomU)==0)
                printf("    Usuario encontrado, introduzca la contraseña.\n");
                n=1;
            else
                i++;
        }while(i < n_usuarios || n==0);

        if(i == n_usuarios)
                printf("    Usuario no encontrado, vuelva a introducir el usuario.\nUsuario:");

    }while(n==0);
    
    do{
    fgets(pass, 9, stdin);
    fflush(stdin);
    usu[9]='\0'
    
    while(id==0)
    {
        printf("Contraseña:");
        if(strcmp(pass, user[i].pass)==0)
            printf("    Contraseña correcta.\n\n\nIniciando sesión...");
            id = user[i].idUs;
        else
            printf("Contraseña incorrecta, vuelve a introducirla.");
    }
    
    return id;

}
