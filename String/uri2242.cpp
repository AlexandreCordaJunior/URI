#include <bits/stdc++.h>

using namespace std;

bool palin(string str){
	for(int i = 0; i < str.size() / 2; i++){
		if(str[i] != str[str.size() -  1 - i]){
			return false;
		}
	}
	return true;
}

int main()
{
	string str, temp;
	getline(cin, str);
	temp = "";
	for(int i = 0; i < str.size(); i++){
		if(str[i] == 'a' or str[i] == 'e' or str[i] == 'i'
			or str[i] == 'o' or str[i] == 'u'){
			temp += str[i];
		}
	}
	printf("%c\n", palin(temp) ? 'S' : 'N');
}