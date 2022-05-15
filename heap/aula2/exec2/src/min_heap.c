#include "heap.h"

int pai (int i) {
   return (i - 1)/2;
}

int esquerda (int i) {
   return (i * 2) + 1;
}

int direita (int i) {
   return (i * 2) + 2;
}

void trocar (int *V, int a, int b) {
   int aux = V[a];
   V[a] = V[b];
   V[b] = aux;
}

void imprimir (int *V, int size) {
   int i;
   for (i = 0; i < size; i++) {
      printf("%d ", V[i]);
   }
   printf("\n");
}

void min_heapify (int *V, int size, int i) {
    int e = esquerda(i);
    int d = direita(i);
    int menor = i;

    if (e < size && V[e] < V[i]) {
        menor = e;
    } else {
        menor = i;
    }
    if (d < size && V[d] < V[menor]) {
        menor = d;
    }

    if (menor != i) {
        trocar(V, i, menor);
        min_heapify(V, size, menor);
    }
}

void build_min_heap (int *V, int size) {
    int n_ = size / 2 - 1;
    for (int i = n_; i >= 0; i--) {
        min_heapify(V, size, i);
    }
}

int heap_extract_min (int *V, int *size) {
    if (*size < 1) {
        fprintf(stderr, "vetor com nenhum elemento...\n");
        exit(1);
    }
    int min = V[0];
    V[0] = V[*size - 1];
    *size = *size - 1;
    min_heapify(V, *size, 0);
    return min;
}

void heap_decrease_key (int *V, int i, int chave) {
    if (chave > V[i]) {
        fprintf(stderr, "chave maior que atual...\n");
        exit(1);
    }

    V[i] = chave;
    while (i > 0 && V[pai(i)] > V[i]) {
        trocar(V, i, pai(i));
        i = pai(i);
    }
}

void min_heap_insert (int **V, int chave, int *size) {
    int *ptr_ = (int *)realloc(*V, sizeof(int) * (*size + 1));
    if (!V) {
        fprintf(stderr, "nao foi possivel realocar o vetor...\n");
        exit(1);
    }
    *V = ptr_;
    (*size)++;
    (*V)[(*size - 1)] = INT_MAX;
    heap_decrease_key(*V, *size - 1, chave);   
}

void push_back(int **V, int chave, int *size) {
    int *ptr_ = (int *)realloc(*V, sizeof(int) * (*size + 1));
    if (!ptr_) {
        fprintf(stderr, "nao foi possivel realocar o vetor...\n");
        exit(1);
    }
    *V = ptr_;
    (*size)++;
    (*V)[(*size - 1)] = chave;
}

int main () {
    
    vector *vec = (vector*)malloc(sizeof(vector));
    vec->v = NULL;
    vec->size = 0;
   
    // insert each element inside a vector
    int aux[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    for (int i = 0; i < (long)(sizeof(aux) / sizeof(int)); i++)
        //min_heap_insert(&vec->v, aux[i], &vec->size);
        push_back(&vec->v, aux[i], &vec->size);

    printf("initial state: ");
    imprimir (vec->v, vec->size);

    printf("build_min_heap: ");
    build_min_heap (vec->v, vec->size);
    imprimir (vec->v, vec->size);

    printf("heap_extract_min: "); 
    heap_extract_min (vec->v, &vec->size);
    imprimir (vec->v, vec->size);
    
    printf("heap_decrease_key: ");
    //Modificando a última chave {16} para o valor {1}!
    heap_decrease_key (vec->v, vec->size - 1, 1);
    imprimir (vec->v, vec->size);

    printf("min_heap_insert: ");
    //Inserindo uma nova chave com valor {0}!
    min_heap_insert (&vec->v, 0, &vec->size);
    imprimir (vec->v, vec->size);

    free(vec->v);
    free(vec);
    return 0;
}
