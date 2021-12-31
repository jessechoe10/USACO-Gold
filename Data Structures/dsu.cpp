#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define pb push_back
#define rofn(i, n) for(ll i = n - 1; i >= 0; i--)

const ll MAXN = 2e5;

struct DSU {
	ll par[MAXN], size[MAXN];
	void init(ll n){
		forn(i, n) par[i] = i, size[i] = 1;
	}
	ll find(ll v){
		if(v == par[v]){
			return v; 
		}
		return par[v] = find(par[v]);
	}
	void merge(ll a, ll b){
		a = find(a), b = find(b);
		if(a != b){
			if(size[a] < size[b]){
				swap(a, b);
			}
			par[b] = a;
			size[a] += size[b];
		}
	}
  	bool same(ll a, ll b){
		return find(a) == find(b);
	}
	ll get(ll v){
		return size[find(v)];
	}
};
