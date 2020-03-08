#include <bits/stdc++.h>

using namespace std;

int gdc(int a, int b){
	if(b == 0){
		return a;
	}
	return gdc(b, a % b);
}

int main()
{
	int num;
	scanf("%d", &num);

	while(num--){
		int n1, d1, n2, d2;
		char op;

		scanf("%d / %d %c %d / %d", &n1,  &d1, &op, &n2, &d2);

		int resN, resD;

		switch(op){
			case '+':
			resN = (n1 * d2 + n2 * d1);
			resD = (d1 * d2);
			break;
			case '-':
			resN = (n1 * d2 - n2 * d1);
			resD = (d1 * d2);
			break;
			case '*':
			resN = n1 * n2;
			resD = d1 * d2;
			break;
			case '/':
			resN = (n1 * d2);
			resD = (n2 * d1);
			break;
		}

		int oriN, oriD;
		oriN = resN;
		oriD = resD;

		int common = gdc(oriN, oriD);
		resN /= common;
		resD /= common;

		if(resD < 0){
			resD = resD * (-1);
			resN = resN * (-1);
		}

		printf("%d/%d = %d/%d\n", oriN, oriD, resN, resD);
	}
}