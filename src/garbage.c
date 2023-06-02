#include <stdio.h>
#include <stdlib.h>
#include "garbage.h"



//Declarar las variables del módulo

int init_gc(int max_mem)
{
	//TODO
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