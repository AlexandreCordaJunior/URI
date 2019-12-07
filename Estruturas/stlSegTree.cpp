#include <bits/stdc++.h>

using namespace std;

int n;
int *tree;

void init(){
	tree = (int *) malloc(sizeof(int) * 4 * n);
	for(int i = 0; i < 4 * n; i++){
		tree[i] = 0;
	}
}

void buildTree(int *vet){

	for(int i = 0; i < n ; i++){
		//printf("%d\n", tree[i]);
		tree[n + i] = vet[i];
	}
	for(int i = n - 1; i > 0; i--){
		tree[i] = tree[2 * i] + tree[2 * i | 1];
	}
}

int query(int l, int r){
	int sum = 0;
	for(l += n, r += n; l < r; l /= 2, r /= 2){
		if(l % 2){
			sum += tree[l++];
		}
		if(r % 2){
			sum += tree[--r];
		}
	}
	return sum;
}

void update(int pos, int value){
	tree[pos + n] = value;
	pos += n;
	for(int i = pos; i > 1; i /= 2){
		tree[i / 2] = tree[i] + tree[i ^ 1];
	}
}

int main()
{
	int vet[] = {10,18,81,61,74};
	n = sizeof(vet) / sizeof(vet[0]);
	init();
	buildTree(vet);
	printf("%d\n", query(0, 3));
	printf("%d\n", query(4, 5));
	printf("%d\n", query(1, 4));
}