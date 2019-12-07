#include <bits/stdc++.h>

using namespace std;

int max(int a, int b){
    return a > b ? a : b;
}

int **dp;

int sack(pair<int, int> *vet, int qtd, int tam){
    if(tam == 0 || qtd == 0) return 0;
    if(dp[qtd][tam] != 0) return dp[qtd][tam];
    if(vet[qtd - 1].first > tam) return sack(vet, qtd - 1, tam);
    int maximo = max(
        sack(vet, qtd - 1, tam),
        sack(vet, qtd, tam - vet[qtd - 1].first) + vet[qtd - 1].second
    );
    dp[qtd][tam] = maximo;
    return maximo;
}

int main()
{
    int qtd, tamanho;
    scanf("%d %d", &qtd, &tamanho);
    pair<int, int> *vet = new pair<int, int>[qtd];
    for(int i = 0; i < qtd; i++){
        int t, valor;
        scanf("%d %d", &t, &valor);
        vet[i] = {t, valor};
    }
    dp = (int **) malloc(sizeof(int *) * (qtd + 1));
    for(int i = 0; i <= qtd; i++){
        dp[i] = (int *) malloc(sizeof(int) * (tamanho + 1));
    }
    for(int i = 0; i <= qtd; i++){
        for(int j = 0; j <= tamanho; j++){
            dp[i][j] = 0;
        }
    }
    printf("%d\n", sack(vet, qtd, tamanho));
}
