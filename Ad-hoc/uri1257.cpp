#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    while(n--){
        int linhas, cont;
        cont = 0;
        scanf("%d", &linhas);
        for(int i = 0; i < linhas; i++){
            getchar();
            char str[51];
            scanf("%s", str);
            for(int j = 0; j < strlen(str); j++){
                cont += (str[j] - 'A') + i + j;
            }
        }
        printf("%d\n", cont);
    }
}
