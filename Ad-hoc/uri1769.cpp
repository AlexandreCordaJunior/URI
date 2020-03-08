#include <bits/stdc++.h>
#define db(x) cout << x << endl

using namespace std;

int main()
{
	string str;
	while(getline(cin, str)){
		int d1, d2, d3, d4, d5, d6, d7, d8, d9, b1, b2;

		d1 = str[0] - '0';
		d2 = str[1] - '0';
		d3 = str[2] - '0';
		d4 = str[4] - '0';
		d5 = str[5] - '0';
		d6 = str[6] - '0';
		d7 = str[8] - '0';
		d8 = str[9] - '0';
		d9 = str[10] - '0';

		b1 = str[12] - '0';
		b2 = str[13] - '0';

		int sum1 = d1 + (d2 * 2) + (d3 * 3) + (d4 * 4) + (d5 * 5) + (d6 * 6) + (d7 * 7) + 
			(d8 * 8) + (d9 * 9);
		int rest1 = sum1 % 11;
		if(rest1 == 10) rest1 = 0;

		int sum2 = (d1 * 9) + (d2 * 8) + (d3 * 7) + (d4 * 6) + (d5 * 5) + (d6 * 4) + (d7 * 3) + 
			(d8 * 2) + d9;
		int rest2 = sum2 % 11;
		if(rest2 == 10) rest2 = 0;

		if(rest1 == b1 && rest2 == b2){
			printf("CPF valido\n");
		}
		else{
			printf("CPF invalido\n");
		}
	}
}