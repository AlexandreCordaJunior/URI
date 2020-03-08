#include <bits/stdc++.h>
#define db(x) cout << x << endl

using namespace std;

int main()
{
	int num;
	while(1){
		scanf("%d", &num);
		if(!num) break;

		int *vet = new int[num];

		for(int i = 0; i < num; i++){
			scanf("%d", &vet[i]);
		}

		int picos = 0;
		if(num == 2){
			printf("2\n");
		}
		else{
			for(int i = 0; i < num; i++){
				//db(vet[(i - 1) < 0 ? num - 1 : (i - 1)] << " " << vet[i] << " " << vet[(i + 1) % num]);
				if(vet[i] > vet[(i - 1) < 0 ? num - 1 : (i - 1)] && vet[(i + 1) % num] < vet[i]){
					picos++;
					//db(i << " " << 1);
				}
				else{
					if(vet[i] < vet[(i - 1) < 0 ? num - 1 : (i - 1)] && vet[(i + 1) % num] > vet[i]){
						picos++;
					//	db(i << " " << 2);
					}
				}
			}
			printf("%d\n", picos);
		}
	}
}