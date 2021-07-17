#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll             long long
#define fo(i,n)        for(int i=0;i<n;i++)
#define endl           "\n"
#define MAX(a,b)       (a>b) ? a : b
#define MIN(a,b)       (a>b) ? b : a
#define fi             first
#define se             second
#define MOD 1000000007
#define pb             push_back
#define mp             make_pair

void topo_kahn(vector<int> adj[], vector<int> &in_degree, int n) {
  queue<int> q;
  vector<int> topo;
  fo(i, n + 1) {
    if (in_degree[i] == 0) q.push(i);
  }

  while (!q.empty()) {
    int ver = q.front();
    q.pop();
    topo.pb(ver);
    for (auto it : adj[ver]) {
      in_degree[it] -= 1;
      if (in_degree[it] == 0) q.push(it);
    }
  }
  if (topo.size() != n) cout << "cycle present" << endl;
  else {
    for (auto it : topo) cout << it << " ";
  }
}

int main() {
# ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for getting input from output.txt
  freopen("output.txt", "w", stdout);
# endif
  int t = 1;
  while (t--) {
    int n, e, x, y;
    cin >> n >> e;
    vector<int> adj[n + 1]; //directed edges only
    vector<int> in_degree(n + 1, 0);
    in_degree[0] = -99;
    fo(i, e) {
      cin >> x >> y;
      adj[x].pb(y);
      in_degree[y] += 1;
    }
    topo_kahn(adj, in_degree, n);
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
