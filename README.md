# Aplicación Garbage Collector

**Proyecto para el Trabajo Práctico Integrador**



----
**Autores**:  Aguilar Eduardo, Bravo Gonzalo, Carriqueo Mariela, VelazqueZ Laura.

**Materia**: Programación I.

**Universidad**: Universidad Nacional de Río Negro.

**Profesores**: Mariguin Miguel, Teira Daniel.

**Año Lectivo**: 2023

----


# Proyecto

## *_Descripción del problema_*

Un garbage collector (recolector de basura) es un agente que administra un
bloque de memoria para un conjunto de programas que necesitan ejecutar sus
algoritmos. Su funcionamiento se describe en los párrafos que siguen:

● Al arrancar el sistema se define la cantidad de memoria que administrará
el sistema y se inicializa la estructura con punteros nulos.

● Una vez en ejecución, el sistema recibe pedidos de memoria por parte de
los clientes. Este pedido puede venir acompañado de una cantidad de
memoria necesaria y un texto con la firma del proceso.
  - En caso de haber disponibilidad de memoria a reservar, se devuelve
un identificador del puntero,que usará el programa para operar.
  - Los identificadores se guardan en una variable de tipo int.
  - En caso de no haber disponibilidad debe devolver un identificador
inválido.

● Durante la ejecución del sistema, un cliente con un bloque reservado puede
requerir ampliar la memoria. En este caso se intentará aumentar el espacio
reservado y se devolverá OK (cero) cuando sea posible y ERROR (-1)
cuando no se pueda.

● Cada vez que el cliente asigna el identificador a otra variable, el compilador
se lo informa al garbage collector mediante la función add_reference,
que aumenta un contador de referencias a un bloque.

● Cada vez que una variable termina su tiempo de vida, el compilador se lo
informa al garbage collector mediante la función remove_reference y el
garbage collector decrementa un contador de referencias.

● El sistema mantiene el estado de las referencias y cuando algún contador
de referencias llega a 0 (cero), el garbage collector debe liberar la
memoria.

● El administrador ofrece información del estado de la memoria a través de
las funciones:
  - Cantidad de memoria en uso (vs. cantidad de memoria restante).
  - Cantidad de bloques prestados, tamaños y cantidad de referencias
vivas.
  - Listado de procesos (identificados con su firma) y cuanta memoria
tienen reservada.

● Al terminar la vida del sistema, el garbage collector deberá liberar toda la
memoria tomada por los clientes.

Se pide: implementar la interfaz de funciones dada y ejecutar el caso de pruebas
propuesto en el enunciado. El sistema no deberá generar pérdidas de memoria
del sistema.



## *Interfaz de funciones (API)*

int init_gc(int max_mem);

int new_block(int sz,char name[]);

int* mem_ptr(int block);

int resize(int block, int sz);

int add_reference(int block);

int remove_reference(int block);

int used_memory();

int available_memory();

void destroy_agent();
