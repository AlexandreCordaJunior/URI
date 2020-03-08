#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num1, num2;
	scanf("%d %d", &num1, &num2);

	if(num2 <= 2){
		printf("nova\n");
	}
	else{
		if(num2 >= 97){
			printf("cheia\n");
		}
		else{
			if(num1 < num2){
				printf("crescente\n");
			}
			else{
				printf("minguante\n");
			}
		}
	}
}