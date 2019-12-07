#include <bits/stdc++.h>

using namespace std;

struct Graph{
    int v;
    int **matrix;
    int **tempo;

    Graph(int v){
        this->v = v;
        matrix = (int **) malloc(sizeof(int *) * v);
        tempo = (int **) malloc(sizeof(int *) * v);

        for(int i = 0; i < v; i++){
            matrix[i] = (int *) malloc(sizeof(int) * v);
            tempo[i] = (int *) malloc(sizeof(int) * v);
        }

        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                matrix[i][j] = 0;
                tempo[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v, int w){
        matrix[u][v] = w;
    }

    void addTempo(int u, int v, int w){
        tempo[u][v] = w;
    }

    bool dijkstra(int start, int finish, int *parent){
        bool *visited = new bool[v];
        int *distance = new int[v];
        for(int i = 0; i < v; i++){
            visited[i] = false;
            distance[i] = INT_MAX;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});
        distance[start] = 0;
        while(!pq.empty()){
            pair<int, int> u = pq.top();
            //printf("%d %d\n", u.second, u.first);
            pq.pop();
            visited[u.second] = true;
            if(u.second == finish) break;
            for(int i = 0; i < v; i++){
                //printf("%d -> %d : %d\n", i, u.second ,matrix[u.second][i]);
                if(matrix[u.second][i] != 0){
                    int distancia = distance[u.second] + tempo[u.second][i];
                    if(distance[i] == INT_MAX or distance[i] > distancia){
                        distance[i] = distancia;
                        parent[i] = u.second;
                        pq.push({distancia, i});
                        visited[i] = true;
                    }
                }
            }
        }
        return visited[finish];
    }

    int fordFulkerson(int start, int finish){
        int *parent = new int[v];
        for(int i = 0; i < v; i++){
            parent[i] = -1;
        }
        int maxFlow = 0;
        while(dijkstra(start, finish, parent)){
            int pathFlow = INT_MAX;
            int custo = 0;
            for(int i = finish; parent[i] != -1; i = parent[i]){
                int u = parent[i];
                pathFlow = min(pathFlow, matrix[u][i]);
                //custo = min(custo, tempo[u][i]);
            }
            for(int i = finish; parent[i] != -1; i = parent[i]){
                int u = parent[i];
                //printf("%d %d %d\n", u, i, tempo[u][i]);
                matrix[u][i] -= pathFlow;
                //custo -= tempo[u][i];
                custo += tempo[u][i];
                //printf("%d\n", custo);
                matrix[i][u] += pathFlow;
            }
            maxFlow += custo;
        }
        return maxFlow;
    }

    void printEdge(){
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    }

    void printTempo(){
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                printf("%d ", tempo[i][j]);
            }
            printf("\n");
        }
    }

};

int main()
{
    int postos, refi, e;
    scanf("%d %d %d", &postos, &refi, &e);

    Graph g(postos + refi + 2);

    pair<int, int> *postosVet = new pair<int, int>[postos];
    for(int i = 0; i < postos; i++){
        int demanda;
        scanf("%d", &demanda);
        postosVet[i] = {demanda, i + 1};
    }

    pair<int, int> *refiVet = new pair<int, int>[refi];
    for(int i = 0; i < refi; i++){
        int estoque;
        scanf("%d", &estoque);
        refiVet[i] = {estoque, i + 1 + postos};
    }

    for(int i = 0; i < postos; i++){
        g.addEdge(postosVet[i].second, postos + refi + 1, postosVet[i].first);
    }

    for(int i = 0; i < refi; i++){
        g.addEdge(0, refiVet[i].second, refiVet[i].first);
    }

    for(int i = 0; i < e; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g.addEdge(refiVet[v - 1].second, postosVet[u - 1].second, INT_MAX >> 3);
        g.addTempo(refiVet[v - 1].second, postosVet[u - 1].second, w);
    }

    printf("%d\n", g.fordFulkerson(0, postos + refi + 1));
}
