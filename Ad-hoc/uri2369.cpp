#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	scanf("%d", &num);
	int cons = 0;

	if(num > 100){
		cons += (num - 100) * 5;
		num = 100;
	}
	if(num > 30){
		cons += (num - 30) * 2;
		num = 30;
	}
	if(num > 10){
		cons += (num - 10);
		num = 10;
	}
	cons += 7;
	printf("%d\n", cons);
}