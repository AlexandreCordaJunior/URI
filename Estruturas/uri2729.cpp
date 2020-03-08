#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	scanf("%d", &num);
	getchar();
	while(num--){
		unordered_map<string, bool> mapa;
		string str;
		getline(cin, str);

		int espacos = 0;
		for(int i = 0; i < str.size(); i++){
			if(str[i] == ' '){
				espacos++;
			}
		}

		vector<string> vet;
		for(int i = 0; i < espacos; i++){
			string str1 = str.substr(0, str.find(' '));
			str = str.substr(str.find(' ') + 1, str.size());

			if(mapa[str1] == false){
				vet.push_back(str1);
				mapa[str1] = true;
			}
		}
		if(mapa[str] == false){
			vet.push_back(str);
			mapa[str] = true;
		}

		sort(vet.begin(), vet.end());

		for(int i = 0; i < vet.size(); i++){
			if(i == 0){
				cout << vet[i];
			}
			else{
				cout << " " << vet[i];
			}
		}
		cout << endl;
	}
}