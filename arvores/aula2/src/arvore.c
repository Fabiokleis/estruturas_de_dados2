#include "arvore.h"

Arvore* cria_arv_vazia (void) {
   return NULL;
}

Arvore* constroi_arv (char c, Arvore *e, Arvore *d) {
   Arvore *no = (Arvore*)malloc(sizeof(Arvore));
   no->info = c;
   no->esq = e;
   no->dir = d;
   return no;
}

bool verifica_arv_vazia (Arvore *a) {
   return (a == NULL);
}

void arv_libera (Arvore* a) {
   if (!verifica_arv_vazia(a)) {
      arv_libera (a->esq);
      arv_libera (a->dir);
      free(a);
   }
}

//========= Exercício 1 - pré-ordem ====
void pr_imprime_arv (Arvore *a) {
    if (!verifica_arv_vazia(a)) {
        printf("%c\n", a->info);
        pr_imprime_arv(a->esq);
        pr_imprime_arv(a->dir);
    }
}

//========= Exercício 1 - in-ordem ====

//========= Exercício 1 - pós-ordem ====

//========= Exercício 2 - pertence ====
bool pertence_arv (Arvore *a, char c) {}

//========= Exercício 3 - conta nós ====
int conta_nos (Arvore *a) {}

//========= Exercício 4 - calcula altura ====
int calcula_altura_arvore (Arvore *a) {}

//========= Exercício 5 - conta folhas ====



int main (int argc, char *argv[]) {

   Arvore *a = constroi_arv ('a',
       constroi_arv('b',
       cria_arv_vazia(),
       constroi_arv('d', cria_arv_vazia(),cria_arv_vazia())
     ),
     constroi_arv('c',
       constroi_arv('e',cria_arv_vazia(),cria_arv_vazia()),
       constroi_arv('f',cria_arv_vazia(),cria_arv_vazia())
     )
   );	

   //========= Exercício 1 - pré-ordem ====
    pr_imprime_arv (a);

   arv_libera (a);

   return 0;
}


