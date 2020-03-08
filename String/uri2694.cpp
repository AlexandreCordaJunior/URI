#include <bits/stdc++.h>

using namespace std;

int main()
{
	int num;
	scanf("%d", &num);
	getchar();

	while(num--){
		int num1, num2, num3;
		string temp;
		getline(cin, temp);

		string str = "";
		for(int i = 0; i < temp.size(); i++){
			if(isdigit(temp[i])){
				str += temp[i];
			}
			else{
				str += ' ';
			}
		}
		num1 = stoi(str);
		string t = to_string(num1);

		str = str.substr(str.find(t) + t.size(), str.size());

		num2 = stoi(str);
		t = to_string(num2);

		str = str.substr(str.find(t) + t.size(), str.size());

		num3 = stoi(str);
		t = to_string(num3);

		str = str.substr(str.find(t) + t.size(), str.size());

		printf("%d\n", num1 + num2 + num3);

	}
}