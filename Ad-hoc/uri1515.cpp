#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	while(scanf("%d", &num) && num){
		getchar();

		string str;
		int min = INT_MAX >> 1;
		string planeta = "";
		for(int i = 0; i < num; i++){
			getline(cin, str);
			string str1 = str.substr(0, str.find(' '));
			str = str.substr(str.find(' ') + 1, str.size());

			int rebebido = stoi(
				str.substr(0, str.find(' '))
			);

			int delay = stoi(
				str.substr(str.find(' ') + 1, str.size())
			);

			if(rebebido - delay < min){
				min = rebebido - delay;
				planeta = str1;
			}
		}
		cout << planeta << endl;
	}
}