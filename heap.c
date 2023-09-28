#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;

/*
2. Implemente la función `void* heap_top(Heap* pq)`. Esta función retorna el dato con mayor prioridad del montículo. 
    > Recuerde que este dato se encuentra en la raíz el montículo, es decir, en la primera casilla del arreglo.

*/

void* heap_top(Heap* pq){
  if (pq->heapArray[0].data==NULL){
    return NULL;
  }
  void* raiz = pq->heapArray[0].data;
  return raiz;
}



void heap_push(Heap* pq, void* data, int priority){

}


void heap_pop(Heap* pq){

}



/*
1. Implemente la función `Heap* createHeap()`. Esta función crea un nuevo dato de tipo Heap inicializando sus variables. Considere que la capacidad incial es de 3 casillas para el arreglo.
   > Recuerde reservar memoria para el Heap y también para el arreglo `heapArray`.
*/


Heap* createHeap(){
Heap* heap = (Heap*)malloc(sizeof(Heap));
  heap->size=0;
  heap->capac=3;
  heap->heapArray=(heapElem *) malloc(sizeof(heapElem)*heap->capac); 
;
  return heap;
}
