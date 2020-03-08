#include <bits/stdc++.h>

using namespace std;

int cont = 1;
map<string, int> indice;

bool comp(string str1, string str2){
	if(str1.size() > str2.size()) return true;
	if(str1.size() < str2.size()) return false;
	if(indice[str1] < indice[str2]) return true;
	if(indice[str1] > indice[str2]) return false;
}

int main()
{
	map<string, bool> jaVotou;
	vector<string> sim;
	vector<string> nao;

	string str;
	while(getline(cin, str)){

		if(str.compare("FIM") == 0) break;

		string str1, str2;
		str1 = str.substr(0, str.find(' '));
		str2 = str.substr(str.find(' ') + 1, str.size());

		if(jaVotou[str1] == false){
			jaVotou[str1] = true;
			indice[str1] = cont++;

			if(str2.compare("YES") == 0){
				sim.push_back(str1);
			}
			else{
				nao.push_back(str1);
			}
		}
	}
	sort(sim.begin(), sim.end());
	sort(nao.begin(), nao.end());
	for(auto i: sim){
		cout << i << endl;
	}
	for(auto i: nao){
		cout << i << endl;
	}
	cout << endl;
	cout << "Amigo do Habay:" << endl;
	sort(sim.begin(), sim.end(), comp);

	cout << sim[0] << endl;
}