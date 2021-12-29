#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

#define forn(i, n) for(int i = 0; i < n; i++)

const ll MAXN = 100;
const ll INF = 1e9;

ll dp[MAXN][MAXN][7];
ll cost[MAXN][MAXN];

int main(){
	freopen("cbarn2.in", "r", stdin);
	freopen("cbarn2.out", "w", stdout);
	ll n, K; cin >> n >> K;
	vl a(n);
	forn(i, n){
		cin >> a[i];
	}
	forn(i, n){
		forn(j, n){
			for(ll k = i + 1; k <= i + j; k++){
				cost[i][(i + j + 1) % n] += ((k - i) * a[k % n]);
			}
		}
	}
	forn(i, n) forn(j, n) forn(k, 7) dp[i][j][k] = INF;
	forn(c, n){
		dp[c][c][0] = 0;
		forn(k, 7){
			for(ll i = c; i < n; i++){
				for(ll j = c; j < i; j++){
					if(k > 0){
						dp[c][i][k] = min(dp[c][i][k], dp[c][j][k - 1] + cost[j][i]);
					}
				}
				if(k == K - 1){
					dp[c][i][k] += cost[i][c];
				}
			}
		}
	}
	ll res = INF;
	forn(i, n){
		forn(j, n){
			res = min(dp[i][j][K - 1], res);		
		}
	}
	cout << res << endl;
}