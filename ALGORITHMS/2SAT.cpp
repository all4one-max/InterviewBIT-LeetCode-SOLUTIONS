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
vector<int> vertices;
vector<int> order;
vector<int> comp(mx2, -1);

void dfs1(int v) {
  visited[v] = 1;
  for (auto it : adj[v]) {
    if (!visited[it]) dfs1(it);
  }
  order.pb(v);
}

void dfs2(int v, int comp_num) {
  visited[v] = 1;
  comp[v] = comp_num;
  for (auto it : adjT[v]) {
    if (!visited[it]) {
      dfs2(it, comp_num);
    }
  }
  return;
}

void solve() {
  cin >> n >> m;
  map<int, int> neg;
  int i = 1, j = m + 1;
  while (i <= m) {
    neg[i] = j;
    neg[j] = i;
    i++; j++;
  }
  fo(i, n) {
    string s;
    cin >> s >> u1;
    if (s == "-") u1 = neg[u1];
    cin >> s >> u2;
    if (s == "-") u2 = neg[u2];
    adj[neg[u1]].pb(u2);
    adj[neg[u2]].pb(u1);
    adjT[u2].pb(neg[u1]);
    adjT[u1].pb(neg[u2]);
    vertices.pb(u1); vertices.pb(u2);
    vertices.pb(neg[u1]); vertices.pb(neg[u2]);
  }
  for (auto v : vertices) {
    if (!visited[v]) dfs1(v);
  }
  reverse(all(order));
  for (auto v : vertices) visited[v] = 0;
  int comp_num = 1;
  for (auto v : order) {
    if (!visited[v]) {
      dfs2(v, comp_num);
      comp_num++;
    }
  }
  vector<string> ans(m + 1);
  fo1(i, m + 1) {
    if (comp[i] == -1) {
      ans[i] = "+";
      continue;
    }
    if (comp[i] == comp[neg[i]]) {
      cout << "IMPOSSIBLE" << endl;
      return;
    }
    if (comp[i] < comp[neg[i]]) {
      ans[i] = "-";
    }
    else {
      ans[i] = "+";
    }
  }
  fo1(i, m + 1) cout << ans[i] << " "; cout << endl;
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
  fo(i, t) solve();
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
