#include <bits/stdc++.h>

using namespace std;

struct Present{
	int id, x, y, z, tam;

	Present(int id, int x, int y, int z){
		this->id = id;
		this->x = x;
		this->y = y;
		this->z = z;
		tam = x * y * z;
	}
};

bool compareId(Present p1, Present p2){
	return (p1.id < p2.id);
}

bool comparePeso(Present p1, Present p2){
	return (p1.tam > p2.tam);
}

int main()
{
	int cases;
	scanf("%d", &cases);
	while(cases--){
		int noel, bru;
		scanf("%d %d", &noel, &bru);
		Present *p = (Present *) malloc(sizeof(Present) * noel);
		for(int i = 0; i < noel; i++){
			int id, x, y, z;
			scanf("%d %d %d %d", &id, &x, &y, &z);
			p[i] = Present(id, x, y, z);
		}

		sort(p, p + noel, compareId);
		stable_sort(p, p + noel, comparePeso);

		Present *bruno = (Present *) malloc(sizeof(Present) * bru);
		for(int i = 0; i < bru; i++){
			bruno[i] = Present(p[i].id, p[i].x, p[i].y, p[i].z);
		}
		sort(bruno, bruno + bru, compareId);
		bool espaco = true;
		for(int i = 0; i < bru; i++){
			if(espaco){
				printf("%d", bruno[i].id);
				espaco = false;
			}
			else{
				printf(" %d", bruno[i].id);
			}
		}
		printf("\n");
	}
}