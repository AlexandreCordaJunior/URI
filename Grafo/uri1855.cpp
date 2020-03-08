#include <bits/stdc++.h>
#define db(x) cout << x << endl

using namespace std;

int main(){
    int x, y;
    scanf("%d\n%d", &y, &x);
    char mat[101][101];
    int visited[101][101];
    for(int i = 0; i < x; i++){
        getchar();
        for(int j = 0; j < y; j++){
            scanf("%c", &mat[i][j]);
            visited[i][j] = 0;
        }
    }
    
    stack<pair<int, int>> s;
    visited[0][0] = 1;
    s.push({0, 0});
    bool bau = false;

    while(!s.empty()){
        pair<int, int> u = s.top(); s.pop();

        if(mat[u.first][u.second] == '>'){
            for(int j = u.second; j < y; j++){
                if(mat[u.first][j] == '*'){
                    bau = true;
                    break;
                }
                if(mat[u.first][j] == '>' or mat[u.first][j] == '^' or
                    mat[u.first][j] == '<' or mat[u.first][j] == 'v'){
                    if(visited[u.first][j] == 0){
                        s.push({u.first, j});
                    }
                }
                visited[u.first][j] = 1;
            }
        }
        else if(mat[u.first][u.second] == 'v'){
            for(int i = u.first; i < x; i++){
                if(mat[i][u.second] == '*'){
                    bau = true;
                    break;
                }
                if(mat[i][u.second] == '>' or mat[i][u.second] == '^' or
                    mat[i][u.second] == '<' or mat[i][u.second] == 'v'){
                    if(visited[i][u.second] == 0){
                        s.push({i, u.second});
                    }
                }
                visited[i][u.second] = 1;
            }
        }
        else if(mat[u.first][u.second] == '<'){
            for(int j = u.second - 1; j >= 0; j--){
                if(mat[u.first][j] == '*'){
                    bau = true;
                    break;
                }
                if(mat[u.first][j] == '>' or mat[u.first][j] == '^' or
                    mat[u.first][j] == '<' or mat[u.first][j] == 'v'){
                    if(visited[u.first][j] == 0){
                        s.push({u.first, j});
                    }
                }
                visited[u.first][j] = 1;
            }
        }
        else if(mat[u.first][u.second] == '^'){
            for(int i = u.first - 1; i >= 0; i--){
                if(mat[i][u.second] == '*'){
                    bau = true;
                    break;
                }
                if(mat[i][u.second] == '>' or mat[i][u.second] == '^' or
                    mat[i][u.second] == '<' or mat[i][u.second] == 'v'){
                    if(visited[i][u.second] == 0){
                        s.push({i, u.second});
                    }
                }
                visited[i][u.second] = 1;
            }
        }
    }
    printf("%c\n", bau ? '*' : '!');
}