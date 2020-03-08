#include <bits/stdc++.h>
#define db(x) ;

using namespace std;

int main()
{
	while(1){
		string str;
		getline(cin, str);
		if(str[0] == '*') break;

		string str1;
		bool alit = true;
		char letter = tolower(str[0]);
		while(1){
			str1 = str.substr(0, str.find(' '));
			if(tolower(str1[0]) != letter){
				alit = false;
				break;
			}
			str = str.substr(str.find(' ') + 1, str.size());
			db(str1 << " " << str);
			if(str.compare(str1) == 0) break;
		}
		printf("%c\n", alit ? 'Y' : 'N');
	}
}