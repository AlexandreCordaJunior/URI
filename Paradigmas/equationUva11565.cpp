#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	bool sol = false;
	for(int x = -100; x <= 100; x++){
		for(int y = -100; y <= 100; y++){
			for(int z = -100; z <= 100; z++){
				if(x != y && x != z && y != z){
					if(x + y + z == a && x * y * z == b && (x * x) + (y * y) + (z * z) == c){
						if(!sol){
							printf("%d %d %d\n", x, y, z);
							sol = true;
						}
					}
				}
			}
		}
	}
}