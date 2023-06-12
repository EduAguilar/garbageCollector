#include <stdio.h>
#include "garbage.c"

int main() {
    char name[20]; //texto con la firma del proceso
    int sz =1; //tamaño de memoria
    int opcion =1; //variable para elegir si se quiere seguir creando bloques de memoria
    int i=0; //contador de bloques
    int max_mem = 1000; //se define la cantidad de memoria disponible que administrara el sistema

    init_gc(max_mem); //llama a la funcion init_gc

    while(sz>0 && opcion==1){ //mientras la memoria pedida sea menor o igual a la memoria disponible, se podra seguir reservando memoria
        printf("Ingrese la cantidad de memoria necesaria para el nuevo bloque:\n"); //el sistema recibe pedidos de memoria por parte del cliente
        scanf(" %i",&sz);
        getchar();
        printf("Ingrese un texto con la firma del proceso:\n");
        fgets(name, sizeof(name), stdin);

//sz <= cur_available_memory()
        if (sz <= cur_available_memory()){ 
            if (new_block(sz, name)==OK){ //llama a la funcion new_block
                printf("El bloque de memoria ha sido reservado con la firma %s\n", name);
                printf("Identificador: Bloque %i - Memoria reservada: %i - Nombre %s\n", arrayBlock[i], arraySZ[i], name);
                printf("Memoria disponible: %d\n", cur_available_memory());
                i++;
            }
        }
        else{
            printf("No se reservo el bloque de memoria, la memoria es insuficiente.\n");
            printf("Su memoria disponible es: %d\n", cur_available_memory());
            printf("Asigne menos memoria al nuevo bloque\n");
            //break;
        }
        if(cur_available_memory()==0){ //si no queda memoria disponible
        printf("Ya No hay memoria disponible\n");
        break;
        }
        printf("Desea crear otro bloque de memoria? (1: Si / 0: No): ");
        scanf(" %i",&opcion);     
    }

    return 0;	


/* Caso de prueba para aprobacion del tp    
    int max_mem = 1000;
	int block1, block2, block3, block4;

//prueba de init_gc y new_block con caso de prueba

	// Prueba de init_gc
	init_gc(max_mem);


	// Prueba de new_block
	block1 = new_block(200, "Block 1");
	block2 = new_block(300, "Block 2");
	block3 = new_block(150, "Block 3");
	block4 = new_block(400, "Block 4");
	

	// Prueba de resize
	resize(block2, 400);
	resize(block4, 250);

	// Prueba de add_reference
	add_reference(block1);
	add_reference(block2);
	add_reference(block2); // Agregar dos referencias al mismo bloque
	add_reference(block3);

	// Prueba de remove_reference
	remove_reference(block2);
	remove_reference(block2); // Quitar una referencia más al mismo bloque

	// Prueba de used_memory
	int used_mem = cur_used_memory();
	printf("Used memory: %d\n", used_mem);

	// Prueba de available_memory
	int available_mem = cur_available_memory();
	printf("Available memory: %d\n", available_mem);

	// Prueba de destroy_agent
	destroy_agent();
	
	return 0;
*/	
}