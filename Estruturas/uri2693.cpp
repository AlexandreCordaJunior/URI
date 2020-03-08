#include <bits/stdc++.h>
#define db(x) cout << x << endl
#define fs first
#define sd second

using namespace std;

typedef pair<string, pair<char, int>> rota;

bool comp(rota r1, rota r2){
	if(r1.sd.sd < r2.sd.sd){
		return true;
	}
	if(r1.sd.sd > r2.sd.sd){
		return false;
	}
	if(r1.sd.fs < r2.sd.fs){
		return true;
	}
	if(r1.sd.fs > r2.sd.fs){
		return false;
	}
	if(r1.fs < r2.fs){
		return true;
	}
	else{
		return false;
	}
}

int main()
{
	int num;
	while(scanf("%d", &num) != EOF){
		getchar();
		rota *vet = new rota[num];

		for(int i = 0; i < num; i++){
			string str, str1, str2;
			getline(cin, str);

			if(str.compare("\0") == 0){
				i--;
				continue;
			}

			if(str.find('\0') != -1){
				str = str.substr(str.find('\n') + 1, str.size());
			}

			str1 = str.substr(0, str.find(' '));
			str = str.substr(str.find(' ') + 1, str.size());

			str2 = str.substr(0, str.find(' '));
			str = str.substr(str.find(' ') + 1, str.size());
			char zona = str2[0];
			int num = stoi(str);

			vet[i] = {str1, {zona, num}};
		}
		sort(vet, vet + num, comp);
		for(int i = 0; i < num; i++){
			cout << vet[i].first << endl;
		}
	}
}