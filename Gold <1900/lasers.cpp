#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;

#define pb push_back
#define forn(i, n) for(ll i = 0; i < n; i++)
#define f first
#define s second

const ll INF = 1e10;

int main(){
	freopen("lasers.in", "r", stdin);
	freopen("lasers.out", "w", stdout);
	ll n; cin >> n; vl x(n + 2), y(n + 2); 
	cin >> x[0] >> y[0] >> x[n + 1] >> y[n + 1];
	map<ll, vl> horizontal, vertical;
	horizontal[x[0]].pb(0), horizontal[x[n + 1]].pb(n + 1);
	vertical[y[0]].pb(0), vertical[y[n + 1]].pb(n + 1);
	for(ll i = 1; i <= n; i++){
		cin >> x[i] >> y[i];
		horizontal[x[i]].pb(i);
		vertical[y[i]].pb(i);
	}
	vl dist(n + 2, INF); dist[0] = 0;
	queue<pl> q; q.push({0, 0}), q.push({0, 1});
	while(!q.empty()){
		pl cur = q.front(); q.pop();
		if(cur.s == 0){ // originally horizontal
			for(ll u: vertical[y[cur.f]]){
				if(dist[cur.f] + 1 < dist[u]){
					dist[u] = dist[cur.f] + 1;
					q.push({u, 1});
				}
			}
		} else { // originally vertical
			for(ll u: horizontal[x[cur.f]]){
				if(dist[cur.f] + 1 < dist[u]){
					dist[u] = dist[cur.f] + 1;
					q.push({u, 0});
				}
			}
		}
	}
	if(dist[n + 1] == INF){
		cout << -1 << endl;
	} else {
		cout << dist[n + 1] - 1 << endl;
	}
}