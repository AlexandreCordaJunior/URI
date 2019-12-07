#include <bits/stdc++.h>

using namespace std;

const int N = 1000000;
int n;
int tree[2*N];

void build(int *vet){
	for(int i = 0; i < n; i++){
		tree[n + i] = vet[i];
	}
	for(int i = n - 1; i > 0; i--){
		/*Se par, 2*i + (2 * (i + 1))*/
		/*Se impar 2(2 * i) + 1*/
		tree[i] = tree[i << 1] + tree[i << 1 | 1];
	}
	for(int i = 0; i < 2 * n; i++){
		printf("%d %d\n", i, tree[i]);
	}
}

void updateTree(int pos, int value){
	tree[pos + n] = value;
	pos += n;
	for(int i = pos; i > 1; i >>= 1){
		tree[i >> 1] = tree[i] + tree[i^1];
	}
}

int query(int l, int r){
	int res = 0;
	/*l e r dividem por 2*/
	for(l += n, r += n; l < r; l >>= 1, r >>= 1){
		/*Se l for impar*/
		if(l & 1){
			res += tree[l++];
		}
		/*Se r for impar*/
		if(r & 1){
			res += tree[--r];
		}
	}
	return res;
}

int main()
{
	int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	n = sizeof(vet) / sizeof(vet[0]);
	build(vet);
	printf("Query 1 to 3 : %d\n", query(1, 3));
	updateTree(2, 1);
	printf("Query 1 to 3 : %d\n", query(1, 3));
}