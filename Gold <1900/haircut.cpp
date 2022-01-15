#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define rofn(i, n) for(ll i = n - 1; i >= 0; i--)

const ll MAXN = 1e5 + 2;

struct BIT {
	ll n, bit[MAXN];
	void init(){
		forn(i, n + 1) bit[i] = 0;
	}
	ll sum(ll k){
		ll res = 0;
		for(; k > 0; k-=k&(-k)) res += bit[k];
		return res;
	}
	void upd(ll k, ll x){
		for(; k <= n; k+=k&(-k)) bit[k] += x;
	}
};

int main(){
	freopen("haircut.in", "r", stdin);
	freopen("haircut.out", "w", stdout);
	ll n; cin >> n;
	vl a(n); forn(i, n) cin >> a[i];
	BIT bit; bit.n = n; bit.init();
	vl res(n);
	forn(i, n){
		if(a[i] > 0) bit.upd(a[i], 1);
		if(a[i] < n) res[a[i]] += bit.sum(n) - bit.sum(a[i]);
	}
	vl dp(n);
	forn(i, n - 1){
		dp[i + 1] = dp[i] + res[i];
	}
	forn(i, n){
		cout << dp[i] << endl;
	}
}