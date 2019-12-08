#include <bits/stdc++.h>
#define db(x) cout << x << endl;

using namespace std;

int dist[501][501];
int n, m;

int dijkstra(pair<int, int> start, pair<int, int> finish, string *vet){
	dist[start.first][start.second] = 0;
	priority_queue<pair<int, pair<int, int>>,
		vector<pair<int, pair<int, int>>>,
		greater<pair<int, pair<int, int>>>> q;

	q.push({0, {start.first, start.second}});
	while(!q.empty()){
		pair<int, pair<int, int>> u = q.top(); q.pop();
		int x = u.second.first;
		int y = u.second.second;
		int valor;
		if(x != 0){
			if(vet[x - 1][y] == 'H' or vet[x - 1][y] == 'E'){
				valor = 0;
			}
			else if(vet[x - 1][y] == '#'){
				valor = INT_MAX >> 2;
			}
			else if(vet[x - 1][y] == '.'){
				valor = 0;
			}
			else{
				valor = vet[x - 1][y] - '0';
			}
			if(dist[x - 1][y] > u.first + valor){
				dist[x - 1][y] = u.first + valor;
				q.push({dist[x - 1][y], {x - 1, y}});
			}
		}
		if(x != n - 1){
			if(vet[x + 1][y] == 'H' or vet[x + 1][y] == 'E'){
				valor = 0;
			}
			else if(vet[x + 1][y] == '#'){
				valor = INT_MAX >> 2;
			}
			else if(vet[x + 1][y] == '.'){
				valor = 0;
			}
			else{
				valor = vet[x + 1][y] - '0';
			}
			if(dist[x + 1][y] > u.first + valor){
				dist[x + 1][y] = u.first + valor;
				q.push({dist[x + 1][y], {x + 1, y}});
			}
		}
		if(y != 0){
			if(vet[x][y - 1] == 'H' or vet[x][y - 1] == 'E'){
				valor = 0;
			}
			else if(vet[x][y - 1] == '#'){
				valor = INT_MAX >> 2;
			}
			else if(vet[x][y - 1] == '.'){
				valor = 0;
			}
			else{
				valor = vet[x][y - 1] - '0';
			}
			if(dist[x][y - 1] > u.first + valor){
				dist[x][y - 1] = u.first + valor;
				q.push({dist[x][y - 1], {x, y - 1}});
			}
		}
		if(y != m - 1){
			if(vet[x][y + 1] == 'H' or vet[x][y + 1] == 'E'){
				valor = 0;
			}
			else if(vet[x][y + 1] == '#'){
				valor = INT_MAX >> 2;
			}
			else if(vet[x][y + 1] == '.'){
				valor = 0;
			}
			else{
				valor = vet[x][y + 1] - '0';
			}
			if(dist[x][y + 1] > u.first + valor){
				dist[x][y + 1] = u.first + valor;
				q.push({dist[x][y + 1], {x, y + 1}});
			}
		}
	}
	return dist[finish.first][finish.second];

}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			dist[i][j] = INT_MAX >> 2;
		}
	}
	getchar();
	string *vet = new string[n];
	for(int i = 0; i < n; i++){
		getline(cin, vet[i]);
	}
	pair<int, int> posH, posE;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(vet[i][j] == 'H'){
				posH = {i, j};
			}
			else if(vet[i][j] == 'E'){
				posE = {i, j};
			}
		}
	}

	int x = dijkstra(posH, posE, vet);
	if(x == INT_MAX >> 2){
		printf("ARTSKJID\n");
	}
	else{
		printf("%d\n", x);
	}
}