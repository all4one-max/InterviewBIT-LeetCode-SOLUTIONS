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

ll n, x, m, y, e;
ll curr = 0;

void euler_tour(vector<ll> &euler, vector<int> &visited, vector<ll> adj[], ll i) {
  visited[i] = 1;
  euler[curr++] = i;
  for (auto it : adj[i]) {
    if (visited[it] == 0) {
      euler_tour(euler, visited, adj, it);
      euler[curr++] = i;
    }
  }
  return;
}

void solve() {
  cin >> n >> e;
  vector<ll> adj[n + 1];
  ll u1, u2;
  fo(i, e) {
    cin >> u1 >> u2;
    adj[u1].pb(u2);
    adj[u2].pb(u1);
  }
  vector<ll> euler(2 * n - 1, 0);
  vector<int> visited(n + 1, 0);
  visited[0] = 1;
  euler_tour(euler, visited, adj, 1);
  for (auto it : euler) cout << it << " ";
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
