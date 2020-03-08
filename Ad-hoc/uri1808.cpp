#include <bits/stdc++.h>

using namespace std;

int main()
{
	string str;
	getline(cin, str);

	int cont = 0;
	int total = 0;
	for(int i = 0; i < str.size(); i++){
		if(str[i] == '1' && i != str.size() - 1 && str[i + 1] == '0'){
			total += 10;
			cont++;
			i++;
		}
		else{
			total += str[i] - '0';
			cont++;
		}
	}
	printf("%.2lf\n", total / (double) cont);
}