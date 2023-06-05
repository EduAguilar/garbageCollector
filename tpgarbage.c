#include <stdio.h>
#include <stdlib.h> // libreria que contiene las funciones malloc y realloc
#include <string.h> // libreria que contiene las funciones strcpy y strlen
#include "garbage.h" // header que contiene las constantes OK y ERROR, y declaraciones de funciones 

int max_mem=1000; //se define la cantidad de memoria que administrara el sistema
int block[]; //como no usamos estructuras, usamos arreglos
int pointer[];
int reference[];
int[];
int[];

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

int add_reference(int block){ //se agrega una referencia a un bloque de memoria existente
    //cuando llega a cero va a llamar a free()
    free();
}