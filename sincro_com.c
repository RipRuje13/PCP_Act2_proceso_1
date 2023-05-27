#include <stdio.h>
#include <string.h>
#include <wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>


FILE *fp;// se crea el archivo
int s1,s2, s3, s4, s5,pid,j,s,cont=0; //declarar sumatoria
char st2[20];
size_t resultado;
void sum(int *arreglo,int in,int n, int *suma);
void archivo(int sumat);

int process_fork(int nproc)
{
    int i;
    for (i = 1; i <= nproc - 1; i++)
    {
    if (fork() == 0)
    return (i);
    }
    return (0);
}


int main() {
    int tamArr = 99; //tamaño del arreglo
    int n = 200; // rango del numero aleatorio
    int arreglo[tamArr];
    int ran; 
    int total=0,i;
    
    srand(time(NULL)); // funcion para generar aleatorio

    for (int i = 0; i<tamArr; i++){
        arreglo[i] = rand()%n;
        //printf("%d, ", arreglo[i]);
    }

        pid = process_fork(5);
        switch(pid){
            
            case 0:
            for (i =0; i < 5; i++) wait(&i);
            /* Abrimos para lectura */
  int suma = 0;
  fp = fopen("Suma.txt", "r");
  if (fp == NULL)
  {
	  printf("El fichero no se ha podido abrir para lectura.\n");
	  return -1;
  }
  // Se lee número por número.
  int num;
  while (!feof(fp))
  {
    resultado = fread(&num, sizeof(int), 1, fp);
	if (resultado != 1)
	{
		break;
	}
	suma = suma + num;
  }

  if (ferror(fp)!=0)
  {
	  printf("Ha ocurrido algún error en la lectura de números.\n");
  }
  else
  {
	  //printf("La suma de los números leídos es: %d\n.",suma);
  }

  if (fclose(fp)!=0)
  {
    printf("No se ha podido cerrar el fichero.\n");
	
  }
            printf("sumatoria total: %d \n", getpid());
            exit(0);
            
            exit(0);

            case 1:
                s1=0;
                sum(arreglo, 0, 19, &s1);
                printf("El valor de la sumatoria del la posicion 0 a 19 es: %d\n",s1);
                printf("Numero de Proceso es [ID %d]\n",getpid());
                archivo(s1);
            exit(0);

            case 2:
                s2=0;
                sum(arreglo, 20, 39, &s2);
                printf("El valor de la sumatoria del la posicion 20 a 39 es: %d\n",s2);
                printf("Numero de Proceso es [ID %d]\n",getpid());
                archivo(s2);
            exit(0);

            case 3:
                s3=0;
                sum(arreglo, 40, 59, &s3);
                printf("El valor de la sumatoria del la posicion 40 a 59 es: %d\n",s3);
                printf("Numero de Proceso es [ID %d]\n",getpid());
                archivo(s3);
            exit(0);

            case 4:
                s4=0;
                sum(arreglo, 60, 79, &s4);
                printf("El valor de la sumatoria del la posicion 60 a 79 es: %d\n",s4);
                printf("Numero de Proceso es [ID %d]\n",getpid());
                archivo(s4);
            exit(0);

            case 5:
                s5=0;
                sum(arreglo, 80, 99, &s5);
                printf("El valor de la sumatoria del la posicion 80 a 99 es: %d\n",s5);
                printf("Numero de Proceso es [ID %d]\n",getpid());
                archivo(s5);
            exit(0);
        }
        

    
}

void sum(int *arr,int in,int n, int *suma){
    if(in<n){
        *suma = *suma + arr[in];
        in++;
        sum(arr,in,n,suma);
    }
}

void archivo(int sumat){

    if((fp=fopen("Suma.txt","a"))==NULL){
        printf("error al abrir el archivo/escritura");
        exit(0);
    }
    else{
        printf("escribiendo archivo \n\n");
        fprintf(fp,"%d\n",sumat);
        fclose(fp);
    }
}