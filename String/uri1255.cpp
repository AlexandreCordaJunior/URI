#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	scanf("%d", &num);
	getchar();
	while(num--){
		string str;
		getline(cin, str);
		int vet[26];
		for(int i = 0; i < 26; i++){
			vet[i] = 0;
		}
		for(int i = 0; i < str.size(); i++){
			vet[tolower(str[i]) - 'a']++;
		}
		int max = 0;
		for(int i = 0; i < 26; i++){
			if(max < vet[i]) max = vet[i];
		}
		for(int i = 0; i < 26; i++){
			if(vet[i] == max){
				printf("%c", i + 'a');
			}
		}
		printf("\n");
	}
}