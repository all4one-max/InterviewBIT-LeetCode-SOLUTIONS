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

int n,  m, y, e, t, k, q, u1, u2,  w, v, x;
int h, a, b;
const int mx = 400005, mod = 1LL << 32, mx2 = 200005 , mx3 = 100005, INF = 1000000000000000000;

int ans = 0;
vector<vector<int>> vis(20, vector<int> (20, 0));
void place(int a, int b) {
  if (a == 0 && b == 0 ) {
    ans++;
    return;
  }
  fo(i, h) {
    fo(j, w) {
      if (vis[i][j] == 0) {
        if (a && (j + 1) < w && !vis[i][j + 1]) {
          vis[i][j] = vis[i][j + 1] = 1;
          place(a - 1, b);
          vis[i][j] = vis[i][j + 1] = 0;
        }
        if (a && (i + 1) < h && !vis[i + 1][j]) {
          vis[i + 1][j] = vis[i][j] = 1;
          place(a - 1, b);
          vis[i + 1][j] = vis[i][j] = 0;
        }
        if (b) {
          vis[i][j] = 1;
          place(a, b - 1);
          vis[i][j] = 0;
        }
        return;
      }
    }
  }
}

void solve() {
  cin >> h >> w >> a >> b;
  place(a, b);
  cout << ans << endl;
  return;
}

signed main()
{ tezi
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
