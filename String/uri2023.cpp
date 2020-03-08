#include <bits/stdc++.h>

using namespace std;

int main()
{
	string str;
	vector<string> vet;
	map<string, string> mapa;
	while(getline(cin, str)){
		string temp = "";
		for(int i = 0; i < str.size(); i++){
			temp += tolower(str[i]);
		}
		mapa[temp] = str;
		vet.push_back(temp);
	}
	sort(vet.begin(), vet.end());
	cout << mapa[vet[vet.size() - 1]] << endl;
}