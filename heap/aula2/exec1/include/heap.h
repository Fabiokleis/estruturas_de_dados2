#include <stdio.h>
#include <stdlib.h>

int pai (int i); 
void trocar (int V[], int a, int b);
void imprimir (int V[], int size);
void max_heapify (int V[], int size, int i); 
void build_max_heap (int V[], int size);
void heap_sort (int V[], int size); 
void heap_decrease_key (int V[], int i, int chave, int size); 
