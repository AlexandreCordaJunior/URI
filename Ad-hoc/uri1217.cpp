#include <bits/stdc++.h>

using namespace std;

int main()
{
	int dias;
	scanf("%d", &dias);

	double totalKg, totalRs;
	totalKg = totalRs = 0;

	for(int w = 0; w < dias; w++){
		double preco;
		scanf("%lf", &preco);

		totalRs += preco;

		getchar();
		string total;
		getline(cin, total);
		int espacos = 1;
		for(int i = 0; i < total.size(); i++){
			if(total[i] == ' ') espacos++;
		}
		printf("day %d: %d kg\n", w + 1, espacos);

		totalKg += espacos;
	}
	printf("%.2lf kg by day\n", totalKg / (double) dias);
	printf("R$ %.2lf by day\n", totalRs / (double) dias);
}