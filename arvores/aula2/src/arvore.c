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
void pre_imprime_arv (Arvore *a) {
    if (!verifica_arv_vazia(a)) {
        printf("%c\n", a->info);
        pre_imprime_arv(a->esq);
        pre_imprime_arv(a->dir);
    }
}

//========= Exercício 1 - in-ordem ====
void in_imprime_arv (Arvore *a) {
    if (!verifica_arv_vazia(a)) {
        in_imprime_arv(a->esq);
        printf("%c\n", a->info);
        in_imprime_arv(a->dir);
    }
}

//========= Exercício 1 - pós-ordem ====
void pos_imprime_arv (Arvore *a) {
    if (!verifica_arv_vazia(a)) {
        pos_imprime_arv(a->esq);
        pos_imprime_arv(a->dir);
        printf("%c\n", a->info);
    }
}

//========= Exercício 2 - pertence ====
bool pertence_arv (Arvore *a, char c) {
    if (!verifica_arv_vazia(a)) {
        if (a->info == c) return true;
        return pertence_arv(a->esq, c) || pertence_arv(a->dir, c);
    } else return false;
}

//========= Exercício 3 - conta nós ====
int conta_nos (Arvore *a) {
    if (!verifica_arv_vazia(a)) {
        return conta_nos(a->esq) + conta_nos(a->dir) + 1;
    } else return 0;
}

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
   printf("//// pré-ordem ////\n");
   pre_imprime_arv (a);

   //========= Exercício 1 - in-ordem ====
   printf("//// in-ordem ////\n");
   in_imprime_arv (a);

   //========= Exercício 1 - pós-ordem ====
   printf("//// pós-ordem ////\n");
   pos_imprime_arv (a);

   //========= Exercício 2 - pertence ====
   bool per = pertence_arv (a, 'a');
   printf("`a` pertence %d\n", per);

   //========= Exercício 3 - pertence ====
   int nos = conta_nos(a);
   printf("total de nos da arvore a: %d\n", nos);



   arv_libera (a);

   return 0;
}
