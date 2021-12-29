#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using sl = multiset<ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)

int main(){
	freopen("hayfeast.in", "r", stdin);
	freopen("hayfeast.out", "w", stdout);
	ll n, m; cin >> n >> m;
	vl f(n), s(n);
	forn(i, n){
		cin >> f[i] >> s[i];
	}
	ll i = 0, j = 0, sumF = 0; 
	ll res = 1e9; sl spicy;
	while(j < n){
		while(sumF < m){
			sumF += f[j];
			spicy.insert(s[j]);
			j++;
		}
		res = min(res, *spicy.rbegin());
		sumF -= f[i];
		spicy.erase(spicy.find(s[i]));
		i++;
	}
	cout << res << endl;
}