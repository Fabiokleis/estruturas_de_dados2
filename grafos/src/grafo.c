#include <stdio.h>
#include <stdlib.h>
#include "limits.h"
#include "../include/grafo.h"

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

GrafoAP* criar_grafo_adj_peso (int tamanho) {
    int v;
    GrafoAP *G = (GrafoAP *)malloc(sizeof(GrafoAP));
    G->E = 0;
    G->V = tamanho;
    G->Adj = (NoA_p **)malloc(tamanho * sizeof(NoA_p *));
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

void liberar_grafo_adj_peso (GrafoAP *G) {
    int v;
    for (v = 0; v < G->V; v++) {
        if (G->Adj[v] != NULL) {
            free(G->Adj[v]);
        }
    }
    free(G->Adj);
    free(G);
}
// mostra o grafo M booleano;
void print_grafoM (GrafoM *G) {
    printf("    ");
    for (int i = 0; i < G->V; i++) {
        printf("%d ", i);
    }
    printf("\n\n");
    for (int i = 0; i < G->V; i++) {
      printf("%d  ", i);
      for (int j = 0; j < G->V; j++) {
          if (G->Mat[i][j] < 0) {
              printf(" 0");
          } else {
              printf(" %d", G->Mat[i][j]);
          }
      }
      printf( "\n");
    }
}

// percorre e mostra todas as listas dento do G->adj;
void print_grafoA (GrafoA *G) {
    NoA *no_a = NULL;
    for (int i = 0; i < G->V; i++) {
        printf("%d -> ", i);
        for (no_a = G->Adj[i]; no_a != NULL; no_a = no_a->next) {
            printf(" %d", no_a->id);
        }
        printf("\n");
    }
}
void print_arestaAP(GrafoAP *G) {
    NoA_p *no_a = NULL;
    for (int i = 0; i < G->V; i++) {
        printf("%d -> ", i);
        for (no_a = G->Adj[i]; no_a != NULL; no_a = no_a->next) {
            printf(" %d (w:%d)", no_a->id, no_a->payload);
        }
        printf("\n");
    }
}
// coloca INT_MIN em todas as posicoes da matriz;
void inicia_matriz(GrafoM *G) {
    for (int i = 0; i < G->V; i++) {
        for (int j = 0; j < G->V; j++) {
            G->Mat[i][j] = INT_MIN;
        }
    }
}

// coloca 1 para a ligacao entre dois vertices
void insere_arestaM(GrafoM *G, int v1, int v2) {
    if (G->Mat[v1][v2] < 0) {
        G->Mat[v1][v2] = 1;
        G->E++; // incrementa o número total de arestas a cada insercao
    }
}

NoA* inserir_no(NoA* no_a, int id) {
    NoA *novo_a = (NoA *) malloc(sizeof(NoA));
    novo_a->id = id;
    novo_a->next = no_a; // insere na cabeça
    return novo_a;
}

// insere uma nova aresta entre dois vertices sem ordem
void insere_arestaA(GrafoA *G, int v, int id) {
    G->Adj[v] = inserir_no(G->Adj[v], id);
    G->E++; // incrementa o numero total de arestas a cada insercao
}

void insere_arestaM_peso(GrafoM *G, int v1, int v2, int peso) {
    if (G->Mat[v1][v2] < 0) {
        G->Mat[v1][v2] = peso;
        G->E++;
    }
}

NoA_p* inserir_no_peso(NoA_p* no_a, int id, int peso) {
    NoA_p *novo_a = (NoA_p *) malloc(sizeof(NoA_p));
    novo_a->id = id;
    novo_a->payload = peso;
    novo_a->next = no_a; // insere na cabeça
    return novo_a;
}

void insere_arestaA_peso(GrafoAP *G, int v, int id, int peso) {
    G->Adj[v] = inserir_no_peso(G->Adj[v], id, peso);
    G->E++; // incrementa o numero total de arestas a cada insercao
}

void liste_a_incidentes_grafo_mat(GrafoM *G, int v) {
    int c = 0;
    for (int i = 0; i < G->V; i++) {
        if (G->Mat[v][i] > 0 || G->Mat[i][v] > 0) {
            if (G->Mat[v][i] == v || G->Mat[i][v] == v) // remove a incidencia com ele `mesmo`?
                continue;
            c++;
        }
    }
    printf("arestas incidentes em %d: %d\n", v, c);
}
// conta todos as arestas de um grafo e mostra
void liste_a_incidentes_grafo_adj(GrafoAP *G, int v) {
    int c = 0;
    NoA_p *no_a = NULL;
    for (int i = 0; i < G->V; i++) {
        for (no_a = G->Adj[i]; no_a != NULL; no_a = no_a->next) {
            if (no_a->id == v || (no_a->id != v && G->Adj[i] == G->Adj[v])) {
                if (no_a->id == v && G->Adj[i] == G->Adj[v]) // remove a incidencia com ele `mesmo`?
                    continue;
                c++;
            }
        }
    }
    printf("arestas incidentes em %d: %d\n", v, c);
}
// conta todas as arestas que saem de um grafo e mostra
void lista_a_saem_grafo_mat(GrafoM *G, int v) {
    int c = 0;
    for (int i = 0; i < G->V; i++) {
        if (G->Mat[v][i] > 0) {
            c++;
        }
    }
    printf("arestas que saem %d: %d\n", v, c);
}
// conta todas as arestas que saem de um grafo e mostra
void lista_a_saem_grafo_adj(GrafoAP *G, int v) {
    int c = 0;
    NoA_p *no_a = NULL;
    for (no_a = G->Adj[v]; no_a != NULL; no_a = no_a->next) {
        c++;
    }
    printf("arestas que saem %d: %d\n", v, c);
}
// mostra os vertices adjacentes a um determinado vertice
void lista_v_visinhos_grafo_mat(GrafoM *G, int v) {
    printf("vertecies adjacentes ao vertice %d:", v);
    for (int i = 0; i < G->V; i++) {
        if (G->Mat[v][i] > 0) {
            if (G->Mat[v][i] == v) // remove a incidencia com ele `mesmo`?
                continue;
            printf(" %d", i);
        }

    }
    printf("\n");
}
// mostra os vertices adjacentes a um determinado vertice
void lista_v_visinhos_grafo_adj(GrafoAP *G, int v) {
    printf("vertecies adjacentes ao vertice %d:", v);
    NoA_p *no_a = NULL;
    for (no_a = G->Adj[v]; no_a != NULL; no_a = no_a->next) {
        printf(" %d", no_a->id);
    }
    printf("\n");
}
/* */
int main () {
    // 1)
    /*
     * 0 -- 5
     * | \    \
     * |  2 -- 4
     * | / \  /
     * 1 -- 3
     *
     */
    printf("matriz de adjacencia nao direcionada\n");
    int Vm = 6; //Número de vértices
    GrafoM* Gm = criar_grafo_mat (Vm);
    inicia_matriz(Gm); // inicia todos os valores para 0
    // 0
    insere_arestaM(Gm, 0, 5);
    insere_arestaM(Gm, 0, 1);
    insere_arestaM(Gm, 0, 2);
    // 1
    insere_arestaM(Gm, 1, 0);
    insere_arestaM(Gm, 1, 3);
    insere_arestaM(Gm, 1, 2);
    // 3
    insere_arestaM(Gm, 3, 1);
    insere_arestaM(Gm, 3, 4);
    insere_arestaM(Gm, 3, 2);
    // 4
    insere_arestaM(Gm, 4, 5);
    insere_arestaM(Gm, 4, 3);
    insere_arestaM(Gm, 4, 2);
    // 5
    insere_arestaM(Gm, 5, 0);
    insere_arestaM(Gm, 5, 4);
    // 2
    insere_arestaM(Gm, 2, 0);
    insere_arestaM(Gm, 2, 1);
    insere_arestaM(Gm, 2, 3);
    insere_arestaM(Gm, 2, 4);

    print_grafoM(Gm);
    liberar_grafo_mat (Gm);
    printf("lista de adjacencia nao direcionada\n");

    int Va = 6; // numero de vértices
    GrafoA* Ga = criar_grafo_adj (Va);

    // 0
    insere_arestaA(Ga, 0, 5);
    insere_arestaA(Ga, 0, 1);
    insere_arestaA(Ga, 0, 2);

    // 1
    insere_arestaA(Ga, 1, 0);
    insere_arestaA(Ga, 1, 3);
    insere_arestaA(Ga, 1, 2);
    // 3
    insere_arestaA(Ga, 3, 1);
    insere_arestaA(Ga, 3, 4);
    insere_arestaA(Ga, 3, 2);
    // 4
    insere_arestaA(Ga, 4, 5);
    insere_arestaA(Ga, 4, 3);
    insere_arestaA(Ga, 4, 2);
    // 5
    insere_arestaA(Ga, 5, 0);
    insere_arestaA(Ga, 5, 4);

    // 2
    insere_arestaA(Ga, 2, 0);
    insere_arestaA(Ga, 2, 1);
    insere_arestaA(Ga, 2, 3);
    insere_arestaA(Ga, 2, 4);

    print_grafoA(Ga);
    liberar_grafo_adj (Ga);

    // 2)
    /*
     * V    V     P
     * 0 --> 5
     * 0 --> 1
     * 1 --> 2
     * 1 --> 3
     * 2 --> 0
     * 2 --> 4
     * 3 --> 2
     * 4 --> 3
     * 5 --> 4
    */
    printf("matriz de adjacencia direcionada\n");
    int Vmd = 6; //Número de vértices
    GrafoM* Gmd = criar_grafo_mat (Vmd);
    inicia_matriz(Gmd);
    // 0
    insere_arestaM(Gmd, 0, 5);
    insere_arestaM(Gmd, 0, 1);
    // 1
    insere_arestaM(Gmd, 1, 2);
    insere_arestaM(Gmd, 1, 3);
    // 2
    insere_arestaM(Gmd, 2, 0);
    insere_arestaM(Gmd, 2, 4);
    // 3
    insere_arestaM(Gmd, 3, 2);
    // 4
    insere_arestaM(Gmd, 4, 3);
    // 5
    insere_arestaM(Gmd, 5, 4);

    print_grafoM(Gmd);
    liberar_grafo_mat (Gmd);

    printf("lista de adjacencia direcionada\n");
    int Vad = 6; //Número de vértices
    GrafoA* Gad = criar_grafo_adj(Vad);
    // 0
    insere_arestaA(Gad, 0, 5);
    insere_arestaA(Gad, 0, 1);
    // 1
    insere_arestaA(Gad, 1, 2);
    insere_arestaA(Gad, 1, 3);
    // 2
    insere_arestaA(Gad, 2, 0);
    insere_arestaA(Gad, 2, 4);
    // 3
    insere_arestaA(Gad, 3, 2);
    // 4
    insere_arestaA(Gad, 4, 3);
    // 5
    insere_arestaA(Gad, 5, 4);

    print_grafoA(Gad);
    liberar_grafo_adj(Gad);

    // 3)
    /*
    • Liste o numero de arestas incidentes a um dado vertice.
    • Liste o numero de arestas que saem de um dado vertice.
    • Liste todas os vizinhos de um dado vertice (vertices adjacentes)
 */
    //Numero de arestas incidentes ao vertice 3: 4.
    //Numero de arestas que saem do vertice 4: 2.
    //Vertices adjacentes ao v́ertice 2: 0 3.
    /*  V    V     P
     * 0 --> 1     1
     * 0 --> 3     5
     * 1 --> 3     8
     * 2 --> 0     5
     * 2 --> 3     4
     * 3 --> 3     6
     * 3 --> 4     3
     * 4 --> 2     7
     * 4 --> 5     9
     * 5 --> 0     2
    */
    printf("matriz de adjacencia direcionada com peso\n");
    int Vmdp = 6; //Número de vértices
    GrafoM* Gmd_p = criar_grafo_mat (Vmdp);
    inicia_matriz(Gmd_p);
    // 0
    insere_arestaM_peso(Gmd_p, 0, 1, 1);
    insere_arestaM_peso(Gmd_p, 0, 3, 5);
    // 1
    insere_arestaM_peso(Gmd_p, 1, 3, 8);
    // 2
    insere_arestaM_peso(Gmd_p, 2, 0, 5);
    insere_arestaM_peso(Gmd_p, 2, 3, 4);
    // 3
    insere_arestaM_peso(Gmd_p, 3, 3, 6);
    insere_arestaM_peso(Gmd_p, 3, 4, 3);
    // 4
    insere_arestaM_peso(Gmd_p, 4, 2, 7);
    insere_arestaM_peso(Gmd_p, 4, 5, 9);
    // 5
    insere_arestaM_peso(Gmd_p, 5, 0, 2);

    print_grafoM(Gmd_p);
    liste_a_incidentes_grafo_mat(Gmd_p, 3);
    lista_a_saem_grafo_mat(Gmd_p, 4);
    lista_v_visinhos_grafo_mat(Gmd_p, 2);
    liberar_grafo_mat (Gmd_p);

    printf("lista de adjacencia direcionada com peso\n");
    int Vad_p = 6; //Número de vértices
    GrafoAP* Gad_p = criar_grafo_adj_peso(Vad_p);
    // 0
    insere_arestaA_peso(Gad_p, 0, 1, 1);
    insere_arestaA_peso(Gad_p, 0, 3, 5);
    // 1
    insere_arestaA_peso(Gad_p, 1, 3, 8);
    // 2
    insere_arestaA_peso(Gad_p, 2, 0, 5);
    insere_arestaA_peso(Gad_p, 2, 3, 4);
    // 3
    insere_arestaA_peso(Gad_p, 3, 3, 6);
    insere_arestaA_peso(Gad_p, 3, 4, 3);
    // 4
    insere_arestaA_peso(Gad_p, 4, 2, 7);
    insere_arestaA_peso(Gad_p, 4, 5, 9);
    // 5
    insere_arestaA_peso(Gad_p, 5, 0, 2);

    print_arestaAP(Gad_p);
    liste_a_incidentes_grafo_adj(Gad_p, 3);
    lista_a_saem_grafo_adj(Gad_p, 4);
    lista_v_visinhos_grafo_adj(Gad_p, 2);
    liberar_grafo_adj_peso(Gad_p);


    return 0;
}
