#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define forn(i, n) for(ll i = 0; i < n; i++)

const ll MAXN = 7500, MOD = 2019201997;

ll dp[MAXN + 1][MAXN + 1];

ll cost(ll x, ll y){
	return (2019201913 * x + 2019201949 * y) % MOD;
}

int main(){
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	ll n, k; cin >> n >> k;
	forn(i, n + 1){
		forn(j, k + 1){
			dp[i][j] = MOD;
		}
	}
	for(ll i = 2; i <= n; i++){
		for(ll j = 2; j <= k; j++){
			if(i >= j){
				dp[i][j] = min(dp[j - 1][j - 1], cost(j - 1, i));
			}
		}
	}
	cout << dp[n][k] << endl;
}