#include <stdio.h>
#include <stdlib.h> // libreria que contiene las funciones malloc y realloc
#include <string.h> // libreria que contiene las funciones strcpy y strlen
#include "include/garbage.h" // header que contiene las constantes OK y ERROR, y declaraciones de funciones

int max_mem=1000; //se define la cantidad de memoria disponible que administrara el sistema
// Variables globales
int *block=NULL;
int tam_block=0; //tamaño de memoria del bloque
char name[10]; //texto con la firma del proceso
int *referencias[]={0};
int memoria_utilizada=0; //cantidad de memoria utilizada
int bloques_utilizados=0; //cantidad de bloques de memoria

int main(){
    int sz, opcion; //sz: memoria pedida por el cliente
    init_gc(max_mem); //llama a la funcion init_gc
    printf("Ingrese un la cantidad de memoria necesaria para el bloque:\n"); //el sistema recibe pedidos de memoria por parte del cliente
    scanf("%d",&sz);
    getchar();
    printf("Ingrese un texto con la firma del proceso:\n");
    fgets(name, sizeof(name), stdin);
    if (new_block(sz, name)==OK){ //llama a la funcion new_block
        printf("El bloque de memoria ha sido reservado con la firma %s\n", name);
        printf("Identificador: Bloque%d - Memoria reservada: %d - Nombre %s\n", bloques_utilizados, tam_block, name);
        printf("Memoria disponible: %d\n", cur_available_memory());
    }
    else {
        printf("No se pudo reservar el bloque de memoria\n");
    } 
    while(cur_available_memory()>0 && cur_available_memory()<=max_mem){ //mientras haya memoria disponible, se podra reservar nuevos bloques
        printf("Desea crear otro bloque de memoria? (1: Si / 0: No): ");
        scanf("%d",&opcion);  
        if (opcion==1){ 
                printf("Ingrese un la cantidad de memoria necesaria para el nuevo bloque:\n"); //el sistema recibe pedidos de memoria por parte del cliente
                scanf("%d",&sz);
                getchar();
                printf("Ingrese un texto con la firma del proceso:\n");
                fgets(name, sizeof(name), stdin);
                if (new_block(sz, name)==OK){ //llama a la funcion new_block
                    printf("El bloque de memoria ha sido reservado con la firma %s\n", name);
                    printf("Identificador: Bloque%d - Memoria reservada: %d - Nombre %s\n", bloques_utilizados, tam_block, name);
                    printf("Memoria disponible: %d\n", cur_available_memory());
                }
            }
            else{
                printf("No se reservo el bloque de memoria\n");
                break;
        }  
    }
    if(cur_available_memory()==0){ //si no queda memoria disponible
        printf("No hay memoria disponible\n");
    }
    return 0;
}

int init_gc(int max_mem){ //funcion que inicializa el garbage collector, parametro: memoria total del sistema
    if (max_mem<=0)//si la memoria total del sistema es menor o igual a cero,
        return ERROR; //da error
    else
        return OK; //sino se inicia el garbage collector
}

int new_block(int sz,char* name){ //funcion para reservar un nuevo bloque de memoria
    int memoria_disponible=cur_available_memory();//llama a la funcion cur_available_memory(), para saber la memoria disponible
    if (sz>0 && sz<memoria_disponible){ //pregunta si la memoria pedida es menor a la memoria disponible
        block=(int*)malloc(sizeof(int)*sz); //si se cumple la condicion, asigna la memoria dinamica al bloque
        bloques_utilizados=bloques_utilizados+1;
        memoria_utilizada=memoria_utilizada+sz;
        tam_block=sz;
        strncpy(name, name, sizeof(name)-1);
        name[sizeof(name)-1]='\0';
        return OK;
    }
    else
        if(block==NULL){  //si la condicion no se cumple porque no hay memoria, devuelve un identificador invalido
            return ERROR;
    }  
}

int cur_available_memory(void){ //calcula cuanta memoria queda disponible.
    int memoria_disponible=max_mem-memoria_utilizada; //resta la memoria que se va reserrvando a la memoria total del sistema
    if (memoria_disponible==0){ //si ya no queda mas mememoria retorna 0
        return 0;
    }
    else{
    return memoria_disponible; //retorna la cantidad de memoria que queda disponible
    }
}
