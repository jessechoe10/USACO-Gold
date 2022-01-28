#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;
using vpl = vector<pl>;

#define forn(i, n) for (ll i = 0; i < n; i++)
#define pb push_back
#define f first
#define s second

const ll MAXN = 1000, INF = 1e9;

/* 
 * Let dp[i][j] represent the minimum cost with a flow 
 * of j from node 1 to node i
 */

ll c[MAXN], f[MAXN], dp[MAXN][MAXN + 1], n, m;
vpl adj[MAXN];

// Binary search on the answer for the maximum ratio

bool works(ll r)
{
	// Initialize the DP array with infinity
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j <= MAXN; j++)
		{
			dp[i][j] = INF;
		}
	}

	// Set the base cases of the DP

	forn(j, MAXN + 1) dp[0][j] = 0;

	// Process the DP in BFS order starting from point 1

	queue<ll> q;
	q.push(0);

	while (!q.empty())
	{
		ll cur = q.front();
		q.pop();
		for (pl u : adj[cur])
		{
			bool changed = false;

			/* 
			 * This is when the edge going from cur to u.f
			 * doesn't contribute to the flow rate.
			 */

			for (ll i = 0; i < f[u.s]; i++)
			{
				if (dp[cur][i] + c[u.s] < dp[u.f][i])
				{
					changed = true;
					dp[u.f][i] = dp[cur][i] + c[u.s];
				}
			}

			/* 
			 * This is when the edge going from cur to u.f
			 * contributes to the flow rate.
			 */

			for (ll i = f[u.s]; i <= MAXN; i++)
			{
				if (dp[cur][f[u.s]] + c[u.s] < dp[u.f][f[u.s]])
				{
					changed = true;
					dp[u.f][f[u.s]] = dp[cur][f[u.s]] + c[u.s];
				}
			}

			// Add node u.f to the queue if the answer changed

			if (changed)
			{
				q.push(u.f);
			}
		}
	}
	for (ll i = 0; i <= MAXN; i++)
	{
		// Check if 10^6 * flow rate - r * cost >= 0

		ll cost = 1e6 * i - r * dp[n - 1][i];
		if (cost >= 0)
			return true;
	}
	return false;
}

int main()
{

	// File IO

	freopen("pump.in", "r", stdin);
	freopen("pump.out", "w", stdout);

	// Read in the input

	cin >> n >> m;
	for (ll i = 0; i < m; i++)
	{
		ll a, b;
		cin >> a >> b >> c[i] >> f[i];
		--a, --b; // Zero index the nodes

		/* 
		 * Connect the two nodes while storing the index of 
		 * the flow and cost
		 */

		adj[a].pb({b, i}), adj[b].pb({a, i});
	}

	/* 
	 * You binary search on the answer from 0 to 10^9 since 
	 * the ratio can be at most 10^3 and 10^6 * 10^3 = 10^9
     */

	ll l = 0, r = 1e9, ans = 0;
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