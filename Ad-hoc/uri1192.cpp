#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	scanf("%d", &num);
	getchar();
	while(num--){
		string str;
		getline(cin, str);
		if((str[0] - '0') == (str[2] - '0')){
			printf("%d\n", (str[0] - '0') * (str[0] - '0'));
		}
		else{
			if(islower(str[1])){
				printf("%d\n", str[2] - '0' + str[0] - '0');
			}
			else{
				printf("%d\n", (str[2] - '0') - (str[0] - '0'));
			}
		}
	}
}