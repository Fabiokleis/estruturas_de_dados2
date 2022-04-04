#include "abbLista.h"
/*
 
    inserindo elementos de 0->99999...
    Tempo de execução busca em abb em ordem: 0.001057000000000

    inserindo elementos de forma aleatoria...
    Tempo de execução busca em abb em ordem aleatória: 0.000001000000000

 */

Arvore* cria_arvore_vazia (void) {
   return NULL;
}

void arvore_libera (Arvore* a) {
   if (a != NULL) {
      arvore_libera (a->esq);
      arvore_libera (a->dir);
      free(a);
   }
}

//========= Q1 - inserir
Arvore* inserir (Arvore *a, int v) {
   if (a == NULL) {
       a = (Arvore*)malloc(sizeof(Arvore));
       a->info = v;
       a->esq = NULL;
       a->dir = NULL;
   } else if (v < a->info) {
       a->esq = inserir(a->esq, v);
   } else {
       a->dir = inserir(a->dir, v);
   }

   return a;
}

//========= Q1 - remover
Arvore* remover (Arvore *a, int v) {
   if (a == NULL) return NULL;
   else {
       if (a->info > v) {
           a->esq = remover(a->esq, v);
       } else if (a->info < v) {
           a->dir = remover(a->dir, v);
       } else if ((a->esq == NULL) && (a->dir == NULL)) {
           free(a);
           a = NULL;
       } else if (a->dir == NULL) {
           Arvore *tmp = a;
           a = a->esq;
           free(tmp);
       } else if (a->esq == NULL) {
           Arvore *tmp = a;
           a = a->dir;
           free(tmp);
       } else {
           Arvore *tmp = a->esq;
           while (tmp->dir != NULL)
               tmp = tmp->dir;
           a->info = tmp->info;
           tmp->info = v;
           a->esq = remover(a->esq, v);
       }
   }
   return a;
}


//========= Q1 - busca
int buscar (Arvore *a, int v) {
  if (a == NULL) return 0;
  else if (v < a->info) return buscar(a->esq, v);
  else if (v > a->info) return buscar(a->dir, v);
  else return 1;
}

//========= Q2 - min =====
int min (Arvore *a) {
    if (a == NULL) return -1;
    Arvore *tmp = a;
    while (tmp->esq != NULL)
        tmp = tmp->esq;
    return tmp->info;

}

//========= Q2 - max =====
int max (Arvore *a) {
    if (a == NULL) return 0;
    Arvore *tmp = a;
    while (tmp->dir != NULL)
        tmp = tmp->dir;
    return tmp->info;
}

//========= Q3 - imprime_decrescente =====
void imprime_decrescente (Arvore *a) {
    if (a == NULL) return;
    else {
        imprime_decrescente(a->dir);
        printf("%d ", a->info);
        imprime_decrescente(a->esq);
    }
}


//========= Q4 - maior ramo =====
int maior_ramo (Arvore *a) {
    if (a == NULL) return 0;
    else {
        if (a->esq == NULL && a->dir == NULL) return a->info;
        int c = maior_ramo(a->esq);
        int d = maior_ramo(a->dir);

        if (a->esq != NULL && a->dir != NULL) {
            return (c > d ? c : d) + a->info;
        }
        return ((a->esq != NULL) ? c : d) + a->info;
    }
}

void pre_order (Arvore* a) {
   if (a != NULL) {
      printf("%d ", a->info);
      pre_order (a->esq);
      pre_order (a->dir);
   } 
}

int main () {

   int i;

   Arvore *a = cria_arvore_vazia ();

   a = inserir (a, 50);
   a = inserir (a, 30);
   a = inserir (a, 90);
   a = inserir (a, 20);
   a = inserir (a, 40);
   a = inserir (a, 95);
   a = inserir (a, 10);
   a = inserir (a, 35);
   a = inserir (a, 45);

   printf("\n");
   pre_order (a);	
   printf("\n");
 
   printf("chave 5: %d\n", buscar(a, 5));
   printf("chave 45: %d\n", buscar(a, 45));

   printf("min: %d\n", min(a));
   printf("max: %d\n", max(a));
   printf("ordem decrescente: ");
   imprime_decrescente(a);
   printf("\n");

   printf("\nmaior ramo: %d\n", maior_ramo(a));
   
    /*
   // ====== Q5 ====
   clock_t start, end;
   double elapsed_time;

   Arvore *q5 = cria_arvore_vazia();
   int n;
   printf("inserindo elementos de 0->99999...\n");
   for (n = 0; n < 100000; n++) 
       q5 = inserir(q5, n);

   start = clock();
   int result = buscar(q5, 100000);
   end = clock();

   elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
   printf("%d\n", result);
   printf("Tempo de execução busca em abb em ordem: %.15f\n", elapsed_time);

   Arvore *q52 = cria_arvore_vazia();
   printf("inserindo elementos de forma aleatoria...\n");
   srand(time(NULL));
   for (n = 0; n < 100000; n++)
       q52 = inserir(q52, rand() % 100000);

   start = clock();
   result = buscar(q52, 100000);
   end = clock();

   elapsed_time = (end - start)/(double)CLOCKS_PER_SEC;
   printf("%d\n", result);
   printf("Tempo de execução busca em abb em ordem aleatória: %.15f\n", elapsed_time);
    */
   return 0;
}



