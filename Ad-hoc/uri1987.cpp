#include <bits/stdc++.h>

using namespace std;

int main()
{
	string str;
	while(getline(cin, str)){
		string num2 = str.substr(str.find(' ') + 1, str.size());
		int cont = 0;
		for(int i = 0; i < num2.size(); i++){
			cont += num2[i] - '0';
		}
		printf("%d %s\n", cont, cont % 3 == 0 ? "sim": "nao");
	}
}