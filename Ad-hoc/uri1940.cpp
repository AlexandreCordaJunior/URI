#include <bits/stdc++.h>

using namespace std;

int main()
{
	int j, r;
	scanf("%d %d", &j, &r);

	int pontos[501];
	int max = 0;

	for(int i = 0; i < j; i++){
		pontos[i] = 0;
	}

	for(int i = 0; i < j * r; i++){
		int temp;
		scanf("%d", &temp);
		pontos[i % j] += temp;	
	}

	int index = 0;

	for(int i = 0; i < j; i++){
		if(pontos[i] >= max){
			max = pontos[i];
			index = i;
		}
	}

	/*for(int i = 0; i < j; i++){
		printf("%d\n", pontos[i]);
	}*/
	printf("%d\n", index + 1);
}