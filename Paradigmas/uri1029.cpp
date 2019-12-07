#include <bits/stdc++.h>

using namespace std;

int *vet;

int fibAux(int num){
	if(vet[num] != 0) return vet[num];
	return (fibAux(num - 1) + fibAux(num - 2) + 1);
}

void init(){
	vet = new int[41];
	for(int i = 0; i < 41; i++){
		vet[i] = 0;
	}
	vet[1] = 1;
	vet[2] = 3;
}

int main()
{
	int cases;
	scanf("%d", &cases);
	init();
	while(cases--){
		int num;
		scanf("%d", &num);
		if(num == 1){
			printf("fib(1) = 0 calls = 1\n");
		}
		else{
			if(num == 2){
				printf("fib(2) = 3 calls = 2\n");
			}
			else{
				int x, y, temp;
				x = 1;
				y = 1;
				temp = 2;
				for(int i = 3; i < num; i++){
					temp += y;
					x = y;
					y = temp - x;
				}
				printf("fib(%d) = %d calls = %d\n", num, fibAux(num) - 1, temp);
			}
		}
	}
}