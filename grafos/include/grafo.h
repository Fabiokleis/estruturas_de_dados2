#ifndef GRAFO_H_4WSA51EH
#define GRAFO_H_4WSA51EH
/*Estrutura para um nó em uma lista encadeada: */
typedef struct noA {
   int id;          /*Identificador armazenado no nó. */
   struct noA *next; /* Próximo nó na lista encadeada. */
} NoA;

/*Estrutura de Grafo com lista de adjacências: */
typedef struct grafoA {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   NoA **Adj; /* Lista de adjacências. */
} GrafoA;

/*Estrutura de Grafo com matriz de adjacências: */
typedef struct grafoM {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   int **Mat; /* Matrix de adjacências. */
} GrafoM;

GrafoA* criar_grafo_adj (int tamanho);
GrafoM* criar_grafo_mat (int tamanho);
void liberar_grafo_adj (GrafoA *G);
void liberar_grafo_mat (GrafoM *G);
void print_grafoM(GrafoM *G);
void print_grafoA(GrafoA *G);
void inicia_matriz(GrafoM *G);
void insere_arestaM(GrafoM *G, int v1, int v2);
NoA* inserir_no(NoA* no_a, int id);
void insere_arestaA(GrafoA *G, int v, int id);

#endif /* end of include guard: GRAFO_H_4WSA51EH */
