#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pl = pair<ll, ll>;

#define forn(i, n) for(ll i = 0; i < n; i++)
#define f first
#define s second

const ll MAXN = 1000, INF = 1e9;
ll grid[MAXN][MAXN], dist[MAXN][MAXN][2][4], n, m;

bool outOfBounds(ll x, ll y, ll smell){
	return x < 0 || y < 0 || x >= n || y >= m || grid[x][y] == 0 || (grid[x][y] == 3 && !smell);
}

int main(){
	freopen("dream.in", "r", stdin);
	freopen("dream.out", "w", stdout);
	cin >> n >> m;
	forn(i, n){
		forn(j, m){
			cin >> grid[i][j];
			forn(k, 2){
				forn(l, 4){
					dist[i][j][k][l] = INF;
				}
			}
		}
	}
	vl dx = {1, 0, -1, 0};
	vl dy = {0, 1, 0, -1};
	queue<pair<pl, pl>> q;
	dist[0][0][0][0] = 0;
	dist[0][0][0][1] = 0; 
	q.push({{0, 0}, {0, 0}});
	q.push({{0, 0}, {0, 1}});
	while(!q.empty()){
		pair<pl, pl> cur = q.front(); q.pop();
		if(outOfBounds(cur.f.f, cur.f.s, cur.s.f)){
			continue;
		}
		if(grid[cur.f.f][cur.f.s] <= 3){
			forn(i, 4){
				ll x = cur.f.f + dx[i], y = cur.f.s + dy[i], smell = cur.s.f;
				if(grid[cur.f.f][cur.f.s] == 2){
					smell = 1;
				}
				if(outOfBounds(x, y, smell)){
					continue;
				}
				if(dist[cur.f.f][cur.f.s][cur.s.f][cur.s.s] + 1 < dist[x][y][smell][i]){
					dist[x][y][smell][i] = dist[cur.f.f][cur.f.s][cur.s.f][cur.s.s] + 1;
					q.push({{x, y}, {smell, i}});
				}
			}
		} else {
			if(outOfBounds(cur.f.f + dx[cur.s.s], cur.f.s + dy[cur.s.s], cur.s.f)){
				forn(i, 4){
					ll x = cur.f.f + dx[i], y = cur.f.s + dy[i];
					if(outOfBounds(x, y, 0)){
						continue;
					}
					if(dist[cur.f.f][cur.f.s][cur.s.f][cur.s.s] + 1 < dist[x][y][0][i]){
						dist[x][y][0][i] = dist[cur.f.f][cur.f.s][cur.s.f][cur.s.s] + 1;
						q.push({{x, y}, {0, i}});
					}
				}
			} else {
				ll x = cur.f.f + dx[cur.s.s], y = cur.f.s + dy[cur.s.s];
				if(outOfBounds(x, y, 0)){
					continue;
				}
				if(dist[cur.f.f][cur.f.s][cur.s.f][cur.s.s] + 1 < dist[x][y][0][cur.s.s]){
					dist[x][y][0][cur.s.s] = dist[cur.f.f][cur.f.s][cur.s.f][cur.s.s] + 1;
					q.push({{x, y}, {0, cur.s.s}});
				}
			}
		}
	}
	ll res = INF;
	forn(i, 2){
		forn(j, 4){
			res = min(res, dist[n - 1][m - 1][i][j]);
		}
	}
	if(res == INF){
		cout << -1 << endl;
	} else {
		cout << res << endl;
	}
}