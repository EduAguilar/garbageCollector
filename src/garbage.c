#include <stdio.h>
#include <stdlib.h>
#include "garbage.h"

    int *arrayBlock = NULL;
    int *arrayPointer = NULL;
    int *arrayReference = NULL;
    int *arraySZ = NULL;
    int *arrayCantReference = NULL;
    int memMax;

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
    //TODO
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