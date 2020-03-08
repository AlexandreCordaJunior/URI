#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	scanf("%d", &num);

	for(int i = 0; i < num; i++){
		getchar();
		char str[15];
		scanf("%s", str);

		int len = strlen(str);

		sort(str, str + len);

		do{
			for(int i = 0; i < len; i++){
				printf("%c", str[i]);
			}
			printf("\n");
		} while(next_permutation(str, str + len));
		printf("\n");
	}
}