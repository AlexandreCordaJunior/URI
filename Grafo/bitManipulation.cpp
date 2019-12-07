#include <bits/stdc++.h>

int main()
{
    int s = 42; //101010
    int j = 3;/*Verifica o j-esimo digito*/
    printf("%s\n", (s&(1<<j)) == 0 ? "false": "true");

    j = 1;/*Desativa o j-esimo digito*/
    s &= ~(1 << j);
    printf("%d\n", s);

}
