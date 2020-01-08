#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	while(scanf("%d", &num) != EOF){
		getchar();

		string *vet = new string[num];
		for(int i = 0; i < num; i++){
			string temp;
			getline(cin, temp);
			vet[i] = temp;
		}
		sort(vet, vet + num);
		for(int i = 0; i < num; i++){
			cout << vet[i] << endl;
		}
	}
}