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
	freopen("sleepy.in", "r", stdin);
	freopen("sleepy.out", "w", stdout);
	ll n; cin >> n; vl p(n);
	forn(i, n) cin >> p[i];
	ll k = n - 1;
	for(ll i = n - 1; i >= 0; i--){
		if(i == 0){
			k = 0;
			break;
		} else {
			if(p[i - 1] > p[i]){
				k = i;
				break;
			}
		}
	}
	BIT bit; bit.n = n; bit.init();
	for(ll i = k; i < n; i++){
		bit.upd(p[i], 1);
	}
	cout << k << endl;
	forn(i, k){
		cout << k - i - 1 + bit.sum(p[i]);
		if(i < k - 1) cout << " ";
		bit.upd(p[i], 1);
	}
	cout << endl;
}