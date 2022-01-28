#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define pb push_back
#define rofn(i, n) for(ll i = n - 1; i >= 0; i--)
#define sor(x) sort(begin(x), end(x))
#define f first
#define s second

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

int main(){
	ll n; cin >> n;
	vector<pair<ll, pl>> edges;
	forn(i, n){
		ll c, p1, p2, p3, p4; cin >> c >> p1 >> p2 >> p3 >> p4;
		--p1, --p2, --p3, --p4;
		edges.pb({0, {p1, p2}});
		edges.pb({0, {p3, p4}});
		edges.pb({c, {p1, p3}});
		edges.pb({c, {p1, p4}});
		edges.pb({c, {p2, p3}});
		edges.pb({c, {p2, p4}});
	}
	sor(edges); DSU mst; mst.init(2 * n);
	ll res = 0;
	for(pair<ll, pl> u: edges){
		if(!mst.same(u.s.f, u.s.s)){
			mst.merge(u.s.f, u.s.s);
			res += u.f;
		}
	}
	cout << res << endl;
}