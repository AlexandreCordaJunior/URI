#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int cont = 0;

	for(int i = 0; i < n; i++){
		bool v = true;
		for(int j = 0; j < m; j++){
			int temp;
			scanf("%d", &temp);
			if(!temp) v = false;
		}
		if(v){
			cont++;
		}
	}
	printf("%d\n", cont);
}