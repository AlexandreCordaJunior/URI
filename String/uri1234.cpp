#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	while(getline(cin, str)){
		bool upper = true;
		for(int i = 0; i < str.size(); i++){
			if(isalpha(str[i])){
				if(upper){
					printf("%c", toupper(str[i]));
					upper = false;
				}
				else{
					printf("%c", tolower(str[i]));
					upper = true;
				}
			}
			else{
				printf("%c", str[i]);
			}
		}
		printf("\n");
	}
}