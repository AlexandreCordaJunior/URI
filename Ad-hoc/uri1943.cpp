#include <bits/stdc++.h>

using namespace std;

int main()
{
	int vet[] = {1, 3, 5, 10, 25, 50, 100};
	int num;
	scanf("%d", &num);

	int i;

	for(i = 0; i < 7; i++){
		if(vet[i] >= num) break;
	}
	printf("Top %d\n", vet[i]);
}