#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)

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
	freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);
	ll n; cin >> n;
	BIT bit; bit.n = 2 * n; bit.init();
	vl lst(n, -1); ll res = 0;
	for(ll i = 1; i <= 2 * n; i++){
		ll id; cin >> id; --id;
		if(lst[id] == -1){
			lst[id] = i;
			bit.upd(i, 1);
		} else {
			res += bit.sum(i) - bit.sum(lst[id] - 1) - 1;
			bit.upd(lst[id], -1);
		}
	}
	cout << res << endl;
}