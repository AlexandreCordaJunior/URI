#include <bits/stdc++.h>
#define db(x) cout << x << endl

using namespace std;

bool isPerfectSquare(int n) {
   int root = (int)(sqrt(n) + 0.5);

   return root * root == n;
}

int solve(int varetas){
	int res = 1;
	stack<int> *p = new stack<int>[varetas];

	while(1){
		bool flag = true;
		for(int i = 0; i < varetas; i++){
			if(p[i].empty()){
				p[i].push(res);
				res++;
				flag = false;
				break;
			}
			else{
				if(isPerfectSquare(p[i].top() + res)){
					p[i].push(res);
					res++;
					flag = false;
					break;
				}
			}
		}
		if(flag){
			break;
		}
	}
	return res;
}

int main()
{
	int casos;
	scanf("%d", &casos);

	while(casos--){
		int varetas;
		scanf("%d", &varetas);

		int res = solve(varetas);
		printf("%d\n", res - 1);
	}
}