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

int n,  m, y, e, t, k, q, u1, u2,  w, v, d, x, ans = 0;
const int mx = 100005, mod = 1LL << 32, mx2 = 1000005 , mx3 = 200005, INF = 1000000000000000000;

struct subset {
  int parent;
};

vector<subset> vertices(mx3, {0});

int find_parent_nd_compress(int cur) {
  if (vertices[cur].parent != cur) {
    vertices[cur].parent = find_parent_nd_compress(vertices[cur].parent);
  }
  return vertices[cur].parent;
}

void uunion(int x, int y) {
  int xroot = find_parent_nd_compress(x);
  int yroot = find_parent_nd_compress(y);
  if (xroot > yroot) {
    vertices[y].parent = xroot;
  }
  else vertices[x].parent = yroot;
  return;
}

int make_set() {
  vector<vector<int>> queries(mx3, vector<int> (3, 0));
  fo(i, q) cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
  fo1(i, n + 3) {
    vertices[i].parent = i;
  }
  vector<int> color(mx3, -1);
  for (int i = q - 1; i >= 0; i--) {
    int l = queries[i][0], r = queries[i][1], c = queries[i][2];
    int idx = find_parent_nd_compress(l);
    while (idx <= r) {
      uunion(idx, idx + 1);
      if (color[idx] == -1) color[idx] = c;
      idx = find_parent_nd_compress(idx);
    }
  }
  fo1(i, n + 1) cout << max((int)0, color[i]) << endl;
  return 0;
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
  make_set();
  return 0;
}
/*
    #######
   #
  #
 #######   #     #  # ####   # #     #
       #  # #   #  # #   #  # # #   #s
      #  ####  #  # ####   ####  # #
######  #   # #### #    # #   #   #
*/
