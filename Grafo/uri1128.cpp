#include <bits/stdc++.h>

using namespace std;

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
                matrix[i][j] = INT_MAX >> 1;
            }
        }
    }

    void floyd(){
        for(int k = 0; k < v; k++){
            for(int i = 0; i < v; i++){
                for(int j = 0; j < v; j++){
                    if(matrix[i][j] > matrix[i][k] + matrix[k][j]){
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
            }
        }
    }
};

int main()
{
    while(1){
        int v, e;
        scanf("%d %d", &v, &e);
        if(v == 0 && e == 0) break;
        Graph g(v);
        for(int i = 0; i < e; i++){
            int de, para, op;
            scanf("%d %d %d", &de, &para, &op);

            if(op == 1){
                g.matrix[de - 1][para - 1] = 1;
            }
            else{
                g.matrix[de - 1][para - 1] = g.matrix[para - 1][de - 1] = 1;
            }
        }
        g.floyd();
        bool cone = true;
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                if(i == j) continue;
                if(g.matrix[i][j] == INT_MAX >> 1) cone = false;
            }
        }
        printf("%d\n", cone ? 1 : 0);
    }
}
