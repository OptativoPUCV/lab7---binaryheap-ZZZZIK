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
  if (pq->heapArray[0].data==NULL|| pq->size==0){
    return NULL;
  }
  void* raiz = pq->heapArray[0].data;
  return raiz;
}

/*

3. Implemente la función `void heap_push(Heap* pq, void* data, int p)`. Esta función inserta un nuevo dato con prioridad `p` en el montículo. Si no recuerda como insertar datos en el montículo puede ver las [diapositivas](https://docs.google.com/presentation/d/1ZjXWMf6g05WdICqvno_oyRvorjAThABgbRGbEqc7mYU/edit#slide=id.g55ac49ed61_0_167).


*/

void heap_push(Heap* pq, void* data, int priority){

  if (pq->size == pq->capac) {
    pq->capac *= 2;
    pq->capac += 1;
    pq->heapArray = realloc(pq->heapArray,pq->capac*sizeof(heapElem));
  }
  
  heapElem elemento;
  elemento.priority=priority;
  elemento.data=data;

  pq->heapArray[pq->size]=elemento;
  pq->size++;

  int actual=pq->size-1;
  
  while(actual>0){
    int padre=(actual-1)/2;
    heapElem elem_actual = pq->heapArray[actual];
    heapElem elem_padre= pq->heapArray[padre];

    if(elem_actual.priority>elem_padre.priority){
      pq->heapArray[actual]=elem_padre;
      pq->heapArray[padre] = elem_actual;

      actual=padre;
      
    }else{
      break;
    }
  }
}

/*
4. Implemente la función `void heap_pop(Heap* pq)`. Esta función elimina el mayor elemento del montículo (la raíz). Si no recuerda el procedimiento puede ver las [diapositivas](https://docs.google.com/presentation/d/1ZjXWMf6g05WdICqvno_oyRvorjAThABgbRGbEqc7mYU/edit#slide=id.g10c6e3d52b_0_98).

*/


void heap_pop(Heap* pq){
  if (pq->size==0) return;

  int ultimo_dato=pq->size-1;
  //Cambio último dato por la raíz.
  pq->heapArray[0] = pq->heapArray[ultimo_dato]
  //Eliminamos el nuevo ultimo dato (raíz).
  pq->size--
  


  

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
