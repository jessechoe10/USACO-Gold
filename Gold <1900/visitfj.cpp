#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define f first
#define s second

const ll MAXN = 100;
const ll INF = 1e14;

ll dp[MAXN][MAXN], grid[MAXN][MAXN];

int main(){
	freopen("visitfj.in", "r", stdin);
	freopen("visitfj.out", "w", stdout);
	ll n, t; cin >> n >> t;
	forn(i, n){
		forn(j, n){
			cin >> grid[i][j];
		}
	}
	forn(i, n) forn(j, n) dp[i][j] = INF;
	priority_queue<pair<ll, pl>> pq;
	ll res = INF; dp[0][0] = 0;
	pq.push({0, {0, 0}});
	while(!pq.empty()){
		ll d = -pq.top().f, a = pq.top().s.f, b = pq.top().s.s;
		ll curd = (n - 1 - a) + (n - 1 - b); pq.pop();
		if(curd <= 2){
			res = min(res, d + curd * t);
		}
		forn(i, n){
			forn(j, n){
				ll dist = abs(i - a) + abs(j - b);
				if(dist == 1 || dist == 3){
					if(d + grid[i][j] + 3 * t <= dp[i][j]){
						dp[i][j] = d + grid[i][j] + 3 * t;
						pq.push({-dp[i][j], {i, j}});
					}
				}
			}
		}
	}
	cout << res << endl;
}