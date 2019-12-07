#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> Edge;

struct Graph{
	int v;
	Edge e;

	Graph(int v){
		this->v = v;
		e.assign(v, vector<int>());
	}

	void addEdge(int u, int v){
		e[u].push_back(v);
	}

	vector<int> bfs(int grau, int start){
		bool *visited = new bool[v];
		for(int i = 0; i < v; i++){
			visited[i] = false;
		}
		visited[start] = true;
		queue<pair<int, int>> q;

		q.push({0, start});

		vector<int> vet;

		while(!q.empty()){
			pair<int, int> u = q.front();
			int v = u.second;
			q.pop();

			if(u.first != 0 && u.first <= grau){
				vet.push_back(v);
			}

			for(auto i = e[v].begin(); i != e[v].end(); i++){
				if(visited[*i] == false){
					visited[*i] = true;
					q.push({u.first + 1, *i});
				}
			}
		}
		sort( vet.begin(), vet.end() );
		vet.erase( unique( vet.begin(), vet.end() ), vet.end() );
		return vet;
	}
};

int main()
{
	int e, grau;
	scanf("%d %d", &e, &grau);
	Graph g(2 * e);
	map<string, int> mapa;
	map<int, string> tradutor;

	int index = 0;
	getchar();
	while(e--){
		string pessoa1, pessoa2, temp;
		getline(cin, temp);
		pessoa1 = temp.substr(0, temp.find(' '));
		pessoa2 = temp.substr(temp.find(' ') + 1, temp.size());
		
		if(mapa.find(pessoa1) == mapa.end()){
			mapa[pessoa1] = index++;
			tradutor[index - 1] = pessoa1;
		}
		if(mapa.find(pessoa2) == mapa.end()){
			mapa[pessoa2] = index++;
			tradutor[index - 1] = pessoa2;
		}

		g.addEdge(mapa[pessoa1], mapa[pessoa2]);
	}
	vector<int> vet = g.bfs(grau, mapa["Rerisson"]);
	vector<string> temp;
	for(auto i = vet.begin(); i != vet.end(); i++){
		temp.push_back(tradutor[*i]);
	}
	sort(temp.begin(), temp.end());
	printf("%d\n", temp.size());
	for(auto i = temp.begin(); i != temp.end(); i++){
		cout << *i << endl;
	}
}