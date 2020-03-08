#include <bits/stdc++.h>
#define EPS 10e-6

using namespace std;

int main()
{
	double o, b, i, minimo;
	scanf("%lf %lf %lf", &o, &b, &i);

	minimo = min(o, min(b, i));
	bool empate = false;

	string vencedor = "";

	if(fabs(minimo - o) < EPS){
		vencedor = "Otavio";
	}
	if(fabs(minimo - b) < EPS){
		if(vencedor.compare("") == 0){
			vencedor = "Bruno";		
		}
		else{
			vencedor = "Empate";
		}
	}

	if(fabs(minimo - i) < EPS){
		if(vencedor.compare("") == 0){
			vencedor = "Ian";		
		}
		else{
			vencedor = "Empate";
		}
	}
	cout << vencedor << endl;
}