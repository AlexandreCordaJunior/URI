#include <bits/stdc++.h>
#define db(x) cout << x << endl

using namespace std;

int main()
{
	int num;
	while(scanf("%d", &num) != EOF){
		vector<int> vet;
		for(int i = 0; i < num; i++){
			int lo, hi;
			scanf("%d %d", &lo, &hi);
			for(int j = lo; j <= hi;j++){
				vet.push_back(j);
			}
		}
		sort(vet.begin(), vet.end());
		int q;
		scanf("%d", &q);

		int lo, hi, mid;
		lo = -1;
		hi = vet.size();
		mid = (lo + hi) / 2;

		int index = -1;

		while(lo != hi && lo != mid && hi != mid){
			if(vet[mid] == q){
				index = mid;
				break;
			}
			else{
				if(vet[mid] < q){
					lo = mid;
					mid = (lo + hi) / 2;
				}
				else{
					hi = mid;
					mid = (lo + hi) / 2;
				}
			}
		}
		if(index == -1){
			printf("%d not found\n", q);
		}
		else{
			while(vet[index] == q){
				index--;
			}
			index++;
			int newLo = index;

			while(vet[index] == q){
				index++;
			}
			index--;

			int newHi = index;
			printf("%d found from %d to %d\n", q, newLo, newHi);
		}
	}
}