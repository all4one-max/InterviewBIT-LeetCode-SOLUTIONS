#include <bits/stdc++.h>
#include <map>
using namespace std;
#define tezi           ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int            long long
#define fo(i,n)        for(int i=0;i<n;i++)
#define fo1(i, n)      for (int i = 1; i < n; i++)
#define endl           "\n"
#define MAX(a,b)       (a>b) ? a : b
#define MIN(a,b)       (a>b) ? b : a
#define fi             first
#define se             second
#define pb             push_back
#define mp             make_pair

int n, x, m, y, e, t, k, len, u1, u2,  f, q, unque = 0;
const int mx = 200005, mod = 1000000007, mx2 = 1000001 ;
vector<int> arr(mx2, 0);
vector<int> BIT(mx2, 0);
vector<int> ans(mx2, 0);
struct node {int first, second, index;};
struct node query[mx2];

void update(int idx, int value) {
	while (idx < mx2) {
		BIT[idx] += value;
		idx += idx & (-idx);
	}
	return;
}

int value(int idx) {
	int sm = 0;
	while (idx > 0) {
		sm += BIT[idx];
		idx -= idx & (-idx);
	}
	return sm;
}

bool operator < (node a, node b) {
	if (a.se == b.se) {
		return a.fi < b.fi;
	}
	return a.se < b.se;
}

signed main()
{	tezi
# ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for getting input from output.txt
	freopen("output.txt", "w", stdout);
# endif
	cin >> n;
	fo1(i, n + 1) cin >> arr[i];
	cin >> q;
	fo(i, q) {
		cin >> u1 >> u2;
		query[i].fi = u1; query[i].se = u2; query[i].index = i;
	}
	sort(query, query + q);
	map<int, int> last;
	fo1(i, n + 1) {
		if (last[arr[i]] != 0) update(last[arr[i]], -1);
		else unque += 1;
		update(i, 1);
		last[arr[i]] = i;
		while (k < q && query[k].se == i) {
			ans[query[k].index] = (unque - value(query[k].fi - 1));
			k += 1;
		}
	}
	fo(i, q) cout << ans[i] << endl;
	return 0;
}
