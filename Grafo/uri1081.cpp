#include <bits/stdc++.h>

using namespace std;
bool pode = false;

struct Graph{
    int v;
    int **matrix;
    Graph(int v){
        this->v = v;
        matrix = (int **) malloc(sizeof(int *) * v);
        for(int i = 0; i < v; i++){
            matrix[i] = (int *) malloc(sizeof(int) * v);
        }

        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                matrix[i][j] = 0;
            }
        }
    }

    void DFS(){
        int *visited = new int[v];
        for(int i = 0; i < v; i++){
            visited[i] = 0;
        }
        bool pulo = false;
        for(int i = 0; i < v; i++){
            if(!visited[i]){
                visited[i] = 1;
                DFSAux(i, visited, 2, pulo);
                pulo = true;
            }
        }
        pode = false;
    }

    void DFSAux(int start, int *visited, int level, bool pulo){
        for(int i = 0; i < v; i++){
            if(matrix[start][i] && !visited[i]){
                if(pulo && pode) printf("\n");
                pulo = false;
                for(int j = 0; j < level; j++) printf(" ");
                printf("%d-%d pathR(G,%d)\n", start, i, i);
                pode = true;
                visited[i] = 1;
                DFSAux(i, visited, level + 2, pulo);
            }
            else{
                if(matrix[start][i]){
                    for(int j = 0; j < level; j++) printf(" ");
                    printf("%d-%d\n", start, i);
                }
            }
        }
    }
};

int main()
{
    int casos;
    scanf("%d", &casos);
    for(int i = 0; i < casos; i++){
        int v, e;
        scanf("%d %d", &v, &e);
        Graph g(v);
        for(int i = 0; i < e; i++){
            int de, para;
            scanf("%d %d", &de, &para);
            g.matrix[de][para] = 1;
        }
        if(i != 0) printf("\n");
        printf("Caso %d:\n", i + 1);
        g.DFS();
    }
    printf("\n");
}
