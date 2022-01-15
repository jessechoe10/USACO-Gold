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
	ll get(ll v){
		return size[find(v)];
	}
};

vl adj[MAXN];
bool vis[MAXN];

int main(){
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
	ll n, m; cin >> n >> m;
	forn(i, m){
		ll a, b; cin >> a >> b; --a, --b;
		adj[a].pb(b), adj[b].pb(a);
	}
	vl closing(n); forn(i, n) cin >> closing[i], --closing[i];
	DSU dsu; dsu.init(n); memset(vis, false, sizeof(vis));
	vl res(n); 
	rofn(i, n){
		vis[closing[i]] = true;
		if(i == n - 1){
			res[i] = 1;
		} else {
			for(ll u: adj[closing[i]]){
				if(vis[u]) dsu.merge(closing[i], u);
			}
			res[i] = (dsu.get(closing[i]) == n - i);
		}
	}
	forn(i, n){
		if(res[i]){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}