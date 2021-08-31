#ifndef Canciones_h
#define Canciones_h
#include "list.h"

typedef struct{
  char nombre[30];
  char artista[11];
  char genero[11];
  char lista[10];
  char año[7];
}Cancion;



Cancion* crearCancion(char * nombre, char* artista, char* genero, char* lista, char* año);

void agregarCancion(List * list, char * nombre, char* artista, char* genero, char* lista, char* año);

void BuscarCancionxNombre(List* list, char* nombre);

void BuscarCancionGenero(List* list, char* genero);

void MostrarLista(List * list, char* Lista);


#endif /* Canciones_h */