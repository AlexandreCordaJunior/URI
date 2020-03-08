#include <bits/stdc++.h>

using namespace std;

int main()
{
	int casos;
	scanf("%d", &casos);

	while(casos--){
		int inst;
		scanf("%d", &inst);

		map<int, int> mapa;
		getchar();

		string str;
		for(int i = 1; i <= inst; i++){
			getline(cin, str);
			if(str.compare("LEFT") == 0){
				mapa[i] = -1;
			}
			else{
				if(str.compare("RIGHT") == 0){
					mapa[i] = 1;
				}
				else{
					string str1, str2, str3;
					str1 = str.substr(0, str.find(' '));
					str = str.substr(str.find(' ') + 1, str.size());
					str2 = str.substr(0, str.find(' '));
					str3 = str.substr(str.find(' ') + 1, str.size());

					int indice = stoi(str3);

					mapa[i] = mapa[indice];
				}
			}
		}
		int pos = 0;
		for(int i = 1; i <= inst; i++){
			pos += mapa[i];
		}
		printf("%d\n", pos);
	}
}