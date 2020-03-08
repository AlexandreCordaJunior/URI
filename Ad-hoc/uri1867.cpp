#include <bits/stdc++.h>

using namespace std;

int main()
{
	string str;
	while(1){
		getline(cin, str);
		if(str.compare("0 0") == 0) break;

		string str1, str2;
		str1 = str.substr(0, str.find(' '));
		str2 = str.substr(str.find(' ') + 1, str.size());

		int peso1;
		int peso2;
		do{
			peso1 = 0;
			for(int i = 0; i < str1.size(); i++){
				peso1 += str1[i] - '0';
			}
			str1 = to_string(peso1);
		} while(str1.size() > 1);

		do{
			peso2 = 0;
			for(int i = 0; i < str2.size(); i++){
				peso2 += str2[i] - '0';
			}
			str2 = to_string(peso2);
		} while(str2.size() > 1);

		printf("%d\n", peso1 == peso2 ? 0 : peso1 > peso2 ? 1 : 2);
	}
}