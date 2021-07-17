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
#define pf             push_front
#define mp             make_pair

ll n, x, m, y, e, start;

int help_cycle_ud_dfs(vector<int> adj[], vector<int> &visited, ll v, ll parent) {
  visited[v] = 1;
  for (auto it : adj[v]) {
    if (visited[it] == 0) {
      int vl = help_cycle_ud_dfs(adj, visited, it, v);
      if (vl == 1) return 1;
    }
    else {
      if (parent != it) return 1;
    }
  }
  return 0;
}

void cycle_ud_dfs(vector<int> adj[]) {
  vector<int> visited(n + 1, 0);
  visited[0] = 1;
  fo(i, n + 1) {
    if (visited[i] == 0) {
      int vl = help_cycle_ud_dfs(adj, visited, 1, 1);
      if (vl == 1) {cout << "CYCLE IS PRESENT"; return;}
    }
  }
  cout << "CYCLE IS NOT PRESENT";
  return;
}

void solve() {
  cin >> n >> e;
  vector<int> adj[n + 1];
  ll u1, u2;
  fo(i, e) {
    cin >> u1 >> u2;
    adj[u1].pb(u2);
    adj[u2].pb(u1);
  }
  cycle_ud_dfs(adj);
}

int main() {
# ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for getting input from output.txt
  freopen("output.txt", "w", stdout);
# endif
  int t = 1;
  fo(i, t) solve();

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
