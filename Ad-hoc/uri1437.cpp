#include <bits/stdc++.h>
#define db(x) cout << x << endl

using namespace std;

int main()
{
	int num;
	while(1){
		scanf("%d", &num);
		if(num == 0) break;
		getchar();

		string str;
		getline(cin, str);
		int l, r;
		l = r = 0;
		for(int i = 0; i < str.size(); i++){
			if(str[i] == 'D'){
				r++;
			}
			else{
				l++;
			}
		}
		int res = (l - r) % 4;
		while(res < 0){
			res += 4;
		}
		switch(res){
			case 0:
			printf("N\n");
			break;
			case 1:
			printf("O\n");
			break;
			case 2:
			printf("S\n");
			break;
			case 3:
			printf("L\n");
			break;
		}
	}
}