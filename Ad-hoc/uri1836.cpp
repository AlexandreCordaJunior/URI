#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	scanf("%d", &num);
	getchar();

	for(int i = 0; i < num; i++){
		string str1, str2, str3, str4, str5;

		getline(cin, str1);
		getline(cin, str2);
		getline(cin, str3);
		getline(cin, str4);
		getline(cin, str5);

		string nome = str1.substr(0, str1.find(' '));
		int nivel = stoi(str1.substr(str1.find(' ') + 1, str1.size()));

		int baseHp, ivHp, evHp;
		int baseAt, ivAt, evAt;
		int baseDef, ivDef, evDef;
		int baseSp, ivSp, evSp;

		baseHp = stoi(str2.substr(0, str2.find(' ')));
		str2 = str2.substr(str2.find(' ') + 1, str2.size());
		ivHp = stoi(str2.substr(0, str2.find(' ')));
		evHp = stoi(str2.substr(str2.find(' ') + 1, str2.size()));

		baseAt = stoi(str3.substr(0, str3.find(' ')));
		str3 = str3.substr(str3.find(' ') + 1, str3.size());
		ivAt = stoi(str3.substr(0, str3.find(' ')));
		evAt = stoi(str3.substr(str3.find(' ') + 1, str3.size()));

		baseDef = stoi(str4.substr(0, str4.find(' ')));
		str4 = str4.substr(str4.find(' ') + 1, str4.size());
		ivDef = stoi(str4.substr(0, str4.find(' ')));
		evDef = stoi(str4.substr(str4.find(' ') + 1, str4.size()));

		baseSp = stoi(str5.substr(0, str5.find(' ')));
		str5 = str5.substr(str5.find(' ') + 1, str5.size());
		ivSp = stoi(str5.substr(0, str5.find(' ')));
		evSp = stoi(str5.substr(str5.find(' ') + 1, str5.size()));

		int HP = ((ivHp + baseHp + (sqrt(evHp) / 8.0) + 50) * nivel) / 50 + 10;
		int AT = ((ivAt + baseAt + (sqrt(evAt) / 8.0)) * nivel) / 50 + 5;
		int DEF = ((ivDef + baseDef + (sqrt(evDef) / 8.0)) * nivel) / 50 + 5;
		int SPE = ((ivSp + baseSp + (sqrt(evSp) / 8.0)) * nivel) / 50 + 5;

		cout << "Caso #" + to_string(i + 1) + ": " + nome + " nivel " + to_string(nivel) << endl;

		printf("HP: %d\n", HP);
		printf("AT: %d\n", AT);
		printf("DF: %d\n", DEF);
		printf("SP: %d\n", SPE);
	}
}