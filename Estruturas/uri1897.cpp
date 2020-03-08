#include <bits/stdc++.h>
#define db(x) cout << x << endl

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

int main()
{
	ll n, m;
	scanf("%lld %lld", &n, &m);

	priority_queue<ii, vector<ii> ,greater<ii>> q;
	q.push({0, n});

	ll res = 0;

	map<ll, ll> mapa;

	while(!q.empty()){
		ii u = q.top(); q.pop();

		if(u.second == m){
			res = u.first;
			break;
		}

		mapa[u.second] = u.first;

		if(mapa[u.second * 2] == 0 && u.second * 2 < INT_MAX){
			q.push({u.first + 1, u.second * 2});
		}
		if(mapa[u.second * 3] == 0 && u.second * 3 < INT_MAX){
			q.push({u.first + 1, u.second * 3});
		}
		if(mapa[u.second / 2] == 0){
			q.push({u.first + 1, u.second / 2});
		}
		if(mapa[u.second / 3] == 0){
			q.push({u.first + 1, u.second / 3});
		}
		if(mapa[u.second + 7] == 0){
			q.push({u.first + 1, u.second + 7});
		}
		if(mapa[u.second - 7] == 0){
			q.push({u.first + 1, u.second - 7});
		}
	}

	printf("%lld\n", res);
}