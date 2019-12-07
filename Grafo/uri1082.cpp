#include <bits/stdc++.h>

using namespace std;

typedef vector<pair<int, int>> vii;

struct Graph{
    int v, e;
    vii edges;

    Graph(int v, int e){
        this->e = e;
        this->v = v;
    }

    void addEdge(int u, int v){
        edges.push_back(make_pair(u, v));
        edges.push_back(make_pair(v, u));
    }

    int connection();
};

struct DisjointSet{
    int n;
    int *parent, *rank;

    DisjointSet(int n){
        this->n = n;
        parent = new int[n + 1];
        rank = new int[n + 1];

        for(int i = 0; i <= n; i++){
            parent[i] = i;
            rank[i] = 0;
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

int Graph::connection()
{
    sort(edges.begin(), edges.end());
    DisjointSet ds(v);
    for(auto i = edges.begin(); i != edges.end(); i++){
        int u = i->first;
        int v = i->second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        if(set_v != set_u){
            //printf("%c %c\n", u + 'a', v + 'a');
            ds.merge(set_u, set_v);
            //printf("%c %c\n\n", ds.parent[set_u] + 'a', ds.parent[set_v] + 'a');
        }
    }
    int vet[v];
    for(int i = 0; i < v; i++){
        vet[i] = 0;
    }
    for(int i = 0; i < v; i++){
        vet[ds.find(i)] = 1;
    }
    int cont = 0;
    for(int i = 0; i < v; i++){
        if(vet[i]){
            cont++;
        }
    }


    vector<vector<int>> vvi;
    vvi.assign(v + 1, vector<int>());
    for(int i = 0; i < v; i++){
        vvi[ds.find(i)].push_back(i);
    }
    bool pri = false;
    sort(vvi.begin(), vvi.end());
    for(int i = 0; i <= v; i++){
        for(auto j = vvi[i].begin(); j != vvi[i].end(); j++){
            printf("%c,",(*j) + 'a');
            pri = true;
        }
        if (pri) printf("\n");
        pri = false;
    }

    return cont;

}

int main()
{
    int cases;
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++){
        int v, e;
        scanf("%d %d", &v, &e);
        Graph g(v, e);
        for(int j = 0; j < e; j++){
            getchar();
            char u, v;
            scanf("%c %c", &u, &v);
            int iu = u - 'a';
            int iv = v - 'a';
            g.addEdge(iu, iv);
        }
        printf("Case #%d:\n", i + 1);
        printf("%d connected components\n\n", g.connection());
    }
    return 0;
}