#include <bits/stdc++.h>

using namespace std;

int main()
{
	while(1){
		int num;
		scanf("%d", &num);
		if(num == 0) break;
		deque<int> deq;
		vector<int> desc;
		for(int i = 1; i <= num; i++){
			deq.push_front(i);
		}
		while(deq.size() != 1){
			int topo = deq.back();
			deq.pop_back();
			desc.push_back(topo);
			topo = deq.back();
			deq.pop_back();
			deq.push_front(topo);
		}
		printf("Discarded cards: ");
		for(auto i = desc.begin(); i != desc.end(); i++){
			if(i == desc.begin()){
				printf("%d", *i);
			}
			else{
				printf(", %d", *i);
			}
		}
		printf("\n");
		printf("Remaining card: %d\n", deq.front());
	}
}