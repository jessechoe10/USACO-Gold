#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

#define forn(i, n) for(int i = 0; i < n; i++)

const ll MAXN = 1e5;

ll dp[MAXN][21][3];

bool beat(ll x, ll y){
	return (x == 0 && y == 1) || (x == 1 && y == 2) || (x == 2 && y == 0);
}

ll max(ll x, ll y, ll z){
	return max(x, max(y, z));
}

int main(){
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
	ll n, K; cin >> n >> K;
	vl gestures(n);
	forn(i, n){
		char g; cin >> g;
		if(g == 'H'){
			gestures[i] = 0;
		} else if(g == 'P'){
			gestures[i] = 1;
		} else {
			gestures[i] = 2;
		}
	}
	memset(dp, 0, sizeof(dp));
	ll res = 0;
	forn(i, n){
		forn(j, min((ll)i + 1, K + 1)){
			if(i > 0 && j > 0){
				dp[i][j][0] = max(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2], dp[i - 1][j][0]) + beat(0, gestures[i]);
				dp[i][j][1] = max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][2], dp[i - 1][j][1]) + beat(1, gestures[i]);
				dp[i][j][2] = max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1], dp[i - 1][j][2]) + beat(2, gestures[i]);
			} else if(i > 0){
				dp[i][j][0] = dp[i - 1][j][0] + beat(0, gestures[i]);
				dp[i][j][1] = dp[i - 1][j][1] + beat(1, gestures[i]);
				dp[i][j][2] = dp[i - 1][j][2] + beat(2, gestures[i]);
			} else {
				dp[i][j][0] = beat(0, gestures[i]);
				dp[i][j][1] = beat(1, gestures[i]);
				dp[i][j][2] = beat(2, gestures[i]);
			}
			res = max(res, max(dp[i][j][0], dp[i][j][1], dp[i][j][2]));
		}
	}
	cout << res << endl;
}