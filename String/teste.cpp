#include <bits/stdc++.h>
typedef long long int ll;
#define read() freopen("input.txt", "r", stdin)
using namespace std;

int main(void)
{
	string s;

	while(getline(cin, s)){
		ll sum = 0;
		bool b = 0, c = 0;

		for(int i = 0; i < s.length(); i++){
			if(sum > 2147483647 or (isalpha(s[i]) and s[i] != 'l' and s[i] != 'o' and s[i] != 'O')){
				c = 1;
				break;		
			}
			if(isdigit(s[i]))
				sum = sum * 10 + (s[i] - '0'), b = 1;
			else if(s[i] == 'l')
				sum = sum * 10 + 1, b = 1;
			else if(s[i] == 'o' or s[i] == 'O')
				sum = sum * 10 + 0, b = 1;
		}

		if(!b or c or sum > 2147483647)
			cout << "error" << endl;
		else
			cout << sum << endl;
	}

	return 0;
}