#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define forn(i, n) for(ll i = 0; i < n; i++)

const ll MAXN = 2e5 + 1;

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
