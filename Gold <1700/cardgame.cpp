#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

#define forn(i, n) for(int i = 0; i < n; i++)
#define pb push_back
#define sor(x) sort(begin(x), end(x))
#define rsor(x) sort(begin(x), end(x), greater<ll>())

int main(){
	freopen("cardgame.in", "r", stdin);
	freopen("cardgame.out", "w", stdout);
	ll n; cin >> n;
	set<ll> elsie;
	vl high(n / 2), low(n / 2);
	forn(i, n / 2){
		cin >> high[i];
		elsie.insert(high[i]);
	}
	forn(i, n / 2){
		cin >> low[i];
		elsie.insert(low[i]);
	}
	vl bessie;
	for(int i = 1; i <= 2 * n; i++){
		if(!elsie.count(i)){
			bessie.pb(i);
		}
	}
	sor(high), rsor(low);
	vl highB, lowB;
	forn(i, n / 2){
		lowB.pb(bessie[i]);
		highB.pb(bessie[i + n / 2]);
	}
	rsor(lowB);
	ll i = 0, j = 0, res = 0;
	while(j < n / 2){
		if(highB[j] > high[i]){
			i++, j++, res++;
		} else {
			j++;
		}
	}
	i = 0, j = 0;
	while(j < n / 2){
		if(lowB[j] < low[i]){
			i++, j++, res++;
		} else {
			j++;
		}
	}
	cout << res << endl;
}