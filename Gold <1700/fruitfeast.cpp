#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define forn(i, n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = a; i < b; i++)

const ll MAXN = 5e6;

bool dp[2][MAXN + 1];

int main(){
	freopen("feast.in", "r", stdin);
	freopen("feast.out", "w", stdout);
	ll t, a, b; cin >> t >> a >> b;
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1, dp[1][0] = 1;
	forn(i, 2){
		FOR(j, 1, t + 1){
			if(i == 0){
				if(j >= a){
					dp[i][j] |= dp[i][j - a];
				}
				if(j >= b){
					dp[i][j] |= dp[i][j - b];
				}
			} else {
				if(dp[i - 1][j]){
					dp[i][j] |= dp[i - 1][j];
				}
				if(2 * j <= t){
					dp[i][j] |= dp[i - 1][2 * j];
				}
				if((2 * j + 1) <= t){
					dp[i][j] |= dp[i - 1][2 * j + 1];
				}
				if(j >= a){
					dp[i][j] |= dp[i][j - a];
				}
				if(j >= b){
					dp[i][j] |= dp[i][j - b];
				}
			}
		}
	}
	ll res = 0;
	forn(j, t + 1){
		if(dp[1][j]){
			res = j;
		}
	}
	cout << res << endl;
}