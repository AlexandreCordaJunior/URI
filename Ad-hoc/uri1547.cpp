#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	scanf("%d", &num);
	while(num--){
		int qt, sec;
		scanf("%d %d", &qt, &sec);

		int *vet = new int[qt];

		int diff = INT_MAX;
		int index = -1;

		for(int i = 0; i < qt; i++){
			scanf("%d", &vet[i]);
			if(abs(vet[i] - sec) < diff){
				diff = abs(vet[i] - sec);
				index = i;
			}
		}
		printf("%d\n", index + 1);
		
	}
}