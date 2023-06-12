#include <stdio.h>
#include <stdlib.h>
#include "../include/garbage.h"
#include <string.h>

    int *arrayBlock = NULL; //array de bloques
    int *arrayPointer = NULL; //array de punteros
    char **arrayReference = NULL; //array de referencias
    int *arraySZ = NULL; //array de tamaños de memoria de cada bloque
    int *arrayCantReference = NULL; //array de cantidades de referencias
    int memMax; //memoria máxima
    int pos; //posición de los arrays
    int used_memory = 0; //memoria utilizada
    

    

//Declarar las variables del módulo

int init_gc(int max_mem)
{
	//Damos inicio al GC
    memMax = max_mem;
    pos = 0;

    //Inicializamos los arrays asignandoles memoria dinamica
    arraySZ = (int*)malloc(sizeof(int)*1); //asigna la memoria dinamica al array de tamaños
    arrayReference = (char**)malloc(sizeof(char*)*1); //asigna la memoria dinamica al array de referencias
    arrayCantReference = (int*)malloc(sizeof(int)*1); //asigna la memoria dinamica al array de cantidades de referencias
    arrayPointer = (int*)malloc(sizeof(int)*1); //asigna la memoria dinamica al array de punteros
    arrayBlock = (int*)malloc(sizeof(int)*1); //asigna la memoria dinamica al array de bloques
   
    if (max_mem <= 0)
        return ERROR; 
    else
        return OK;
}

int new_block(int sz,char* name)
{
    int memDisponible = cur_available_memory(); //se obtiene la memoria disponible
    printf("Memoria disponible dentro del new_block: %d\n", memDisponible);
    printf("sz: %d\n", sz);
    printf("name: %s\n", name);
    printf("pos: %d\n", pos);
         
    if (sz>0 && sz<memDisponible){
        
        int *block = (int*)malloc(sizeof(int)*sz); //se asigna la memoria dinamica al bloque
        arrayReference [pos] = (char**)malloc(sizeof(char)*strlen(name)); //asigna la memoria dinamica al array de referencias
                
        if (block !=NULL){            
            arrayPointer[pos] = block; //asigna el puntero al array de punteros
            
            arrayBlock[pos] = pos; //asigna el numero de bloque al array de bloques
            arraySZ[pos] = sz; //asigna el tamaño al array de tamaños de memoria de cada bloque
            //arraySZ = (int*)realloc(arraySZ, sizeof(int)*(pos+2)); //asigna la memoria dinamica al array de tamaños
            arrayCantReference[pos] = 1; //asigna la cantidad de referencias al array de cantidades de referencias
            strcpy(arrayReference[pos],name); //asigna el nombre de referencia al array de referencias
            //printf("text: %s\n", arrayReference[pos]);


            pos++;

            return OK;
           
        }
        else{
            return ERROR;
        }
    }
    else{
        printf("Ya no hay memoria disponible.\n");
        return ERROR;
    }
}



int* mem_ptr(int block)
{
    if (block < 0 || block >= pos)
    {
        return ERROR;
    }
    else
    {
        return arrayPointer[block];
    }
}

int resize(int block, int sz)
{
    /*
    block = realloc(block, sizeof(int)*sz);
    arrayBlock = realloc(block, sizeof(int)*sz);
    return block;
    */
}

int add_reference(int block)
{
    //TODO
}

int remove_reference(int block)
{
    //TODO
}

int cur_used_memory(void)
{
    int used_memory = 0;
    for (int i = 0; i < pos; i++)
    {
        used_memory += arraySZ[i];
    }
    return used_memory;
}

int cur_available_memory(void)
{
    return (memMax - cur_used_memory());
}


int destroy_agent()
{
    //TODO
}
