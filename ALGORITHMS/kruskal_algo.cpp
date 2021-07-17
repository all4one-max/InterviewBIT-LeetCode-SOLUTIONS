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
// TIME COMPLEXITY : O(ElogE + E*V)
// HERE THE WORST CASE COMPLEXITY OF get_parent() FUNCTION IS O(V), THIS CAN BE IMPORVED
// UNION BY RANK AND PATH COMPRESSION

int n,  m, y, e, t, k, len, u1, u2,  w, v;
const int mx = 300005, mod = 1000000007, mx2 = 1000005 , mx3 = 100000;

struct Edge {
  int src, dest, weight;
};

bool comp(Edge p1, Edge p2) {
  if (p1.weight < p2.weight) return true;
  return false;
}

int get_parent(int ind, vector<int> &parent) {
  int p = parent[ind];
  while (p != ind) {
    ind = p;
    p = parent[ind];
  }
  return p;
}

Edge* getMST(Edge* edge, int e, int v) {
  Edge* output = new Edge[v - 1];
  vector<int> parent(v + 1, 0);
  fo1(i, v + 1) parent[i] = i;
  int count = 0, i = 0;
  while (count < (v - 1)) {
    int u = edge[i].src, v = edge[i].dest;
    int p1 = get_parent(u, parent), p2 = get_parent(v, parent);
    if (p1 != p2) {
      if (p1 < p2) parent[p2] = parent[p1];
      else parent[p1] = parent[p2];
      output[count] = edge[i];
      count += 1;
    }
    i += 1;
  }
  return output;
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
  Edge* edge = new Edge[e];
  fo(i, e) {
    cin >> u1 >> u2 >> w;
    edge[i].src = u1;
    edge[i].dest = u2;
    edge[i].weight = w;
  }
  sort(edge, edge + e, comp);
  Edge* output = getMST(edge, e, v);
  fo(i, v - 1) {
    if (output[i].src < output[i].dest)
      cout << output[i].src << " " << output[i].dest << " " << output[i].weight << endl;
    else
      cout << output[i].dest << " " << output[i].src << " " << output[i].weight << endl;
  }
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
