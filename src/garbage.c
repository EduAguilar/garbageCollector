#include <stdio.h>
#include <stdlib.h>
#include "../include/garbage.h"
#include <string.h>

//Declarar las variables del módulo    
    int *arrayBlock = NULL; //array de bloques
    int **arrayPointer = NULL; //array de punteros
    char **arrayReference = NULL; //array de referencias
    int *arraySZ = NULL; //array de tamaños de memoria de cada bloque
    int *arrayCantReference = NULL; //array de cantidades de referencias
    int memMax; //memoria máxima
    int pos; //posición de los arrays
    
//Se declara las funciones del módulo
int init_gc(int max_mem) //Esta función inicializa el GC.
{
    printf("Estoy en init_gc\n");
    memMax = max_mem;
    pos = 0;

    //Inicializamos los arrays asignandoles memoria dinamica
    arraySZ = (int*)malloc(sizeof(int)*1); //asigna la memoria dinamica al array de tamaños
    arrayReference = (char**)malloc(sizeof(char*)*1); //asigna la memoria dinamica al array de referencias
    arrayCantReference = (int*)malloc(sizeof(int)*1); //asigna la memoria dinamica al array de cantidades de referencias
    arrayPointer = (int**)malloc(sizeof(int*)*1); //asigna la memoria dinamica al array de punteros
    arrayBlock = (int*)malloc(sizeof(int)*1); //asigna la memoria dinamica al array de bloques
   
    if (max_mem <= 0)
        return ERROR; 
    else
        return OK;
}

int new_block(int sz,char* name) //Esta función crea un nuevo bloque de memoria.
{
    printf("Estoy en new_block\n");
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
            
            return arrayBlock[pos-1];
        }
        else{
            return ERROR;
        }
    }
    else if (cur_available_memory() == 0)
    {
        printf("Ya no hay memoria disponible.\n");
        return ERROR;
    }    
    else{
        printf("No se reservo el bloque de memoria, la memoria es insuficiente.\n");  
        printf("Su memoria disponible es: %d\n", cur_available_memory());      
    }
}

int* mem_ptr(int block) //Esta función devuelve el puntero al bloque de memoria dado
{
    printf("Estoy en mem_ptr\n");
    if (block < 0 || block >= pos)
    {
        return ERROR;
    }
    else
    {
        return arrayPointer[block];
    }
}

int resize(int block, int sz) //Esta función cambia el tamaño de memoria del bloque dado
{
    printf("Estoy en resize\n");

    if (block < 0 || block >= pos)
    {
        printf("Error: índice de bloque inválido\n");
        return ERROR;
    }
    if (sz <= 0) {
        printf("Error: Tamaño de memoria del bloque inválido\n");
        return ERROR;
    }

    int* resize_block = (int*)realloc(arrayPointer[block], sizeof(int) * sz);
    
    printf("estoy en resize, despues del realloc\n");
    if (resize_block == NULL)
    {
        printf("Error: no se pudo cambiar el tamaño de memoria del bloque\n");
        return ERROR;
    }

    arrayPointer[block] = resize_block; //se actualiza el punteros
    arraySZ[block] = sz; //se actualiza el tamaño de memoria del bloque
    return OK;
}

int add_reference(int block) //Esta función incrementa el contador de referencias del bloque dado
{
    printf("Estoy en add_reference\n");
    if (block < 0 || block >= pos)
    {
        printf("Error: índice de bloque inválido\n");
        return ERROR;
    }

    arrayCantReference[block]++; //se incrementa el contador de referencias del bloque dado
    return OK;
}

int remove_reference(int block) //Esta función decrementa el contador de referencias del bloque dado
{
    printf("Estoy en remove_reference\n");
    if (block < 0 || block >= pos)
    {
        printf("Error: índice de bloque inválido\n");
        return ERROR;
    }

    arrayCantReference[block]--; //se decrementa el contador de referencias del bloque dado

    if (arrayCantReference[block] == 0) // Si el contador de referencias llega a cero, se liberar el bloque de memoria correspondiente.
    {
        free(arrayPointer[block]);
        free(arrayReference[block]);

        // Desplazar los elementos restantes del array hacia atrás, para no dejar espacios vacíos
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

int cur_used_memory(void) //Esta función calcula y devuelve la cantidad de memoria usada
{
    int used_memory = 0;
    for (int i = 0; i < pos; i++)
    {
        used_memory += arraySZ[i];
    }
    return used_memory;
}

int cur_available_memory(void) //Esta función devuelve la cantidad de memoria disponible
{
    return (memMax - cur_used_memory());
}

int destroy_agent() //Esta función libera toda la memoria reservada por el GC
{       
    printf("Estoy en destroy_agent\n"); 
    //liberamos la memoria de los arrays punteros
    for (int i = 0; i < pos; i++) 
    {
        free(arrayReference[i]);
        free(arrayPointer[i]);
    }
    
    //libera la memoria de los arrays
    free(arrayReference);
    free(arrayPointer);
    free(arrayBlock);
    free(arraySZ);
    free(arrayReference);
    free(arrayCantReference);

    pos = 0;
    
}
