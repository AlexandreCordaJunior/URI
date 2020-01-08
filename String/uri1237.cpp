#include <bits/stdc++.h>

using namespace std;

int commonSubstring(string str1, string str2, int len1, int len2){
	int lcs[101][101];
	for(int i = 0; i < 101; i++){
		lcs[0][i] = 0;
		lcs[i][0] = 0;
	}
	for(int i = 1; i <= len1; i++){
		for(int j = 1; j <= len2; j++){
			if(str1[i - 1] == str2[j - 1]){
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else{
				lcs[i][j] = 0;
			}
		}
	}
	int result = 0;
	for(int i = 0; i <= len1; i++){
		for(int j = 0; j <= len2; j++){
			if(result < lcs[i][j]){
				result = lcs[i][j];
			}
		}
	}
	return result;
}

int main()
{
	string str1, str2;
	while(getline(cin, str1) && getline(cin, str2)){
		int res = commonSubstring(str1, str2, str1.size(), str2.size());
		cout << res << endl;
	}
}