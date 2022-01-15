#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)

const ll MAXN = 100;

ll dp[MAXN][MAXN][MAXN];

int main(){
	freopen("taming.in", "r", stdin);
	freopen("taming.out", "w", stdout);
	ll n; cin >> n;
	vl a(n); forn(i, n) cin >> a[i];
	forn(i, n){
		forn(j, n){
			forn(k, n){
				dp[i][j][k] = MAXN;
			}
		}
	}
	forn(i, n){
		dp[0][0][i] = (a[0] != i);
	}
	for(ll i = 1; i < n; i++){
		forn(j, n){
			forn(k, n){
				if(k > 0){
					dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k - 1] + (a[i] != k));
				} else if(k == 0 && j > 0){
					forn(l, n){
						if(l < i){
							dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][l] + (a[i] != k));
						}
					}
				}
			}
		}
	}
	forn(i, n){
		ll res = MAXN;
		forn(j, n){
			res = min(res, dp[n - 1][i][j]);
		}
		cout << res << endl;
	}
}