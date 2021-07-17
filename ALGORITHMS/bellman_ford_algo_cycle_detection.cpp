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

int n,  m, y, e, t, k, q, u1, u2,  w, v, d;
const int mx = 300005, mod = 998244353, mx2 = 1000005 , mx3 = 200005, INF = 10000000000000000;
vector<int> dist(2505, INF);
struct edge {
  int src, dest, weight;
};
vector<edge> edges(5005, { -1, -1, -1});
vector<int> adj[2505];
vector<int> visited(2505, 0);

void bellman_ford() {
  vector<int> parent(mx3, -1);
  dist[1] = 0;
  fo(i, n - 1) {
    fo(j, m) {
      if (dist[edges[j].src] < INF) {
        if (dist[edges[j].dest] > (dist[edges[j].src] + edges[j].weight)) {
          dist[edges[j].dest] = (dist[edges[j].src] + edges[j].weight);
          parent[edges[j].dest] = edges[j].src;
        }
      }
    }
  }
  bool any_change = false;
  int x;
  fo(j, m) {
    if (dist[edges[j].src] < INF) {
      if (dist[edges[j].dest] > (dist[edges[j].src] + edges[j].weight)) {
        dist[edges[j].dest] = (dist[edges[j].src] + edges[j].weight);
        parent[edges[j].dest] = edges[j].src;
        x = edges[j].dest;
        any_change = true;
      }
    }
  }

  if (any_change) {
    cout << "YES" << endl;
    fo(i, n) x = parent[x];
    int y = x;
    vector<int> cycle;
    while (true) {
      cycle.pb(y);
      y = parent[y];
      if (y == x) break;
    }
    cycle.pb(x);
    reverse(all(cycle));
    for (auto it : cycle) cout << it << " ";
  }
  else {
    cout << "NO" << endl;
  }
  return;
}

void dfs(int v) {
  visited[v] = 1;
  for (auto it : adj[v]) {
    if (visited[it] == 0) dfs(it);
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
  cin >> n >> m;
  fo(i, m) {
    cin >> u1 >> u2 >> w;
    edges[i].src = u1;
    edges[i].dest = u2;
    edges[i].weight = w;
    adj[u1].pb(u2);
  }
  fo1(i, n + 1) {
    if (visited[i] == 0) {
      dist[i] = 0;
      dfs(i);
    }
  }
  bellman_ford();
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
