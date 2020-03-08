#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	int cont = 1;
	while(scanf("%d", &num) && num){
		int ganhador = -1;

		for(int i = 0; i < num; i++){
			int temp;
			scanf("%d", &temp);
			if(temp == i + 1){
				ganhador = temp;
			}
		}

		printf("Teste %d\n", cont++);
		printf("%d\n\n", ganhador);
	}
}