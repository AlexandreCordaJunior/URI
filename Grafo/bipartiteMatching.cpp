#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

bool findMatch(int i, const vvi &graph, vi &right, vi &left, vi &seen){
	for(int j = 0; j < graph[i].size(); j++){
		if(graph[i][j] && !seen[j]){
			seen[j] = true;
			if(left[j] < 0 || findMatch(left[j], graph, right, left, seen)){
				right[i] = j;
				left[j] = i; 
				return true;
			}
		}
	}
	return false;
}

int bipartiteMatching(vvi &graph, vi &right, vi &left){
	right = vi(graph.size(), -1);
	left = vi(graph[0].size(), -1);
	int cont = 0;
	for(int i = 0; i < graph.size(); i++){
		vi seen(graph[0].size());
		if(findMatch(i, graph, right, left, seen)) cont++;
	}
	return cont;
}

void solve(){
	int n, m;
	scanf("%d", &n);
	vector<int> right(n);
	for(int i = 0; i < n; i++){
		scanf("%d", &right[i]);
	}

	scanf("%d", &m);
	vector<int> left(m);
	for(int i = 0; i < m; i++){
		scanf("%d", &left[i]);
	}

	vvi graph(n, vi(m));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(right[i] == 0){
				if(left[i] == 0){
					graph[i][j] = 1;
				}
			}
			else{
				if((left[j] %right[i]) == 0){
					graph[i][j] = 1;
				}
			}
		}
	}
	printf("%d\n", bipartiteMatching(graph, right, left));
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		printf("Case %d: ", i + 1);
		solve();
	}
	return 0;
}