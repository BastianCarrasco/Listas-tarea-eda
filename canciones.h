#ifndef Canciones_h
#define Canciones_h
#include "list.h"

/*typedef struct{
  char nombre[40];
  char artista[40];
  char genero[40];
  char lista[40];
  char año[40];
}Cancion;*/




Cancion* crearCancion(char * nombre, char* artista, char* genero, char* lista, char* año);

void agregarCancion(List * list, char * nombre, char* artista, char* genero, char* lista, char* año);

void BuscarCancionxNombre(List* list, char* nombre);

void BuscarCancionGenero(List* list, char* genero);

void MostrarLista(List * list, char* Lista);

void EliminarCancion (List * list, char* nombre, char* artista, char* año);


#endif /* Canciones_h */