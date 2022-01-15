#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define sor(x) sort(begin(x), end(x))
#define forn(i, n) for(ll i = 0; i < n; i++)
#define rofn(i, n) for(ll i = n - 1; i >= 0; i--)
#define f first
#define s second

int main(){
	freopen("split.in", "r", stdin);
	freopen("split.out", "w", stdout);
	ll n; cin >> n;
	vpl locations(n);
	ll mnX = 1e9, mnY = 1e9, mxX = 1, mxY = 1;
	forn(i, n){
		cin >> locations[i].f >> locations[i].s;
		mnX = min(locations[i].f, mnX);
		mxX = max(locations[i].f, mxX);
		mnY = min(locations[i].s, mnY);
		mxY = max(locations[i].s, mxY);
	}
	ll area = max(1LL, abs(mxX - mnX)) * max(1LL, abs(mxY - mnY));
	ll res = 0;
	forn(j, 2){
		sor(locations);
		vl yMin(n, 1e9), yMax(n, 1);
		rofn(i, n){
			if(i < n - 1){
				yMin[i] = min(yMin[i + 1], locations[i].s);
				yMax[i] = max(yMax[i + 1], locations[i].s);
			} else {
				yMin[i] = locations[i].s;
				yMax[i] = locations[i].s;
			}
		}
		ll minY = 1e9, maxY = 1, sumMin = 1e18;
		forn(i, n - 1){
			minY = min(locations[i].s, minY);
			maxY = max(locations[i].s, maxY);
			ll area1 = abs(locations[i].f - locations[0].f) * abs(maxY - minY);
			ll area2 = abs(locations[n - 1].f - locations[i + 1].f) * abs(yMax[i + 1] - yMin[i + 1]);
			sumMin = min(sumMin, area1 + area2);
		}
		res = max(res, area - sumMin);
		forn(i, n){
			swap(locations[i].f, locations[i].s);
		}
	}
	cout << res << endl;
}