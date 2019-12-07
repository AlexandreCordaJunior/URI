#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num;
    while(1){
        scanf("%d", &num);
        if(num == 0) break;
        int maria, joao;
        maria = joao = 0;
        while(num--){
            int temp;
            scanf("%d", &temp);
            if(temp == 0) maria++;
            else joao++;
        }
        printf("Mary won %d times and John won %d times\n", maria, joao);
    }
}
