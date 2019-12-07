#include <bits/stdc++.h>

using namespace std;

struct letter{

};

int main()
{
	int d, p;
	while(1){
		scanf("%d %d", &d, &p);
		if(d == 0 && p == 0) break;

		pair<char, int> *ci = new pair<char, int>[d];
		char *str = new char[d + 1];
		getchar();
		for(int i = 0; i < d; i++){
			char temp;
			scanf("%c", &temp);
			ci[i] = {temp, i};
			str[i] = temp;
		}
		str[d] = '\0';
		stable_sort(ci, ci + d);
		bool *vet = new bool[d];
		for(int i = 0; i < d; i++){
			vet[i] = true;
		}
		for(int i = 0; i < p; i++){
			vet[ci[i].second] = false;
		}
		for(int i = 0; i < d; i++){
			if(vet[i]) printf("%c", str[i]);
		}
		printf("\n");
	}
}