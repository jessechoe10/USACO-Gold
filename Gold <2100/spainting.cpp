#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)

const ll MOD = 1e9 + 7;

int main(){
	// freopen("spainting.in", "r", stdin);
	// freopen("spainting.out", "w", stdout);
	ll n, m, k; cin >> n >> m >> k;
	vl s(n), dp1(n), dp2(n); s[0] = m;
	for(ll i = 1; i < k - 1; i++){
		s[i] = (s[i - 1] * m + m) % MOD;
		dp1[i] %= MOD;
	}
	for(ll i = k - 1; i < n; i++){
		forn(j, k){
			dp1[i] += dp1[i - j] * (m - 1);
			dp1[i] %= MOD;
		}
	}
	dp2[k - 1] = m;
	for(ll i = k; i < n; i++){
		dp2[i] += (m * dp2[i - 1]) % MOD;
		dp2[i] %= MOD;
		dp2[i] += ((m - 1) * dp1[i - k]) % MOD;
		dp2[i] %= MOD;
	}
	cout << dp2[n - 1] % MOD << endl;
}