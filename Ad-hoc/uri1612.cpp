#include <bits/stdc++.h>

using namespace std;

int main()
{
	int casos;
	scanf("%d", &casos);
	while(casos--){
		int num;
		scanf("%d", &num);
		if(num % 2 == 0){
			printf("%d\n", num / 2);
		}
		else{
			printf("%d\n", (num + 1) / 2);	
		}
	}
}