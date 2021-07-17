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

int n,  m, e, t, k, len, u1, u2,  w, v, d;
const int mx = 200005, mod = 998244353 , mx2 = 1000005 , mx3 = 100000;
vector<vector<int>> residual_capacity(1000, vector<int>(1000, 0));
vector<int> adj[1000];
vector<int> parent;

int bfs(int source, int sink) {
  parent.assign(1000, -1);
  parent[source] = -2;
  queue<pair<int, int>> q;
  q.push({source, mx});
  vector<int> visited(1000, 0);
  visited[source] = 1;

  while (!q.empty()) {
    int cur = q.front().first;
    int flow = q.front().second;
    q.pop();

    for (int next : adj[cur]) {
      if (parent[next] == -1 && residual_capacity[cur][next] && visited[next] == 0) {
        parent[next] = cur;
        int new_flow = min(flow, residual_capacity[cur][next]);
        if (next == sink)
          return new_flow;
        q.push({next, new_flow});
        visited[next] = 1;
      }
    }
  }
  return 0;
}

int max_flow(int source, int sink) {
  int new_flow, flow = 0;
  vector<int> augmented_path;

  while (new_flow = bfs(source, sink)) {
    flow += new_flow;
    int cur = sink;
    augmented_path.pb(sink);
    while (cur != source) {
      int prev = parent[cur];
      augmented_path.pb(prev);
      residual_capacity[prev][cur] -= new_flow;
      residual_capacity[cur][prev] += new_flow;
      cur = prev;
    }
    reverse(all(augmented_path));
    for (auto it : augmented_path) cout << it << " ";
    cout << endl << "THE FLOW INCREASED BY " << new_flow << endl;
    augmented_path.clear();
  }

  return flow;
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
    residual_capacity[u1][u2] = w;
    adj[u1].pb(u2);
    adj[u2].pb(u1);
  }
  int source, sink;
  cin >> source >> sink;
  cout << max_flow(source, sink);
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
