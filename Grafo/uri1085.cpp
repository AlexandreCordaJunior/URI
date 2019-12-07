#include <bits/stdc++.h>

using namespace std;



struct Graph{
	int v;

};

int main()
{
	int palavras;
	while(1){
		scanf("%d", &palavras);
		if(palavras == 0) break;

		string origem, destino, total;
		getline(cin, total);
		origem = total.substr(0, total.find(' '));
		destino = total.substr(total.find(' ') + 1, total.size());


	}
}