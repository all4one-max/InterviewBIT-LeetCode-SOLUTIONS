#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>
using namespace __gnu_pbds;
using namespace std;
#define tezi           ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set    tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//#define int            long long
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
vector<int> adj[mx3], tin, low;
vector<bool> visited;
set<int> cut_points;
int timer = 0;

/*
To solve questions related to articulation points and bridges it's very important
to understand the concept of dfs tree, which you can look up in detail in fft's
blog, but let's discuss some key points here itself.

1. A Back edge is always from a vertex to an ancestor of that vetex in the dfs
tree.

----Point 2 and 3 are related to bridge------
2. A span edge can be a bridge only if there is a back edge from some subtree of
it's child to it's ancestor.

3. A back edge can never be a bridge.

Now in the code for finding articulation point, low[i] signifies the lowest time of entry
vertex or the lowest depth vertex, vertex i can reach.
*/


void find_cutpoints_helper(int vertex, int parent) {
  visited[vertex] = true;
  tin[vertex] = low[vertex] = timer++;
  int children = 0;
  for (auto it : adj[vertex]) {
    if (it == parent) continue;
    if (visited[it]) {
      // if a node which is the child of vertex has already been visited, then this mean
      // it -> vertex is a back edge
      low[vertex] = min(low[vertex], tin[it]);
    }
    else {
      children++;
      find_cutpoints_helper(it, vertex);
      low[vertex] = min(low[vertex], low[it]);
      // now if the low value of my child is greater than my time in of the parent
      // then this means there is not any back edge from the descendents of this child
      // to the ancestor
      if (low[it] >= tin[vertex] && parent != -1) {
        cut_points.insert(vertex);
      }
    }
  }
  if (parent == -1 && children > 1) cut_points.insert(vertex);
  return;
}

void find_cutpoints() {
  timer = 0;
  visited.assign(v, false);
  tin.assign(v, -1);
  low.assign(v, -1);
  for (int i = 1; i < (v + 1); ++i) {
    if (!visited[i]) find_cutpoints_helper(i, -1);
  }
  for (auto it : cut_points) cout << it << " ";
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
    cin >> u1 >> u2;
    adj[u1].pb(u2);
    adj[u2].pb(u1);
  }
  find_cutpoints();
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
