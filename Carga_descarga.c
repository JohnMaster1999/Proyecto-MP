#include "Carga_descarga.h"
#include <stdio.h>
#include <string.h>

void carga_usu(Usuarios* usu, int* max)
{
	FILE * us;
	//int cmax = 59;
	char c[59];
	*max = 0;
	int i = 0, j;


	us = fopen ("Usuario.txt", "r");


	if (us == NULL)
	{
		puts("Se ha producido un error en la apertura del fichero: usuarios.txt");
		exit (1);
	}else
	{ //USUARIOS.txt abierto exitosamente
		while(fgets(c, 59, us)!=NULL)
		{
			*max++;
			usu = (Usuarios*) realloc(usu, *max * sizeof(Usuarios));
			
			j = 0;
			char id[3];
			do
			{
				id[j] = c[i];
				i++; j++;
			}while(c[i]!='-');
			sscanf(id, "%d", &usu[*max-1].idUs);
			i++;

			j=0;
			do
			{
				usu[*max-1].Nomb[j] = c[i];
				i++; j++;
			}while(c[i]!='-');
			usu[*max-1].Nomb[j] = '/0';
			i++;

			j=0;
			do
			{
				usu[*max-1].Perf[j] = c[i];
				i++; j++;
			}while(c[i]!='-');
			usu[*max-1].Perf[j] = '/0';
			i++;

			j=0;
			do
			{
				usu[*max-1].NomU[j] = c[i];
				i++; j++;
			}while(c[i]!='-');
			usu[*max-1].NomU[j] = '/0';
			i++;

			j=0;
			do
			{
				usu[*max-1].pass[j] = c[i];
				i++; j++;
			}while(c[i]!= '/n' && c[i] != EOF);
			usu[*max-1].pass[j] = '/0';
			i=0;

		}
		fclose(us);
	}

}

void carga_mat(Materias* mate, int* max)
{
	FILE * mat;
	//int cmax = 59;
	char c[59];
	*max = 0;
	int i = 0, j;

	mat = fopen ("Materias.txt", "r");

	if (mat == NULL)
	{
		puts("Se ha producido un error en la apertura del fichero: materias.txt");
		exit (1);
	}else
	{//MATERIAS.TXT abierto exitosamente
		while(fgets(c, 59, mat) != NULL)
		{
			*max++;
			mate = (Materias*) realloc(mate, *max * sizeof(Materias));
			j = 0;
			char id[4];
			do
			{
				id[j] = c[i];
				i++; j++;
			}while(c[i]!='-');
			sscanf(id, "%d", &mate[*max-1].Id_materia);
			i++;

			j = 0;
			do
			{
				mate[*max-1].Nombre_Materia[j] = c[i];
				i++; j++;
			}while (c[i] != '-');
			mate[*max-1].Nombre_Materia[j] = '/0';
			i++;

			j = 0;
			do
			{
				mate[*max-1].Abrev_materia[j] = c[i];
				i++; j++;
			}while (c[i] != '/n' && c[i] != EOF);
			mate[*max-1].Abrev_materia[j] = '/0';
			i = 0;

		}
		fclose(mat);
	}
}

void carga_hor(Horarios* h, int* max)
{
	FILE * hor;
	//int cmax = 59;
	char c[59];
	*max = 0;
	int i = 0, j;

	hor = fopen ("Horarios.txt", "r");

	if (hor == NULL)
	{
		puts("Se ha producido un error en la apertura del fichero: materias.txt");
		exit (1);
	}else
	{//HORARIOS.TXT abierto exitosamente
		while(fgets(c, 59, hor) != NULL)
		{
			*max++;
			h = (Horarios*) realloc(h, *max * sizeof(Horarios));

			j = 0;
			char id[3];
			do
			{
				id[j] = c[i];
				i++; j++;
			}while(c[i]!='-');
			sscanf(id, "%d", &h[*max-1].Id_Profesor);
			i++;

			char dia;
			dia = c[i];
			sscanf(dia, "%d", &h[*max-1].Dia_Clase);
			i++;

			j = 0;
			char hor_clas[6];
			do
			{
				hor_clas[j] = c[i];
				i++; j++;
			}while(c[i]!='-');
			sscanf(hor_clas, "%d", &h[*max-1].Hora_Clase);
			i++;

			j = 0;
			char id_mat[4];
			do
			{
				id_mat[j] = c[i];
				i++; j++;
			}while(c[i]!='-');
			sscanf(id_mat, "%d", &h[*max-1].Id_materia);
			i++;


			j = 0;
			do
			{
				h[*max-1].Grupo[j] = c[i];
				i++; j++;
			}while (c[i] != '/n' && c[i] != EOF);
			h[*max-1].Grupo[j] = '/0';
			i = 0;
		}
		fclose(hor);
	}
}

void carga_cal(Calif* ca, int* max, int idM, int idA)
{
	FILE * cal;
	//int cmax = 59;
	char c[57];
	*max = 0;
	int i = 0, j;

	cal = fopen ("Calificaciones.txt", "r");

	if (cal == NULL)
	{
		puts("Se ha producido un error en la apertura del fichero: Calificaciones.txt");
		exit (1);
	}else
	{//CALIFICACIONES.TXT abierto exitosamente
		while(fgets(c, 57, cal) != NULL)
		{
			i = 41;
			j = 0;
			char idMa[4];
			int idMat;
			do
			{
				idMa[j] = c[i];
				i++; j++;
			}while(c[i]!='-');
			sscanf(idMa, "%d", &idMat);
			i++;
			
			j = 0;
			char idAl[6];
			int idAlu;
			do
			{
				idAl[j] = c[i];
				i++; j++;
			}while(c[i]!='-');
			sscanf(idAl, "%d", &idAlu);

			if (idMat == idM && idAlu == idA)
			{
				*max++;
				ca = (Calif*) realloc(ca, *max * sizeof(Calif));

				i = 0;
				j = 0;
				char dia[2];
				do
				{
					dia[j] = c[i];
					i++; j++;
				}while(c[i]!='/');
				sscanf(dia, "%d", &ca[*max].Fech_calif.dia);
				i++;
				
				j = 0;
				char mes[2];
				do
				{
					mes[j] = c[i];
					i++; j++;
				}while(c[i]!='/');
				sscanf(mes, "%d", &ca[*max].Fech_calif.mes);
				i++;
				
				j = 0;
				char anio[4];
				do
				{
					anio[j] = c[i];
					i++; j++;
				}while(c[i]!='-');
				sscanf(anio, "%d", &ca[*max].Fech_calif.anio);
				i++;
				
				j = 0;
				do
				{
					ca[*max].Desc_calif[j] = c[i];
					i++; j++;
				}while(c[i]!='-');
				ca[*max].Desc_calif[j] = '/0';
				i++;

				ca[*max].Id_amun = idA;

				ca[*max].Id_materia = idM;

				i = 55;
				j = 0;
				char calficacion[2];
				do
				{
					calficacion[j] = c[i];
					i++; j++;
				}while(c[i]!='/n' && c[i] != EOF);
				sscanf(calficacion, "%d", &ca[*max].Valor_calif);

			}

		}
		fclose(cal);
	}

}

void carga_al(Alumnos* al, Materias* materias, int maxM, int* max)
{
	FILE * alu;
	//int cmax = 59;
	char c[132];
	*max = 0;
	int i = 0, j;

	alu = fopen ("Alumnos.txt", "r");

	if (alu == NULL)
	{
		puts("Se ha producido un error en la apertura del fichero: alumnos.txt");
		exit (1);
	}else
	{//ALUMNOS.TXT abierto exitosamente
		while(fgets(c, 132, alu) != NULL)
		{
			*max++;
			al = (Alumnos*) realloc(al, *max * sizeof(Alumnos));

			j = 0;
			char id[6];
			do
			{
				id[j] = c[i];
				i++; j++;
			}while(c[i]!='-');
			sscanf(id, "%d", &al[*max-1].idUs);
			i++;

			j = 0;
			do
			{
				al[*max-1].Nomb[j] = c[i];
				i++; j++;
			}while (c[i] != '-');
			al[*max-1].Nomb[j] = '/0';
			i++;

			j = 0;
			do
			{
				al[*max-1].Dir[j] = c[i];
				i++; j++;
			}while (c[i] != '-');
			al[*max-1].Dir[j] = '/0';
			i++;

			j = 0;
			do
			{
				al[*max-1].Loc[j] = c[i];
				i++; j++;
			}while (c[i] != '-');
			al[*max-1].Loc[j] = '/0';
			i++;

			j = 0;
			do
			{
				al[*max-1].Curso[j] = c[i];
				i++; j++;
			}while (c[i] != '-');
			al[*max-1].Curso[j] = '/0';
			i++;

			j = 0;
			do
			{
				al[*max-1].Grup[j] = c[i];
				i++; j++;
			}while (c[i] != '/n' && c[i] != EOF);
			al[*max-1].Grup[j] = '/0';
			i++;

			FILE *matri;
			char c2[12];
			al[*max-1].nMat = 0;
			
			matri = fopen ("Matriculas.txt", "r");

			if (matri == NULL)
			{
				puts("Se ha producido un error en la apertura del fichero: Matriculas.txt");
				exit (1);
			}else
			{//MATRICULAS.TXT abierto exitosamente
				while(fgets(c2, 12, matri) != NULL)
				{
					j = 0;
					i = 5;
					char id_alum[6];
					int idAlMa;
					do
					{
						id_alum[j] = c[i];
						i++; j++;
					}while(c[i]!='/n' && c[i] != EOF);
					sscanf(id_alum, "%d", &idAlMa);

					if (id_alum == al[*max-1].idUs)
					{
						al[*max-1].nMat++;
						al[*max-1].Materias = (Mat_Alum*) realloc(al[*max-1].Materias, al[*max-1].nMat * sizeof(Mat_Alum));

						j = 0;
						i = 0;
						char id_materia[4];
						int idMaMa;
						do
						{
							id_materia[j] = c[i];
							i++; j++;
						}while(c[i]!='-');
						sscanf(id_materia, "%d", &idMaMa);

						i=0;
					
						do
						{
							if (materias[i].Id_materia == idMaMa)
							{
								strcpy(al[*max].Materias[al[*max-1].nMat].Mat, materias[i].Nombre_Materia);
								i = maxM + 1;
							}
							i++;
						} while (i<=maxM);

						carga_cal (al[*max].Materias[al[*max].nMat].Calf_, &al[*max].Materias[al[*max].nMat].nCal, idMaMa, idAlMa);

					}					

				}
				fclose(matri);
			}

		}
		fclose(alu);
	}
}


void guarda_usu(Usuarios* usu, int* max)
{
	FILE *fich;
    int i=0;

    fich=fopen("Usuarios.txt","w+");

    while(i < *max - 1)
	{
      fprintf(fich, "%03d-%s-%s-%s-%s\n", usu[i].idUs, usu[i].Nomb, usu[i].Perf, usu[i].NomU, usu[i].pass);
       i++;
    }
	fprintf(fich, "%03d-%s-%s-%s-%s", usu[i].idUs, usu[i].Nomb, usu[i].Perf, usu[i].NomU, usu[i].pass);

    printf("\n Usuarios guardados.\n");
	fclose(fich);
}

void guarda_mat(Materias* mate, int* max)
{
	FILE *fich;
    int i=0;

    fich=fopen("Materias.txt","w+");

	while(i < *max - 1)
	{
        fprintf(fich, "%04d-%s-%s\n", mate[i].Id_materia, mate[i].Nombre_Materia, mate[i].Abrev_materia);
	    i++;
    }
	fprintf(fich, "%04d-%s-%s", mate[i].Id_materia, mate[i].Nombre_Materia, mate[i].Abrev_materia);

    printf("\n Materias guardadas.\n");
	fclose(fich);
}

void guarda_hor(Horarios* h, int* max)
{
	FILE *fich;
    int i=0;

    fich=fopen("Horarios.txt","w+");

	while(i < *max - 1)
	{
    	fprintf(fich, "%03d-%d-%d-%04d-%s\n", h[i].Id_Profesor, h[i].Dia_Clase, h[i].Hora_Clase, h[i].Id_materia, h[i].Grupo);
        i++;
  	}
	fprintf(fich, "%03d-%d-%d-%04d-%s", h[i].Id_Profesor, h[i].Dia_Clase, h[i].Hora_Clase, h[i].Id_materia, h[i].Grupo);

    printf("\n Horarios guardados.\n");
	fclose(fich);
}

void guarda_cal(Calif* cal, int max, char finChar)
{
	FILE *fich;
    int i=0;

    fich=fopen("Calificaciones.txt","a"); //append

	while(i < max - 1)
	{
    	fprintf(fich, "%02d/%02d/%04d-%s-%04d-%06d-%d\n", cal[i].Fech_calif.dia, cal[i].Fech_calif.mes, cal[i].Fech_calif.anio, cal[i].Desc_calif, cal[i].Id_materia, cal[i].Id_amun, cal[i].Valor_calif);
        i++;
  	}
	fprintf(fich, "%02d/%02d/%04d-%s-%04d-%06d-%d%c\n", cal[i].Fech_calif.dia, cal[i].Fech_calif.mes, cal[i].Fech_calif.anio, cal[i].Desc_calif, cal[i].Id_materia, cal[i].Id_amun, cal[i].Valor_calif, finChar);
	fclose(fich);
}

void guarda_matr(Mat_Alum* materias, int max, int idA, char finChar)
{
	FILE *fich1, *fich2;
    int i=0;

    fich1=fopen("Matriculas.txt","a"); //append
	fich2 = fopen("Calificaciones.txt", "w+"); //borra en contenido
	fclose(fich2);

	while(i < max - 1)
	{
    	fprintf(fich1, "%04d-%06d\n", materias[i].Calf_->Id_materia, idA);
		guarda_cal(materias[i].Calf_, materias[i].nCal, '/n');
        i++;
  	}
	fprintf(fich1, "%04d-%06d%c", materias[i].Calf_->Id_materia, idA, finChar);
	guarda_cal(materias[i].Calf_, materias[i].nCal, EOF);
	fclose(fich1);
}

void guarda_al(Alumnos* al, int* max)
{
	FILE *fich1, *fich2;
    int i=0;

    fich1=fopen("Alumnos.txt","w+");
	fich2=fopen("Matriculas.txt", "w+"); //Borra el contenido
	fclose(fich2);

    while(i < *max - 1)
	{
        fprintf(fich1, "%06d-%s-%s-%s-%s-%s\n", al[i].idUs, al[i].Nomb, al[i].Dir, al[i].Loc, al[i].Curso, al[i].Grup);
		guarda_matr(al[i].Materias, al[i].nMat, al[i].idUs, '/n');
        i++;
    }
	fprintf(fich1, "%06d-%s-%s-%s-%s-%s", al[i].idUs, al[i].Nomb, al[i].Dir, al[i].Loc, al[i].Curso, al[i].Grup);
	guarda_matr(al[i].Materias, al[i].nMat, al[i].idUs, EOF);

	printf("\n Alumnos guardados.\n");
    printf("\n Materias guardadas.\n");
    printf("\n Calificaciones guardadas.\n");
	fclose(fich1);
	
}

void Carga_datos (Alumnos* al, Materias* mate, Horarios* hor, Usuarios* usu, int* alM, int* matM, int* horM, int* usM)
{
	carga_usu(usu, usM);
	carga_mat(mate, matM);
	carga_hor(hor, horM);
	carga_al(al, mate, *matM, alM);
}

void Guarda_datos (Alumnos* al, Materias* mate, Horarios* hor, Usuarios* usu, int* alM, int* matM, int* horM, int* usM)
{
	guarda_al(al, alM);
	guarda_usu(usu, usM);
	guarda_mat(mate, matM);
	guarda_hor(hor, horM);
}
