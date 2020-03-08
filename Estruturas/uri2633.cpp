#include <bits/stdc++.h>

using namespace std;

typedef pair<int, string> peca;

int main()
{
	int num;
	while(scanf("%d", &num) != EOF){
		getchar();

		peca *vet = new peca[num];

		for(int i = 0; i < num; i++){
			string str;
			getline(cin, str);
			string str1 = str.substr(0, str.find(' '));
			str = str.substr(str.find(' ') + 1, str.size());

			vet[i] = {stoi(str), str1};
		}
		sort(vet, vet + num);

		for(int i = 0; i < num; i++){
			if(i == 0){
				cout << vet[i].second;
			}
			else{
				cout << " " << vet[i].second;
			}
		}
		cout << endl;
	}
}