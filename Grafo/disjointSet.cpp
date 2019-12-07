#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

struct Graph{
    int V, E;
    vector<pair<int, ii>> edges;
    Graph(int V, int E){
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int w){
        edges.push_back(make_pair(w, make_pair(u, v)));
    }

    int kruskal();
};

struct DisjointSet{
    int *parent;
    int *rank;
    int n;

    DisjointSet(int n){
        this->n = n;
        parent = new int[n + 1];
        rank = new int[n + 1];

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
    int weight = 0;
    sort(edges.begin(), edges.end());
    DisjointSet ds(V);
    for(auto i = edges.begin(); i != edges.end(); i++){
        int u = i->second.first;
        int v = i->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        if(set_u != set_v){
            weight += i->first;
            ds.merge(set_u, set_v);
        }
    }
    return weight;
}

int main()
{
    Graph g(9, 14);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    printf("%d\n", g.kruskal());
}
