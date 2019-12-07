#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define _ <<", "<<

const int INF = 0x3f3f3f3f;
const int N = 105, A = 11, M = 3 * N * (1 << A);

int n, cnt, mcnt, r[M];
map<string, int> m;
vector<int> a[N];

bitset<1005> val[M];
unordered_map<bitset<1005>, int> ms;

int b[M], x, vis[M], mat[M];
vector<int> g[M];

bool match(int u){
	if(vis[u] == x) return 0;
	vis[u] = x;
	for(int v : g[u]){
		if(!b[v] or match(b[v])){
			b[v] = u;
			mat[u] = 1;
			return 1;
		}
	}
	return 0;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int x;
		char s[15];
		scanf("%d", &x);
		while(x--){
			scanf("%s", s);
			if(!m.count(s)) m[s] = mcnt++;
			a[i].push_back(m[s]);
		}

		for(int j = 1; j < (1 << a[i].size()); j++){
			bitset<1005> xx = 0;
			for(int k = 0; k < a[i].size(); k++){
				xx.set(a[i][k]);
			}
			if(!ms.count(xx)){
				cnt++;
				val[cnt] = xx;
				ms[xx] = cnt;
				r[cnt] = i;
			}
		}
	}

	for(int i = 1; i <= cnt; i++){
		if(val[i].count() > 1){
			for(int j = 0; j < a[r[i]].size(); j++){
				auto xx = val[i];
				int bit = a[r[i]][j];
				if(!xx[bit]) continue;

				xx.reset(bit);

				g[ms[xx]].push_back(i + cnt);
			}
		}
	}

	for(int i = 1; i <= cnt; i++){
		random_shuffle(g[i].begin(), g[i].end());
	}

	int ans = cnt;

	while(1){
		int xx = 0;
		x++;

		for(int i = 1; i <= cnt; i++){
			if(!mat[i]){
				xx += match(i);
			}
		}
		if(xx == 0) break;
		ans -= xx;
	}

	printf("%d\n", ans);
}