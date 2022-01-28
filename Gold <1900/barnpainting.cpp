#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

#define forn(i, n) for(ll i = 0 ; i < n; i++)
#define pb push_back

const ll MAXN = 1e5, MOD = 1e9 + 7;

vl adj[MAXN]; ll color[MAXN], dp[MAXN][3];

ll dfs(ll cur, ll par, ll curC, ll parC){
	if(curC == parC || (color[cur] >= 0 && curC != color[cur])){
		return 0;
	}
	if(dp[cur][curC] >= 0){
		return dp[cur][curC];
	}
	dp[cur][curC] = 1;
	for(ll u: adj[cur]){
		if(u == par) continue;
		ll res = 0;
		forn(i, 3){
			res += dfs(u, cur, i, curC);
			res %= MOD;
		}
		dp[cur][curC] *= res;
		dp[cur][curC] %= MOD;
	}
	return dp[cur][curC];
}

int main(){
	freopen("barnpainting.in", "r", stdin);
	freopen("barnpainting.out", "w", stdout);
	ll n, k; cin >> n >> k;
	forn(i, n - 1){
		ll x, y; cin >> x >> y;
		--x, --y; 
		adj[x].pb(y), adj[y].pb(x);
	}
	forn(i, n){
		color[i] = -1;
		forn(j, 3){
			dp[i][j] = -1;
		}
	}
	forn(i, k){
		ll b, c; cin >> b >> c; --b, --c;
		color[b] = c;
	}
	ll res = 0;
	forn(i, 3){
		res += dfs(0, -1, i, -1);
	}
	cout << (res % MOD) << endl;
}
