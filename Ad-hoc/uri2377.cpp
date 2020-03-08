#include <bits/stdc++.h>

using namespace std;

int main()
{
	int dis, ped;
	scanf("%d %d", &dis, &ped);

	int qtdPed = dis / ped;

	int pK, pP;
	scanf("%d %d", &pK, &pP);
	int sum = 0;
	sum += (pK * dis) + (pP * qtdPed);
	printf("%d\n", sum);
}