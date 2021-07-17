#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>
// #include "atcoder/math.hpp"
using namespace __gnu_pbds;
using namespace std;
#define tezi           ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set    tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define int            long long
#define fo(i,n)        for (int i=0;i<n;i++)
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

int n,  m, y, e, t, k, q, u1, u2,  w, v, c, d, x;
const int mx = 400005, mod = 1LL << 32, mx2 = 200005 , mx3 = 100005, INF = 1000000000000000000;
vector<int> adj[mx2];
vector<int> adjT[mx2];
vector<int> visited(mx2, 0);
vector<int> order;
vector<int> component;

void dfs1(int v) {
  visited[v] = 1;
  for (auto it : adj[v]) {
    if (!visited[it]) dfs1(it);
  }
  order.pb(v);
  return;
}

void dfs2(int v) {
  visited[v] = 1;
  component.pb(v);
  for (auto it : adjT[v]) {
    if (!visited[it]) dfs2(it);
  }
  return;
}

void solve(int t) {
  cin >> n >> m;
  fo(i, m) {
    cin >> u1 >> u2;
    adj[u1].pb(u2);
    adjT[u2].pb(u1);
  }
  fo1(i, n + 1) {
    if (!visited[i]) dfs1(i);
  }
  reverse(all(order));
  fo(i, n + 1) visited[i] = 0;
  for (auto v : order) {
    if (!visited[v]) {
      component.clear();
      dfs2(v);
      for (auto it : component) cout << it << " ";
      cout << endl;
    }
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
  t = 1;
  fo(i, t) solve(i);
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
