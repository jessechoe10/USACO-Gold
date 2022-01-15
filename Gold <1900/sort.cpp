#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define forn(i, n) for(ll i = 0; i < n; i++)
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
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	ll n; cin >> n;
	vpl a(n);
	forn(i, n){
		cin >> a[i].f;
		a[i].s = i + 1;
	}
	sor(a);
	BIT bit; bit.n = n;
	bit.init();
	ll res = 1;
	forn(i, n){
		bit.upd(a[i].s, 1);
		res = max(res, i + 1 - bit.sum(i + 1));
	}
	cout << res << endl;
}