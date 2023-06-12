#include <stdio.h>
#include "garbage.c"

int main() {
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
	
/*
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
*/
	// Prueba de used_memory
	int used_mem = cur_used_memory();
	printf("Used memory: %d\n", used_mem);

	// Prueba de available_memory
	int available_mem = cur_available_memory();
	printf("Available memory: %d\n", available_mem);

	// Prueba de destroy_agent
	destroy_agent();
	
	return 0;
	
}