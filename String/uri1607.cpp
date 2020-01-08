#include <bits/stdc++.h>
#define db(x) cout << x << endl

using namespace std;

int main()
{
	int num;
	scanf("%d", &num);
	getchar();
	while(num--){
		int cont = 0;
		string total, str1, str2;
		getline(cin, total);
		str1 = total.substr(0, total.find(' '));
		str2 = total.substr(total.find(' ') + 1, total.size());

		for(int i = 0; i < str1.size(); i++){
			if(str1[i] <= str2[i]){
				cont += (str2[i] - str1[i]);
			}
			else{
				cont += (26 - (str1[i] - str2[i]));
			}
		}
		printf("%d\n", cont);
	}
}