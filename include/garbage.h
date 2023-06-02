//
//  Programación 1 - Trabajo pràctico: Implementaciòn de un garbage collector.
//
//  Declaración de interfaz de funciones del garbage collector.

// Contantes de valores de retorno de funciones
#define OK         0
#define ERROR   (-1)


//Inicializacion del GC. Se indica cantidad de memoria.
int init_gc(int max_mem);

//Creacion de un nuevo bloque de memoria.
int new_block(int sz,char* name);

//Redimensionamiento de memoria.
int resize(int block, int sz);

//Se agrega una referencia a un bloque de memoria existente.
int add_reference(int block);

//Se elimina una referencia a un bloque de memoria.
int remove_reference(int block);

//Calcula cuanta memoria queda
int cur_used_memory(void);

//Calcula cuanta memoria queda disponible.
int cur_available_memory(void);

//Destructor del GC.
int destroy_agent();
