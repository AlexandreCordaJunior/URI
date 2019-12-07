#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[5001];

void init(){
	for(int i = 0; i < 5001; i++){
		dp[i] = 0;
	}
}

ll knapSack(int stacks, int blocks){
	if(blocks == 0){
		dp[stacks] += 1;
	}
	else{
		if(stacks == 0){
			return 0;
		}
		dp[stacks] += max(
			knapSack(stacks - 1, blocks),
			knapSack(stacks - 1, blocks - 1) + 1
		);
	}
	return dp[stacks];
}

int main()
{
	int stacks, blocks;
	scanf("%d %d", &stacks, &blocks);
	init();
	printf("%lld\n", knapSack(stacks, blocks - stacks) % 1000000007);
	printf("\n");
	for(int i = 0; i < 5001; i++){
		printf("%lld\n", dp[i]);
	}
}