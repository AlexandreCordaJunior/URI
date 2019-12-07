#include <bits/stdc++.h>

using namespace std;

int temp[231];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int casos;
	scanf("%d", &casos);
	while(casos--){
		bool first = true;
		int pessoas;
		scanf("%d", &pessoas);
		memset(temp, 0, sizeof(temp));
		for(int i = 0; i < pessoas; i++){
			int t;
			scanf("%d", &t);
			temp[t]++;
			//printf("\t%d : %d\t\n", temp[t], t);
		}
		for(int i = 20; i < 231; i++){
			while(temp[i]){
				if(first){
					printf("%d", i);
					first = false;
				}
				else printf(" %d", i);
				temp[i]--;
			}
		}
		printf("\n");
	}
}