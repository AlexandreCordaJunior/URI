#include <bits/stdc++.h>

using namespace std;

int main()
{
	string str;
	vector<string> vet;
	map<string, int> mapa;
	while(getline(cin, str)){
		string temp;
		for(int i = 0; i < str.size(); i++){
			if(isalpha(str[i])){
				temp += tolower(str[i]);
			}
			else{
				if(temp[temp.size() - 1] != ' '){
					temp += ' ';
				}
			}
		}

		str = temp;
		string str1;
		int qtdEsp = 0;

		for(int i = 0; i < str.size(); i++){
			if(i == str.size() - 1) break;
			if(str[i] == ' '){
				qtdEsp++;
			}
		}

		for(int i = 0; i < qtdEsp; i++){
			str1 = str.substr(0, str.find(' '));
			str = str.substr(str.find(' ') + 1, str.size());
			if(mapa[str1] == 0 && str1.compare(" ") != 0){
				mapa[str1] = 1;
				vet.push_back(str1);
			}
		}
		if(str.find(' ') != -1){
			str = str.substr(0, str.find(' '));
		}
		if(mapa[str] == 0 && str.compare(" ") != 0){
			mapa[str] = 1;
			vet.push_back(str);
		}
	}
	sort(vet.begin(), vet.end());
	for(int i = 0; i < vet.size(); i++){
		if(i == 0){
			
			if(vet[i].compare("\0") != 0){
				cout << vet[i] << endl;
			}
		}
		else{
			cout << vet[i] << endl;
		}
	}
}