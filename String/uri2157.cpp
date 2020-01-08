#include <bits/stdc++.h>

using namespace std;

void inverso(string str){
	for(int i = str.size() - 1; i >= 0; i--){
		printf("%c", str[i]);
	}
}

int main()
{
	int num;
	scanf("%d", &num);
	while(num--){
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		for(int i = v1; i <= v2; i++){
			printf("%d", i);
		}
		for(int i = v2; i >= v1; i--){
			string str = to_string(i);
			inverso(str);
		}
		printf("\n");
	}
}