#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	int num;
	scanf("%d", &num);
	while(num--){
		ll temp;
		scanf("%lld", &temp);

		if(temp % 4 == 0){
			printf("%d\n", 1);
		}
		if(temp % 4 == 1){
			printf("%d\n", 7);
		}
		if(temp % 4 == 2){
			printf("%d\n", 9);
		}
		if(temp % 4 == 3){
			printf("%d\n", 3);
		}
	}
}