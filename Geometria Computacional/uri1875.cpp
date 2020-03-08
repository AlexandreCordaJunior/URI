#include <bits/stdc++.h>

using namespace std;

int main()
{
	int casos;
	scanf("%d", &casos);

	while(casos--){
		int r, g, b;
		r = g = b = 0;

		int gols;
		scanf("%d", &gols);
		while(gols--){
			getchar();
			char c1, c2;
			scanf("%c %c", &c1, &c2);

			if(c1 == 'R'){
				if(c2 == 'R');
				else if(c2 == 'G'){
					r += 2;
				}
				else{
					r += 1;	
				}
			}
			else if(c1 == 'G'){
				if(c2 == 'R'){
					g += 1;
				}
				else if(c2 == 'G');
				else{
					g += 2;
				}
			}
			else{
				if(c2 == 'R'){
					b += 2;
				}
				else if(c2 == 'G'){
					b += 1;
				}
			}
		}
		int maximo = max(max(r, g), b);

		int cont = 0;
		if(maximo == r) cont++;
		if(maximo == g) cont++;
		if(maximo == b) cont++;

		if(cont == 3){
			printf("trempate\n");
		}
		if(cont == 2){
			printf("empate\n");
		}
		if(cont == 1){
			if(maximo == r){
				printf("red\n");
			}
			else if(maximo == g){
				printf("green\n");
			}
			else{
				printf("blue\n");
			}
		}
	}
}