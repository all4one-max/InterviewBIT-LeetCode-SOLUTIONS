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
// TIME COMPLEXITY = O(logV)

int n,  m, e, t, k, len, u1, u2,  w, v, d;
const int mx = 300005, mod = 1000000007, mx2 = 1000005 , mx3 = 100000;

struct subset {
  int rank, parent;
};

struct Edge {
  int src, dest;
};

vector<Edge> edge(mx, {0, 0});
vector<subset> vertices(mx, {0, 0});

int find_parent_nd_compress(int cur) {
  if (vertices[cur].parent != cur) {
    vertices[cur].parent = find_parent_nd_compress(vertices[cur].parent);
  }
  return vertices[cur].parent;
}

void uunion(int x, int y) {
  int xroot = find_parent_nd_compress(x);
  int yroot = find_parent_nd_compress(y);

  if (xroot != yroot) {
    if (vertices[xroot].rank > vertices[yroot].rank) vertices[yroot].parent = xroot;
    else if (vertices[xroot].rank < vertices[yroot].rank) vertices[xroot].parent = yroot;
    else {
      vertices[yroot].parent = xroot;
      vertices[xroot].rank += 1;
    }
  }
  return;
}

int isCycle() {
  fo(i, n + 1) {
    vertices[i].rank = 0;
    vertices[i].parent = i;
  }
  fo(i, m) {
    int x = find_parent_nd_compress(edge[i].src);
    int y = find_parent_nd_compress(edge[i].dest);
    if (x == y) return 1;
    uunion(x, y);
  }
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
  cin >> n >> m;
  fo(i, m) {
    cin >> u1 >> u2;
    edge[i].src = u1;
    edge[i].dest = u2;
  }
  if (isCycle() == 1) cout << "CYCLE IS PRESENT" << endl;
  else cout << "CYCLE IS NOT PRESENT" << endl;
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
