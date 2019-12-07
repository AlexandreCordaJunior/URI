#include <bits/stdc++.h>
#define EPSILON 0.000001;

using namespace std;

bool AreSame(double a, double b)
{
    return fabs(a - b) < EPSILON;
}

int main()
{
    int tiras, area;
    while(1){
        scanf("%d %d", &tiras, &area);
        if(tiras == 0 && area == 0) break;
        int *vet = new int[tiras];
        for(int i = 0; i < tiras; i++){
            int temp;
            scanf("%d", &temp);
            vet[i] = temp;
        }
        sort(vet, vet + tiras);
        int total = 0;
        for(int i = 0; i < tiras; i++){
            total += vet[i];
        }
        if(total < area){
            printf("-.-\n");
        }
        else{
            if(total == area){
                printf(":D\n");
            }
            else{
                double low, high, mid;
                low = 0.0;
                high = (double) vet[tiras - 1];
                while(low >= 0.0  && high <= vet[tiras - 1] && !AreSame(low, high)){
                    mid = (low + high) / 2.0;
                    double cont = 0.0;
                    //printf("%.2f %.2f %.2f\n", low, mid, high);
                    for(int i = 0; i < tiras; i++){
                        cont += vet[i] - mid > 0 ? vet[i] - mid : 0;
                        //printf("%d %.2f\n", i, cont);
                    }
                    //printf("%.2f\n", cont);
                    if(AreSame(cont, area)){
                        printf("%.4f\n", mid);
                        break;
                    }
                    else{
                        if(cont > area){
                            low = mid;
                        }
                        else{
                            high = mid;
                        }
                    }
                }
                if(AreSame(low, high)){
                    printf("%.4f\n", low);
                }
            }
        }
    }
}
