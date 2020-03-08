#include <bits/stdc++.h>
#define db(x) cout << x << endl

using namespace std;

int main()
{
	string str;
	while(getline(cin, str)){
		queue<char> q;
		for(int i = 0; i < str.size(); i++){
			if(str[i] == '[' or str[i] == ']'){
				q.push(str[i]);
			}
		}
		
		string total = "";	
		bool normal = true;
		while(!q.empty()){
			char c = q.front(); q.pop();
			string str1 = str.substr(0, str.find(c));
			str = str.substr(str.find(c) + 1, str.size());

			if(normal){
				total = total + str1;
			}
			else{
				total = str1 + total;
			}
			if(c == ']'){
				normal = true;
			}
			else{
				normal = false;
			}
		}
		if(normal){
			total = total + str;	
		}
		else{
			total = str + total;
		}
		
		cout << total << endl;
		
	}
}