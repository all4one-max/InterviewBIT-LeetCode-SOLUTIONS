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
// SPFA IS AN OPTIMISATION OF BELLMAN-FORD ALGORITHM
// TIME COMPLEXITY : ON AVERAGE CASE O(E), BUT IT HASN'T BEEN PROVEN YET
//                   ON WORST CASE O(V*E) SAME AS BELLMAN-FORD
// IT WORKS IN CASE OF NEGATIVE WEIGHTS AND DETECTS NEGATIVE WEIGHT CYCLE

int n,  m, y, e, t, k, len, u1, u2,  w, v;
const int mx = 300005, mod = 1000000007, mx2 = 1000005 , mx3 = 100005, INF = 10000000000000000;
vector<pii> adj[mx3];
vector<bool> inQueue(mx3, false);
vector<int> dist(mx3, INF);
vector<int> visits(mx3, 0);

void spfa() {
  queue<int> q;
  q.push(1);
  dist[1] = 0;
  inQueue[1] = true;
  bool neg_cycle = false;
  while (!q.empty()) {
    int u = q.front();
    visits[u]++;
    q.pop();
    inQueue[u] = false;
    if (visits[u] >= n) {
      neg_cycle = true;
      break;
    }
    for (auto it : adj[u]) {
      int v = it.fi, w = it.se;
      if (dist[u] < INF && dist[v] > (dist[u] + w)) {
        dist[v] = (dist[u] + w);
        if (inQueue[v] == false) {
          q.push(v);
          inQueue[v] = true;
        }
      }
    }
  }
  if (neg_cycle) {
    fo1(i, n + 1) {
      if (visits[i] == n) {
        cout << "FOUND NEGATIVE WEIGHT CYCLE" << endl;
      }
    }
  }
  else {
    fo1(i, n + 1) cout << dist[i] << " ";
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
  cin >> n >> m;
  fo(i, m) {
    cin >> u1 >> u2 >> w;
    adj[u1].pb({u2, w});
  }
  spfa();
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
