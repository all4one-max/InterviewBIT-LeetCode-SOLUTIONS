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
#define sz(v)          v.size()
#define pii            pair<int, int>

int n,  m, y, e, t, q, u1, u2,  w, v, c, d, x, timer = 1;;
const int mx = 400005, mod = 1000000007, mx2 = 200005 , mx3 = 2000005, INF = 1000000000000000000;
vector<int> a(mx2, 0);
vector<vector<int>> st(mx2, vector<int> (25, 0));
vector<int> logg(mx2, 0); // for computation of RMQ in O(1)

void LOG() {
    // logg is with base 2
    logg[1] = 0;
    for (int i = 2; i <= n; i++) {
        logg[i] = logg[i / 2] + 1;
    }
    return;
}

void pre_process() {
    fo(i, n) st[i][0] = a[i];
    fo1(k, 25) {
        for (int i = 0; (i + (1 << k) - 1) < n; i++) {
            // in case of RSQ
            // st[i][k] = st[i][k - 1] + st[i + (1 << (k - 1))][k - 1];
            // in case of RMQ
            st[i][k] = min(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
        }
    }
    return;
}

int RSQ(int l, int r) {
    int ans = 0;
    for (int k = 24; k >= 0; k--) {
        if (l + (1 << k) - 1 <= r) {
            ans += st[l][k];
            l += (1 << k);
        }
    }
    return ans;
}

int RMQ(int l, int r) {
    // When computing the minimum of a range, it doesn't matter if we process a
    // value in the range once or twice. Therefore instead of splitting a range
    // into multiple ranges, we can also split the range into only two overlapping
    // ranges with power of two length.
    int ln = r - l + 1;
    int lg = logg[ln];
    int ans = min(st[l][lg], st[r - (1 << lg) + 1][lg]);
    return ans;
}

void solve() {
    cin >> n >> q;
    fo(i, n) cin >> a[i];
    pre_process();
    LOG();
    fo(i, q) {
        cin >> u1 >> u2;
        u1--; u2--;
        cout << RMQ(u1, u2) << endl;
    }
    return;
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
