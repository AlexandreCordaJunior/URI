#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> vii;
bool cycle2 = false;
int *visited;

struct Graph{
    int v, e;
    vii edges;

    Graph(int v, int e){
        this->v = v;
        this->e = e;
        edges.assign(v, vector<int>());
    }

    void addEdge(int u, int v){
        edges[u].push_back(v);
    }

    void cycle(int);
};

void Graph::cycle(int i){
    visited[i] = 1;
    //printf("oi %d\n", i);
    if(cycle2) return;
    for(auto j = edges[i].begin(); j != edges[i].end(); j++){
        //printf("%d %d\n", i, *j);
        if(visited[*j] == 1){
            cycle2 = true;
            return;
        }
        else{
            if(visited[*j] == 0){
                cycle(*j);
            }
        }
    }
    visited[i] = 2;
}

int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--){
        int v, e;
        scanf("%d %d", &v, &e);
        Graph g(v, e);
        cycle2 = false;
        while(e--){
            int u, v;
            scanf("%d %d", &u, &v);
            g.addEdge(u - 1, v - 1);
        }
        visited = (int *) malloc(sizeof(int) * v);
        for(int i = 0; i < v; i++){
            visited[i] = 0;
        }
        for(int i = 0; i < v; i++){
            if(visited[i] == 0){
                g.cycle(i);
            }
            if(cycle2){
                break;
            }
        }

        printf("%s\n", cycle2 ? "SIM" : "NAO");
        free(visited);
    }
}
