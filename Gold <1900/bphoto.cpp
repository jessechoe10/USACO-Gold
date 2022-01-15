#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define rofn(i, n) for(ll i = n - 1; i >= 0; i--)
#define f first
#define s second
#define sor(x) sort(begin(x), end(x))

const ll MAXN = 1e5 + 1;

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
	freopen("bphoto.in", "r", stdin);
	freopen("bphoto.out", "w", stdout);
	ll n; cin >> n;
	map<ll, ll> mp;
	vl h(n); forn(i, n) cin >> h[i], mp[h[i]] = 0;
	ll cur = 1; vl height(n);
	for(pl a: mp){
		mp[a.f] = cur; ++cur;
	}
	forn(i, n) height[i] = mp[h[i]];
	BIT bit1, bit2; bit1.n = n, bit2.n = n; 
	bit1.init(), bit2.init(); vl l(n), r(n);
	forn(i, n){
		l[i] = bit1.sum(n) - bit1.sum(height[i]);
		bit1.upd(height[i], 1);
	}
	rofn(i, n){
		r[i] = bit2.sum(n) - bit2.sum(height[i]);
		bit2.upd(height[i], 1);
	}
	ll res = 0;
	forn(i, n){
		if(l[i] > r[i]){
			swap(l[i], r[i]);
		}
		if(r[i] > 2 * l[i]){
			++res;
		}
	}
	cout << res << endl;
}