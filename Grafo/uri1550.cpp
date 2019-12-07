#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vet;
int distancia[10010];

int inv(int i){
	string str = to_string(i);
	reverse(str.begin(), str.end());
	stringstream aux(str);
	int x = 0;
	aux >> x;
	return x;
}

void init(){
	vet.assign(10010, vector<int>());
	for (int i = 0; i < 10010; i++){
		vet[i].push_back(i + 1);
		vet[i].push_back(inv(i));
	}
}

void dijkstra(int source){
	distancia[source] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
	queue.push(make_pair(0, source));
	while(!queue.empty()){
		pair<int, int> u = queue.top();
		//printf("%d\n", u.second);
		int vertex = u.second;
		int weight = u.first;
		queue.pop();
		if(vertex < 10010){
			for(int i = 0; i < vet[vertex].size(); i++){
				int newV = vet[vertex][i];
				if(newV < 10010 && distancia[newV] > weight + 1){
					distancia[newV] = weight + 1;
					queue.push(make_pair(distancia[newV], newV));
				}
			}
		}
	}
}



int main()
{
	init();
	
	int cases;
	scanf("%d", &cases);
	while(cases--){
		for (int i = 0; i < 10010; i++){
			distancia[i] = INT_MAX >> 1;
		}
		int u, v;
		scanf("%d %d", &u, &v);
		dijkstra(u);
		printf("%d\n", distancia[v]);

	}
}