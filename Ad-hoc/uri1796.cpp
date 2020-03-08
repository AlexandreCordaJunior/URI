#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	scanf("%d", &num);

	int satisfeitos, insatisfeitos;
	satisfeitos = insatisfeitos = 0;

	for(int i = 0; i < num; i++){
		int temp;
		scanf("%d", &temp);
		if(temp == 0) satisfeitos++;
		else insatisfeitos++;
	}
	printf("%c\n",
		satisfeitos > insatisfeitos ? 'Y' : 'N');
}