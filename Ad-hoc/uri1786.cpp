#include <bits/stdc++.h>

using namespace std;

int main()
{
	string str;
	while(getline(cin, str)){
		int cont1 = 0;
		for(int i = 0; i < 9; i++){
			cont1 = cont1 + ((str[i] - '0') * (i + 1));
		}
		cont1 = cont1 % 11;
		if(cont1 == 10) cont1 = 0;

		int cont2 = 0;
		for(int i = 0; i < 9; i++){
			cont2 = cont2 + ((str[i] - '0') * (9 - i));
		}
		cont2 = cont2 % 11;
		if(cont2 == 10) cont2 = 0;

		printf("%c%c%c.%c%c%c.%c%c%c-%d%d\n", str[0], str[1], str[2], str[3], str[4],
			str[5], str[6], str[7], str[8], cont1, cont2);
			
	}
}