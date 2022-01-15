#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define f first
#define s second

const ll MAXN = 1000;
const ll INF = 1e10;

ll dp[MAXN + 1][MAXN + 1][2];

ll dist(pl a, pl b){
	return (b.f - a.f) * (b.f - a.f) + (b.s - a.s) * (b.s - a.s);
}

int main(){
	freopen("checklist.in", "r", stdin);
	freopen("checklist.out", "w", stdout);
	ll h, g; cin >> h >> g;
	vpl holstein(h), gurnsey(g);
	forn(i, h){
		cin >> holstein[i].f >> holstein[i].s;
	}
	forn(i, g){
		cin >> gurnsey[i].f >> gurnsey[i].s;
	}
	forn(i, h + 1){
		forn(j, g + 1){
			dp[i][j][0] = INF, dp[i][j][1] = INF;
		}
	}
	dp[1][0][0] = 0, dp[0][0][0] = 0, dp[0][0][1] = 0;
	for(ll i = 2; i <= h; i++){
		dp[i][0][0] = dp[i - 1][0][0] + dist(holstein[i - 2], holstein[i - 1]);
	}
	for(ll i = 1; i <= h; i++){
		for(ll j = 1; j <= g; j++){
			dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][1] + dist(gurnsey[j - 1], holstein[i - 1]));
			if(i >= 2){
				dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0] + dist(holstein[i - 2], holstein[i - 1]));
			}
			dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][0] + dist(holstein[i - 1], gurnsey[j - 1]));
			if(j >= 2){
				dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][1] + dist(gurnsey[j - 2], gurnsey[j - 1]));
			}
		}
	}
	cout << dp[h][g][0] << endl;
}