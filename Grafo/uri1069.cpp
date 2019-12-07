#include <bits/stdc++.h>

using namespace std;

int main()
{
	int cases;
	scanf("%d", &cases);
	getchar();
	while(cases--){
		string str;
		getline(cin, str);
		int cont = 0;
		stack<char> pilha;
		for(int i = 0; i < str.length(); i++){
			if(str[i] == '<'){
				pilha.push('<');
			}
			else{
				if(str[i] == '>'){
					if(!pilha.empty() && pilha.top() == '<'){
						cont += 1;
						pilha.pop();
					}
					else{
						pilha.push('>');
					}
				}
			}
		}
		printf("%d\n", cont);
	}
}