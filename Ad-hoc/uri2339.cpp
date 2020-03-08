#include <bits/stdc++.h>

using namespace std;

int main()
{
	int c, p, qtd;
	scanf("%d %d %d", &c, &p, &qtd);
	if(qtd * c > p){
		printf("N\n");
	}
	else{
		printf("S\n");	
	}
}