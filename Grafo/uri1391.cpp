#include <bits/stdc++.h>

using namespace std;

int shortest = 0;

typedef pair<int, int> ii;
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

     void addEdge(int u, int v, int w){
        matrix[u][v] = w;
     }

     int dijkstra(int start, int finish, bool prim = true){
         int *distance = new int[v];
         int *pai = new int[v];
         for(int i = 0; i < v; i++){
            distance[i] = INT_MAX;
            pai[i] = -1;
         }

         pai[start] = -1;
         distance[start] = 0;
         priority_queue<ii> q;
         q.push(make_pair(0, start));
         while(!q.empty()){
            int u = q.top().second;
            q.pop();
            for(int i = 0; i < v; i++){
                if(matrix[u][i]){
                    int v = i;
                    int d = matrix[u][i];
                    if(distance[v] > distance[u] + d){
                        distance[v] = distance[u] + d;
                        q.push(make_pair(distance[v], v));
                        pai[v] = u;
                    }
                }

            }
         }
         int novo = finish;
         while (1){
            if(pai[novo] == -1) break;
            matrix[pai[novo]][novo] = 0;
            novo = pai[novo];
         }
         if(prim){
            shortest = distance[finish];
            return dijkstra(start, finish, false);
        }
        else{
            if(distance[finish] > shortest){
                return distance[finish];
            }
            else{
                return dijkstra(start, finish, false);
            }
        }
         //return -1;
     }
};

int main()
{
    while(1){

        int v, e;
        scanf("%d %d", &v, &e);
        if(v == 0 && e == 0) break;
        Graph g(v);
        int start, destiny;
        scanf("%d %d", &start, &destiny);
        shortest = 0;
        while(e--){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            g.addEdge(u, v, w);
        }
        int num = g.dijkstra(start, destiny);
        printf("%d\n", num == INT_MAX ? -1 : num);
    }
}
