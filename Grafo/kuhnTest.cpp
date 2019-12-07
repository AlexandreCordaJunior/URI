#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

struct Graph{
	vi right;
	vi left;
	vvi e;

	int sizeRight;
	int sizeLeft;

	Graph(int sizeRight, int sizeLeft, vi right, vi left){
		this->sizeRight = sizeRight;
		this->sizeLeft = sizeLeft;
		this->right = right;
		this->left = left;

		e.assign(sizeRight, vi());
		for(int i = 0; i < sizeRight; i++){
			e[i].assign(sizeLeft, 0);
		}

		for(int i = 0; i < sizeRight; i++){
			for(int j = 0; j < sizeLeft; j++){
				if(right[i] == 0){
					if(left[i] == 0){
						e[i][j] = 1;
					}
				}
				else{
					if(left[j] % right[i] == 0){
						e[i][j] = 1;
					}
				}
			}
		}
		printf("%d\n", biMatch());
		/*for(int i = 0; i < sizeRight; i++){
			for(int j = 0; j < sizeLeft; j++){
				printf("%d\t", e[i][j]);
			}
			printf("\n");
		}*/
	}

	int biMatch(){
		for(int i = 0; i < sizeRight; i++){
			right[i] = -1;
		}
		for(int i = 0; i < sizeLeft; i++){
			left[i] = -1;
		}

		int cont = 0;
		for(int i = 0; i < sizeRight; i++){
			vi seen;
			for(int j = 0; j < sizeLeft; j++){
				seen.push_back(0);
			}
			if(find(i, seen)) cont++;
		}
		return cont;
	}

	int find(int i, vi &seen){
		for(int j = 0; j < sizeLeft; j++){
			if(e[i][j] && !seen[j]){
				seen[j] = true;
				if(left[j] < 0 || find(left[j], seen)){
					right[i] = j;
					left[j] = i;
					return true;
				}
			}
		}
		return false;
	}
};

int main()
{
	int casos;
	scanf("%d", &casos);
	for(int w = 0; w < casos; w++){
		int n, m;
		scanf("%d", &n);
		vector<int> vetN(n);
		for(int i = 0; i < n; i++){
			scanf("%d", &vetN[i]);
		}
		scanf("%d", &m);
		vector<int> vetM(m);

		for(int i = 0; i < m; i++){
			scanf("%d", &vetM[i]);
		}
		printf("Case %d: ", w + 1);

		Graph g(n, m, vetN, vetM);
	}
}