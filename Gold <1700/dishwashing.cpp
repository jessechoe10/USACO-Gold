#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

#define forn(i, n) for(int i = 0; i < n; i++)

int main(){
	freopen("dishes.in", "r", stdin);
	freopen("dishes.out", "w", stdout);
	ll n; cin >> n;
	vl dish(n), base(n, -1); forn(i, n) cin >> dish[i];
	ll k = 0; stack<ll> s[n], clean;
	while(k < n){
		ll cur = dish[k], i = 0;
		if(!clean.empty()){
			if(cur < clean.top()){
				break;
			}
		}
		while(cur > base[i] && base[i] != -1){
			i++;
		}
		if(base[i] == -1){
			s[i].push(cur);
			base[i] = cur;
		} else {
			while(cur > s[i].top()){
				clean.push(s[i].top());
				s[i].pop();
			}
			s[i].push(cur);
		}
		k++;
	}
	cout << k << endl;
}