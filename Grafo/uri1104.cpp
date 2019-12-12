#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b;
	while(1){
		scanf("%d %d", &a, &b);
		if(!a && !b) break;
		int *vet1 = new int[a];
		int *vet2 = new int[b];
		vector<bool> taken1(100002, false);
		vector<bool> taken2(100002, false);
		for(int i = 0; i < a; i++){
			scanf("%d", &vet1[i]);
			taken1[vet1[i]] = true;
		}

		for(int i = 0; i < b; i++){
			scanf("%d", &vet2[i]);
			taken2[vet2[i]] = true;
		}

		int count1, count2;
		count1 = count2 = 0;
		for(int i = 0; i < a; i++){
			if(!taken2[vet1[i]]){
				taken2[vet1[i]] = true;
				count1++;
			}
		}

		for(int i = 0; i < b; i++){
			if(!taken1[vet2[i]]){
				taken1[vet2[i]] = true;
				count2++;
			}
		}
		printf("%d\n", min(count1, count2));
	}
}