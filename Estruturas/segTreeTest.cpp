#include <bits/stdc++.h>
#define left(x) x << 1
#define right(x) (x << 1) + 1


using namespace std;

typedef vector<int> vi;

struct SegTree{
	vi vet, tree;
	int n;

	SegTree(vi vet){
		this->vet = vet;
		n = (int)vet.size();
		tree.assign(n, 0);
		build(1, 0, n - 1);
		/*for(auto a : tree){
			printf("%d\n", a);
		}*/
	}

	void build(int el, int l, int r){
		if(r == l)  tree[el] = l;
		else{
			build(left(el), l, (l + r) / 2);
			build(right(el), (l + r) / 2 + 1, r);
			int p1 = tree[left(el)];
			int p2 = tree[right(el)];
			tree[el] = (vet[p1] <= vet[p2]) ? p1 : p2;
		}
	}
	int query(int i, int j){
		return query(1, 0, n - 1, i, j);
	}

	int query(int el, int l, int r, int i, int j){
		if(i > r || j < l) return -1;
		if(l >= i && r <= j) return tree[el];

		int p1 = query(left(el), l, (l + r) / 2, i, j);
		int p2 = query(right(el), (l + r) / 2 + 1, r, i, j);
		if(p1 == -1) return p2;
		if(p2 == -1) return p1;
		return (vet[p1] <= vet[p2]) ? p1 : p2;
	}
};

int main()
{
	vi vet;
	vet.push_back(18);
	vet.push_back(17);
	vet.push_back(13);
	vet.push_back(19);
	vet.push_back(15);
	vet.push_back(11);
	vet.push_back(20);

	SegTree s(vet);
	printf("Query de (1, 3) = %d\n", s.query(1, 3));
	printf("Query de (4, 6) = %d\n", s.query(4, 6));
}