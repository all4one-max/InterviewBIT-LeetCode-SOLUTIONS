#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <map>
using namespace __gnu_pbds;
using namespace std;
#define fst            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll             long long
#define fo(i,n)        for(ll i=0;i<n;i++)
#define endl           "\n"
#define MAX(a,b)       (a>b) ? a : b
#define MIN(a,b)       (a>b) ? b : a
#define fi             first
#define se             second
#define MOD            1000000007
#define pb             push_back
#define mp             make_pair

ll n, x, m, y, e;
const ll mx = 100005;
vector<ll> adj[100001];
vector<ll> transpose[100001];
vector<ll> cost(100001, 0);
stack<ll> stac;
vector<ll> visited(100001, 0);
vector<ll> visitedT(100001, 0);

void kosaraju_helper(ll v) {
  visited[v] = 1;
  for (auto it : adj[v]) {
    if (visited[it] == 0) {
      kosaraju_helper( it);
    }
  }
  stac.push(v);
  return;
}

void kosaraju_transpose_helper(ll v, vector<ll> &li) {
  visitedT[v] = 1;
  li.pb(cost[v - 1]);
  for (auto it : transpose[v]) {
    if (visitedT[it] == 0) {
      kosaraju_transpose_helper(it,  li);
    }
  }
  return;
}

int main()
{ fst
# ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for getting input from output.txt
  freopen("output.txt", "w", stdout);
# endif
  cin >> n;
  fo(i, n) cin >> cost[i];

  cin >> e;
  ll u1, u2;
  fo(i, e) {
    cin >> u1 >> u2;
    adj[u1].pb(u2);
    transpose[u2].pb(u1);
  }
  visited[0] = 1;
  fo(i, n + 1) {
    if (visited[i] == 0) {
      kosaraju_helper( i);
    }
  }
  visitedT[0] = 1;
  ll cst = 0, ways = 1;
  while (stac.empty() == 0) {
    ll ele = stac.top();
    stac.pop();
    if (visitedT[ele] == 0) {
      vector<ll> li;
      kosaraju_transpose_helper(ele,  li);
      ll mn = 4e18, count = 0;
      for (auto it : li) mn = MIN(mn, it);
      for (auto it : li) {if (it == mn) count++;}
      cst += mn;
      ways = (((ways % MOD)) * (count % MOD)) % MOD;
    }
  }
  cout << cst << " " << ways;
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
