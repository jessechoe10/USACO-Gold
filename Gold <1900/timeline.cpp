#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define f first
#define s second
#define sor(x) sort(begin(x), end(x))
#define pb push_back

const ll MAXN = 1e5;

vpl adj[MAXN];

int main(){
	freopen("timeline.in", "r", stdin);
	freopen("timeline.out", "w", stdout);
	ll n, m, c; cin >> n >> m >> c;
	vl s(n); forn(i, n) cin >> s[i];
	vl parent(n); queue<ll> q;
	forn(i, c){
		ll a, b, x; cin >> a >> b >> x;
		--a, --b; adj[a].pb({b, x}); parent[b]++;
	}
	forn(i, n) if(!parent[i]) q.push(i);
	while(!q.empty()){
		ll cur = q.front(); q.pop();
		for(pl u: adj[cur]){
			s[u.f] = max(s[u.f], s[cur] + u.s);
			if(!(--parent[u.f])) q.push(u.f);
		}
	}
	forn(i, n) cout << s[i] << endl;
}