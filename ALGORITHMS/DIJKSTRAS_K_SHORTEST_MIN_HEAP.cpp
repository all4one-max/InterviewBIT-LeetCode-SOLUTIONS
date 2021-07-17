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

int n,  m, y, e, t, k, len, u1, u2,  w, v;
const int mx = 300005, mod = 1000000007, mx2 = 200005 , mx3 = 100000, INF = 1e15;
vector< pair<int, int> > adj[mx2];

/*
so basically when we implement dijkstra we add a vertex to the priority queue
only one time and this is based on the fact that the minimum distance to this
vertex from the source has been found but when we are implementing dijkstra for
k shortest path we will add a vertex at most k times into the priority queue
*/

void dijkstra_k_shortest() {
  vector<vector<int>> dist(mx2, vector<int>(k, INF));
  priority_queue <
  pair<int, int>,
       vector<pair<int, int>>,
       greater<pair<int, int>>
       > q;
  q.push({0, 1});
  dist[1][0] = 0;
  while (!q.empty()) {
    u1 = q.top().se;
    int d = q.top().fi;
    q.pop();
    if (d > dist[u1][k - 1]) continue;
    for (auto it : adj[u1]) {
      u2 = it.fi;
      w = it.se;
      if (dist[u2][k - 1] > (d + w)) {
        dist[u2][k - 1] = (d + w);
        q.push({dist[u2][k - 1], u2});
        sort(all(dist[u2]));
      }
    }
  }
  fo(i, k) cout << dist[n][i] << " "; cout << endl;
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
  cin >> n >> m >> k;
  fo(i, m) {
    cin >> u1 >> u2 >> w;
    adj[u1].pb({u2, w});
  }
  dijkstra_k_shortest();
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
