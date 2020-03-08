#include <bits/stdc++.h>

using namespace std;

int **dp;

void init(int n, int m){
	dp = (int **) malloc(sizeof(int *) * (n + 1));
	for(int i = 0; i <= n; i++){
		dp[i] = (int *) malloc(sizeof(int) * (m + 1));
		for(int j = 0; j <= m; j++){
			dp[i][j] = -1;
		}
	}
}

bool isSub(string str, int lenStr, int localStr, string temp, int lenTemp, int localTemp){
	if(dp[localStr][localTemp] != -1){
		return dp[localStr][localTemp];
	}
	if(localTemp == lenTemp){
		return true;
	}
	if(localStr == lenStr){
		dp[localStr][localTemp] = 0;
		return false;
	}
	if(str[localStr] == temp[localTemp]){
		bool caminho1 = isSub(str, lenStr, localStr + 1, temp, lenTemp, localTemp + 1);
		bool caminho2 = isSub(str, lenStr, localStr + 1, temp, lenTemp, localTemp);
		dp[localStr][localTemp] = caminho1 or caminho2;
		return dp[localStr][localTemp];
	}
	return isSub(str, lenStr, localStr + 1, temp, lenTemp, localTemp);
}

int main()
{
	int num;
	scanf("%d", &num);
	getchar();
	for(int i = 0; i < num; i++){
		string str;
		getline(cin, str);

		int q;
		scanf("%d", &q);
		getchar();

		for(int j = 0; j < q; j++){
			string temp;
			getline(cin, temp);

			init(str.size(), temp.size());
			bool sub = isSub(str, str.size(), 0, temp, temp.size(), 0);
			printf("%s\n", sub ? "Yes": "No");
		}
	}
}