#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define f first
#define s second
#define pb push_back

const ll MOD = 1e9 + 7;

ll binpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1){
			res = res * a;
			res %= MOD;
		}
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

int main(){
	freopen("help.in", "r", stdin);
	freopen("help.out", "w", stdout);
	ll n; cin >> n;
	vl dp(2 * n + 1);
	vpl res(n);
	forn(i, n){
		cin >> res[i].f >> res[i].s;
		dp[res[i].f]++, dp[res[i].s]--;
	}
	for(ll i = 1; i <= 2 * n; i++){
		dp[i] += dp[i - 1];
	}
	ll ans = 0;
	forn(i, n){
		ans += binpow(2, n - 1 - dp[res[i].f - 1]);
		ans %= MOD;
	}
	cout << ans << endl;
}