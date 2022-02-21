#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define f first
#define s second

const ll MAXN = 5000;
const ll MOD = 1e9 + 7;

ll dp[MAXN + 1][MAXN + 1], res[26][MAXN];

ll binpow(ll a, ll b){
	a %= MOD;
	ll res = 1;
	while(b > 0){
		if(b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int main(){
	freopen("poetry.in", "r", stdin);
	freopen("poetry.out", "w", stdout);
	ll n, m, k; cin >> n >> m >> k;
	vl s(n), c(n);
	forn(i, n){
		cin >> s[i] >> c[i]; c[i]--;
	}
	vl sum(k + 1, 0); sum[0] = 1;
	for(ll i = 1; i <= k; i++){
		forn(j, c.size()){
			if(i - s[j] >= 0){
				dp[i][c[j]] += sum[i - s[j]];
				dp[i][c[j]] %= MOD;
			}
		}
		forn(j, n){
			sum[i] += dp[i][j];
			sum[i] %= MOD;
		}
	}
	map<ll, ll> freq;
	forn(i, m){
		char e; cin >> e;
		freq[e - 'A']++;
	}
	ll res = 1;
	forn(i, 26){
		if(freq[i] == 0){
			continue;
		}
		ll cur = 0;
		forn(j, n){
			cur += binpow(dp[k][j], freq[i]);
			cur %= MOD;
		}
		res *= cur;
		res %= MOD;
	}
	cout << res << endl;
}
