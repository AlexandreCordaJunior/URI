#include <bits/stdc++.h>
#define db(x) cout << x << endl

using namespace std;

int main()
{
	int num;
	scanf("%d", &num);
	getchar();

	map<string, char> mapa;
	mapa["=.==="] = 'a';
	mapa["===.=.=.="] = 'b';
	mapa["===.=.===.="] = 'c';
	mapa["===.=.="] = 'd';
	mapa["="] = 'e';
	mapa["=.=.===.="] = 'f';
	mapa["===.===.="] = 'g';
	mapa["=.=.=.="] = 'h';
	mapa["=.="] = 'i';
	mapa["=.===.===.==="] = 'j';
	mapa["===.=.==="] = 'k';
	mapa["=.===.=.="] = 'l';
	mapa["===.==="] = 'm';
	mapa["===.="] = 'n';
	mapa["===.===.==="] = 'o';
	mapa["=.===.===.="] = 'p';
	mapa["===.===.=.==="] = 'q';
	mapa["=.===.="] = 'r';
	mapa["=.=.="] = 's';
	mapa["==="] = 't';
	mapa["=.=.==="] = 'u';
	mapa["=.=.=.==="] = 'v';
	mapa["=.===.==="] = 'w';
	mapa["===.=.=.==="] = 'x';
	mapa["===.=.===.==="] = 'y';
	mapa["===.===.=.="] = 'z';
	

	while(num--){
		string str;
		getline(cin, str);

		int qtdTresPontos = 0;

		string temp1, temp2, temp3;
		temp2 = str;
		temp3 = "";
		while(1){
			if(temp2.find(".......") != -1){
				temp1 = temp2.substr(0, temp2.find("......."));
				temp2 = temp2.substr(temp2.find(".......") + 7, temp2.size());

				temp3 += (temp1 + '*');
			}
			else{
				temp3 += temp2;
				break;
			}
		}
		str = temp3;
		int qtdEst = 0;
		for(int i = 0; i < str.size(); i++){
			if(str[i] == '*') qtdEst++;
		}

		for(int i = 0; i < qtdEst; i++){
			string str1 = str.substr(0, str.find('*'));
			str = str.substr(str.find('*') + 1, str.size());
			qtdTresPontos = 0;

			for(int j = 0; j < str1.size(); j++){
				if(str1[j] == '.' && str1[j - 1] == '.' && str1[j + 1] == '.'){
					qtdTresPontos++;
				}
			}
			for(int j = 0; j < qtdTresPontos; j++){
				string str2 = str1.substr(0, str1.find("..."));
				str1 = str1.substr(str1.find("...") + 3, str1.size());
				printf("%c", mapa[str2]);
			}
			printf("%c ", mapa[str1]);
		}

		qtdTresPontos = 0;

		for(int j = 0; j < str.size(); j++){
			if(str[j] == '.' && str[j - 1] == '.' && str[j + 1] == '.'){
				qtdTresPontos++;
			}
		}
		for(int j = 0; j < qtdTresPontos; j++){
			string str1 = str.substr(0, str.find("..."));
			str = str.substr(str.find("...") + 3, str.size());
			printf("%c", mapa[str1]);
		}
		printf("%c\n", mapa[str]);
	}
}