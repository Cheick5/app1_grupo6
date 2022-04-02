#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "libros.h"


Libro libros[999]; //HACEMOS LA ARRAY GLOBAL PARA PODER EDITARLA DENTRO DE TODAS LAS FUNCIONES


int menu(); //Protipo menu
int leer(int argc, char *argv[]);
void printValues();
void cambiar_sede(int index,char sede[]);
int buscar();

int main(int argc, char *argv[]){
    
    leer(argc,argv);
    printValues();
    printf("*************\n");
    cambiar_sede(1,"hola si con quien");
    printValues();
    printf("*************\n");
    getchar();
    return 0;
}




void cambiar_sede(int index,char sede[90]){

    strcpy(libros[index].sede,sede);

}



void printValues(){


    for (int i=0;i<15;i++){
        printf("titulo = %s, " ,libros[i].titulo );
        printf("autor = %s, " ,libros[i].autor  );
        printf("anio = %s, " ,libros[i].anio );
        printf("estante_numero = %s, " ,libros[i].estante_numero );
        printf("estante_seccion = %s, " ,libros[i].estante_seccion );
        printf("piso = %s, " ,libros[i].piso );
        printf("edificio = %s, " ,libros[i].edificio );
        printf("sede = %s, " ,libros[i].sede );
        printf( "delete = %d ", libros[i].to_delete);




        printf("\n");
        printf("\n");
    }
}

int buscar() {
    char nombre[50];
    printf("Escriba el nombre del libro que desea\n");
    scanf("%s", nombre);

    for (int i = 0; i < 6; ++i) {
        if (strcmp(libros[i].titulo, nombre) == 0) {
            return i;
        }
    }
}

int leer(int argc, char *argv[]){
        char archivo[30];

    strcpy(archivo,argv[1]);

    FILE *fp = fopen(archivo,"r"); //abrir en write
    if (!fp){
        printf("FP NO EXISTE");
    }

    char buff[2000];
    int contador_fila = 0;
    int contador_campo = 0;

    int i = 0;

    while(fgets(buff,2000,fp)){
        contador_campo = 0;
        contador_fila ++;

        if(contador_fila == 1){
            continue; //No nos importa la primer fila, ya que son los nombres de cada columna
        }


        char *campo = strtok(buff,","); //Separa una string en una serie de "tokens" usando el delimitador coma https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm

        while (campo){

             switch(contador_campo){
                 case 0: strcpy(libros[i].titulo,campo);
                 break;

                 case 1: strcpy(libros[i].autor,campo);
                 break;

                 case 2: strcpy(libros[i].anio,campo);
                 break;

                case 3: strcpy(libros[i].estante_numero,campo);
                 break;

                 case 4: strcpy(libros[i].estante_seccion,campo);
                 break;

                 case 5: strcpy(libros[i].piso,campo);
                 break;

                 case 6: strcpy(libros[i].edificio,campo);
                 break;

                 case 7: strcpy(libros[i].sede,campo);
                 break;

                 default:
                     break;
             }
             campo = strtok(NULL,","); //actualizar valor del campo
             contador_campo ++;
        }
        libros[i].to_delete=0;
        i++;
    }
    fclose(fp);
}


int menu(){

    // do{
        int x;
        printf("\n**************************************\n");
        printf("\nBienvenido al inventario de libros UAI\n");
        printf("Ingrese uno de los siguientes numeros para hacer la accion a su derecha\n");
        printf("1.  Buscar un libro\n");
        printf("2.  Agregar un libro nuevo\n");
        printf("3.  Quitar un libro existente\n");
        printf("4.  Agregar una sede\n");
        printf("5.  Quitar una sede\n"); //Solo si no tiene libros asociados
        printf("6.  Editar un libro\n");
        printf("7.  Cambiar un libro de sede\n");
        printf("8.  Cambiar un libro de seccion\n");
        printf("9.  Cambiar un libro de piso \n");
        printf("10. Agregar secciones\n");
        printf("11. Eliminar secciones\n"); //Solo si no tiene libros asociados
        printf("12. Agregar pisos\n");
        printf("13. Quitar pisos\n"); //Solo si no tiene libros asociados
        printf("\n**************************************\n");
        scanf("%d", &x);
        return(x);
    // }while(true);
}
