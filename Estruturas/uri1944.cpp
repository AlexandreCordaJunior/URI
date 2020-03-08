#include <bits/stdc++.h>

using namespace std;

bool isInverse(string str1, string str2){
	for(int i = 0; i < str1.size(); i++){
		if(str1[i] != str2[str2.size() - i - 1]){
			return false;
		}
	}
	return true;
}

int main()
{
	int num;
	scanf("%d", &num);
	getchar();

	stack<string> s;
	s.push("FACE");
	int cont = 0;

	for(int i = 0; i < num; i++){
		string str;
		getline(cin, str);
		
		string temp = "";
		temp += str[0];
		temp += str[2];
		temp += str[4];
		temp += str[6];

		string topo = s.top();
		if(isInverse(topo, temp)){
			s.pop();
			cont++;
		}
		else{
			s.push(temp);
		}
		if(s.empty()){
			s.push("FACE");
		}
	}
	printf("%d\n", cont);
}