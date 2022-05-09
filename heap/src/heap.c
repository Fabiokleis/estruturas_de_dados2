#include <stdio.h>

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
   /*TERMINAR*/
}

int main () {

   int i;

   int size = 10;

   int V[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
   printf("Vetor inicial : ");
   imprimir (V, size);

   build_max_heap(V, size);
   printf("Vetor max_heapify: ");
   imprimir (V, size);

//   heap_sort (V, size);
//   printf("Vetor ordenado: ");
//   imprimir (V, size);
  
   return 0;
}

