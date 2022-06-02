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

typedef struct noA_p {
    int id;          /*Identificador armazenado no nó. */
    int payload;     /* Peso armazenado no nó */
    struct noA_p *next; /* Próximo nó na lista encadeada. */
} NoA_p;

/*Estrutura de Grafo com lista de adjacências com peso */
typedef struct grafoAP {
    int E; /* Quantidade de arestas. */
    int V; /* Quantidade de vértices. */
    NoA_p **Adj; /* Lista de adjacências. */
} GrafoAP;

/*Estrutura de Grafo com matriz de adjacências: */
typedef struct grafoM {
   int E; /* Quantidade de arestas. */
   int V; /* Quantidade de vértices. */
   int **Mat; /* Matrix de adjacências. */
} GrafoM;

GrafoA* criar_grafo_adj (int tamanho);
GrafoM* criar_grafo_mat (int tamanho);
GrafoAP* criar_grafo_peso(int tamanho);
NoA* inserir_no(NoA* no_a, int id);
NoA_p* inserir_no_peso(NoA_p* no_a, int id, int peso);
void liberar_grafo_adj (GrafoA *G);
void liberar_grafo_mat (GrafoM *G);
void liberar_grafo_adj_peso (GrafoAP *G);
void print_grafoM(GrafoM *G);
void print_grafoA(GrafoA *G);
void print_arestaAP(GrafoAP *G);
void inicia_matriz(GrafoM *G);
void insere_arestaM(GrafoM *G, int v1, int v2);
void insere_arestaA(GrafoA *G, int v, int id);
void insere_arestaM_peso(GrafoM *G, int v1, int v2, int peso);
void insere_arestaA_peso(GrafoAP *G, int v, int id, int peso);

void liste_a_incidentes_grafo_mat(GrafoM *G, int v);
void liste_a_incidentes_grafo_adj(GrafoAP *G, int v);
void lista_a_saem_grafo_mat(GrafoM *G, int v);
void lista_a_saem_grafo_adj(GrafoAP *G, int v);
void lista_v_visinhos_grafo_mat(GrafoM *G, int v);
void lista_v_visinhos_grafo_adj(GrafoAP *G, int v);
#endif /* end of include guard: GRAFO_H_4WSA51EH */
