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
// TIME COMPLEXITY : O(V + E)

int n,  m, y, e, t, k, len, u1, u2,  w, v;
const int mx = 300005, mod = 1000000007, mx2 = 1000005 , mx3 = 100000;
vector<int> dist(mx3, mod);
vector< pair<int, int> >adj[mx3];

void bfs_0_1() {
  deque<int> dq;
  dq.push_front(1);
  dist[1] = 0;
  while (!dq.empty()) {
    u1 = dq.front();
    dq.pop_front();
    for (auto it : adj[u1]) {
      u2 = it.fi;
      w = it.se;
      if (dist[u2] > (dist[u1] + w)) {
        dist[u2] = (dist[u1] + w);
        if (w == 0) dq.push_front(u2);
        else dq.push_back(u2);
      }
    }
  }
  fo1(i, v + 1) {
    cout << 1 << " " << i << " " << dist[i] << endl;
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
    u1++; u2++;
    adj[u1].pb({u2, w});
    adj[u2].pb({u1, w});
  }
  bfs_0_1();
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
