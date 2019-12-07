#include <bits/stdc++.h>

using namespace std;

struct graph{
    int vertices;
    int **weight;
};
typedef struct graph Graph;

Graph *createGraph(int vertices){
    Graph *g = (Graph *) malloc(sizeof(Graph));
    g->vertices = vertices;
    g->weight = (int **) malloc(sizeof(int *) * vertices);
    for(int i = 0; i < vertices; i++){
        g->weight[i] = (int *) malloc(sizeof(int) * vertices);
        for(int j = 0; j < vertices; j++){
            g->weight[i][j] = INT_MAX >> 1;
        }
    }
    return g;
}

int **Floyd_Warshal(Graph *g, int vertex){
    for(int i = 0; i < vertex; i++) g->weight[i][i] = 0;
    int **dist = (int **) malloc(sizeof(int *) * vertex);
    for(int i = 0; i < vertex; i++){
        dist[i] = (int *) malloc(sizeof(int) * vertex);
        for(int j = 0; j < vertex; j++){
            dist[i][j] = g->weight[i][j];
        }
    }

    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            if(g->weight[i][j] != INT_MAX >> 1 &&
                g->weight[j][i] != INT_MAX >> 1){
                dist[i][j] = dist[j][i] = 0;
            }
        }
    }

    for(int k = 0; k < vertex; k++){
        for(int i = 0; i < vertex; i++){
            for(int j = 0; j < vertex; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    return dist;
}

int cont = 0;

int main()
{
    while(1){
        int vertices, edges;
        if(cont) printf("\n");
        scanf("%d %d", &vertices, &edges);
        if(vertices == 0 && edges == 0) break;

        Graph *g = createGraph(vertices);
        for(int i = 0; i < edges; i++){
            int de, para, peso;
            scanf("%d %d %d", &de, &para, &peso);
            g->weight[de - 1][para - 1] = peso;
        }
        int queries;
        scanf("%d", &queries);
        int **matrix = Floyd_Warshal(g, vertices);
        /*for(int i = 0; i < vertices; i++){
            for(int j = 0; j < vertices; j++){
                printf("%d\t", matrix[i][j]);
            }
            printf("\n");
        }*/

        for(int i = 0; i < queries; i++){
            int de, para;
            scanf("%d %d", &de, &para);
            int dist = matrix[de - 1][para - 1];
            if(dist == INT_MAX >> 1){
                printf("Nao e possivel entregar a carta\n");
            }
            else{
                printf("%d\n", dist);
            }
        }
        cont = 1;
    }
}
