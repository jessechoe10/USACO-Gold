#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define pb push_back

const ll MAXN = 1e5;

vl adj[MAXN], subtree[MAXN];
ll dp[MAXN], n;

void dfs(ll cur, ll par){
	dp[cur] = 1;
	for(ll u: adj[cur]){
		if(u != par){
			dfs(u, cur);
			dp[cur] += dp[u];
			subtree[cur].pb(dp[u]);
		}
	}
	if(dp[cur] != n) subtree[cur].pb(n - dp[cur]); 
}

bool works(ll k){
	if((n - 1) % k == 0){
		vl freq(k);
		forn(i, k) freq[i] = 0;
		forn(i, n){
			ll unpaired = 0;
			for(ll u: subtree[i]){
				if(u % k == 0) continue;
				if(freq[k - (u % k)]) freq[k - (u % k)]--, unpaired--;
				else freq[u % k]++, unpaired++;
			}
			if(unpaired) return 0;
		}
		return 1;
	}
	return 0;
}

int main(){
	freopen("deleg.in", "r", stdin);
	freopen("deleg.out", "w", stdout);
	cin >> n;
	forn(i, n - 1){
		ll a, b; cin >> a >> b;
		--a, --b;
		adj[a].pb(b), adj[b].pb(a);
	}
	dfs(0, -1);
	forn(i, n - 1){
		cout << works(i + 1);
	}
	cout << endl;
}