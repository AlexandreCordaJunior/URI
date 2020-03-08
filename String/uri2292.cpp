#include <bits/stdc++.h>
#define db(x) cout << x << endl

using namespace std;

typedef unsigned long long ll;

int main()
{
	int casos;
	scanf("%d", &casos);
	getchar();

	while(casos--){
		string str;
		getline(cin, str);

		string inicial = str.substr(0, str.find(' '));
		ll mudancas = stoi(str.substr(str.find(' ') + 1, str.size()));

		ll num = 0;
		for(int i = 0; i < inicial.size(); i++){
			if(inicial[i] == 'O'){
				num |= (1 << i);
			}
		}
		num += mudancas;
		
		for(int i = 0; i < inicial.size(); i++){
			if(num & (1 << i)){
				printf("O");
			}
			else{
				printf("X");
			}
		}
		printf("\n");
	}
}