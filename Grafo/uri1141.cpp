#include <bits/stdc++.h>

using namespace std;

int num;
char **vet;
int *peso;

bool compare(char *str1, char *str2){
	return strlen(str1) < strlen(str2);
}

int cultivando(int i, int num){
	if(peso[i] != 0){
		return peso[i];
	}
	for(int j = i + 1; j < num; j++){
		int max = peso[i];
		if(strstr(vet[j], vet[i]) != NULL){
			int temp = 1 + cultivando(j, num);
			if(temp > max){
				max = temp;
			}
			peso[i] = max;
		}
	}
	return peso[i];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(1){
		num;
		scanf("%d", &num);
		if(num == 0) break;
		vet = (char **) malloc(sizeof(char *) * num);
		peso = new int[num];
		for(int i = 0; i < num; i++){
			getchar();
			char str[1001];
			scanf("%s", str);
			vet[i] = (char *) malloc(sizeof(char) * (strlen(str) + 1));
			strcpy(vet[i], str);
			peso[i] = 0;
		}
		sort(vet, vet + num, compare);
		int max = 0;
		for(int i = 0; i < num; i++){
			int temp = cultivando(i, num);
			if(temp > max){
				max = temp;
			}
		}
		printf("%d\n", max + 1);
	}
}