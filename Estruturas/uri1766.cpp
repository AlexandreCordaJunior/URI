#include <bits/stdc++.h>

using namespace std;

typedef pair<string, pair<int, pair<int, double>>> Rena;

bool comp(Rena r1, Rena r2){
	if(r1.second.first > r2.second.first){
		return true;
	}
	else if(r1.second.first < r2.second.first){
		return false;
	}
	else{
		if(r1.second.second.first < r2.second.second.first){
			return true;
		}
		else if(r1.second.second.first > r2.second.second.first){
			return false;
		}
		else{
			if(r1.second.second.second < r2.second.second.second){
				return true;
			}
			else if(r1.second.second.second > r2.second.second.second){
				return false;
			}
			else{
				return r1.first < r2.first;
			}
		}
	}
}

int main()
{
	int casos;
	scanf("%d", &casos);

	for(int w = 0; w < casos; w++){
		int n, m;
		scanf("%d %d", &n, &m);
		getchar();

		Rena *vet = new Rena[n];

		for(int i = 0; i < n; i++){
			string str;
			getline(cin, str);
			string str1 = str.substr(0, str.find(' '));
			str = str.substr(str.find(' ') + 1, str.size());

			string temp = str.substr(0, str.find(' '));
			str = str.substr(str.find(' ') + 1, str.size());

			int peso = stoi(temp);

			temp = str.substr(0, str.find(' '));
			str = str.substr(str.find(' ') + 1, str.size());

			int idade = stoi(temp);
			
			temp = str.substr(0, str.find(' '));
			str = str.substr(str.find(' ') + 1, str.size());

			double altura = stod(temp);

			vet[i] = {str1, {peso, {idade, {altura}}}};
		}

		sort(vet, vet + n, comp);

		/*for(int i = 0; i < n; i++){
			cout << vet[i].first << " " << vet[i].second.first << " " << vet[i].second.second.first << " " << vet[i].second.second.second << endl;
		}*/
		printf("CENARIO {%d}\n", w + 1);
		for(int i = 0; i < m; i++){
			cout << i + 1 << " - " << vet[i].first << endl;
		}
	}
}