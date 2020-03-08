#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	while(scanf("%d", &n) != EOF){
		int h, c, l;
		scanf("%d %d %d", &h, &c, &l);

		double area = n * (hypot(h, c) * l);
		printf("%.4lf\n", area / 10000.0);
	}
}