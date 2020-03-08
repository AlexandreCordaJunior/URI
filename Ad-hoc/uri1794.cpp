#include <bits/stdc++.h>

using namespace std;

int main()
{
	int peso;
	scanf("%d", &peso);

	int la, lb;
	scanf("%d %d", &la, &lb);

	int sa, sb;
	scanf("%d %d", &sa, &sb);

	bool pos = true;
	if(peso < la or peso > lb){
		pos = false;
	}
	if(pos){
		if(peso < sa or peso > sb){
			pos = false;
		}	
	}
	printf("%s\n", pos ? "possivel" : "impossivel");
}