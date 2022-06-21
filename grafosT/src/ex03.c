#include <stdio.h>
#include <stdlib.h>
#include "../include/grafow.h"
/*Função para criar um grafo com lista de adjacências.*/
GrafoA* criar_grafo_adj (int tamanho) {
   int v;
   GrafoA *G = (GrafoA *)malloc(sizeof(GrafoA));
   G->E = 0;
   G->V = tamanho;
   G->Adj = (NoA **)malloc(tamanho * sizeof(NoA *));
   for (v = 0; v < G->V; v++) {
      G->Adj[v] = NULL;
   }
   return G;
}

/*Função para criar um grafo com matriz de adjacências.*/
GrafoM* criar_grafo_mat (int tamanho) {
   int v;
   GrafoM *G = (GrafoM *)malloc(sizeof(GrafoM));
   G->E = 0;
   G->V = tamanho;
   G->Mat = (int **)malloc(tamanho * sizeof(int *));
   for (v = 0; v < G->V; v++) {
      G->Mat[v] = (int *)malloc(tamanho * sizeof(int));
   }
   return G;
}

void _adicionar_aresta_mat (int i, int j, int w, GrafoM *G) {
   if (G->Mat[i][j]) {
      printf("The edge already exist!\n");	   
   }	   
   else {
      G->Mat[i][j] = w;
   }   
}

void adicionar_aresta_mat (int i, int j, int w, GrafoM *G) {
   _adicionar_aresta_mat (i, j, w, G);
   G->E++;
}

void _adicionar_aresta_adj (int i, int j, int w, GrafoA *G) {
   NoA *aux, *ultimo = NULL;
   for (aux = G->Adj[i]; aux != NULL; aux = aux->next) {
      if (aux->id == j) {
	 printf("The edge already exist!\n");
         return;	 
      }	      
      ultimo = aux;
   }	   
   NoA *novo = (NoA *)malloc(sizeof(NoA));
   novo->id = j;
   novo->w = w;
   novo->next = NULL;
   if (ultimo != NULL)
      ultimo->next = novo;
   else {
      G->Adj[i] = novo;	   
   }
}

void adicionar_aresta_adj (int i, int j, int w, GrafoA *G) {
   _adicionar_aresta_adj (i, j, w, G);
   G->E++;
}

void imprimir_grafo_adj (GrafoA *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      NoA *u;      	   
      for (u = G->Adj[v]; u != NULL; u = u->next) {
	 printf ("%d (w:%d) ", u->id, u->w);     
      }
      printf("\n");
   }
}

void imprimir_grafo_mat (GrafoM *G) {
   int u, v;
   for (u = 0; u < G->V; u++) {
      for (v = 0; v < G->V; v++) {
	 printf("%d ", G->Mat[u][v]);       
      }	      
      printf("\n");
   }	   
}

void inicializar_grafo_mat (GrafoM *G) {
   int u, v;
   for (u = 0; u < G->V; u++) {
      for (v = 0; v < G->V; v++) {
	 G->Mat[u][v] = 0;       
      }	      
   }	   
}

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_adj (GrafoA *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      if (G->Adj[v] != NULL) {
         free(G->Adj[v]);
      }
   }
   free(G->Adj);
   free(G);
}

/*Função para destruir um grafo construído com lista de adjacências.*/
void liberar_grafo_mat (GrafoM *G) {
   int v;
   for (v = 0; v < G->V; v++) {
      if (G->Mat[v] != NULL) {
         free(G->Mat[v]);
      }
   }
   free(G->Mat);
   free(G);
}

int arestas_incidentes_adj (GrafoA *G, int u) {
   int v;
   int sum = 0;
   for (v = 0; v < G->V; v++) {
      NoA *aux;      	   
      for (aux = G->Adj[v]; aux != NULL; aux = aux->next) {
	 if (aux->id == u) {
            sum++;		 
	 }   	 
      }
   }
   return sum;   
}

int arestas_saem_adj (GrafoA *G, int v) {
   int sum = 0;
   NoA *u;      	   
   for (u = G->Adj[v]; u != NULL; u = u->next) {
      sum++;		 
   }
   return sum; 
}

void vertices_adjacentes_adj (GrafoA *G, int v) {
   NoA *u;      	   
   for (u = G->Adj[v]; u != NULL; u = u->next) {
      printf ("%d ", u->id);		 
   }
   printf("\n");
}

int arestas_incidentes (GrafoM *G, int u) {
   int i;
   int sum = 0;
   for (i = 0; i < G->V; i++) {
      if (G->Mat[i][u] > 0) {
	 sum++;     
      } 	       
   }	 
   return sum;  
}

int arestas_saem (GrafoM *G, int u) {
   int i;
   int sum = 0;
   for (i = 0; i < G->V; i++) {
      if (G->Mat[u][i] > 0) {
	 sum++;     
      } 	       
   }	 
   return sum;  
}

void vertices_adjacentes (GrafoM *G, int u) {
   int i;
   printf("Vertices adjacentes ao vertice %d: ", u);
   for (i = 0; i < G->V; i++) {
      if (G->Mat[u][i] > 0) {
	 printf ("%d ", i);     
      } 	       
   }	 
   printf("\n");
}

/* */
int main () {

   int Va = 6; /*Número de vértices*/

   GrafoA* Ga = criar_grafo_adj (Va);
   adicionar_aresta_adj (0, 1, 1, Ga);
   adicionar_aresta_adj (0, 3, 5, Ga);
   adicionar_aresta_adj (1, 3, 8, Ga);
   adicionar_aresta_adj (2, 0, 5, Ga);
   adicionar_aresta_adj (2, 3, 4, Ga);
   adicionar_aresta_adj (3, 3, 6, Ga);
   adicionar_aresta_adj (3, 4, 3, Ga);
   adicionar_aresta_adj (4, 2, 7, Ga);
   adicionar_aresta_adj (4, 5, 9, Ga);
   adicionar_aresta_adj (5, 0, 2, Ga);

   printf("Lista de adjacencia:\n");
   imprimir_grafo_adj (Ga);
   printf("\n");

   printf ("Numero de arestas incidentes ao vertice %d: %d\n", 3, arestas_incidentes_adj (Ga, 3));
   printf ("Numero de arestas que saem do vertice %d: %d\n", 4, arestas_saem_adj (Ga, 4));
   vertices_adjacentes_adj (Ga, 2);

   int Vm = 6; /*Número de vértices*/

   GrafoM* Gm = criar_grafo_mat (Vm);

   inicializar_grafo_mat (Gm);
   adicionar_aresta_mat (0, 1, 1, Gm);
   adicionar_aresta_mat (0, 3, 5, Gm);
   adicionar_aresta_mat (1, 3, 8, Gm);
   adicionar_aresta_mat (2, 0, 5, Gm);
   adicionar_aresta_mat (2, 3, 4, Gm);
   adicionar_aresta_mat (3, 3, 6, Gm);
   adicionar_aresta_mat (3, 4, 3, Gm);
   adicionar_aresta_mat (4, 2, 7, Gm);
   adicionar_aresta_mat (4, 5, 9, Gm);
   adicionar_aresta_mat (5, 0, 2, Gm);

   printf("Matriz de adjacencia:\n");
   imprimir_grafo_mat (Gm);

   printf ("Numero de arestas incidentes ao vertice %d: %d\n", 3, arestas_incidentes (Gm, 3));
   printf ("Numero de arestas que saem do vertice %d: %d\n", 4, arestas_saem (Gm, 4));
   vertices_adjacentes (Gm, 2);

   liberar_grafo_adj (Ga);
   liberar_grafo_mat (Gm);

   return 0;
}

