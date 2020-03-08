#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, s;
	scanf("%d %d", &n, &s);
	getchar();

	string *vet = new string[n];
	for(int i = 0; i < n; i++){
		getline(cin, vet[i]);
	}
	sort(vet, vet + n);
	cout << vet[s - 1] << endl;
}