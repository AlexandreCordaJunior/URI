#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll fat[11];
int dp[100002];

void init(){
	fat[0] = 1;
	for(int i = 1; i < 11; i++){
		fat[i] = i * fat[i - 1];
	}
	for(int i = 0; i < 100002; i++){
		dp[i] = -1;
	}
}

int minimo(int num){
	if(num == 0) return 0;
	if(num < 0) return INT_MAX >> 1;
	if(dp[num] != -1){
		return dp[num];
	}

	int esc = INT_MAX >> 1;
	for(int i = 0; i < 11; i++){
		int res = minimo(num - fat[i]) + 1;
		esc = min(res, esc);
	}
	dp[num] = esc;
	return esc;
}

int main()
{
	init();
	int num;
	scanf("%d", &num);

	int res = minimo(num);
	printf("%d\n", res);
}