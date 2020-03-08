#include <bits/stdc++.h>

using namespace std;

int main()
{
	int vet1[5], vet2[5];
	for(int i = 0; i < 5; i++){
		scanf("%d", &vet1[i]);
	}

	bool comp = true;

	for(int i = 0; i < 5; i++){
		scanf("%d", &vet2[i]);
		if(vet1[i] == vet2[i]){
			comp = false;
		}
	}
	printf("%c\n", comp ? 'Y' : 'N');
}