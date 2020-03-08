#include <bits/stdc++.h>

using namespace std;

int main()
{
	int l, r, r1, r2;

	while(scanf("%d %d %d %d", &l, &r, &r1, &r2) && l && r && r1 && r2){
		if(r1 > r2){
			int temp = r1;
			r1 = r2;
			r2 = temp;
		}

		double cTotal = r1 + r2;
		double h1, h2;
		h1 = r1 / 2.0;
		h2 = r2 / 2.0;
		double h = h2 - h1;

		cTotal += sqrt((cTotal * cTotal) - (h * h));
		printf("%lf %d %d\n", cTotal, l, r);
	}
}