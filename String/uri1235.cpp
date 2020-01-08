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
		int mid = str.size() / 2;
		for(int i = mid - 1; i >= 0; i--){
			printf("%c", str[i]);
		}
		for(int i = str.size() - 1; i >= mid; i--){
			printf("%c", str[i]);
		}
		printf("\n");
	}
}