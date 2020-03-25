#ifndefine PRODUCTOS
#define PRODUCTOS

typedef struct {
	
	int id,precio;
	char nombre [10];
	
}producto; 

int aux;

char modificar (int* id, char* nombre []);

int existencias (int* id, char* nombre[]);

int disponibilidad (int* id, char* nombre[]);

