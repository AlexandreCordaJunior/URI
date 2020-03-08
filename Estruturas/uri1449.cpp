#include <bits/stdc++.h>

using namespace std;

int main()
{
	int casos;
	scanf("%d", &casos);
	for(int w = 0; w < casos; w++){
		int trad, queries;
		scanf("%d %d", &trad, &queries);
		getchar();

		map<string, string> mapa;

		for(int i = 0; i < trad; i++){
			string str1, str2;
			getline(cin, str1);
			getline(cin, str2);
			mapa[str1] = str2;
		}
		for(int i = 0; i < queries; i++){
			string str;
			getline(cin, str);

			int qtdEsp = 0;
			for(int j = 0; j < str.size(); j++){
				if(str[j] == ' ') qtdEsp++;
			}
			for(int j = 0; j < qtdEsp; j++){
				string str1 = str.substr(0, str.find(' '));
				str = str.substr(str.find(' ') + 1, str.size());

				if(mapa[str1].compare("") == 0){
					cout << str1;
				}
				else{
					cout << mapa[str1];
				}
				cout << " ";
			}
			if(mapa[str].compare("") == 0){
				cout << str << endl;
			}
			else{
				cout << mapa[str] << endl;
			}
		}
		cout << endl;
	}
}