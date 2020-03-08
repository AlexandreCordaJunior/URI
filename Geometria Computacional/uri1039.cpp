#include <bits/stdc++.h>
#define db(x) cout << x << endl
#define epsilon 10e-6

using namespace std;

int main()
{
	int r1, x1, y1, r2, x2, y2;

	while(scanf("%d %d %d %d %d %d", &r1, &x1, &y1, &r2, &x2, &y2) != EOF){
		bool dentro = false;

		double dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

		if(r1 > (dist + r2)) dentro = true;

		if(fabs(r1 - (dist + r2)) < epsilon) dentro = true;

		printf("%s\n", dentro ? "RICO": "MORTO");
	}
}