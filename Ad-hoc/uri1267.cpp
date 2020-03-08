#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, d;
	while(scanf("%d %d", &a, &d) && a && d){
		int matrix[d][a];
		vector<int> todos(a, 1);

		for(int i = 0; i < d; i++){
			for(int j = 0; j < a; j++){
				scanf("%d", &matrix[i][j]);
				todos[j] &= matrix[i][j];
			}
		}
		int res = 0;
		for(int i = 0; i < a; i++){
			res |= todos[i];
		}
		printf("%s\n", res ? "yes" : "no");
	}
}