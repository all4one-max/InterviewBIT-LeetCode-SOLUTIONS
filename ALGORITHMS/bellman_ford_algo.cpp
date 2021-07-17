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
// TIME COMPLEXITY : O(V*E)
// THIS ALGO WORKS ONLY IN CASE OF DIRECTED GRAPH
// IT WORKS IN CASE OF NEGATIVE WEIGHTS AND DETECTS NEGATIVE WEIGHT CYCLE

/* FOR UNDIRECTED GRAPH
  As a matter of fact any undirected graph is also a directed graph.

  You just have to specify any edges {u, v} twice (u, v) and (v, u).

  But don't forget, that this also means any edge with a negative weight will count as a loop.
  As the Bellman-Ford algorithm ONLY works on graphs that don't contain any cycles with negative
  weights this actually means your un-directed graph mustn't contain any edges with negative weight.

  If it doesn't its pretty fine to use Bellmann-Ford.
*/

int n,  m, y, e, t, k, len, u1, u2,  w, v;
const int mx = 300005, mod = 1000000007, mx2 = 1000005 , mx3 = 100005;
vector<int> dist(mx3, mx3);
vector< pair<int, int> >adj[mx3];

struct edge {
  int src, dest, weight;
};

void bellman_ford(edge* edges, int vertex, int path_vertex) {
  vector<int> parent(mx3, -1);
  dist[vertex] = 0;
  while (true) {
    bool any_change = false;
    fo(j, e) {
      if (dist[edges[j].src] < mx3) {
        if (dist[edges[j].dest] > (dist[edges[j].src] + edges[j].weight)) {
          dist[edges[j].dest] = (dist[edges[j].src] + edges[j].weight);
          parent[edges[j].dest] = edges[j].src;
          any_change = true;
        }
      }
    }
    if (!(any_change)) break;
  }
  // shortest distance to all
  fo1(i, v + 1) {
    cout << dist[i] << endl;
  }
  // shortest path from vertex to path_vertex
  vector<int> path;
  if (dist[path_vertex] == mx3) cout << "No path from " << v << " to " << t << "." << endl;
  else {
    for (int cur = path_vertex; cur != -1; cur = parent[cur]) {
      path.pb(cur);
    }
    reverse(path.begin(), path.end());
  }
  for (auto it : path) {
    cout << it << " ";
  }
  cout << endl;
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
  edge* edges = new edge[e];
  fo(i, e) {
    cin >> u1 >> u2 >> w;
    u1++; u2++;
    edges[i].src = u1;
    edges[i].dest = u2;
    edges[i].weight = w;
  }
  bellman_ford(edges, 1, 5);
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
