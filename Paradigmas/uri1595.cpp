#include <bits/stdc++.h>

using namespace std;

int main()
{
	int casos;
	scanf("%d", &casos);
	for(int i = 0; i < casos; i++){
		int space, qtdCorridas, aceleracao;
		scanf("%d %d %d", &space, &qtdCorridas, &aceleracao);
		int *velocidades = new int[space];
		for(int i = 0; i < space; i++){
			scanf("%d", &velocidades[i]);
		}
		sort(velocidades, velocidades + space);
		for(int i = 0; i < qtdCorridas; i++){
			velocidades[i] += aceleracao;
		}
		double sum = 0.0;
		for(int i = 0; i < space; i++){
			sum += (1.0 / velocidades[i]);
		}
		printf("%.2lf\n", sum);
	}
}