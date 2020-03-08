#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	scanf("%d", &num);

	vector<string> comp;
	vector<string> naoComp;

	getchar();
	for(int i = 0; i < num; i++){
		string str;
		getline(cin, str);

		string str1 = str.substr(0, str.find(' '));
		str = str.substr(str.find(' ') + 1, str.size());

		if(str1.compare("+") == 0){
			comp.push_back(str);
		}
		if(str1.compare("-") == 0){
			naoComp.push_back(str);	
		}
		cout << str1 << endl;
	}
	sort(comp.begin(), comp.end());
	sort(naoComp.begin(), naoComp.end());
	for(auto i: comp){
		cout << i << endl;
	}
	for(auto i: naoComp){
		cout << i << endl;
	}
	printf("Se comportaram: %d | Nao se comportaram: %d\n", (int)comp.size(), (int)naoComp.size());
}
