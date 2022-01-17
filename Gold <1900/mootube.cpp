#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define pb push_back
#define all(x) begin(x), end(x)
#define rofn(i, n) for(ll i = n - 1; i >= 0; i--)
#define f first
#define s second

const ll MAXN = 1e5;

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

bool cmp(pair<ll, pl> a, pair<ll, pl> b){
    return a.f > b.f;
}

int main(){
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    ll n, q; cin >> n >> q;
    vector<pair<ll, pl>> edges(n);  
    forn(i, n - 1){
        cin >> edges[i].s.f >> edges[i].s.s >> edges[i].f;
        --edges[i].s.f, --edges[i].s.s;
    }
    sort(all(edges), cmp);
    vector<pair<ll, pl>> queries(q);
    forn(i, q){
        cin >> queries[i].f >> queries[i].s.f;
        queries[i].s.s = i; --queries[i].s.f;
    }
    sort(all(queries), cmp);
    ll j = 0; DSU dsu; dsu.init(n);
    vl res(q);
    forn(i, q){
        while(edges[j].f >= queries[i].f){
            dsu.merge(edges[j].s.f, edges[j].s.s);
            j++;
        }
        res[queries[i].s.s] = dsu.get(queries[i].s.f) - 1;
    }
    forn(i, q){
        cout << res[i] << endl;
    }
}