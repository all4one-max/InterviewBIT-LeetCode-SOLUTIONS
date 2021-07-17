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
// INCOMPLETE. WASN'T ABLE TO SOLVE IT ALTHOUGH READ THE EDITORIAL 5-10 TIMES
int n,  m, y, e, t, k, len, u1, u2,  w, v, d;
const int mx = 200005, mod = 1000000007, mx2 = 1000005 , mx3 = 100000;
vector<vector<int>> masks(mx, vector<int> (32, 0));

struct Edge {
  int src, dest, weight;
};

struct subset {
  int rank, parent;
};

bool comp(Edge p1, Edge p2) {
  if (p1.weight < p2.weight) return true;
  return false;
}

int find_parent_nd_compress(subset* ranks, int cur) {
  if (ranks[cur].parent != cur) {
    ranks[cur].parent = find_parent_nd_compress(ranks, ranks[cur].parent);
  }
  return ranks[cur].parent;
}

void uunion(subset* ranks, int x, int y) {
  int xroot = find_parent_nd_compress(ranks, x);
  int yroot = find_parent_nd_compress(ranks, y);

  if (ranks[xroot].rank > ranks[yroot].rank) ranks[yroot].parent = xroot;
  else if (ranks[xroot].rank < ranks[yroot].rank) ranks[xroot].parent = yroot;
  else {
    ranks[yroot].parent = xroot;
    ranks[xroot].rank += 1;
  }
  return;
}

int getMST(Edge* edge, int e, int v) {
  int mst = 0;
  subset* ranks = new subset[v + 1];
  fo(i, v + 1) {
    ranks[i].rank = 0;
    ranks[i].parent = i;
  }
  vector<int> parent(v + 1, 0);
  fo1(i, v + 1) parent[i] = i;
  int count = 0, i = 0;
  while (count < (v - 1)) {
    int u1 = edge[i].src, u2 = edge[i].dest;
    int p1 = find_parent_nd_compress(ranks, u1), p2 = find_parent_nd_compress(ranks, u2);
    if (p1 != p2) {
      count++;
      uunion(ranks, p1, p2);
      mst += edge[i].weight;
      //cout << edge[i].weight << endl;
    }
    i += 1;
  }
  return mst;
}

bool comp1(vector<int> v1, vector<int>v2) {
  if (v1[0] < v2[0]) {
    return true;
  }
  return false;
}


signed main()
{ tezi
# ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for getting input from output.txt
  freopen("output.txt", "w", stdout);
# endif
  cin >> n >> d;
  Edge* edge  = new Edge[n];
  map<int, int> mp;
  fo(i, n) {
    vector<int> dim = {0, 0, 0, 0, 0};
    fo(j, d) cin >> dim[j];
    fo(j, 32) {
      int cur = 0;
      for (int k = 4; k >= 0; k--) {
        if ((j >> k) & 1) cur += dim[k];
        else cur -= dim[k];
      }
      masks[i][j] = cur;
    }
  }
  vector<vector<int>> masks_min(32, vector<int>(3, 1e7 + 10));
  fo(i, 32) {
    fo(j, n) {
      if (masks[j][i] < masks_min[i][0]) masks_min[i] = {masks[j][i], j, i};
    }
  }
  fo(i, n) {
    fo(j, 32) {
      int cur_length = min();
    }
  }
  sort(edge, edge + n, comp);
  //fo(i, n) cout << edge[i].src << " " << edge[i].dest << " " << edge[i].weight << endl;
  cout <<  -1 * getMST(edge, n, n) << endl;
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
