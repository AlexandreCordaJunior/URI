#include <bits/stdc++.h>

using namespace std;

int main()
{
	string str;
	while(getline(cin, str)){
		for(int i = 0; i < str.size(); i++){
			for(int j = 0; j < i; j++){
				printf(" ");
			}

			for(int j = 0; j < str.size() - i; j++){
				if(j == 0){
					printf("%c", str[j]);
				}
				else{
					printf(" %c", str[j]);
				}
			}
			printf("\n");
		}
		printf("\n");
	}
}