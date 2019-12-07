#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    string matrix[y];
    for(int i = 0; i < y; i++){
        getchar();
        string temp;
        getline(cin, temp);

        matrix[i] = temp;
    }
    int cont = 0;
    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++){
            if(matrix[i][j] == '*') cont = 1;
        }
    }
    if(!cont){
        printf("!\n");
    }
    else{
        bool gratis = true;
        int i = 0;
        int j = 0;
        while(1){
            if((!gratis) && (i == 0) && (j == 0)){
                printf("!\n");
                break;
            }
            gratis = false;
            if(i < 0 or i >= y or j < 0 or j >= x){
                break;
            }
            if(matrix[i][j] == '*'){
                printf("*\n");
                break;
            }
            switch(matrix[i][j]){
                case '>':
                    j++;
                    while(j < x && matrix[i][j] == '.'){
                        //printf("%d %d\n", i, j);
                        j++;

                    }
                    if(j >= x){
                        printf("!\n");
                        break;
                    }
                    break;
                case '<':
                    j--;
                    while(j >= 0 && matrix[i][j] == '.'){
                        //printf("%d %d\n", i, j);
                        j--;
                    }
                    if(j < 0){
                        printf("!\n");
                        break;
                    }
                    break;
                case '^':
                    i--;
                    while(i >= 0 && matrix[i][j] == '.'){
                        //printf("%d %d\n", i, j);
                        i--;
                    }
                    if(i < 0){
                        printf("!\n");
                        break;
                    }
                    break;
                case 'v':
                    i++;
                    while(i < y && matrix[i][j] == '.'){
                        //printf("%d %d\n", i, j);
                        i++;
                    }
                    if(i >= y){
                        printf("!\n");
                        break;
                    }
                    break;
            }
        }
    }
}
