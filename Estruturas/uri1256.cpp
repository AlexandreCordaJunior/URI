#include <bits/stdc++.h>

using namespace std;

struct Hash{
	vector<vector<int>> vvi;
	int n;

	Hash(int n){
		this->n = n;
		vvi.assign(n, vector<int>());
	}

	void chain(int key){
		vvi[key % n].push_back(key);
	}

	void print(){
		for(int i = 0; i < n; i++){
			vvi[i].push_back(-1);
		}
		for(int i = 0; i < n; i++){
			printf("%d -> ", i);
			for(auto v : vvi[i]){
				if(v == -1){
					printf("\\");
				}
				else{
					printf("%d -> ", v);
				}
			}
			printf("\n");
		}
	}

};

int main()
{
	int casos;
	scanf("%d", &casos);
	for(int i = 0; i < casos; i++){
		if(i != 0) printf("\n");
		int espaco, chaves;
		scanf("%d %d", &espaco, &chaves);
		Hash h(espaco);
		for(int i = 0; i < chaves; i++){
			int temp;
			scanf("%d", &temp);
			h.chain(temp);
		}
		h.print();
	}
}