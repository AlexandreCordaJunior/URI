#include <bits/stdc++.h>
#define lessSig(i) i & (-i)


using namespace std;

typedef vector<int> vi;

struct FenwickTree{
	vi tree;

	FenwickTree(int n){
		tree.assign(n + 1, 0);
	}
	void adjust(int valor, int pulo){
		for(; valor < (int) tree.size(); valor += lessSig(valor)){
			tree[valor] += pulo;
		}
	}
	void print(){
		for(auto i : tree){
			printf("%d\n", i);
		}
	}

	int query(int a, int b){
		return query(b) - (a == 1 ? 0 : query(a - 1));
	}

	int query(int a){
		int sum = 0;
		for(; a ; a -= lessSig(a)){
			sum += tree[a];
		}
		return sum;
	}
};

int main()
{
	int f[] = {2, 4, 5, 5, 6, 6, 6, 7, 7, 8, 9};
	FenwickTree tree(10);
	for(int i = 0; i <= 10; i++){
		tree.adjust(f[i], 1);
	}

	printf("%d\n", tree.query(1, 1));
	printf("%d\n", tree.query(1, 2));
	printf("%d\n", tree.query(1, 6));
	printf("%d\n", tree.query(1, 10));
	printf("%d\n", tree.query(3, 6));
	tree.adjust(5, 2);
	printf("%d\n", tree.query(1, 10));
	//tree.print();
}