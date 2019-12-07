#include <bits/stdc++.h>

using namespace std;

bool prim = true;

bool compare(pair<int, int> i1, pair<int, int> i2){
	return i2.second < i1.second;
}

bool compare2(pair<int, int> i1, pair<int, int> i2){
	return i1.first < i2.first;
}

int main()
{
	string str1;
	while(getline(cin, str1)){
		if(!prim){
			printf("\n");
		}
		map<char, int> mapa;
		for(int i = 0; i < 128; i++){
			mapa[i] = 0;
		}
		for(int i = 0; i < str1.size(); i++){
			mapa[str1[i]]++;
		}
		vector<pair<int, int>> vii;
		for(int i = 0; i < 128; i++){
			if(mapa[i] != 0){
				vii.push_back({mapa[i], (int) i});
			}
		}
		sort(vii.begin(), vii.end(), compare);
		stable_sort(vii.begin(), vii.end(), compare2);
		for(auto el : vii){
			printf("%d %d\n", el.second, el.first);
		}
		prim = false;
	}
}