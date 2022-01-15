#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define pb push_back

const ll MAXN = 1000, MAXT = 1000, INF = 1e9;

ll dp[MAXN + 1][MAXT + 1]; vl roads[MAXN];

int main(){
	freopen("time.in", "r", stdin);
	freopen("time.out", "w", stdout);
	ll n, m, c; cin >> n >> m >> c;
	vl moonies(n); forn(i, n) cin >> moonies[i];
	forn(i, m){
		ll a, b; cin >> a >> b; 
		--a, --b; roads[b].pb(a);
	}
	forn(i, n) forn(j, MAXT + 1) dp[i][j] = -INF;
	dp[0][0] = 0; ll ans = 0;
	for(ll i = 1; i < MAXT; i++){
		forn(j, n){
			if(dp[i - 1][j] != -INF){
				for(ll u: roads[j]){
					dp[i][u] = max(dp[i][u], dp[i - 1][j] + moonies[u]);
				}
			}
		}
		ans = max(ans, dp[i][0] - (c * i * i));
	}
	cout << ans << endl;
}