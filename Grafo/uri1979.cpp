#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> vvi;

struct Graph{
	int v;
	vvi e;
	Graph(int v){
		this->v = v;
		e.assign(v, vector<int>());
	}

	void addEdge(int u, int v){
		e[u].push_back(v);
		e[v].push_back(u);
	}

	bool isBi(int start){
		queue<int> q;
		q.push(start);
		vector<int> color(v, INT_MAX);
		color[start] = 0;
		bool bi = true;
		while(!q.empty() && bi){
			int u = q.front(); q.pop();
			for(auto v: e[u]){
				if(color[v] == INT_MAX){
					color[v] = 1 - color[u];
					q.push(v);
				}
				else if(color[v] == color[u]){
					bi = false;
					break;
				}
			}
		}
		/*for(int i = 0; i < v; i++){
			printf("%d\n", color[i]);
		}*/
		return bi;
	}
};

int main()
{
	int v;
	while(1){
		scanf("%d", &v);
		if(v == 0) break;
		Graph g(v);
		for(int i = 0; i < v; i++){
			int u;
			scanf("%d", &u);
			string str;
			getchar();
			getline(cin, str);
			int espacos = 0;
			for(int i = 0; i < str.size(); i++){
				if(str[i] == ' ') espacos++;
			}
			//printf("%d\n", espacos);
			string str1, str2;
			str2 = str;
			for(int j = 0; j < espacos; j++){
				str1 = str2.substr(0, str2.find(' '));
				str2 = str2.substr(str2.find(' ') + 1, str2.size());
				int num = stoi(str1);
				g.addEdge(u - 1, num - 1);
			//	printf("%d %d\n", u, num);
			}
			g.addEdge(u - 1, stoi(str2) - 1);
			//printf("%d %d\n", u, stoi(str2));
		}
		printf("%s\n", g.isBi(0) ? "SIM" : "NAO");
	}
}