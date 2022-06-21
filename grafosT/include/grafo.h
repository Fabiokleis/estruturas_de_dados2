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
void _adicionar_aresta_mat (int i, int j, GrafoM *G);
void adicionar_aresta_mat (int i, int j, GrafoM *G);
void _adicionar_aresta_adj (int i, int j, GrafoA *G);
void adicionar_aresta_adj (int i, int j, GrafoA *G); 
void imprimir_grafo_adj (GrafoA *G); 
void imprimir_grafo_mat (GrafoM *G); 
void inicializar_grafo_mat (GrafoM *G); 
void liberar_grafo_adj (GrafoA *G); 
void liberar_grafo_mat (GrafoM *G); 
