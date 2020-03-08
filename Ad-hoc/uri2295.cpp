#include <bits/stdc++.h>

using namespace std;

int main()
{
	double precoAlcool, precoGas, kmAlcool, kmGas;

	scanf("%lf %lf %lf %lf", &precoAlcool, &precoGas, &kmAlcool, &kmGas);
	printf("%c\n", precoAlcool / kmAlcool < precoGas / kmGas ? 'A': 'G');
}