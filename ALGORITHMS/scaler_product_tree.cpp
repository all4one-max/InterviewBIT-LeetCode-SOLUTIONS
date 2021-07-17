#include <bits/stdc++.h>
using namespace std;
#define tezi           ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int            long long
#define fo(i,n)        for(int i=0;i<n;i++)
#define fo1(i, n)      for (int i = 1; i < n; i++)
#define endl           "\n"
#define pb             push_back

int n,  m, y, e, q, u1, u2,  w, v, cur = 0;
const int mx = 300005, mx2 = 1000005 , mx3 = 100005;
const int mod = 4294967296;
int gilbertOrder(int x, int y, int pow, int rotate) {
  if (pow == 0) {
    return 0;
  }
  int hpow = 1 << (pow - 1);
  int seg = (x < hpow) ? (
              (y < hpow) ? 0 : 3
            ) : (
              (y < hpow) ? 1 : 2
            );
  seg = (seg + rotate) & 3;
  const int rotateDelta[4] = {3, 0, 0, 1};
  int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
  int nrot = (rotate + rotateDelta[seg]) & 3;
  int subSquareSize = (int)1 << (2 * pow - 2);
  int ans = seg * subSquareSize;
  int add = gilbertOrder(nx, ny, pow - 1, nrot);
  ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
  return ans;
}
struct  query {
  int l, r, id, lc;
  int ord;
  void calcOrder() {
    ord = gilbertOrder(l, r, 23, 0);
  }
};

int res = 0;
vector<int> ww(mx, 0);
vector<int> adj[mx];
vector<int> height(mx, 0);
vector<int> start_time(mx, 0);
vector<int> end_time(mx, 0);
vector<int> time_to_node(mx2, 0);
vector<int> ans(mx, 0);
vector<int> weight(mx, 0);
vector<int> vis(mx, 0);
vector<query> queries(mx);
vector<array<int, 2>> d(mx, { -1, -1});
int up[mx][26];

int lift_node(int u1, int k) {
  int i = 0;
  while (k > 0) {
    if (k & 1) {
      u1 = up[u1][i];
      if (u1 == -1) return -1;
    }
    k = k >> 1;
    i += 1;
  }
  return u1;
}

void binary_lift(int v, int p) {
  start_time[v] = ++cur;
  time_to_node[cur] = v;
  up[v][0] = p;
  for (int i = 1; i < 26; i++) {
    if (up[v][i - 1] != -1) {
      up[v][i] = up[up[v][i - 1]][i - 1];
    } else up[v][i] = -1;
  }
  for (auto it : adj[v]) {
    if (it != p) {
      weight[it] = (((ww[it] % mod) * (ww[it] % mod)) % mod + weight[v]) % mod;
      height[it] = height[v] + 1;
      binary_lift(it, v);
    }
  }
  end_time[v] = ++cur;
  time_to_node[cur] = v;
  return;
}

int LCA(int u, int v) {
  if (height[u] < height[v]) swap(u, v);
  u = lift_node(u, height[u] - height[v]);

  if (u == v) return u;

  for (int i = 25; i >= 0; i--) {
    if (up[u][i] != up[v][i]) {
      u = up[u][i];
      v = up[v][i];
    }
  }
  return lift_node(u, 1);
}

void chck(int i) {
  int kk = height[i];
  if (vis[i]) {
    if (d[kk][1] != -1) res = ( res - (((ww[d[kk][0]]) * (ww[d[kk][1]])) % mod) + mod ) % mod;
    if (d[kk][0] == i) {
      d[kk][0] = d[kk][1];
      d[kk][1] = -1;
    } else {
      d[kk][1] = -1;
    }
  }
  else {
    if (d[kk][0] == -1) {
      d[kk][0] = i;
    } else {
      d[kk][1] = i;
      res = ( res + (((ww[d[kk][0]]) * (ww[d[kk][1]])) % mod) ) % mod;
    }
  }
  vis[i] ^= 1;
  return;
}

void compute() {
  int cur_l = queries[0].l, cur_r = queries[0].l - 1;
  fo(i, q) {
    while (cur_l < queries[i].l) chck(time_to_node[cur_l++]);
    while (cur_l > queries[i].l) chck(time_to_node[--cur_l]);
    while (cur_r < queries[i].r) chck(time_to_node[++cur_r]);
    while (cur_r > queries[i].r) chck(time_to_node[cur_r--]);
    ans[queries[i].id] = (res + weight[queries[i].lc]) % mod;
  }
  fo(i, q) cout << ans[i] % mod << endl;
  return;
}

bool comp(query a, query b) {
  return a.ord < b.ord;
}

signed main()
{ tezi
# ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for getting input from output.txt
  freopen("output.txt", "w", stdout);
# endif
  cin >> n >> q;
  fo1(i, n + 1) cin >> ww[i];
  fo(i, n - 1) {
    cin >> u1 >> u2;
    adj[u1].pb(u2);
    adj[u2].pb(u1);
  }
  weight[1] = ((ww[1] % mod) * (ww[1] % mod)) % mod;
  binary_lift(1, -1);
  fo(i, q) {
    cin >> u1 >> u2;
    queries[i].id = i;
    queries[i].lc = LCA(u1, u2);
    if (start_time[u1] > start_time[u2]) swap(u1, u2);
    if (u1 == u2) {
      queries[i].l = start_time[u1];
      queries[i].r = start_time[u2];
    }
    else {
      queries[i].l = end_time[u1];
      queries[i].r = start_time[u2];
    }
    queries[i].calcOrder();
  }
  sort(queries.begin(), queries.begin() + q, comp);
  compute();
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
