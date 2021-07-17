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

void cycle_ud_bfs(vector<int> adj[]) {
  vector<int> visited(n + 1, 0);
  visited[0] = 1;
  visited[1] = 1;
  vector<int> parent(n + 1, -1);
  queue<int> q;
  q.push(1);
  while (not(q.empty())) {
    ll ele = q.front();
    q.pop();
    for (auto it : adj[ele]) {
      if (visited[it] == 0) {
        q.push(it);
        visited[it] = 1;
        parent[it] = ele;
      }
      else {
        if (parent[ele] != it) {
          cout << "CYCLE IS PRESENT";
          return;
        }
      }
    }
  }
  cout << "NO CYCLE";

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
  cycle_ud_bfs(adj);
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
