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

void zero_one_bfs(vector< pair<int, int> > adj[]) {
  vector<ll> distance(n + 1, 1e5);
  distance[start] = 0;
  deque<int> q;
  q.pb(start);
  while (not(q.empty())) {
    ll ele = q.front();
    q.pop_front();
    for (auto it : adj[ele]) {
      if (distance[it.fi] > distance[ele] + it.se) {
        distance[it.fi] = distance[ele] + it.se;
        if (it.se == 1) q.pb(it.fi);
        else q.pf(it.fi);
      }
    }
  }
  for (auto it : distance) cout << it << " ";
  return;
}

void solve() {
  cin >> n >> e;
  vector< pair<int, int> > adj[n + 1];
  ll u1, u2, w;
  cin >> start;
  fo(i, e) {
    cin >> u1 >> u2 >> w;
    adj[u1].pb({u2, w});
    adj[u2].pb({u1, w});
  }

  zero_one_bfs(adj);
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
