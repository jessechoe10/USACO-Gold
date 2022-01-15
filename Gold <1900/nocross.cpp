#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

const ll MAXN = 1000;

ll dp[MAXN + 1][MAXN + 1];

ll max(ll a, ll b, ll c){
	return max(a, max(b, c));
}

int main(){
	freopen("nocross.in", "r", stdin);
	freopen("nocross.out", "w", stdout);
	ll n; cin >> n;
	vl id1(n), id2(n);
	/*
		id1 represents the breed ID of the fields 
		on the first side of the road

		id2 represents the breed ID of the fields
		on the other side of the road.
	*/
	for(ll i = 0; i < n; i++){
		cin >> id1[i];
	}
	for(ll i = 0; i < n; i++){
		cin >> id2[i];
	}
	memset(dp, 0, sizeof(dp));
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + abs(id1[i] - id2[j]) <= 4);
		}
	}
	cout << dp[n][n] << endl;
}