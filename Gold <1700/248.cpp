#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using sl = set<ll>;

#define forn(i, n) for(int i = 0; i < n; i++)
#define rofn(i, n) for(int i = n; i >= 0; i--)
#define pb push_back

const ll MAXN = 248;

ll dp[MAXN][MAXN];

int main(){
	freopen("248.in", "r", stdin);
	freopen("248.out", "w", stdout);
	ll n; cin >> n;
	vl a(n); memset(dp, -1, sizeof(dp));
	forn(i, n){
		cin >> a[i];
	}
	ll res = 1;
	for(int j = 1; j <= n; j++){
		forn(i, n){
			if(i + j <= n){
				if(j == 1){
					dp[i][i + j - 1] = a[i];
				}
				for(int k = i; k < i + j - 1; k++){
					if(dp[i][k] == dp[k + 1][i + j - 1] && dp[i][k] > 0){
						dp[i][i + j - 1] = max(dp[i][i + j - 1], dp[i][k] + 1);
					}
				}
				res = max(res, dp[i][i + j - 1]);
			}
		}
	}
	cout << res << endl;
}