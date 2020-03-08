#include <bits/stdc++.h>

using namespace std;

int main()
{
	int casos;
	while(1){
		scanf("%d", &casos);
		if(casos == 0) break;
		int l, r;
		l = r = 0;
		for(int i = 0; i < casos; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			if(x > y){
				l++;
			}
			else{
				if(x < y){
					r++;
				}
			}
		}
		printf("%d %d\n", l, r);
	}
}