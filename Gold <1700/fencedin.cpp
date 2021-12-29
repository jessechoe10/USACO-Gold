#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using pll = pair<ll, pl>;

#define forn(i, n) for(int i = 0; i < n; i++)
#define f first
#define s second
#define sor(x) sort(begin(x), end(x))
#define pb push_back

const ll MAXN = 5e6;

ll parent[MAXN], rnk[MAXN];

struct DSU {
	void init(ll n){
		forn(i, n){
			parent[i] = i, rnk[i] = 0;
		}
	}
	ll find(ll v){
		if(v == parent[v]){
			return v;
		}
		return parent[v] = find(parent[v]);
	}
	void merge(ll a, ll b){
		a = find(a);
		b = find(b);
		if(a != b){
			if(rnk[a] < rnk[b]) swap(a, b);
			parent[b] = a;
			if(rnk[a] == rnk[b]) rnk[a]++;
		}
	}
	bool same(ll a, ll b){
		return find(a) == find(b);
	}
};

vector<pll> edges;

void buildGraph(vl a, vl b, ll A, ll B){
	ll n = a.size(), m = b.size();
	vl verticalEdges, horizontalEdges;
	verticalEdges.pb(b[0]);
	forn(i, m - 1){
		verticalEdges.pb(b[i + 1] - b[i]);
	}
	verticalEdges.pb(B - b[m - 1]);
	forn(i, (n + 1) * (m + 1)){
		if(i % (n + 1) != n){
			edges.pb({verticalEdges[i / (n + 1)], {i, i + 1}});
		}
	}
	horizontalEdges.pb(a[0]);
	forn(i, n - 1){
		horizontalEdges.pb(a[i + 1] - a[i]);
	}
	horizontalEdges.pb(A - a[n - 1]);
	forn(i, (n + 1) * (m + 1)){
		if((i / (n + 1)) > 0){
			edges.pb({horizontalEdges[i % (n + 1)], {i - (n + 1), i}});
		}
	}
}

int main(){
	freopen("fencedin.in", "r", stdin);
	freopen("fencedin.out", "w", stdout);
	ll A, B, n, m; cin >> A >> B >> n >> m;
	vl a(n), b(m);
	forn(i, n) cin >> a[i];
	forn(i, m) cin >> b[i];
	sor(a), sor(b);
	ll nodes = (n + 1) * (m + 1);
	DSU mst; mst.init(nodes);
	buildGraph(a, b, A, B);
	sor(edges); ll length = 0;
	for(pll edge: edges){
		if(!mst.same(edge.s.f, edge.s.s)){
			length += edge.f;
			mst.merge(edge.s.f, edge.s.s);
		}
	}
	cout << length << endl;
}