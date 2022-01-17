#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define forn(i, n) for (ll i = 0; i < n; i++)
#define f first
#define s second
#define pb push_back

const ll MAXN = 250, MAXW = 1000, INF = 1e9;

ll dp[MAXN + 1][MAXW + 1], n, w;
vpl cows;

// Binary search on the answer for r, the ratio * 1000

bool works(ll r)
{
	for (ll i = 0; i <= n; i++)
	{
		for (ll j = 1; j <= w; j++)
		{
			dp[i][j] = -INF;
		}
	}

	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= w; j++)
		{
			ll cost = 1000 * cows[i - 1].s - r * cows[i - 1].f;
			dp[i][j] = max(dp[i - 1][max(0LL, j - cows[i - 1].f)]
			+ cost, dp[i - 1][j]);
		}
	}

	return dp[n][w] >= 0;
}

int main()
{
	freopen("talent.in", "r", stdin);
	freopen("talent.out", "w", stdout);
	cin >> n >> w;
	for (ll i = 0; i < n; i++)
	{
		ll w, t;
		cin >> w >> t;
		cows.pb({w, t});
	}
	ll l = 0, r = 1e6, ans = 0;
	while (l <= r)
	{
		ll m = l + (r - l) / 2;
		if (works(m))
		{
			ans = m;
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}
	}
	cout << ans << endl;
}