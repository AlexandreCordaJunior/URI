#include <bits/stdc++.h>

using namespace std;

bool compare(string s1, string s2){
	return s1.size() > s2.size();
}

int main()
{
	int casos;
	scanf("%d", &casos);
	getchar();
	while(casos--){
		string s;
		getline(cin, s);
		int espacos = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == ' ') espacos++;
		}
		espacos++;

		vector<string> vet;
		string str1, str2;
		str2 = s;
		for(int i = 0; i < espacos; i++){
			str1 = str2.substr(0, str2.find(' '));
			str2 = str2.substr(str2.find(' ') + 1, str2.size());

			vet.push_back(str1);
		}

		stable_sort(vet.begin(), vet.end(), compare);
		for(auto i = vet.begin(); i != vet.end(); i++){
			if(i == vet.begin()){
				cout << *i;
			}
			else{
				cout << " " << *i;
			}
		}
		printf("\n");
	}
}