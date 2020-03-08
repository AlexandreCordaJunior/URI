#include <bits/stdc++.h>

using namespace std;

map<int, int> mapa;

void colatz(int num){
	int max = 0;
	int originalNum = num;
	while(num != 1){
		if(num > max){
			max = num;
		}

		if(mapa[num] != 0){
			if(mapa[num] > max){
				mapa[originalNum] = mapa[num];
				return;
			}
		}

		if(num % 2 == 0){
			num /= 2;
		}
		else{
			num = 3 * num + 1;
		}
	}
	mapa[originalNum] = max;
}

int main()
{
	int num;
	while(1){
		scanf("%d", &num);
		if(!num) break;
		if(num == 1){
			printf("1\n");
		}
		else{
			colatz(num);
			printf("%d\n", mapa[num]);	
		}
	}
}