#include <bits/stdc++.h>
#define db(x) cout << x << endl

using namespace std;

struct team{
	int num;
	int pontos;
	int tomados;
	int cestas;
	int insc;

	team(){}

	team(int num){
		this->num = num;
		pontos = 0;
		cestas = 0;
		tomados = 0;
		insc = 0;
	}
};

bool eq(double a, double b){
	return fabs(a - b) < 10e-6;
}

typedef struct team Team;

bool comp(Team t1, Team t2){
	if(t1.pontos < t2.pontos){
		return false;
	}
	if(t1.pontos > t2.pontos){
		return true;
	}
	double raz1, raz2;
	raz1 = t1.tomados == 0 ? t1.cestas : t1.cestas / (double) t1.tomados;
	raz2 = t2.tomados == 0 ? t2.cestas : t2.cestas / (double) t2.tomados;

	if(eq(raz1, raz2)){
		if(t1.cestas < t2.cestas){
			return false;
		}
		if(t1.cestas > t2.cestas){
			return true;
		}
		if(t1.insc > t2.insc){
			return true;
		}
		return false;


	}
	if(raz1 > raz2){
		return true;
	}
	else{
		return false;
	}
}

int caso = 1;

int main()
{
	int num;
	while(scanf("%d", &num) && num){
		if(caso != 1) printf("\n");
		Team *vet = new Team[num];
		for(int i = 0; i < num; i++) vet[i] = team(i + 1);
		for(int i = 0; i < (num * (num - 1)) / 2; i++){
			int time1, pontos1, time2, pontos2;
			scanf("%d %d %d %d", &time1, &pontos1, &time2, &pontos2);
			if(pontos1 > pontos2){
				vet[time1 - 1].pontos += 2;
				vet[time2 - 1].pontos += 1;
			}
			else{
				vet[time1 - 1].pontos += 1;
				vet[time2 - 1].pontos += 2;	
			}
			vet[time1 - 1].cestas += pontos1;
			vet[time1 - 1].tomados += pontos2;
			vet[time2 - 1].cestas += pontos2;
			vet[time2 - 1].tomados += pontos1;
			vet[time1 - 1].insc++;
			vet[time2 - 1].insc++;
		}
		sort(vet, vet + num, comp);
		printf("Instancia %d\n", caso++);
		for(int i = 0; i < num; i++){
			if(i == 0) printf("%d", vet[i].num);
			else printf(" %d", vet[i].num);
		}
		printf("\n");

		/*for(int i = 0; i < num; i++){
			printf("%d %d %d %d %d -- %.6lf\n", vet[i].insc, vet[i].num, vet[i].cestas, vet[i].tomados, vet[i].pontos, vet[i].cestas / (double) vet[i].tomados);
		}*/
	}
}