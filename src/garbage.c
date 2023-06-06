#include <stdio.h>
#include <stdlib.h>
#include "../include/garbage.h"
#include <string.h>

    int *arrayBlock = NULL;
    int *arrayPointer = NULL;
    char **arrayReference = NULL;
    int *arraySZ = NULL;
    int *arrayCantReference = NULL;
    int memMax;
    int pos;
    

//Declarar las variables del módulo

int init_gc(int max_mem)
{
	//Damos inicio al GC
    max_mem = memMax;
    pos = 0;
   
    if (max_mem <= 0)
        return ERROR; 
    else
        return OK;
}

int new_block(int sz,char* name)
{
        int *block=NULL; //se inicializa con punteros nulos
        int memDisponible = cur_available_memory(); //se obtiene la memoria disponible
         
    if (sz>0 && sz<memDisponible){
        if (block !=NULL){
            block=(int*)malloc(sizeof(int)*sz); //asigna la memoria dinamica al bloque
            arrayPointer[pos] = block; //asigna el puntero al array de punteros
            arrayBlock[pos] = pos; //asigna el numero de bloque al array de bloques
            arraySZ[pos] = sz; //asigna el tamaño al array de tamaños
            arrayCantReference[pos] = 1; //asigna la cantidad de referencias al array de cantidades de referencias
            strcpy(arrayReference[pos],name); //asigna el nombre de referencia al array de referencias

            /* para revisar si es necesario y en donde iría
            arrayReference = (char**)malloc(sizeof(char*)*sz); //asigna la memoria dinamica al array de referencias
            arraySZ = (int*)malloc(sizeof(int)*sz); //asigna la memoria dinamica al array de tamaños
            arrayCantReference = (int*)malloc(sizeof(int)*sz); //asigna la memoria dinamica al array de cantidades de referencias
            arrayPointer = (int*)malloc(sizeof(int)*sz); //asigna la memoria dinamica al array de punteros
            arrayBlock = (int*)malloc(sizeof(int)*sz); //asigna la memoria dinamica al array de bloques
            */

            pos++;
    
            return OK;
           
        }
        else{
            return ERROR;
        }
    }
    else{
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
    block = realloc(block, sizeof(int)*sz);
    arrayBlock = realloc(block, sizeof(int)*sz);
    return block;
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
    //TODO
}

int cur_available_memory(void)
{
    //TODO
}


int destroy_agent()
{
    //TODO
}


void copia_cadena(char *str,int pos){
    printf("copia: \n");
    arrayReference[pos] = (char*)malloc(sizeof(char)*strlen(str));
    strcpy(arrayReference[pos],str);
    printf("%s\n",arrayReference[pos]);  

}