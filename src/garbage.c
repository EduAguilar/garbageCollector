#include <stdio.h>
#include <stdlib.h>
#include "../include/garbage.h"
#include <string.h>

//Declarar las variables del módulo    
    int *arrayBlock = NULL; //array de bloques
    int *arrayPointer = NULL; //array de punteros
    char **arrayReference = NULL; //array de referencias
    int *arraySZ = NULL; //array de tamaños de memoria de cada bloque
    int *arrayCantReference = NULL; //array de cantidades de referencias
    int memMax; //memoria máxima
    int pos; //posición de los arrays
    
//Declarar las funciones del módulo
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
    //printf("Memoria disponible dentro del new_block: %d\n", memDisponible);
    //printf("sz: %d\n", sz);
    //printf("name: %s\n", name);
    //printf("pos: %d\n", pos);
         
    if (sz>0 && sz<=memDisponible){
        
        int *block = (int*)malloc(sizeof(int)*sz); //se asigna la memoria dinamica al bloque
        arrayReference [pos] = (char**)malloc(sizeof(char)*strlen(name)); //asigna la memoria dinamica al array de referencias
                
        if (block !=NULL){            
            arrayPointer[pos] = block; //asigna el puntero al array de punteros
            
            arrayBlock[pos] = pos; //asigna el numero de bloque al array de bloques
            arraySZ[pos] = sz; //asigna el tamaño al array de tamaños de memoria de cada bloque
            arrayCantReference[pos] = 1; //asigna la cantidad de referencias al array de cantidades de referencias
            strcpy(arrayReference[pos],name); //asigna el nombre de referencia al array de referencias
            
            pos++;

            return OK;
        }
        else{
            return ERROR;
        }
    }
    else{
        //printf("Ya no hay memoria disponible.\n");
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
    if (block < 0 || block >= pos)
    {
        printf("Error: índice de bloque inválido\n");
        return ERROR;
    }
    if (sz <= 0) {
        printf("Error: Tamaño de memoria del bloque inválido\n");
        return ERROR;
    }

    int* new_block = (int*)realloc(arrayPointer[block], sizeof(int) * sz);
    
    if (new_block == NULL)
    {
        printf("Error: no se pudo cambiar el tamaño de memoria del bloque\n");
        return ERROR;
    }

    arrayPointer[block] = new_block; //se actualiza el punteros
    arraySZ[block] = sz; //se actualiza el tamaño de memoria del bloque
    return OK;
}

int add_reference(int block) //Esta función debe incrementar el contador de referencias del bloque dado por block
{
    if (block < 0 || block >= pos)
    {
        printf("Error: índice de bloque inválido\n");
        return ERROR;
    }

    arrayCantReference[block]++; //se incrementa el contador de referencias del bloque dado
    return OK;
}

int remove_reference(int block)
{
    /*int remove_reference(int block) //Esta función debe decrementar el contador de referencias 
                                     //del bloque dado por block y, si el contador llega a cero, liberar el bloque de memoria correspondiente
{
    if (block < 0 || block >= pos)
    {
        return ERROR; // Identificador de bloque inválido
    }

    arrayCantReference[block]--;

    if (arrayCantReference[block] == 0)
    {
        free(arrayPointer[block]);
        free(arrayReference[block]);

        // Desplazar los elementos restantes del array hacia atrás
        for (int i = block; i < pos - 1; i++)
        {
            arrayPointer[i] = arrayPointer[i + 1];
            arrayBlock[i] = arrayBlock[i + 1];
            arraySZ[i] = arraySZ[i + 1];
            arrayReference[i] = arrayReference[i + 1];
            arrayCantReference[i] = arrayCantReference[i + 1];
        }

        pos--;
    }

    return OK;
}
*/
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
{    //destroy_agent() //Esta función debe liberar toda la memoria reservada por el GC
    
    //liberamos la memoria de los arrays punteros
    for (int i = 0; i < pos; i++) 
    {
        free(arrayReference[i]);
    }

    //libera la memoria de los arrays
    free(arrayPointer);
    free(arrayBlock);
    free(arraySZ);
    free(arrayReference);
    free(arrayCantReference);

    pos = 0;
}
