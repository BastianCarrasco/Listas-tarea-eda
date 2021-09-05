#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"
#include"canciones.h"

int main(){

	  char buscar[30];
    char buscar_nombre[30];
    char nombre[41];
    char artista[40];
    char genero[40];
    char lista[10];
    char año[40];

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
       
        FILE * canciones = fopen("canciones.csv","r");
        char linea[300];
        char *token;

        switch(op)
        {  
///////////////////////////////////////////////////////////////////
        case 1:
        
        while(fgets(linea,sizeof(linea), canciones)!=NULL){

          token=strtok(linea,",");
          strcpy(nombre,token);
          token=strtok(NULL,",");
          strcpy(artista,token);
          token=strtok(NULL,",");
          strcpy(genero,token);
          token=strtok(NULL,",");
          strcpy(año,token);
          token=strtok(NULL,"\n");
          strcpy(lista,token);

          

          agregarCancion(listaCanciones, nombre, artista, genero,lista, año);

        }
        break;
//////////////////////////////////////////////////////////////

        case 2:

        
        

//////////////////////////////////////////////////////////////

        case 3:

        printf("Nombre de la Cancion:  ");
        scanf(" %[^\n]",nombre);
        printf("Nombre de Artista:  ");
        scanf(" %[^\n]",artista);
        printf("Nombre de Genero:  ");
        scanf(" %[^\n]",genero);
        printf("Año:  ");
        scanf(" %[^\n]",año);
        printf("Lista:  ");
        scanf(" %[^\n]",lista);
        
        
        agregarCancion(listaCanciones, nombre, artista, genero,lista, año);
        pushBack(listaCanciones,agregarCancion);

        break;
//////////////////////////////////////////////////////////////

        case 4:
      
        printf("Nombre de la Cancion:  ");
        
        scanf(" %[^\n]",buscar);
        
        printf("\n");
        firstList(listaCanciones);

        while(1){

          if (strcmp(listaCanciones->current->data->nombre,buscar)==0){
            printf("Nombre: %s\n",listaCanciones->current->data->nombre);
            printf("Artista: %s\n",listaCanciones->current->data->artista);
            printf("Genero: %s\n",listaCanciones->current->data->genero);
            printf("Año: %s\n",listaCanciones->current->data->año);
            printf("Lista: %s\n",listaCanciones->current->data->lista);
            break;

          }

          nextList(listaCanciones);

          if (listaCanciones->current->next==NULL){
            printf("Cancion no esta en la lista\n ");
            break;
          }
             
        }
        break;
////////////////////////////////////////////////////////////
        case 5:

        firstList(listaCanciones);

        printf("Nombre de Artista: ");
        scanf(" %[^\n]",buscar);
        printf("\n");
        int llave=0;
        while(1){
          

          if (strcmp(listaCanciones->current->data->artista,buscar)==0){
            printf("Nombre: %s\n",listaCanciones->current->data->nombre);
            printf("Artista: %s\n",listaCanciones->current->data->artista);
            printf("Genero: %s\n",listaCanciones->current->data->genero);
            printf("Año: %s\n",listaCanciones->current->data->año);
            printf("Lista: %s\n",listaCanciones->current->data->lista);
            printf("\n");
            llave = 1;
          }

          nextList(listaCanciones);

          if (listaCanciones->current->next==NULL && llave == 0 ){
            printf("Artista no esta en la lista\n ");
            break;
          }
          if (listaCanciones->current->next==NULL && llave == 1){
            break;
          }
          
             
        }
        break;
/////////////////////////////////////////////////////////////////

         case 6:

        firstList(listaCanciones);

        printf("Nombre de Genero: ");
        scanf(" %[^\n]",buscar);
        printf("\n");
        int llave_genero=0;
        char multi_genreo[40];
        char *tok;

       
        
        while(1){
          strcpy(multi_genreo,listaCanciones->current->data->genero);
          tok=strtok(multi_genreo," ");

          while(tok!=NULL){
          

          if (strcmp(tok,buscar)==0){
            printf("Nombre: %s\n",listaCanciones->current->data->nombre);
            printf("Artista: %s\n",listaCanciones->current->data->artista);
            printf("Genero: %s\n",listaCanciones->current->data->genero);
            printf("Año: %s\n",listaCanciones->current->data->año);
            printf("Lista: %s\n",listaCanciones->current->data->lista);
            printf("\n");
            llave_genero = 1;
          }
          tok = strtok(NULL," ");
        }

          

          if (listaCanciones->current->next==NULL && llave_genero == 0 ){
            printf("Genero no esta en la lista\n ");
            break;
          }
          if (listaCanciones->current->next==NULL && llave_genero == 1){
            break;
          }
          nextList(listaCanciones);
             
        }
        break;



//////////////////////////////////////////////////////////////////
        case 7:

    printf("ELIMINAR CANCION \n");

        printf("Nombre de la Cancion:  ");
        scanf(" %[^\n]",nombre);
        EliminarCancion(listaCanciones, nombre, artista, año);
          break;

/////////////////////////////////////////////////////////////////

        case 8:

        firstList(listaCanciones);

        printf("Nombre de la lista:\n");
        scanf(" %[^\n]",buscar);
        printf("\n");
        int cont=0;

        while(1){

          if (strcmp(listaCanciones->current->data->lista,buscar)==0){
            cont++;
          }

          nextList(listaCanciones);

          if (listaCanciones->current->next==NULL && cont == 0 ){
            printf("La lista no existe\n ");
       
            break;
          }
          if (listaCanciones->current->next==NULL && cont >= 1){
            printf ("%s contiene %d canciones\n",buscar,cont);
            break;
          }
             
        }
        break;
        
/////////////////////////////////////////////////////////////////
        case 9:

        firstList(listaCanciones);

        printf("Nombre de Lista: ");
        scanf("  %[^\n]",buscar);
        printf("\n");
        int llave_lista=0;
        

        while(1){

          if (strcmp(listaCanciones->current->data->lista,buscar)>=0){
            printf("Nombre: %s\n",listaCanciones->current->data->nombre);
            printf("Artista: %s\n",listaCanciones->current->data->artista);
            printf("Genero: %s\n",listaCanciones->current->data->genero);
            printf("Lista: %s\n",listaCanciones->current->data->año);
            printf("\n");
            llave_lista = 1;
          }

          nextList(listaCanciones);

          if (listaCanciones->current->next==NULL && llave_lista == 0 ){
            printf("La lista no existe\n ");
       
            break;
          }
          if (listaCanciones->current->next==NULL && llave_lista == 1){
            break;
          }
             
        }
        break;


///////////////////////////////////////////////////////////////////////
       

        case 10:
            
            firstList(listaCanciones);

            while((listaCanciones->current->next)!=NULL){
              printf("Nombre: %s\n",listaCanciones->current->data->nombre);
              printf("Artista: %s\n",listaCanciones->current->data->artista);
              printf("Genero: %s\n",listaCanciones->current->data->genero);
              printf("Año: %s\n",listaCanciones->current->data->año);
              printf("Lista: %s\n ",listaCanciones->current->data->lista);
              printf("\n");
              nextList(listaCanciones);
              
            }

        break; 


///////////////////////////////////////////////////////////////////////  

        case 0:

        printf("PROGRAMA FINALIZADO");
        return 0;    

        
}
    }
    }