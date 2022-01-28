#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;
using vpll = vector<pair<pl, ll>>;

#define pb push_back
#define sor(x) sort(begin(x), end(x))
#define forn(i, n) for(ll i = 0; i < n; i++)
#define f first
#define s second

int main(){
	freopen("snowboots.in", "r", stdin);
	freopen("snowboots.out", "w", stdout);
	ll n, b; cin >> n >> b;
	vpl snow(n);
	forn(i, n){
		cin >> snow[i].f;
		snow[i].s = i + 1;
	}
	sor(snow); vpll boots(b);
	forn(i, b){
		cin >> boots[i].f.f >> boots[i].f.s;
		boots[i].s = i;
	}
	sor(boots); vl res(b); ll r = 0; 
	multiset<ll> ms; ms.insert(snow[r].s);
	forn(i, b){
		while(snow[r + 1].f <= boots[i].f.f){
			r++; ms.insert(snow[r].s);
		}
		ll cur = 1, step = boots[i].f.s;
		while(cur + step < n){
			if(cur == *(--ms.upper_bound(cur + step))){
				res[boots[i].s] = 0;
				break;
			}
			cur = *(--ms.upper_bound(cur + step));
		}
		if(cur + step >= n){
			res[boots[i].s] = 1;
		}
	}
	forn(i, b){
		cout << res[i] << endl;
	}
}