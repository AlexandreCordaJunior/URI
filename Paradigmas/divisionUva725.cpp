#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	for(int fghij = 1234; fghij <= 98765 / n; fghij++){
		int abcde = fghij * n;
		int temp, used = (fghij < 10000);
		temp = abcde;
		while(temp){
			//printf("%d\n", 1 << (temp % 10));
			used |= 1 << (temp % 10);
			temp /= 10;
		}
		temp = fghij;
		while(temp){
			used |= 1 << (temp % 10);
			temp /= 10;
		}
		if(used == (1<<10) - 1){
			printf("%0.5d / %0.5d = %d\n", abcde, fghij, n);
		}
	}
}