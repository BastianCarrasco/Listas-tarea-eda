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
    if(list->head==NULL)pushFront(list,nuevo);
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

Cancion* BuscarArtista(List* list, char* artista){
    list->current = list->head;
    Cancion* cancion = firstList(list);
    while(strcmp(cancion->artista,artista)!=0){
        cancion = nextList(list);
    }
    if(strcmp(cancion->artista,artista)==0) return cancion;
    return NULL;
}

Cancion* BuscarAño(List* list, char* año){
    list->current = list->head;
    Cancion* cancion = firstList(list);
    while(strcmp(cancion->año,año)!=0){
        cancion = nextList(list);
    }
    if(strcmp(cancion->año,año)==0) return cancion;
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
    
void EliminarNombre (List * list, char* nombre){
  list->current = list->head;
  Cancion * cancion = BuscarNombre(list, nombre);
  popCurrent (list);
}

void EliminarArtista (List * list, char* artista){
  list->current = list->head;
  Cancion * cancion = BuscarArtista(list, artista);
  popCurrent (list);
}

void EliminarAño (List * list, char* año){
  list->current = list->head;
  Cancion * cancion = BuscarAño(list, año);
  popCurrent (list);
}

void EliminarCancion (List * list, char* nombre, char* artista, char* año){

  EliminarNombre(list,nombre);
  EliminarArtista(list,artista);
  EliminarAño(list,año);

  printf("----------------------\n");
  printf("  CANCION ELIMINADA\n");
  printf("----------------------\n");


}
