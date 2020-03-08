#include <bits/stdc++.h>

using namespace std;

pair<int, int> par[] = {
	{0, 1},
	{-1, 0},
	{0, -1},
	{1, 0}
};

int main()
{
	int num;
	while(scanf("%d", &num) && num){
		string *vet = new string[num];
		for(int i = 0; i < num; i++){
			vet[i] = "";
			for(int j = 0; j < num; j++){
				vet[i] += "O";
			}
		}
		int meio = ((num + 1) / 2) - 1;
		vet[meio][meio] = 'X';
		
		int pos = 0;
		int cont = 0;
		int andadas = 1;

		int xAtual, yAtual;
		xAtual = yAtual = meio;

		for(int i = 0; i < num; i++){
			cout << vet[i] << endl;
		}
		cout << "@"<< endl;

		bool quebrar = false;
		if(num == 1) quebrar = true;

		while(!quebrar){
			for(int i = 0; i < 2; i++){
				if(quebrar) break;
				for(int j = 0; j < andadas; j++){
					vet[xAtual][yAtual] = 'O';
					xAtual = xAtual + par[pos].first;
					yAtual = yAtual + par[pos].second;
					vet[xAtual][yAtual] = 'X';

					for(int k = 0; k < num; k++){
						cout << vet[k] << endl;
					}
					cout << "@" << endl;
					if(xAtual == yAtual && xAtual == num - 1){
						quebrar = true;
						break;
					}
				}
				pos = (pos + 1) % 4;
			}	
			andadas++;
		}
	}
}