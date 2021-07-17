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
//TIME COMPLEXITY : O(ElogV) or O(ElogE) O(ElogE + ElogV)

int n,  m, y, e, t, k, len, u1, u2,  w, v;
const int mx = 300005, mod = 1000000007, mx2 = 1000005 , mx3 = 100000;

struct Edge {
  int src, dest, weight;
};
vector<Edge> edge;
vector<Edge> output;

struct subset {
  int rank, parent;
};
vector<subset> ranks;

bool comp(Edge p1, Edge p2) {
  if (p1.weight < p2.weight) return true;
  return false;
}

int find_parent_nd_compress(int cur) {
  if (ranks[cur].parent != cur) {
    ranks[cur].parent = find_parent_nd_compress(ranks[cur].parent);
  }
  return ranks[cur].parent;
}

void uunion(int x, int y) {
  int xroot = find_parent_nd_compress(x);
  int yroot = find_parent_nd_compress(y);

  if (ranks[xroot].rank > ranks[yroot].rank) ranks[yroot].parent = xroot;
  else if (ranks[xroot].rank < ranks[yroot].rank) ranks[xroot].parent = yroot;
  else {
    ranks[yroot].parent = xroot;
    ranks[xroot].rank += 1;
  }
  return;
}

void getMST(int e, int v) {
  fo(i, v + 1) ranks.pb({0, i});
  int edege_count = 0, i = 0, mst = 0;
  // A graph with V vertices will have (V-1) edges in its spanning tree if that graph
  // is conncted. So, in the case of disconnected graph we would need to iterate over
  // all the edges. therefore for disonnected graph the condition in the while loop
  // would be i < e
  while (edege_count < (v - 1)) {
    int u1 = edge[i].src, u2 = edge[i].dest;
    int p1 = find_parent_nd_compress(u1), p2 = find_parent_nd_compress(u2);
    if (p1 != p2) {
      output.pb(edge[i]);
      mst += edge[i].weight;
      edege_count++;
      uunion(p1, p2);
    }
    i += 1;
  }
  cout << mst << endl;
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
    edge.pb({u1, u2, w});
  }
  sort(edge.begin(), edge.end(), comp);
  getMST(e, v);
  // fo(i, v - 1) {
  //   if (output[i].src < output[i].dest)
  //     cout << output[i].src << " " << output[i].dest << " " << output[i].weight << endl;
  //   else
  //     cout << output[i].dest << " " << output[i].src << " " << output[i].weight << endl;
  // }
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
