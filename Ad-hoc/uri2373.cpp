#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	scanf("%d", &num);

	int cont = 0;
	for(int i = 0; i < num; i++){
		int latas, copos;
		scanf("%d %d", &latas, &copos);

		if(latas > copos){
			cont += copos;
		}
	}
	printf("%d\n", cont);
}