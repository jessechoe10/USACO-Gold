#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define f first
#define s second

int main(){
	freopen("art2.in", "r", stdin);
	freopen("art2.out", "w", stdout);
	ll n; cin >> n; 
	vl colors(n + 2), l(n + 1, n), r(n + 1, -1);
	forn(i, n + 2){
		if(i >= 1 && i <= n) cin >> colors[i];   
		l[colors[i]] = min(i, l[colors[i]]);
		r[colors[i]] = max(i, r[colors[i]]);
	}
	stack<ll> st;
	ll res = 0;
	forn(i, n + 2){
		ll c = colors[i];
		if(i == l[c]){
			st.push(c);
			res = max(res, (ll)st.size());
		}
		if(i == r[c]){
			if(st.top() != c){
				cout << -1 << endl;
				return 0;
			} else {
				st.pop();
			}
		}
	}
	cout << res - 1 << endl;
}