#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)

const ll MAXN = 400;
const ll INF = 1e9;

ll dp[MAXN + 1][MAXN + 1];

int main(){
	freopen("snakes.in", "r", stdin);
	freopen("snakes.out", "w", stdout);
	ll n, k; cin >> n >> k;
	vl pre(n + 1), a(n);
	forn(i, n) cin >> a[i];
	forn(i, n) pre[i + 1] = pre[i] + a[i]; 
	forn(i, n + 1) forn(j, k + 1) dp[i][j] = INF; 
	ll curMax = 0;
	for(ll i = 1; i <= n; i++){
		curMax = max(curMax, a[i - 1]);
		dp[i][0] = curMax * i - pre[i];
	}
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= k; j++){
			if(i <= j){
				continue;
			}
			curMax = a[i - 1];
			for(ll l = i - 1; l >= 0; l--){
				dp[i][j] = min(dp[i][j], dp[l][j - 1] + (i - l) * curMax - (pre[i] - pre[l]));
				if(l > 0) curMax = max(curMax, a[l - 1]);
			}
		}
	}
	cout << dp[n][k] << endl;
}