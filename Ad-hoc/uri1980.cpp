#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll fat[16];

void init()
{
	fat[0] = 1;
	for(int i = 1; i < 16; i++){
		fat[i] = i * fat[i - 1];
	}
}

int main()
{
	init();
	string str;
	while(cin >> str){
		if(str == "0"){
			break;
		}

		printf("%lld\n", fat[str.size()]);
	}
	
}
