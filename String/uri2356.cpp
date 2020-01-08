#include <bits/stdc++.h>

using namespace std;

int main()
{
	string str1, str2;
	while(getline(cin, str1) && getline(cin, str2)){
		if(str1.find(str2) != string::npos){
			printf("Resistente\n");
		}
		else{
			printf("Nao resistente\n");
		}
	}
}