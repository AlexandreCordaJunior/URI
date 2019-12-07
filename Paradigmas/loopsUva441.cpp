#include <bits/stdc++.h>

using namespace std;

int main()
{
	int vet[] = {5, 1, 3, 9, 4, 6, 4, 2, 6, 1, 2};
	sort(vet, vet + 11);
	int k = 11;
	for(int a = 0; a < k - 5; a++){
		for(int b = a + 1; b < k - 4; b++){
			for(int c = b + 1; c < k - 3; c++){
				for(int d = c + 1; d < k - 2; d++){
					for(int e = d + 1; e < k - 1; e++){
						for(int f = e + 1; f < k; f++){
							printf("%d %d %d %d %d %d\n", vet[a], vet[b], vet[c], vet[d], vet[e], vet[f]);
						}
					}
				}	
			}
		}
	}
}