#include <bits/stdc++.h>

using namespace std;

int main()
{
    int soldados;
    scanf("%d", &soldados);
    int *rainha = new int[soldados];
    int *rivais = new int[soldados];
    for(int i = 0; i < soldados; i++){
        scanf("%d", &rivais[i]);
    }
    for(int i = 0; i < soldados; i++){
        scanf("%d", &rainha[i]);
    }
    sort(rivais, rivais + soldados);
    sort(rainha, rainha + soldados);

    int cont = 0;
    int j = 0;
    for(int i = 0; i < soldados; i++){
        while(j < soldados){
            if(rainha[j++] > rivais[i]){
                cont++;
                break;
            }
        }
    }
    printf("%d\n", cont);
}
