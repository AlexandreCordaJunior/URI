#include <bits/stdc++.h>
#define db(x) cout << x << endl

using namespace std;

vector<int> primos;
int *qtdDiv;
int *qtdHiperprimos;

void init()
{
	primos.push_back(2);
	primos.push_back(3);
	qtdDiv = new int[2000001];
	qtdHiperprimos = new int[2000001];
	qtdDiv[2] = qtdDiv[3] = 2;
	qtdHiperprimos[2] = 1;
	qtdHiperprimos[3] = 2;

	for(int i = 4; i < 2000001; i++){
		db(i);
		qtdDiv[i] = 2;
		bool ehPrimo = true;

		for(auto j: primos){
			if(i % j == 0){
				ehPrimo = false;
				qtdDiv[i]++;
			}
		}
		qtdHiperprimos[i] = qtdHiperprimos[i - 1];
		if(find(primos.begin(), primos.end(), qtdDiv[i]) != primos.end()){
			qtdHiperprimos[i]++;
		}
		if(ehPrimo){
			primos.push_back(i);
		}
	}
}

int main()
{
	init();

	int num;
	while(scanf("%d", &num) != EOF){
		db(qtdHiperprimos[num]);
	}
}