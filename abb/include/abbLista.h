#ifndef ABBLISTA_H
#define ABBLISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct arvore {
   int info;
   struct arvore *esq;
   struct arvore *dir;
} Arvore;

Arvore* cria_arv_vazia (void);
void arv_libera (Arvore* a);
Arvore* inserir (Arvore *a, int v);
Arvore* remover (Arvore *a, int v);
int buscar (Arvore *a, int v);
void pre_order (Arvore* a); 
int min (Arvore *a);
int max (Arvore *a);
void imprime_decrescente (Arvore *a);
int maior_ramo (Arvore *a);
#endif
