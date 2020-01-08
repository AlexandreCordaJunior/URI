#include <bits/stdc++.h>

using namespace std;

int main(){
	string str;
	bool estrela = false;
	bool under = false;

	while(getline(cin, str)){
		for(int i = 0; i < str.size(); i++){
			if(str[i] == '*'){
				if(estrela){
					printf("</b>");
					estrela = false;
				}
				else{
					printf("<b>");
					estrela = true;
				}
			}
			else if(str[i] == '_'){
				if(under){
					printf("</i>");
					under = false;
				}
				else{
					printf("<i>");
					under = true;
				}
			}
			else printf("%c", str[i]);
		}
		printf("\n");
	}
}