#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<pair<int, ii>> viii;
typedef long long ll;

struct Graph{
    int v, e;
    viii edges;

    Graph(int e, int v){
        this->e = e;
        this->v = v;
    }

    void addEdge(int u, int v, ll w){
        edges.push_back(make_pair(w, make_pair(u, v)));
        edges.push_back(make_pair(w, make_pair(v, u)));
    }

    ll kruskal();
};

struct DisjointSet{
    int *rank, *parent, n;

    DisjointSet(int n){
        this->n = n;
        rank = new int[n + 1];
        parent = new int[n + 1];

        for(int i = 0; i <= n; i++){
            rank[i] = 0;
            parent[i] = i;
        }
    }

    int find(int i){
        if(i != parent[i]){
            parent[i] = find(parent[i]);
        }
        return parent[i];
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

ll Graph::kruskal(){
    ll weight = 0;
    sort(edges.begin(), edges.end());
    DisjointSet ds(v);
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
    while(1){
        int v, e;
        scanf("%d %d", &v, &e);
        if(v == 0  && e == 0) break;
        Graph g(v, 2 * e);
        ll cont = 0;
        for(int i = 0; i < e; i++){
            int de, para;
            ll peso;
            scanf("%d %d %lld", &de, &para, &peso);
            cont += peso;
            g.addEdge(de, para, peso);
        }
        printf("%lld\n", cont - g.kruskal());
    }
}
