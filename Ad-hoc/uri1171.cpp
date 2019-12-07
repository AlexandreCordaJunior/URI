#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num;
    scanf("%d", &num);
    map<int, int> mapa;
    for(int i = 0; i <= 2000; i++){
        mapa[i] = 0;
    }
    while(num--){
        int temp;
        scanf("%d", &temp);
        mapa[temp]++;
    }
    for(int i = 0; i <= 2000; i++){
        if(mapa[i] != 0){
            printf("%d aparece %d vez(es)\n", i, mapa[i]);
        }
    }
}
