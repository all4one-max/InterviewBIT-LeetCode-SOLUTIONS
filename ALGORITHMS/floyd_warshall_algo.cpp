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
// TIME COMPLEXITY :  O(V**3)
// IT WORKS IN THE CASE OF NEGATIVE WEIGHTS BUT DOES NOT WORK IN CASE OF NEGATIVE CYCLE

int n,  m, y, e, t, k, len, u1, u2,  w, v;
const int mx = 300005, mod = 1000000007, mx2 = 1000005 , mx3 = 100000, INF = 1000000000;
vector<vector<int>> dist(1001, vector<int> (1001, INF));

void floyd_warshall() {
  for (int k = 1; k < (v + 1); ++k) {
    for (int i = 1; i < (v + 1); ++i) {
      for (int j = 1; j < (v + 1); ++j) {
        if (dist[i][k] < INF && dist[k][j] < INF)
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  fo1(i, v + 1) {
    fo1(j, v + 1) {
      cout << dist[i][j] << " ";
    }
    cout << endl;
  }
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
  cin >> v >> e;
  fo(i, v + 1) dist[i][i] = 0;
  fo(i, e) {
    cin >> u1 >> u2 >> w;
    dist[u1][u2] = w;
    dist[u2][u1] = w;
  }
  floyd_warshall();
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
