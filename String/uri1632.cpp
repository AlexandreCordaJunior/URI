#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	scanf("%d", &num);
	getchar();
	while(num--){
		string str;
		getline(cin, str);

		int max = 1;
		for(int i = 0; i < str.size(); i++){
			if(tolower(str[i]) == 'a' or tolower(str[i]) == 'e' or
				tolower(str[i]) == 'i' or tolower(str[i]) == 'o' or 
				tolower(str[i]) == 's'){
				max *= 3;
			}
			else{
				max *= 2;
			}
		}
		printf("%d\n", max);
	}
}