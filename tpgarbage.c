#include <stdio.h>
#include <stdlib.h> // libreria que contiene las funciones malloc y realloc
#include "garbage.h" // header que contiene las constantes OK y ERROR, y declaraciones de funciones 

int max_mem=1000; //se define la cantidad de memoria que administrara el sistema

int main(){
    int sz; //sz: memoria pedida por el cliente
    char name[10]; //texto con la firma del proceso
    init_gc(max_mem); //llama a la funcion init_gc
    printf("Ingrese un la cantidad de memoria necesaria para el bloque:\n"); //el sistema recibe pedidos de memoria por parte del cliente
    scanf("%d",&sz);
    getchar();
    printf("Ingrese el nombre del nuevo bloque de memoria:\n");
    gets(name);
    new_block(sz, name); //llama a la funcion new_block
    return 0;
}

int init_gc(int max_mem){ //funcion que inicializa el garbage collector
    if (max_mem <= 0)
        return ERROR; 
    else
        return OK;
}

int new_block(int sz,char* name){ //funcion para crear de un nuevo bloque de memoria
    int *block=NULL; //se inicializa la estructura con punteros nulos
    if (sz>0 && sz<max_mem){
        block=(int*)malloc(sizeof(int)*sz); //asigna la memoria dinamica
        return block;
    }
    else
        if(block==NULL){  //si no hay memoria devuelve un identificador invalido
            return ERROR;
    }
}

int* mem_ptr(int block){  //funcion que devuelve un puntero a la memoria del bloque. Busca el bloque de memoria correspondiente al identificador "nombre" y devuelve el puntero
    
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