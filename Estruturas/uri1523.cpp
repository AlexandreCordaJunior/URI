#include <bits/stdc++.h>
#define db(x) cout << x << endl

using namespace std;

typedef pair<int, pair<char, int>> par;

bool comp(par p1, par p2){
	if(p1.first < p2.first){
		return true;
	}
	if(p1.first > p2.first){
		return false;
	}
	if(p1.second.second == p2.second.second){
		return p1.second.first == 'C' ? true : false;
	}
	else{
		return p1.second.first == 'C' ? false : true;
	}
}

int main()
{
	int n, k;
	while(scanf("%d %d", &n, &k) && n && k){
		par *vet = new par[2 * n];

		for(int i = 0; i < n; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			vet[2 * i].first = x;
			vet[2 * i].second.first = 'C';
			vet[2 * i].second.second = i;

			vet[2 * i + 1].first = y;
			vet[2 * i + 1].second.first = 'S';
			vet[2 * i + 1].second.second = i;
		}

		sort(vet, vet + (2 * n), comp);

		/*for(int i = 0; i < 2 * n; i++){
			cout << vet[i].first << " " << vet[i].second.first << " " << vet[i].second.second << endl;
		}*/

		stack<par> s;
		bool error = false;

		for(int i = 0; i < 2 * n; i++){
			if(vet[i].second.first == 'C'){
				if(1 + s.size() > k){
					//db("1");
					error = true;
					break;
				}
				else{
					s.push(vet[i]);
				}
			}
			else{
				if(s.size() == 0 or 1 > k){
					//db("2");
					error = true;
					break;
				}
				else{
					par p = s.top(); s.pop();
					if(p.second.second != vet[i].second.second){
						//db("3");
						//db(p.second.second << " " << vet[i].second.second);
						error = true;
						break;
					}
				}
			}
		}
		printf("%s\n", error ? "Nao" : "Sim");
	}
}