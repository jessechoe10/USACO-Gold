#include <bits/stdc++.h>

using namespace std;

const ll MAXN = 2e5;

struct SegTree {
	// Copy pasted from https://cp-algorithms.com/data_structures/segment_tree.html
	ll n, t[4*MAXN];
	void build(vl a, int v, int tl, int tr) {
		if (tl == tr) {
			t[v] = a[tl];
		} else {
			ll tm = (tl + tr) / 2;
			build(a, v*2, tl, tm);
			build(a, v*2+1, tm+1, tr);
			t[v] = t[v*2] + t[v*2+1];
		}
	}
	ll query(ll v, ll tl, ll tr, ll l, ll r) {
		if (l > r) 
			return 0;
		if (l == tl && r == tr) {
			return t[v];
		}
		ll tm = (tl + tr) / 2;
		return query(v*2, tl, tm, l, min(r, tm))
			+ query(v*2+1, tm+1, tr, max(l, tm+1), r);
	}
	void update(ll v, ll tl, ll tr, ll pos, ll new_val) {
		if (tl == tr) {
			t[v] = new_val;
		} else {
			ll tm = (tl + tr) / 2;
			if (pos <= tm)
				update(v*2, tl, tm, pos, new_val);
			else
				update(v*2+1, tm+1, tr, pos, new_val);
			t[v] = t[v*2] + t[v*2+1];
		}
	}
};
