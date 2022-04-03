#include "libros.h"
#include <stdio.h>
#include <string.h>

extern Libro libros[];


extern int contador_libro;


int buscar(char *nombre) {

    for (int i = 0; i < contador_libro; ++i) {
        if (strcmp(libros[i].titulo, nombre) == 0) {
            return i;
        }
    }
}

void borrar_libro(char *nombre) {

     int index=buscar(nombre);

     for (int i = 0; i < contador_libro; ++i) {
         if (strcmp(libros[i].titulo,nombre)==0){
             libros[i].to_delete=1;
        }
    }
    printf("Accion realizada\n");
}



void infoLibro(int index) {
   printf( "Titulo del libro: %s\n", libros[index].titulo);
   printf( "Autor del libro: %s\n", libros[index].autor);
   printf( "Anio de publicacion: %s\n", libros[index].anio);
   printf( "Numero del estante: %s\n", libros[index].estante_numero);
   printf( "Seccion del estante: %s\n", libros[index].estante_seccion);
   printf( "Piso: %s\n", libros[index].piso);
   printf( "Edificio: %s\n", libros[index].edificio);
   printf( "Sede: %s\n", libros[index].sede);
}

void cambiar_sede(int index,char sede[90]){

    strcpy(libros[index].sede,sede);

}


void nuevo(int c_libros){

   printf("Nombre del libro a ingresar:");
   char nombre[300];

   //scanf("%s",nombre);
   strcpy(nombre,"nombre");

   printf("Autor de libro a ingresar:");
   char autor[300];
   //scanf("%s",autor);
    strcpy(autor,"asd");

   printf("Anio del libro a ingresar:");
   char anio[300];
  // scanf("%s",anio);
    strcpy(anio,"nomb");

   printf("Numero del estante de libro a ingresar:");
   char nest[300];
   //scanf("%s",nest);
    strcpy(nest,"nombrasde");

   printf("Seccion del libro a ingresar:");
   char seccion[300];
  // scanf("%s",seccion);
    strcpy(seccion,"nombr");

   printf("Piso del libro a ingresar:");
   char piso[300];
  // scanf("%s",piso);
    strcpy(piso,"nomasdb");

   printf("Edificio del libro a ingresar:");
   char edificio[300];
  // scanf("%s",edificio);
    strcpy(edificio,"nombreee");

   printf("Sede del libro a ingresar:");
   char sede[300];

   //scanf("%s",sede);
    strcpy(sede,"no\n");

   Libro libro;

   strcpy(libro.titulo,nombre);

   strcpy(libro.autor,autor);

   strcpy(libro.anio,anio);

   strcpy(libro.estante_numero,nest);

   strcpy(libro.estante_seccion,seccion);

   strcpy(libro.piso,piso);

   strcpy(libro.edificio,edificio);

   strcpy(libro.sede,sede);

   libro.to_delete=0;

   libros[c_libros]=libro;
   contador_libro++;


}
