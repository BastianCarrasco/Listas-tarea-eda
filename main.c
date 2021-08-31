#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"
#include"canciones.h"

int main(){

	  char archivo[20];
    char nombre[41];
    char artista[11];
    char genero[11];
    char lista[10];
    char año[7];

    Cancion* nuevo;

    List * listaCanciones;
    listaCanciones = createList();
    int op;

    while (op!=0)
    {   
        printf("---------------------------------------------------\n");
        printf("1.- Importar Canciones\n");
        printf("2.- Exportar Canciones\n");
        printf("3.- Agregar Cancion\n");
        printf("4.- Buscar Cancion por Nombre\n");
        printf("5.- Buscar Cancion por Artista\n");
        printf("6.- Buscar Cancion por Genero\n");
        printf("7.- Eliminar Cancion\n");
        printf("8.- Mostrar nombres de las listas de reproducción\n");
        printf("9.- Mostrar una lista de reproducción\n");
        printf("10.- Mostrar todas las canciones\n");
        printf("0.- Salir\n");
        printf("---------------------------------------------------\n");
        printf("Indica la opcion: ");
        scanf("%d", &op);
        printf("\n");

        switch(op)
        {         

        case 3:
            printf("Agregar Cancion\n");
            printf("Nombre de la Cancion: ");
            getchar();
            fgets(nombre, 41, stdin); //lee 41 caracteres hasta el salto de linea
            printf("Artista: ");
            fgets(artista,11, stdin);
             printf("Genero: ");
            fgets(genero,11, stdin);
             printf("Año: ");
            fgets(año,7,stdin);
             printf("Lista: ");
            fgets(lista,10, stdin);

             agregarCancion(listaCanciones,nombre,artista,genero,lista,año);
            break;
            return 0;

          case 4:
            printf("Ingrese nombre de la cancion: ");
            getchar();
            fgets(nombre,41,stdin);
            BuscarCancionxNombre(listaCanciones, nombre);
            break;
            return 0;
                }
            }
            return 0;            
}
