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
    int pos = 0;
    

//Declarar las variables del módulo

int init_gc(int max_mem)
{
	//Damos inicio al GC
    max_mem = memMax;
   
    if (max_mem <= 0)
        return ERROR; 
    else
        return OK;
}

int new_block(int sz,char* name)
{
        int *block=NULL; //se inicializa la estructura con punteros nulos
        int memDisponible = cur_available_memory();
        

    if (sz>0 && sz<memDisponible){
        if (block !=NULL){
            block=(int*)malloc(sizeof(int)*sz); //asigna la memoria dinamica al bloque
            arrayReference = (char**)malloc(sizeof(char*)*sz); //asigna la memoria dinamica al array de referencias
            copia_cadena(name,0);


            arraySZ = (int*)malloc(sizeof(int)*sz); //asigna la memoria dinamica al array de tamaños
            arrayCantReference = (int*)malloc(sizeof(int)*sz); //asigna la memoria dinamica al array de cantidades de referencias
            arrayPointer = (int*)malloc(sizeof(int)*sz); //asigna la memoria dinamica al array de punteros
            arrayBlock = (int*)malloc(sizeof(int)*sz); //asigna la memoria dinamica al array de bloques
            pos++;
    
            return OK;
           
        }
        else{
            return ERROR;
        }
    }
   

}


int* mem_ptr(int block)
{
    //TODO
}

int resize(int block, int sz)
{
    //TODO
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