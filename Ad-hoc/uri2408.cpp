#include <bits/stdc++.h>

using namespace std;

int main()
{
	int vet[3];
	for(int i = 0; i < 3; i++){
		scanf("%d", &vet[i]);
	}
	sort(vet, vet + 3);
	printf("%d\n", vet[1]);
}