#include <bits/stdc++.h>
#define db(x) cout << x << endl

using namespace std;

int main()
{
	string str;
	while (getline(cin, str)){
		long long temp = 0;
		bool error = false;

		int qtdNum = 0;
		if(str.compare("\0") == 0){
			error = true;
		}
		else{
			for(int i = 0; i < str.size(); i++){
				if(temp > INT_MAX){
					error = true;
				}
				if(str[i] == 'o' or str[i] == 'O'){
					temp = temp * 10;
					qtdNum++;
				}
				else{
					if(isdigit(str[i])){
						temp = (temp * 10) + (str[i] - '0');
						qtdNum++;
					}
					else{
						if(str[i] == 'l'){
							temp = (temp * 10) + 1;
							qtdNum++;
						}
						else{
							if(str[i] != ',' && str[i] != ' '){
								error = true;
								break;
							}
						}
					}
				}
			}
		}
		if(temp > INT_MAX or qtdNum == 0) error = true;
		
	
		if(error){
			printf("error\n");
		}
		else{
			printf("%lld\n", temp);
		}
	}
}