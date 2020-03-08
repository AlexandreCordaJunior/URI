#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num1, num2;
	scanf("%d %d", &num1, &num2);

	int res = 1;
	while(1){
		if((num1 * (res + 1)) <= (num2 * res)) break;
		res++;
	}
	printf("%d\n", res + 1);
}