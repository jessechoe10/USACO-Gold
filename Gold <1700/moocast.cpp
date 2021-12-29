#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define pb push_back
#define f first
#define s second

const ll MAXN = 1000;

struct DSU {
	ll parent[MAXN], size[MAXN];
	void init(ll n){
		forn(i, n) parent[i] = i, size[i] = 1;
	}
	ll find(ll v){
		if(v == parent[v]){
			return v;
		}
		return parent[v] = find(parent[v]);
	}
	void merge(ll a, ll b){
		a = find(a), b = find(b);
		if(a != b){
			if(size[a] < size[b]){
				swap(a, b);
			}
			parent[b] = a;  
			size[a] += size[b];
		}
	}
	bool same(ll a, ll b){
		return find(a) == find(b);
	}
};

vpl coords; ll n;

bool works(ll x){
	DSU graph; graph.init(n);
	forn(i, n){
		for(ll j = i + 1; j < n; j++){
			ll xD = coords[j].f - coords[i].f;
			ll yD = coords[j].s - coords[i].s;
			ll dist = xD * xD + yD * yD;
			if(dist <= x){
				graph.merge(i, j);
			}
		}
	}
	forn(i, n){
		if(!graph.same(0, i)){
			return false;
		}
	}
	return true;
}

int main(){
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
	cin >> n;
	forn(i, n){
		ll x, y; cin >> x >> y;
		coords.pb({x, y});
	}
	ll l = 0, r = 1e9, ans = 1e9;
	while(l <= r){
		ll m = l + (r - l) / 2;
		if(works(m)){
			ans = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	cout << ans << endl;
}