#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>
using namespace __gnu_pbds;
using namespace std;
#define tezi           ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set    tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
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
#define all(v)         v.begin(), v.end()
#define sz(v)          v.size()
#define pii            pair<int, int>

int n,  m, y, e, t, k, len, u1, u2,  w, v, d;
const int mx = 300005, mod = 1000000007, mx2 = 1000005 , mx3 = 100005, INF = 1e9;

signed main()
{ tezi
# ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for getting input from output.txt
  freopen("output.txt", "w", stdout);
# endif
  cin >> n >> w;
  vector< vector<int> > store(n, vector<int>(2, 0));
  fo(i, n) {
    cin >> u1 >> u2;
    store[i][0] = u1; store[i][1] = u2;
  }
  vector<vector<int>> dp(n + 1, vector<int> (w + 1, 0));
  for (int i = store[n - 1][0]; i <= w; i++) dp[n - 1][i] = store[n - 1][1];
  for (int i = n - 2; i >= 0; i--) {
    for (int j = w; j >= 0; j--) {
      if (store[i][0] > j) dp[i][j] = dp[i + 1][j];
      else {
        dp[i][j] = max(dp[i + 1][j - store[i][0]] + store[i][1], dp[i + 1][j]);
      }
    }
  }
  cout << dp[0][w] << endl;
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
