#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num[5];
	for(int i = 0; i < 5; i++){
		scanf("%d", &num[i]);
	}

	int last = num[0];
	bool crescente = true;
	bool decrescente = true;

	for(int i = 1; i < 5; i++){
		if(last < num[i]){
			crescente = crescente & true;
			decrescente = decrescente & false;
		}
		if(last > num[i]){
			crescente = crescente & false;
			decrescente = decrescente & true;
		}
		last = num[i];
	}
	printf("%c\n", crescente ? 'C' : decrescente ? 'D' : 'N');
}