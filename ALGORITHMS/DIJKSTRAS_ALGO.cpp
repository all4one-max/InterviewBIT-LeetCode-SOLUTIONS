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
// TIME COMPLEXITY : O(V**2)
// IT DOES NOT WORK IN THE CASE OF NEGATIVE WEIGHTS
//

int n,  m, y, e, t, k, len, u1, u2,  w, v = 9;
const int mx = 300005, mod = 1000000007, mx2 = 1000005 , mx3 = 100000;
vector<vector<int>> graph(1000, vector<int> (1000, 0));
vector<int> visited(mx3, 0);
vector<int> dist(mx3, 1000);

int get_min_vertex() {
  int min_vertex = -1, min_dist = 2000;
  fo(i, v) {
    if (visited[i] == 0 && (dist[i] < min_dist)) {
      min_dist = dist[i];
      min_vertex = i;
    }
  }
  return min_vertex;
}

void dijkstra() {
  dist[0] = 0;
  fo(i, v - 1) {
    int min_vertex = get_min_vertex();
    visited[min_vertex] = 1;
    fo(j, v) {
      if ((visited[j] == 0) && (graph[min_vertex][j] != 0) && ((dist[min_vertex] + graph[min_vertex][j]) < dist[j])) {
        dist[j] = (dist[min_vertex] + graph[min_vertex][j]);
      }
    }
  }
  fo1(i, v) {
    cout << 0 << " " << i << " " << dist[i] << endl;
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
  fo(i, e) {
    cin >> u1 >> u2 >> w;
    graph[u1][u2] = w;
  }
  dijkstra();
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
