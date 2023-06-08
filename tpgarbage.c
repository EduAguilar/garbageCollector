#include <stdio.h>
#include <stdlib.h> // libreria que contiene las funciones malloc y realloc
#include <string.h> // libreria que contiene las funciones strcpy y strlen
#include "garbage.h" // header que contiene las constantes OK y ERROR, y declaraciones de funciones 

int max_mem=1000; //se define la cantidad de memoria que administrara el sistema
int block[]; //como no usamos estructuras, usamos arreglos
int pointer[];
int reference[];
int[];
//---------
int cantidad_reference[]; //lo voy a utilizar al asignar memoria 
char **lista_reference //defino el puntero de punteros


int main(){
    int sz; //sz: memoria pedida por el cliente
    int *p;
    char name[10]; //texto con la firma del proceso
    init_gc(max_mem); //llama a la funcion init_gc
    printf("Ingrese un la cantidad de memoria necesaria para el bloque:\n"); //el sistema recibe pedidos de memoria por parte del cliente
    scanf("%d",&sz);
    getchar();
    printf("Ingrese el nombre del nuevo bloque de memoria:\n");
    fgets(name, sizeof(name), stdin);
    new_block(sz, name); //llama a la funcion new_block
    return 0;
}

int init_gc(int max_mem){ //funcion que inicializa el garbage collector
    if (max_mem <= 0)
        return ERROR; 
    else
        return OK;
}

int new_block(int sz,char* name){ //funcion para reservar de un nuevo bloque de memoria
    int memDisponible=cur_available_memory();//llama a la funcion, para saber la memoria disponible
    if (sz>0 && sz<memDisponible){ //tiene que ser menor a la memoria disponible, no a la memoria total
        block=(int*)malloc(sizeof(int)*sz); //asigna la memoria dinamica
        return block;
    }
    else
        if(name==NULL){  //si no hay memoria devuelve un identificador invalido
            return -1;
    }
    strcpy();
    
}

int* mem_ptr(int block){  //funcion que almacena la referencia que retorna en un puntero. Busca el bloque de memoria correspondiente al identificador "nombre" y devuelve el puntero
    int *p=(int*)block; //se inicializa la estructura con punteros nulos
    return p;
}

int resize(int block, int sz){ //funcion que cambia el tamaño de la memoria del bloque 
    int* resize_block=(int*)realloc(block, sizeof(int)*sz);
    if (resize_block!=NULL){
        block=resize_block;
        return OK;
    } else {
        return ERROR;
    }
}
//-----
//Según lo que le entendí a Daniel, tenemos que definir un puntero a un char pointer en el main
int add_reference(int block){ //se agrega una referencia a un bloque de memoria existente
    
  if(name== NULL)
    return ;
    for (contador_ref=1; contador_ref<10; contador_ref++)´{
        
        name[0] = malloc(strlen(n1) + 1);
        name[1] = malloc(strlen(n2) + 1);
        name[2] = NULL;
        strcpy(name[0], n1);
        strcpy(name[1], n2);
    }
  printf("%s, %s", name[0], name[1]);// veo los bloques reservados en malloc.  Entiendo que sería para 10 bloques, no?
}
    //cuando llega a cero va a llamar a free() --> esto lo hace el remove_reference
   
}

int remove_reference(int block){ //la función llama a free cuando el contador llega a 0
    int contador_ref= 10; //acá se declara otra vez la variable y se toma como valor la cant de bloques reservados??
    while(*lista_nombre && (*lista_nombre)[i] != NULL){
      free((*lista_nombre)[i]);
      i++;
    }
    free(*lista_nombre);
}
     free();
}