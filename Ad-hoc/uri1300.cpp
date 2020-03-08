#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	while(scanf("%d", &num) != EOF){
		if(num % 6 == 0){
			printf("Y\n");
		}
		else{
			printf("N\n");	
		}
	}
}