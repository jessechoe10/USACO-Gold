#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)

const ll MAXN = 300, INF = 1e9;

ll dp[MAXN][MAXN];

int main(){
	ll n; cin >> n;
	vl color(n);
	memset(dp, 0, sizeof(dp));
	forn(i, n){
		cin >> color[i];
	}
	forn(i, n){
		forn(j, n){
			if(j > i) dp[i][j] = INF;
		}
	}
	for(ll len = 1; len <= n; len++){
		forn(i, n){
			if(i + len - 1 < n){
				for(ll k = i; k < i + len - 1; k++){
					dp[i][i + len - 1] = min(dp[i][k] + dp[k + 1][i + len - 1], dp[i][i + len - 1]);
				}
				dp[i][i + len - 1] += (color[i] != color[i + len - 1]);
			}
		}
	}
	cout << dp[0][n - 1] + 1 << endl;
}