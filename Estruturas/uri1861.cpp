#include <bits/stdc++.h>

using namespace std;

int main()
{
	string str;

	vector<pair<string, string>> assassinatos;
	unordered_map<string, int> mapa;
	unordered_map<string, bool> morto;
	vector<string> vet;

	while(getline(cin, str)){
		string str1, str2;
		str1 = str.substr(0, str.find(' '));
		str2 = str.substr(str.find(' ') + 1, str.size());
		assassinatos.push_back({str1, str2});
		mapa[str1]++;
		morto[str2] = true;
	}
	
	unordered_map<string, bool> ja;

	for(auto i: assassinatos){
		if(morto[i.first] == false){
			if(ja[i.first] == false){
				vet.push_back(i.first);
				ja[i.first] = true;
			}
		}
	}
	sort(vet.begin(), vet.end());
	cout << "HALL OF MURDERERS" << endl;
	for(auto i: vet){
		cout << i << " " << mapa[i] << endl;
	}
}