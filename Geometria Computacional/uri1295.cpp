#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> point;

int main()
{
	int num;
	while(scanf("%d", &num) && num){
		point *vet = new point[num];

		for(int i = 0; i < num; i++){
			double x, y;
			scanf("%lf %lf", &x, &y);
			vet[i] = {x, y};
		}

		double maxDit = INT_MAX;

		for(int i = 0; i < num; i++){
			for(int j = i + 1; j < num; j++){
				double dist = sqrt((vet[i].first - vet[j].first) * (vet[i].first - vet[j].first)
						+ (vet[i].second - vet[j].second) * (vet[i].second - vet[j].second));
				if(dist < maxDit) maxDit = dist;
			}
		}

		if(maxDit > 10000.0){
			printf("INFINITY\n");
		}
		else{
			printf("%.4lf\n", maxDit);
		}
	}
}