#include <bits/stdc++.h>

using namespace std;

int maxCrossing(int *vet, int start, int median, int finish){
	int sum = 0;
	int left = -999999;
	for(int i = median; i >= start; i--){
		sum += vet[i];
		if(sum > left){
			left = sum;
		}
	}

	sum = 0;
	int right = -999999;
	for(int i = median + 1; i <= finish; i++){
		sum += vet[i];
		if(sum > right){
			right = sum;
		}
	}
	return left + right;
}

int max(int a, int b){
	return a > b ? a : b;
}

int max(int a, int b, int c){
	return max(max(a, b), c);
}

int maxSum(int start, int finish, int *vet){
	if(start == finish){
		return vet[start];
	}
	int median = (start + finish) / 2;
	return max(maxSum(start, median, vet), maxSum(median + 1, finish, vet),
		maxCrossing(vet, start, median, finish));
}

int main()
{
	int num;
	while(scanf("%d", &num) != EOF){
		int diaria;
		scanf("%d", &diaria);
		int *receita = new int[num];
		for(int i = 0; i < num; i++){
			scanf("%d", &receita[i]);
		}
		for(int i = 0; i < num; i++){
			receita[i] = receita[i] - diaria;
			//printf("%d\n", receita[i]);
		}
		int numero = maxSum(0, num - 1, receita);
		printf("%d\n", numero >= 0 ? numero : 0);
	}
}