#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num1, num2;
	bool dentro = true;

	scanf("%d %d", &num1, &num2);

	if(num1 < 0 or 432 < num1){
		dentro = false;
	}

	if(num2 < 0 or 468 < num2){
		dentro = false;
	}

	printf("%s\n", dentro ? "dentro": "fora");
}