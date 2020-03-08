#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, saldo;
	scanf("%d %d", &n, &saldo);
	int minimo = saldo;

	for(int i = 0; i < n; i++){
		int temp;
		scanf("%d", &temp);
		saldo += temp;
		if(saldo < minimo){
			minimo = saldo;
		}
	}
	printf("%d\n", minimo);
}