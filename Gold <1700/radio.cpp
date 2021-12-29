#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)

const ll MAXN = 1000;
const ll INF = 1e9;

ll dp[MAXN + 1][MAXN + 1];

int main(){
	freopen("radio.in", "r", stdin);
	freopen("radio.out", "w", stdout);
	ll n, m; cin >> n >> m;
	ll fx, fy, bx, by;
	cin >> fx >> fy >> bx >> by;
	string fj, bessie; cin >> fj >> bessie;
	vl fjX(n + 1), fjY(n + 1), bX(m + 1), bY(m + 1);
	for(ll i = 1; i <= n; i++){
		fjY[i] = fjY[i - 1];
		fjX[i] = fjX[i - 1];
		if(fj[i - 1] == 'N'){
			fjY[i]++;
		} else if(fj[i - 1] == 'S'){
			fjY[i]--;
		} else if(fj[i - 1] == 'W'){
			fjX[i]--;
		} else {
			fjX[i]++;
		}
	}
	for(ll i = 1; i <= m; i++){
		bY[i] = bY[i - 1];
		bX[i] = bX[i - 1];
		if(bessie[i - 1] == 'N'){
			bY[i]++;
		} else if(bessie[i - 1] == 'S'){
			bY[i]--;
		} else if(bessie[i - 1] == 'W'){
			bX[i]--;
		} else {
			bX[i]++;
		}
	}
	forn(i, n + 1){
		forn(j, m + 1){
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	forn(i, n + 1){
		forn(j, m + 1){
			ll x1 = fx + fjX[i], y1 = fy + fjY[i];
			ll x2 = bx + bX[j], y2 = by + bY[j];
			ll cost = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
			if(j > 0){
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + cost);
			}
			if(i > 0){
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + cost);
			}
			if(i > 0 && j > 0){
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + cost);
			}
		}
	}
	cout << dp[n][m] << endl;
}