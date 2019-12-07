#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

class segTree{
public:
	vi seg, arr;
	int n;

	segTree(const vi &A){
		arr = A;
		n = (int) A.size();
		seg.assign(4 * n, 0);
		build(1, 0, n - 1);
		for(auto a : seg){
			printf("%d\n", a);
		}
	}

	void build(int p, int leftNode, int rightNode){
		if(leftNode == rightNode) seg[p] = leftNode;
		else{
			printf("\t%d\t\n", p);
			build(left(p), leftNode, (leftNode + rightNode) / 2);
			build(right(p), (leftNode + rightNode) / 2 + 1, rightNode);
			int p1 = seg[left(p)];
			int p2 = seg[right(p)];
			seg[p] = (arr[p1] <= arr[p2]) ? p1 : p2;
		}
	}

	int query(int p, int leftNode, int rightNode, int i, int j){
		if(i > rightNode||j < leftNode) return -1;
		if(leftNode >= i && rightNode <= j) return seg[p];
		int p1 = query(left(p), leftNode, (leftNode + rightNode) / 2, i, j);
		int p2 = query(right(p), (leftNode + rightNode) / 2 + 1, rightNode, i, j);
		if(p1 == -1) return p2;
		if(p2 == -1) return p1;
		return (arr[p1] <= arr[p2]) ? p1 : p2;
	}

	int query(int i, int j){
		return query(1, 0, n - 1, i, j);
	}

	int left(int p) {return p << 1;}
	int right(int p) {return (p << 1) + 1;}

};

int main()
{
	int arr[] = {18, 17, 13, 19, 15, 11, 20};
	vi vet(arr, arr + 7);
	segTree st(vet);
	printf("RMQ(1, 3) = %d\n", st.query(1, 3));
	printf("RMQ(4, 6) = %d\n", st.query(4, 6));
}