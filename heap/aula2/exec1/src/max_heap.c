#include "heap.h"

int pai (int i) {
   return (i - 1) / 2;
}

void trocar (int V[], int a, int b) {
   int aux = V[a];
   V[a] = V[b];
   V[b] = aux;
}

void imprimir (int V[], int size) {
   int i;
   for (i = 0; i < size; i++) {
      printf("%d ", V[i]);
   }
   printf("\n");
}

void max_heapify (int V[], int size, int i) {
    int e = (i * 2) + 1; // esquerda 
    int d = (i + 1) * 2; // direita
    int maior = i;
    
    if(e < size && V[e] > V[i]) {
        maior = e;
    } else {
        maior = i;
    }
    if (d < size && V[d] > V[maior]) {
        maior = d;
    }
    if (maior != i) {
        trocar(V, i, maior);
        max_heapify(V, size, maior);
    }
}

void build_max_heap (int V[], int size) {
    int n_ = size / 2 - 1;
    for (int i = n_; i >= 0; i--) {
        max_heapify(V, size, i);
    }
}

void heap_sort (int V[], int size) {
    build_max_heap(V, size);
    for (int i = size-1; i >= 0; i--) {
        trocar(V, i, 0);
        size = i;
        max_heapify(V, size, 0);
    }
}

void heap_decrease_key (int V[], int i, int chave, int size) {
    if (chave > V[i]) {
        fprintf(stderr, "chave maior que atual...\n");
        exit(1);
    }
    V[i] = chave;
    max_heapify(V, size, i);
}

int main () {

   int size = 12;

   int v[] = {15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1};

   imprimir (v, size);

   /*Modificando a chave da posição 0 para o valor 1!*/   
   heap_decrease_key (v, 0, 1, size);
   
   printf ("After decrease-key: \n");
   imprimir (v, size);

   return 0;
}
