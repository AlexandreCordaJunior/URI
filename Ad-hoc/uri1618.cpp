#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	scanf("%d", &num);
	while(num--){
		int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy, Rx, Ry;
		scanf("%d %d %d %d %d %d %d %d %d %d", &Ax, &Ay, &Bx, &By, &Cx, &Cy, &Dx, &Dy, &Rx, &Ry);

		bool in = true;
		
		if(Ax < Cx && Cx < Rx) in = false;
		if(Cx < Ax && Ax < Rx) in = false;
		if(Rx < Ax && Ax < Cx) in = false;
		if(Rx < Cx && Cx < Ax) in = false;
	

	
		if(Ay < Cy && Cy < Ry) in = false;
		if(Cy < Ay && Ay < Ry) in = false;
		if(Ry < Ay && Ay < Cy) in = false;
		if(Ry < Cy && Cy < Ay) in = false;
	
		printf("%d\n", in);
	}
}