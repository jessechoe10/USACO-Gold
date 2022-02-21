#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define pb push_back
#define f first
#define s second

const ll MAXK = 50;
const ll INF = 1e9;

vl cows[MAXK], adj[MAXK];

int main(){
	ll n, k; cin >> n >> k; 
	vl b(n);
	forn(i, n) cin >> b[i], --b[i], cows[b[i]].pb(i); 
	forn(i, k){
		string s; cin >> s;
		forn(j, k){
			if(s[j] == '1'){
				for(ll cow: cows[j]){
					adj[i].pb(cow);
				}
			}
		}
	}
	priority_queue<pl, vpl, greater<pl>> pq;
	pq.push({0, 0});
	vl dist(n, INF); dist[0] = 0;
	while(!pq.empty()){
		pl cur = pq.top(); pq.pop();
		cout << cur.f << " " << cur.s << endl;
		for(ll u: adj[b[cur.s]]){
			if(cur.f + abs(cur.s - u) < dist[u]){
				dist[u] = cur.f + abs(cur.s - u);
				pq.push({dist[u], u});
			}
		}
	}
	if(dist[n - 1] == INF){
		cout << -1 << endl;
		return 0;
	}
	cout << dist[n - 1] << endl;
}