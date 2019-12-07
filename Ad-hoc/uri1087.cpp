#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x1, y1, x2, y2;
    while(1){
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        if(x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0) break;
        if(x1 != x2 && y1 != y2 && (x1 + y1 == x2 + y2 || x1 - y1 == x2 - y2)){
            printf("1\n");
        }
        else{
            int cont = 0;
            if(x1 == x2){
                cont++;
            }
            if(y1 == y2){
                cont ++;
            }
            printf("%d\n", 2 - cont);
        }
    }
}
