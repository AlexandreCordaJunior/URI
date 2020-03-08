#include <bits/stdc++.h>

using namespace std;

int main()
{
	int diametro;
	scanf("%d", &diametro);

	int med[3];
	scanf("%d %d %d", &med[0], &med[1], &med[2]);

	bool cabe = true;
	for(int i = 0; i < 3; i++){
		if(med[0] < diametro){
			cabe = false;
			break;
		}
	}

	printf("%c\n", cabe ? 'S' : 'N');
}