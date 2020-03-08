#include <bits/stdc++.h>

using namespace std;

typedef pair<string, pair<int, pair<int, int>>> pais;


//{par, {g, {s, b}}};
bool comp(pais p1, pais p2){
	if(p1.second.first > p2.second.first) return true;
	if(p1.second.first < p2.second.first) return false;

	if(p1.second.second.first > p2.second.second.first) return true;
	if(p1.second.second.first < p2.second.second.first) return false;

	if(p1.second.second.second > p2.second.second.second) return true;
	if(p1.second.second.second < p2.second.second.second) return false;	

	if(p1.first > p2.first) return false;
	if(p1.first < p2.first) return true;	
}

int main()
{
	int num;
	scanf("%d", &num);
	pais *vet = new pais[num];
	getchar();

	for(int i = 0; i < num; i++){
		string str;
		getline(cin, str);

		string par;
		int g, s, b;

		par = str.substr(0, str.find(' '));
		str = str.substr(str.find(' ') + 1, str.size());

		g = stoi(str.substr(0, str.find(' ')));
		str = str.substr(str.find(' ') + 1, str.size());

		s = stoi(str.substr(0, str.find(' ')));
		str = str.substr(str.find(' ') + 1, str.size());

		b = stoi(str.substr(0, str.find(' ')));
		str = str.substr(str.find(' ') + 1, str.size()); 

		vet[i] = {par, {g, {s, b}}};
	}

	sort(vet, vet + num, comp);

	for(int i = 0; i < num; i++){
		cout << vet[i].first << " " << vet[i].second.first << " " << vet[i].second.second.first << " " << vet[i].second.second.second << endl;
	}
}