#include <bits/stdc++.h>

using namespace std;

int main()
{
	int desc, frases;
	scanf("%d %d", &desc, &frases);
	getchar();
	unordered_map<string, int> mapa;
	for(int i = 0; i < desc; i++){
		string str;
		getline(cin, str);
		string str1 = str.substr(0, str.find(' '));
		string str2 = str.substr(str.find(' ') + 1, str.size());
		string::size_type sz;
		int value = stoi(str2, &sz);
		mapa[str1] = value;
	}
	for(int i = 0; i < frases; i++){
		string str;
		int soma = 0;
		while(1){
			getline(cin, str);
			if(str.compare(".") == 0) {
				break;
			}
			string str1, str2;
			str2 = str;
			while(1){
				if(str2.find(' ') == -1){
					soma += mapa[str2];
					break;
				}
				else{
					str1 = str2.substr(0, str2.find(' '));
					str2 = str2.substr(str2.find(' ') + 1, str2.size());
					soma += mapa[str1];
				}
			}
			//cout << soma << endl;
		}
		printf("%d\n", soma);
	}
}