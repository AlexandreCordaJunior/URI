#include <bits/stdc++.h>

using namespace std;

int main()
{
	int c;
	scanf("%d", &c);
	while(c--){
		int num;
		scanf("%d", &num);
		while(num--){
			int op;
			scanf("%d", &op);
			switch(op){
				case 1:
				printf("Rolien\n");
				break;
				case 2:
				printf("Naej\n");
				break;
				case 3:
				printf("Elehcim\n");
				break;
				case 4:
				printf("Odranoel\n");
				break;
			}
		}
	}
}