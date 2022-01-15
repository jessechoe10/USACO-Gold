#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define pb push_back

const ll MAXN = 20, INF = 1e9;

ll n;

char grid[MAXN][MAXN];

vl dx = {-1, 0, 1, 0}, dy = {0, 1, 0, -1};

struct Node {
	ll ax, ay, ad, bx, by, bd;
};

vector<Node> transition(Node cur){
	vector<Node> res;
	res.pb({cur.ax, cur.ay, (cur.ad + 3) % 4, cur.bx, cur.by, (cur.bd + 3) % 4});
	res.pb({cur.ax, cur.ay, (cur.ad + 1) % 4, cur.bx, cur.by, (cur.bd + 1) % 4});
	ll x1 = cur.ax, y1 = cur.ay;
	if(x1 != 0 || y1 != n - 1){
		if(x1 + dx[cur.ad] >= 0 && x1 + dx[cur.ad] < n){
			x1 += dx[cur.ad];
		}
		if(y1 + dy[cur.ad] >= 0 && y1 + dy[cur.ad] < n){
			y1 += dy[cur.ad];
		}
		if(grid[x1][y1] == 'H'){
			x1 = cur.ax;
			y1 = cur.ay;
		}
	}
	ll x2 = cur.bx, y2 = cur.by;
	if(x2 != 0 || y2 != n - 1){
		if(x2 + dx[cur.bd] >= 0 && x2 + dx[cur.bd] < n){
			x2 += dx[cur.bd];
		}
		if(y2 + dy[cur.bd] >= 0 && y2 + dy[cur.bd] < n){
			y2 += dy[cur.bd];
		}
		if(grid[x2][y2] == 'H'){
			x2 = cur.bx;
			y2 = cur.by;
		}
	}
	res.pb({x1, y1, cur.ad, x2, y2, cur.bd});
	return res;
};

ll dp[MAXN][MAXN][4][MAXN][MAXN][4];

int main(){
	freopen("cownav.in", "r", stdin);
	freopen("cownav.out", "w", stdout);
	cin >> n;
	forn(i, n){
		string s; cin >> s;
		forn(j, n){
			grid[i][j] = s[j];
		}
	}
	dp[n - 1][0][0][n - 1][0][1] = 1;
	queue<Node> q; q.push({n - 1, 0, 0, n - 1, 0, 1});
	while(!q.empty()){
		Node cur = q.front(); q.pop();
		if(cur.ax == 0 && cur.bx == 0 && cur.ay == n - 1 && cur.by == n - 1){
			cout << dp[cur.ax][cur.ay][cur.ad][cur.bx][cur.by][cur.bd] - 1 << endl;
			break;
		}
		for(Node u: transition(cur)){
			if(dp[u.ax][u.ay][u.ad][u.bx][u.by][u.bd] == 0){
				dp[u.ax][u.ay][u.ad][u.bx][u.by][u.bd] = dp[cur.ax][cur.ay][cur.ad][cur.bx][cur.by][cur.bd] + 1;
				q.push(u);
			}
		}
	}
}