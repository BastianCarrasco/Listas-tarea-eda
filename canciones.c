#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"list.h"
#include"canciones.h"

Cancion* crearCancion(char * nombre, char* artista, char *genero, char * lista,char* año){
  Cancion* nuevo = (Cancion*) malloc(sizeof(Cancion));
  strcpy(nuevo->nombre, nombre);
  strcpy(nuevo->artista, artista);
  strcpy(nuevo->genero, genero);
  strcpy(nuevo->lista, lista);
  strcpy(nuevo->año, año);
  return nuevo;
}


void agregarCancion(List * list, char * nombre, char* artista, char * genero, char* lista, char* año){
    Cancion* nuevo = crearCancion(nombre,artista,genero,lista,año);
    if(!list->head)pushFront(list,nuevo);
    else pushBack(list,nuevo);
}

Cancion* BuscarNombre(List* list, char* nombre){
    list->current = list->head;
    Cancion* cancion = firstList(list);
    while(strcmp(cancion->nombre,nombre)!=0){
        cancion = nextList(list);
    }
    if(strcmp(cancion->nombre,nombre)==0) return cancion;
    return NULL;
}

void BuscarCancionxNombre(List* list, char* nombre){
    Cancion* cancionBuscado = BuscarNombre(list, nombre);
    if(!cancionBuscado){
        printf("La cancion buscada no existe");
    }else{
        printf("Nombre: %s ", cancionBuscado->nombre);
        printf("Artista: %s", cancionBuscado->artista);
        printf("Genero: %s", cancionBuscado->genero);
        printf("Año: %s", cancionBuscado->año);
        printf("Lista: %s", cancionBuscado->lista);
        printf("\n\n");
    }
}
    
