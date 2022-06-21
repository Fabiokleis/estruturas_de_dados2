/*Estrutura para um nó em uma lista encadeada: */
typedef struct noA {
   int w;           /*Peso da aresta armazenado no no. */
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
GrafoA* criar_grafo_adj (int tamanho); 
void _adicionar_aresta_mat (int i, int j, int w, GrafoM *G); 
void adicionar_aresta_mat (int i, int j, int w, GrafoM *G); 
void _adicionar_aresta_adj (int i, int j, int w, GrafoA *G); 
void _adicionar_aresta_adj (int i, int j, int w, GrafoA *G);
void imprimir_grafo_adj (GrafoA *G); 
void imprimir_grafo_mat (GrafoM *G); 
void inicializar_grafo_mat (GrafoM *G); 
void liberar_grafo_adj (GrafoA *G); 
void liberar_grafo_mat (GrafoM *G); 
int arestas_incidentes_adj (GrafoA *G, int u); 
int arestas_saem_adj (GrafoA *G, int v); 
void vertices_adjacentes_adj (GrafoA *G, int v); 
int arestas_incidentes (GrafoM *G, int u); 
int arestas_saem (GrafoM *G, int u); 
void vertices_adjacentes (GrafoM *G, int u); 
