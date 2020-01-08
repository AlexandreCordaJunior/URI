#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	scanf("%d", &num);
	getchar();
	map<string, int> mapa;
	mapa["tesoura"] = 1;
	mapa["papel"] = 2;
	mapa["pedra"] = 3;
	mapa["lagarto"] = 4;
	mapa["spock"] = 5;

	while(num--){
		string total, str1, str2;
		int v1, v2;
		getline(cin, total);
		str1 = total.substr(0, total.find(' '));
		str2 = total.substr(total.find(' ') + 1, total.size());
		v1 = mapa[str1];
		v2 = mapa[str2];
		switch(v1){
			case 1:
			switch(v2){
				case 1:
				printf("empate");
				break;
				case 2:
				printf("rajesh");
				break;
				case 3:
				printf("sheldon");
				break;
				case 4:
				printf("rajesh");
				break;
				case 5:
				printf("sheldon");
				break;
			}
			break;

			case 2:
			switch(v2){
				case 1:
				printf("sheldon");
				break;
				case 2:
				printf("empate");
				break;
				case 3:
				printf("rajesh");
				break;
				case 4:
				printf("sheldon");
				break;
				case 5:
				printf("rajesh");
				break;
			}
			break;

			case 3:
			switch(v2){
				case 1:
				printf("rajesh");
				break;
				case 2:
				printf("sheldon");
				break;
				case 3:
				printf("empate");
				break;
				case 4:
				printf("rajesh");
				break;
				case 5:
				printf("sheldon");
				break;
			}
			break;

			case 4:
			switch(v2){
				case 1:
				printf("sheldon");
				break;
				case 2:
				printf("rajesh");
				break;
				case 3:
				printf("sheldon");
				break;
				case 4:
				printf("empate");
				break;
				case 5:
				printf("rajesh");
				break;
			}
			break;

			case 5:
			switch(v2){
				case 1:
				printf("rajesh");
				break;
				case 2:
				printf("sheldon");
				break;
				case 3:
				printf("rajesh");
				break;
				case 4:
				printf("sheldon");
				break;
				case 5:
				printf("empate");
				break;
			}
			break;
		}
		printf("\n");
	}
}