#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)

const ll MAXN = 2e5;

vl bit(MAXN + 1);

struct BIT {
	ll n;
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
	ll n; cin >> n;
	BIT bit; bit.n = n;
	vl b(n), lst(n + 1);
	ll res = 0;
	forn(i, n){
		cin >> b[i];
		if(lst[b[i]] != 0){
			bit.upd(lst[b[i]], -1);
		}
		res += bit.sum(i + 1) - bit.sum(lst[b[i]]);
		lst[b[i]] = i + 1;
		bit.upd(i + 1, 1);
	}
	cout << res << endl;
}