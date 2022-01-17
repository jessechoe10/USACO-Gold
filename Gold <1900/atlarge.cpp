#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;

#define pb push_back
#define f first
#define s second

const ll MAXN = 1e5, INF = 1e9;

vl adj[MAXN];

int main(){
	freopen("atlarge.in", "r", stdin);
	freopen("atlarge.out", "w", stdout);
	ll n, k; 
	cin >> n >> k; 
	--k;
	for(int i = 0; i < n - 1; i++){
		ll a, b; 
		cin >> a >> b; 
		--a, --b;
		adj[a].pb(b), adj[b].pb(a);
	}
	/* 
	 * dist1 represents the shortest path from 
	 * Bessie's location to barn i
	 * dist2 represents the shortest path from 
	 * any given farmers' location to barn i
	 */
	vl dist1(n, INF), dist2(n, INF);
	dist1[k] = 0;
	queue<ll> q; 
	q.push(k);
	// BFS to find the shortest path from node k to node i
	while (!q.empty()) {
		ll cur = q.front(); 
		q.pop();
		for (ll u: adj[cur]) {
			if (dist1[cur] + 1 < dist1[u]) {
				dist1[u] = dist1[cur] + 1;
				q.push(u);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (adj[i].size() == 1) {
			q.push(i);
			dist2[i] = 0;
		}
	}
	/* 
	 * BFS to find the shortest distance between node j to node i, 
	 * where j is a leaf node (the farmers' location)
	 */
	while (!q.empty()) {
		ll cur = q.front(); 
		q.pop();
		for (ll u: adj[cur]) {
			if (dist2[cur] + 1 < dist2[u]) {
				dist2[u] = dist2[cur] + 1;
				q.push(u);
			}
		}
	}
	ll res = 0; 
	q.push(k); 
	vl vis(n);
	while (!q.empty()) {
		ll cur = q.front(); 
		q.pop();
		// Stop Bessie if a given farmer arrives at "cur" first
		if (dist2[cur] <= dist1[cur]) {
			res++;
			continue;
		}
		// Used to avoid backtracking
		if (vis[cur]) {
			continue;
		}
		vis[cur] = true;
		for (ll u: adj[cur]) {
			q.push(u);
		}
	}
	cout << res << endl;
}