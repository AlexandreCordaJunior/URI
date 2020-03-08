#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	scanf("%d", &num);

	vector<string> total;
	int comp, naoComp;
	comp = naoComp = 0;

	getchar();
	for(int i = 0; i < num; i++){
		string str;
		getline(cin, str);

		string str1 = str.substr(0, str.find(' '));
		str = str.substr(str.find(' ') + 1, str.size());

		if(str1.compare("+") == 0){
			comp++;
		}
		if(str1.compare("-") == 0){
			naoComp++;
		}
		total.push_back(str);
	}
	sort(total.begin(), total.end());
	for(auto i: total){
		cout << i << endl;
	}
	printf("Se comportaram: %d | Nao se comportaram: %d\n", comp, naoComp);
}
