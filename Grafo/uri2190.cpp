#include <bits/stdc++.h>

using namespace std;

typedef vector<pair<int, pair<int, int>>> edges;

struct Graph{
    int v;
    edges edge;

    Graph(int v){
        this-> v = v;
    }

    void addEdge(int u, int v, int w){
        edge.push_back({w, {u, v}});
    }

    int kruskal();
};

struct DisjointSet{
    int n;
    int *rank, *parent;

    DisjointSet(int n){
        this->n = n;
        rank = (int *) malloc(sizeof(int) * (n + 1));
        parent = (int *) malloc(sizeof(int) * (n + 1));

        for(int i = 0; i <= n; i++){
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int find(int u){
        if(u != parent[u]){
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void merge(int x, int y){
        x = find(x);
        y = find(y);

        if(rank[x] > rank[y]){
            parent[y] = x;
        }
        else{
            parent[x] = y;
        }
        if(rank[x] == rank[y]){
            rank[y]++;
        }
    }
};

int Graph::kruskal(){
    sort(edge.begin(), edge.end());
    DisjointSet ds(v);
    int sum = 0;
    for(auto e : edge){
        int u = e.second.first;
        int v = e.second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        if(set_u != set_v){
            if(u < v){
                printf("%d %d\n", u + 1, v + 1);
            }
            else{
                printf("%d %d\n", v + 1, u + 1);
            }
            ds.merge(set_u, set_v);
            sum += e.first;
        }
    }
    free(ds.rank);
    free(ds.parent);
    return sum;
}

int casos = 0;

int main()
{
    while(1){
        int v, e;
        scanf("%d %d", &v, &e);
        if(v == 0) break;
        if(casos != 0) printf("\n");
        Graph g(v);

        while(e--){
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            g.addEdge(u - 1, v - 1, w);
        }
        printf("Teste %d\n", ++casos);
        g.kruskal();
    }
}
