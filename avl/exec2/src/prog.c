#include "avl.h"

int main () {

   Arvore *AVL = NULL;

   AVL = inserir (AVL, 14);
   AVL = inserir (AVL, 5);
   AVL = inserir (AVL, 28);
   AVL = inserir (AVL, 2);
   AVL = inserir (AVL, 8);
   AVL = inserir (AVL, 18);
   AVL = inserir (AVL, 33);
   AVL = inserir (AVL, 1);
   AVL = inserir (AVL, 3);
   AVL = inserir (AVL, 6);
   AVL = inserir (AVL, 11);
   AVL = inserir (AVL, 15);
   AVL = inserir (AVL, 20);
   AVL = inserir (AVL, 30);
   AVL = inserir (AVL, 38);
   AVL = inserir (AVL, 4);
   AVL = inserir (AVL, 7);
   AVL = inserir (AVL, 10);
   AVL = inserir (AVL, 12);
   AVL = inserir (AVL, 16);
   AVL = inserir (AVL, 19);
   AVL = inserir (AVL, 21);
   AVL = inserir (AVL, 29);
   AVL = inserir (AVL, 31);
   AVL = inserir (AVL, 35);
   AVL = inserir (AVL, 39);
   AVL = inserir (AVL, 13);
   AVL = inserir (AVL, 22);
   AVL = inserir (AVL, 32);
   AVL = inserir (AVL, 34);
   AVL = inserir (AVL, 36);
   AVL = inserir (AVL, 40);
   AVL = inserir (AVL, 37);


   imprimir_in_order (AVL, 0);

   AVL = remover (AVL, 1);
   imprimir_in_order (AVL, 0);

   return 0;
}
