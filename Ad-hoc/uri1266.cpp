#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	while(scanf("%d", &num) && num){
		int *vet = new int[num];
		for(int i = 0; i < num; i++){
			scanf("%d", &vet[i]);
		}
		int postes = 0;

		int firstOne = 0;
		while(vet[firstOne] != 1 && firstOne != num){
			firstOne++;
		}
		if(firstOne == num){
			firstOne = 0;
		}

		int *newVet = new int[num];
		int index = 0;
		for(int i = firstOne; i < num; i++){
			newVet[index++] = vet[i];
		}
		for(int i = 0; i < firstOne; i++){
			newVet[index++] = vet[i];
		}

		int last = newVet[0];
		for(int i = 1; i < num; i++){
			int cont = 1;
			if(newVet[i] == last){
				int j = i;
				while(newVet[j] == newVet[i] && j != num){
					j++;
					cont++;
				}
				i = j - 1;
				if(newVet[i] == 0){
					if(i == num - 1 && newVet[0] == 0){
						cont++;
					}
					postes += (cont / 2);
				}
				//cout << cont << " " << i << " " << newVet[i] << endl;
				
			}
			last = newVet[i];
		}
		cout << postes << endl;
	}
}