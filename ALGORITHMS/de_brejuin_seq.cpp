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

int n,  m, y, e, t, q, u1, u2,  w, v, c, d, x, k;
const int mx = 400005, mod = 1000000007, mx2 = 200005 , mx3 = 100005, INF = 1000000000000000000;
set<string> seen;
// seen will store the length of n length sequences you have already taken not n - 1
string a = "01";
vector<int> edges; // there would total k**n edges in this vector

void dfs(string node) {
    for (auto it : a) {
        string cur = node + it;
        if (seen.find(cur) == seen.end()) {
            seen.insert(cur);
            dfs(cur.substr(1));
            edges.pb(it - '0');
        }
    }
    return;
}

void solve() {
    cin >> n; // k in the question was 2
    k = 2;
    string start_node = string(n - 1, '0');
    dfs(start_node);
    reverse(all(edges));
    int vl = pow(k, n);
    string ans = start_node;
    fo(i, vl) {
        ans += a[edges[i]];
    }
    cout << ans << endl;
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
