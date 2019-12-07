#include <bits/stdc++.h>

using namespace std;

int sacola(int max, vector<pair<int, int>> vii){
	bool *visited = new bool[max + 1];
	int *max = new int[max + 1];
	for(int i = 0; i <= max; i++){
		visited[i] = false;
		max[i] = 0;
	}
	for(auto par : vii){
		
	}
}

int main()
{
	int pedidos;
	while(1){
		scanf("%d", &pedidos);
		if(pedidos == 0) break;
		int max;
		scanf("%d", &max);
		vector<pair<int, int>> vii;
		for(int i = 0; i < pedidos; i++){
			int temp, qtd;
			scanf("%d %d", &temp, &qtd);
			vii.push_back({temp, qtd});
		}
		sort(vii.begin(), vii.end());
		printf("%d min.\n", sacola());
	}
}