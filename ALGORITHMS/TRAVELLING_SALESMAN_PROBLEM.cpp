#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>
#include <unordered_map>
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

// TIME COMPLEXITY : O(N^2 * 2^N)

int n,  m, e, t, k, len, u1, u2,  w, v, d;
const int mx = 200005, mod = 1000000007, mx2 = 1000005 , mx3 = 100000, INF = 10000000000000000;
vector<vector<int>> arr(21, vector<int>(21, 0));


int dist[10][10] = {
  {0, 20, 42, 25},
  {20, 0, 30, 34},
  {42, 30, 0, 10},
  {25, 34, 10, 0}
};

vector<vector<int>> dp(20, vector<int>(mx2, -1));
// 0 means city not visited and 1 means city visited

int  tsp(int pos, int mask) {
  // dp[pos][mask] is the minimum distance to travel every available city in mask from pos
  // and then return back to 1
  if (mask == (1 << n) - 1) {
    return dist[pos][0];
  }
  if (dp[pos][mask] != -1) {
    return dp[pos][mask];
  }

  //Now from current node, we will try to go to every other node and take the min ans
  int ans = INF;

  //Visit all the unvisited cities and take the best route
  fo(city, n) {
    if ((mask & (1 << city)) == 0) {
      int newAns = dist[pos][city] + tsp(city, mask | (1 << city));
      ans = min(ans, newAns);
    }
  }
  return dp[pos][mask] = ans;
}

signed main()
{ tezi
# ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for getting input from output.txt
  freopen("output.txt", "w", stdout);
# endif
  n = 4;
  cout << "Travelling Saleman Distance is " << tsp(0, 1);

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

