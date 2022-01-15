#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define pb push_back

const ll MAXN = 1e4, MAXK = 1e3;

ll dp1[MAXN + 1][MAXK + 1];

int main(){
	freopen("teamwork.in", "r", stdin);
	freopen("teamwork.out", "w", stdout);
	ll n, k; cin >> n >> k;
	vl x(n + 1);
	for(ll i = 1; i <= n; i++){
		cin >> x[i];
		dp1[i][1] = x[i]; 
	}
	for(ll i = 1; i <= n; i++){
		for(ll j = 2; j <= k; j++){
			if(i >= j){
				dp1[i][j] = max(dp1[i][j - 1], x[i - j + 1]);
			}
		}
	}
	vl dp2(n + 1);
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= k; j++){
			if(i >= j){
				dp2[i] = max(dp2[i], dp2[i - j] + j * dp1[i][j]);
			}
		}
	}
	cout << dp2[n] << endl;
}