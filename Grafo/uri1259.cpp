#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num;
    scanf("%d", &num);
    int *vet = new int[num];
    vector<int> par;
    vector<int> impar;
    for(int i = 0; i < num; i++){
        scanf("%d", &vet[i]);
        if(vet[i] % 2 == 0) par.push_back(vet[i]);
        else impar.push_back(vet[i]);
    }
    sort(par.begin(), par.end());
    sort(impar.begin(), impar.end(), greater<int>());
    for(auto p : par){
        printf("%d\n", p);
    }
    for(auto p : impar){
        printf("%d\n", p);
    }
}
