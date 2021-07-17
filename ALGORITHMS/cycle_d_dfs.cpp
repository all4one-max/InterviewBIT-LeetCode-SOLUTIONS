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

// THE REASON WE CAN NOT USE THE SAME ALGO THAT WE USE IN UNDIRECTED GRAPH IS
// THAT SUPPOSE WE HAVE A GRAPH LIKE 5->1->2->3->4 THEN THE UNDIRECTED ALGO
// WILL PREDICT A CYCLE AS IT WILL FIND 1 ALREADY VISITED
// TO AVOID THIS CASE WE TAKE THE HELP OF RECURSION STACK AND DETECT A CYCLE ONLY WHEN
// THE ELEMENT CURRENTLY PRESENT IN THE RECURSION STACK IS VISITED.

int n,  m, y, e, t, k, q, u1, u2,  w, v, d;
const int mx = 400005, mod = 1LL << 32, mx2 = 1000005 , mx3 = 100005, INF = 10000000000000000;
vector<int> adj[mx3];
vector<int> visited(mx3, 0);
vector<int> rec_stack(mx3, 0);
bool cycle = false;

void dfs(int v, int p) {
  visited[v] = 1;
  rec_stack[v] = 1;
  for (auto it : adj[v]) {
    if (visited[it] == 0) {
      dfs(it, v);
      if (cycle) return;
    }
    else {
      if (rec_stack[it]) {
        cycle = true;
        return;
      }
    }
  }
  rec_stack[v] = 0;
  return;
}

void solve() {
  cin >> n >> m;
  fo(i, m) {
    cin >> u1 >> u2;
    adj[u1].pb(u2);
  }
  fo1(i, n + 1) {
    if (visited[i] == 0 && sz(adj[i])) {
      dfs(i, -1);
      if (cycle) {
        cout << i  << " CYCLE IS PRESENT" << endl;
        return;
      }
    }
    cout << "CYCLE IS NOT PRESENT" << endl;
    return;
  }
}

signed main()
{ tezi
# ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for getting input from output.txt
  freopen("output.txt", "w", stdout);
# endif
  solve();
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

