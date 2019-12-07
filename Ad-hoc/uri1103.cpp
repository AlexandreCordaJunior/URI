#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h1, m1, h2, m2;
    while(1){
        scanf("%d %d %d %d", &h1, &m1, &h2, &m2);
        if(h1 == 0 && m2 == 0 && h2 == 0 && m2 == 0) break;
        int totalM1, totalM2;
        totalM1 = (60 * h1) + m1;
        totalM2 = (60 * h2) + m2;
        //printf("%d %d\n", totalM1, totalM2);

        if(totalM2 > totalM1){
            printf("%d\n", totalM2 - totalM1);
        }
        else{
            totalM1 -= (24 * 60);
            printf("%d\n", totalM2 - totalM1);
        }
    }
}
