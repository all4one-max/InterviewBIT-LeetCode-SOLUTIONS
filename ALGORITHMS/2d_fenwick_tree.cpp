#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>
// #include "atcoder/math.hpp"
using namespace __gnu_pbds;
using namespace std;
#define tezi           ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set    tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int            long long
#define fo(i,n)        for (int i=0;i<n;i++)
#define fo1(i, n)      for (int i = 1; i < n; i++)
#define endl           "\n"
#define MAX(a,b)       (a>b) ? a : b
#define MIN(a,b)       (a>b) ? b : a
#define fi             first
#define se             second
#define pb             push_back
#define mp             make_pair
#define all(v)         v.begin(), v.end()
#define uniq(v)        v.resize(unique(all(v)) - v.begin())
#define sz(v)          v.size()
#define pii            pair<int, int>

int n,  m, y, e, t, k, q, u1, u2,  w, c, d, x, b, ans;
const int mx = 400005, mod = 1LL << 32, mx2 = 200005 , mx3 = 100005, INF = 1000000000000000000;
vector<vector<int>> BIT(1005, vector<int> (1005, 0));
vector<vector<int>> a(1005, vector<int> (1005, 0));

void update(int x, int y, int delta) {
    for (int i = x; i < n + 1; i += (i & -i)) {
        for (int j = y; j < n + 1; j += (j & -j)) {
            BIT[i][j] += delta;
        }
    }
    return;
}

int query(int x, int y) {
    int ret = 0;
    for (int i = x; i > 0; i -= (i & -i))
        for (int j = y; j > 0; j -= (j & -j))
            ret += BIT[i][j];
    return ret;
}

void solve() {
    cin >> n >> q;
    char c;
    fo1(i, n + 1) {
        fo1(j, n + 1) {
            cin >> c;
            a[i][j] = (1 ? (c == '*') : 0);
            if (a[i][j]) update(i, j, 1);
        }
    }
    fo(i, q) {
        cin >> x;
        if (x == 1) {
            cin >> u1 >> u2;
            if (a[u1][u2]) {
                update(u1, u2, -1);
                a[u1][u2] = 0;
            }
            else {
                update(u1, u2, 1);
                a[u1][u2] = 1;
            }
        }
        else {
            cin >> x >> y >> u1 >> u2;
            int ans = query(u1, u2);
            ans -= (query(x - 1, u2));
            ans -= (query(u1, y - 1));
            ans += (query(x - 1, y - 1));
            cout << ans << endl;
        }
    }
}

signed main()
{   tezi
# ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for getting input from output.txt
    freopen("output.txt", "w", stdout);
# endif
    t = 1;
    fo(i, t) solve();
    return 0;
}
/*
    #######
   #
  #
 #######   #     #  # ####   # #     #
       #  # #   #  # #   #  # # #   #
      #  ####  #  # ####   ####  # #
######  #   # #### #    # #   #   #
*/
