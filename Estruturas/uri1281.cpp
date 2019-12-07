#include <bits/stdc++.h>

using namespace std;

int main()
{
	int casos;
	scanf("%d", &casos);
	while(casos--){
		int qtd;
		scanf("%d", &qtd);

		map<string, double> mapa;
		getchar();
		for(int i = 0; i < qtd; i++){
			string str;
			getline(cin, str);
			string str1, str2;
			str1 = str.substr(0, str.find(" "));
			str2 = str.substr(str.find(" ") + 1, str.size());
			string::size_type sz;
			double preco = stod(str2, &sz);
			mapa[str1] = preco;
		}
		double sum = 0.0;
		int prod = 0;
		scanf("%d", &prod);
		getchar();
		for(int i = 0; i < prod; i++){
			string str;
			getline(cin, str);
			string str1, str2;
			str1 = str.substr(0, str.find(' '));
			str2 = str.substr(str.find(' ') + 1, str.size());
			string::size_type sz;
			int p = stoi(str2, &sz);
			sum += p * mapa[str1];
		}
		printf("R$ %.2f\n", sum);
	}
}