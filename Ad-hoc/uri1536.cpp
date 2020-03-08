#include <bits/stdc++.h>

using namespace std;

int main()
{
	int casos;
	scanf("%d", &casos);
	while(casos--){
		int p1, p2, gol1, gol2;
		p1 = p2 = gol1 = gol2 = 0;

		int res11, res12;
		scanf("%d x %d", &res11, &res12);

		if(res11 > res12){
			p1 += 3;
		}
		else{
			if(res11 < res12){
				p2 += 3;
			}
			else{
				p1 += 1;
				p2 += 1;
			}
		}
		gol1 += res11;
		gol2 += res12;

		int res21, res22;
		scanf("%d x %d", &res22, &res21);

		if(res21 > res22){
			p1 += 3;
		}
		else{
			if(res21 < res22){
				p2 += 3;
			}
			else{
				p1 += 1;
				p2 += 1;
			}
		}
		gol1 += res21;
		gol2 += res22;

		if(p1 > p2){
			printf("Time 1\n");
		}
		else{
			if(p1 < p2){
				printf("Time 2\n");
			}
			else{
				if(gol1 > gol2){
					printf("Time 1\n");
				}
				else{
					if(gol1 < gol2){
						printf("Time 2\n");
					}
					else{
						if(res12 > res21){
							printf("Time 2\n");
						}
						else{
							if(res12 < res21){
								printf("Time 1\n");
							}
							else{
								printf("Penaltis\n");
							}
						}
					}
				}
			}
		}
	}
}