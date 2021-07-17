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

// TIME COMPLEXITY : O(n*k)

int n,  m, y, e, t, k, q, u1, u2,  w, v, d;
const int mx = 400005, mod = 1LL << 32, mx2 = 1000005 , mx3 = 100005, INF = 10000000000000000;
vector<int> arr(4005, 0);
vector<vector<int>> dp(4005, vector<int> (4005, 0));

void solve() {
  cin >> n >> k;
  fo(i, n) cin >> arr[i];
  fo(i, 4005) dp[i][0] = 1;
  dp[0][arr[0]] = 1;
  fo1(i, n) {
    fo(j, k + 1) {
      if (arr[i] > j) {
        dp[i][j] = dp[i - 1][j];
      }
      else {
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i]];
      };
    }
  }
  string ans = dp[n - 1][k] ? "yes" : "no";
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
  cin >> t;
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
