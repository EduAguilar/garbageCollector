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
    int sz = 12;
    char name[10] = "Block 1"; 

int main() {
        int block=NULL; //se inicializa la estructura con punteros nulos
        int memDisponible = 20;
        

    if (sz>0 && sz<memDisponible){
        if (block !=NULL){
            pos++;
            block=(int*)malloc(sizeof(int)*sz); //asigna la memoria dinamica al bloque
            arrayReference = (char**)malloc(sizeof(char*)*sz); //asigna la memoria dinamica al array de referencias
            arraySZ = (int*)malloc(sizeof(int)*sz); //asigna la memoria dinamica al array de tamaños
            arrayCantReference = (int*)malloc(sizeof(int)*sz); //asigna la memoria dinamica al array de cantidades de referencias
            arrayPointer = (int*)malloc(sizeof(int)*sz); //asigna la memoria dinamica al array de punteros
            arrayBlock = (int*)malloc(sizeof(int)*sz); //asigna la memoria dinamica al array de bloques
            arrayBlock [pos]= block; //asigna el bloque al array de bloques
            arraySZ [pos]= sz; //asigna el tamaño al array de tamaños
            arrayPointer [pos]= block; //asigna el puntero al array de punteros
            //arrayCantReference [index]= 0; //asigna la cantidad de referencias al array de cantidades de referencias
            arrayReference [pos]= name; //asigna el nombre al array de referencias
            printf("El bloque %s se ha creado correctamente.\n", name);
        }
        else{
            return ERROR;
        }
    }
    printf("El re bloque %s se ha creado correctamente.\n", name);
    return arrayBlock[pos];
}
