#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	while(1){
		scanf("%d", &num);
		if(num == 0) break;

		int vetInc[26];

		for(int i = 0; i < 26; i++){
			vetInc[i] = 0;
		}

		getchar();

		string str, str1, str2, str3;

		int qtdCor, pontos;
		qtdCor = pontos = 0;

		for(int i = 0; i < num; i++){
			getline(cin, str);
			str1 = str.substr(0, str.find(' '));
			str = str.substr(str.find(' ') + 1, str.size());
			str2 = str.substr(0, str.find(' '));
			str3 = str.substr(str.find(' ') + 1, str.size());

			int val = stoi(str2);

			if(str3.compare("correct") == 0){
				qtdCor++;
				pontos += val;
				pontos += (vetInc[str1[0] - 'A'] * 20);
			}
			else{
				vetInc[str1[0] - 'A']++;
			}
		}

		printf("%d %d\n", qtdCor, pontos);
	}
}