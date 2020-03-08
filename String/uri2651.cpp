#include <bits/stdc++.h>

using namespace std;

int main()
{
	string temp;
	getline(cin, temp);
	string str = "";
	for(int i = 0; i < temp.size(); i++){
		str += tolower(temp[i]);
	}
	if(str.find("zelda") != -1){
		printf("Link Bolado\n");
	}
	else{
		printf("Link Tranquilo\n");
	}
}